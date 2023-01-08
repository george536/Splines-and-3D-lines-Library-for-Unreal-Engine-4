

#include "ThreeDimentionalLine.h"


Line3D::Line3D(AActor* Actor) {

	ParentActor = Actor;
	initalized = true;
}

void Line3D::AddPoint(float X, float Y, float Z) {

	assert(initalized);


	Points.Add(FVector(X, Y, Z));

}

void Line3D::DrawLine(FColor color, bool presistent, float thickness) {

	assert(initalized);

	for (int i = 0; i < Points.Num() - 1; i++) {
		DrawDebugLine(ParentActor->GetWorld(), Points[i], Points[i + 1], color, presistent, -1.0f, 0, thickness);
	}

	LastThickness = thickness;

}

void Line3D::EraseAllLines() {

	assert(initalized);

	FlushPersistentDebugLines(ParentActor->GetWorld());

	Points.Empty();
}

void Line3D::ChangeColor(FColor color) {

	assert(initalized && thickness != NULL);

	for (int i = 0; i < Points.Num() - 1; i++) {
		DrawDebugLine(ParentActor->GetWorld(), Points[i], Points[i + 1],color, true, -1.0f, 0, LastThickness);
	}
}

FVector Line3D::GetFirstPoint() {

	assert(initalized);

	return Points[0];
}

FVector Line3D::GetLastPoint() {

	assert(initalized);

	return Points[Points.Num()-1];
}

FVector Line3D::GetPointAt(int index) {

	assert(initalized);

	return Points[index];
}

int Line3D::GetnumberOfPoints() {

	assert(initalized);

	return Points.Num();

}