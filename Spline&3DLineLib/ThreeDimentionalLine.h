
#pragma once

#include "UEComponents.h"
#include "DrawDebugHelpers.h"

class Line3D 
{

private:
	bool initalized = false;

private:
	// callee class which has to be an Actor class
	AActor* ParentActor;

	// holds all FVector points that will form the line
	TArray<FVector> Points;

	// represents lsat used thickness for the line
	float LastThickness;

public:

	// constructor takes in calee Actor class
	Line3D(AActor* Actor);

	// Adds a point in 3D space
	void AddPoint(float X, float Y, float Z);

	// Draws connections between all points
	void DrawLine(FColor color, bool presistent, float thickness);

	// Erases all the lines from world
	void EraseAllLines();

	// changes line color
	void ChangeColor(FColor color);

	// Return FVecor of first point in line
	FVector GetFirstPoint();

	// Returns FVector of last point in line
	FVector GetLastPoint();

	// Returns FVector of point in line at index
	FVector GetPointAt(int index);

	// Returns number of points in line
	int GetnumberOfPoints();
};



class AreaFiller {
public:
	// This function can be usesd to fill area between two lines regardless of the shape of area they form
	static void Fill(AActor* ParentClass,int index, Line3D* Line1, Line3D* Line2, FColor color,int coverignDensity, float thickness, float Deltaelevation) {
		FVector s1 = Line1->GetPointAt(index);
		FVector s2 = Line2->GetPointAt(index);
		FVector E1 = Line1->GetPointAt(index + 1);
		FVector E2 = Line2->GetPointAt(index + 1);

		FVector d1(E1.X - s1.X, E1.Y - s1.Y, E1.Z - s1.Z);
		FVector d2(E2.X - s2.X, E2.Y - s2.Y, E2.Z - s2.Z);

		d1 = d1 / coverignDensity;
		d2 = d2 / coverignDensity;

		s1.Z += Deltaelevation;
		s2.Z += Deltaelevation;

		for (int j = 0; j < coverignDensity; j++) {
			DrawDebugLine(ParentClass->GetWorld(), s1 + d1, s2 + d2, color, true, -1, 0, thickness);
			s1 = s1 + d1;
			s2 = s2 + d2;
		}
	}
};