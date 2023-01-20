
#pragma once

#include "UEComponents.h"
#include "Mesh.h"


class Spline
{

private:
	// To check if Spline component has been initalized or not
	bool Initialized = false;

	// To check if mesh object has been created or not
	bool AddedMesh = false;


private:
	// callee class which has to be an Actor class
	AActor* ParentActor;
	
	USplineComponent* SplineComponent;

	// Mesh class object that is responsible for all operations on the mesh
	Mesh* MeshComponent;

	// indicates whether there has been a mesh component built for all spline points
	bool builtMesh = false;

	UEComponents UEComps;

public:	
	// constructor takes in calee Actor class
	Spline(AActor* Actor);

	// Declares spline and assigns it as RootComponent
	void InitializeSpline(USplineComponent* SplineComp);

	// Adds x,y,z point to the Spline
	void AddPoint(float x, float y, float z);

	// Attach or update the mesh of the spline
	void AttachMesh(UStaticMesh* mesh);

	// Builds the mesh component for the splineComponent
	void BuildMeshComponent(float XScale = 1.0f, float YScale = 1.0f, float ZScale = 1.0f);

	// This function removes spline point and corresponding mesh if exists
	void RemovePoint(int index);

	// Change tangent on spline point
	void ChangeTangent(int index, float DeltaX, float DeltaY, float DeltaZ);

	// Returns the number of points in a spline
	int GetSplinePoints();
};
