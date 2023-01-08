
#include "Spline.h"


Spline::Spline(AActor* Actor)
{
	ParentActor = Actor;

	UEComps.ParentActor = Actor;

}

void Spline::InitializeSpline(USplineComponent* SplineComp) {

	SplineComp = ParentActor->CreateDefaultSubobject<USplineComponent>("Spline");
	if (SplineComp) {
		ParentActor->SetRootComponent(SplineComp);
	}
	SplineComponent = SplineComp;
	UEComps.SplineComponent = SplineComponent;

	Initialized = true;
}

void Spline::AddPoint(float x, float y, float z){

	assert(Initialized);

	SplineComponent->AddSplinePoint(FVector(x, y, z), ESplineCoordinateSpace::World);
	SplineComponent->UpdateSpline();

	if (builtMesh) {
		MeshComponent->BuildSingleMesh(UEComps, SplineComponent->GetNumberOfSplinePoints()-1);
	}

}

void Spline::AttachMesh(UStaticMesh* mesh) {

	MeshComponent = new Mesh();
	MeshComponent->mesh = mesh;

	AddedMesh = true;
}


void Spline::BuildMeshComponent(float XScale, float YScale, float ZScale) {

	assert(AddedMesh);

	builtMesh = MeshComponent->BuildComponent(UEComps, XScale, YScale, ZScale);

}

void Spline::RemovePoint(int index) {

	assert(Initialized);

	SplineComponent->RemoveSplinePoint(index);
	SplineComponent->UpdateSpline();
	
	if (builtMesh) {

		assert(AddedMesh);

		MeshComponent->DeleteMesh(UEComps, index);
	}
}


void Spline::ChangeTangent(int index, float DeltaX, float DeltaY, float DeltaZ) {

	assert(Initialized);

	FVector Tangent = SplineComponent->GetTangentAtSplinePoint(index, ESplineCoordinateSpace::World);

	Tangent.X += DeltaX;
	Tangent.Y += DeltaY;
	Tangent.Z += DeltaZ;

	SplineComponent->SetTangentAtSplinePoint(index, Tangent, ESplineCoordinateSpace::World);
	SplineComponent->UpdateSpline();

	if (builtMesh) {

		assert(AddedMesh);

		MeshComponent->Rebuild(UEComps);
	}
}