
#include "Main.h"
#include "Components/SplineMeshComponent.h"

// Sets default values
AMain::AMain()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

  // Declare a spline component
	s = new Spline(this);

  // Initialize it
	s->InitializeSpline(SplineComponent);

  // Add points
	s->AddPoint(0.0f, 0.0f, 0.0f);
	s->AddPoint(100.0f, 0.0f, 0.0f);
	s->AddPoint(100.0f, 100.0f, 0.0f);
	s->AddPoint(0.0f, 100.0f, 0.0f);

  // Declare two 3D lines
	Line1 = new Line3D(this);
	Line2 = new Line3D(this);
}

// Called when the game starts or when spawned
void AMain::BeginPlay()
{
	Super::BeginPlay();

	SetActorLocation(FVector(0.0f, 0.0f, 0.0f));
  
  // Attach mesh to spline component
	s->AttachMesh(Mesh);

  // Build the mesh we just initialized
	s->BuildMeshComponent();

  // Assign points to the lines
	Line1->AddPoint(0.0f, 0.0f, 0.0f);
	Line1->AddPoint(100.0f, 0.0f, 0.0f);
	Line1->AddPoint(200.0f, 0.0f, 0.0f);
	Line1->AddPoint(300.0f, 0.0f, 0.0f);
	Line1->AddPoint(400.0f, 0.0f, 0.0f);
	
  // Draw line 1
	Line1->DrawLine(FColor::White, true, 5.0f);

	Line2->AddPoint(0.0f, 100.0f, 0.0f);
	Line2->AddPoint(100.0f, 100.0f, 0.0f);
	Line2->AddPoint(200.0f, 100.0f, 0.0f);
	Line2->AddPoint(300.0f, 100.0f, 0.0f);
	Line2->AddPoint(400.0f, 150.0f, 0.0f);

  // Draw line 2
	Line2->DrawLine(FColor::White, true, 5.0f);

  // Fill area between the two lines
	for (int i = 0; i < Line1->GetnumberOfPoints() - 1; i++) {

		AreaFiller::Fill(this, i, Line1, Line2, FColor::Red, 100);

	}

}

// Called every frame
void AMain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

