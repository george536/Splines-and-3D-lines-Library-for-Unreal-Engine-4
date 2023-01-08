
#include "Mesh.h"

bool Mesh::BuildComponent(UEComponents UEComps,float XScale, float YScale, float ZScale) {

	XScale = X;
	YScale = Y;
	ZScale = Z;

	for (int SplineCount = 0; SplineCount < (UEComps.SplineComponent->GetNumberOfSplinePoints()) - 1; SplineCount++) {

		BuildSingleMesh(UEComps, SplineCount);

	}

	return true;

}


void Mesh::Rebuild(UEComponents UEComps) {

	for (int i = 0; i < SplineMeshes.Num(); i++) {
		SplineMeshes[i]->DestroyComponent();
	}
	SplineMeshes.Empty();

	BuildComponent(UEComps, X, Y, Z);
}

void Mesh::DeleteMesh(UEComponents UEComps, int index) {

	if (index == 0 || index == (SplineMeshes.Num() - 1)) {
		SplineMeshes[index]->DestroyComponent();
		SplineMeshes.RemoveAt(index);
		
		return;
	}

	Rebuild(UEComps);
}


void Mesh::BuildSingleMesh(UEComponents UEComps, int index) {
 

	USplineMeshComponent* splineMesh = NewObject<USplineMeshComponent>(UEComps.ParentActor, USplineMeshComponent::StaticClass());
	splineMesh->CreationMethod = EComponentCreationMethod::UserConstructionScript;

	splineMesh->SetStaticMesh(mesh);


	splineMesh->SetMobility(EComponentMobility::Movable);

	const FVector StartPos = UEComps.SplineComponent->GetWorldLocationAtSplinePoint(index);
	const FVector StartTangent = UEComps.SplineComponent->GetWorldTangentAtDistanceAlongSpline(UEComps.SplineComponent->GetDistanceAlongSplineAtSplinePoint(index));
	const FVector EndPos = UEComps.SplineComponent->GetWorldLocationAtSplinePoint(index + 1);
	const FVector EndTangent = UEComps.SplineComponent->GetWorldTangentAtDistanceAlongSpline(UEComps.SplineComponent->GetDistanceAlongSplineAtSplinePoint(index + 1));

	splineMesh->SetCollisionEnabled(ECollisionEnabled::Type::QueryAndPhysics);

	splineMesh->SetStartAndEnd(StartPos, StartTangent, EndPos, EndTangent);

	assert(X != NULL && Y != NULL && Y != NULL);

	splineMesh->SetWorldScale3D(FVector(X, Y, Z));


	SplineMeshes.Add(splineMesh);


	UEComps.ParentActor->RegisterAllComponents();
}