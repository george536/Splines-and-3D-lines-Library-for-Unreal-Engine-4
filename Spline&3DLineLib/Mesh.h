
#pragma once

#include "UEComponents.h"

class Mesh
{
private:
	// TArray contains all mesh components for all spline points
	TArray<USplineMeshComponent*> SplineMeshes;

	// These values will remember the Scale at the time of build
	float X = 1.0f;
	float Y = 1.0f;
	float Z = 1.0f;

public:

	UStaticMesh* mesh;

	// Builds the mesh component for the splineComponent
	bool BuildComponent(UEComponents UEComps, float XScale, float YScale, float ZScale);

	// Re-Builds the mesh after changes on the spline component
	void Rebuild(UEComponents UEComps);

	// Build single mesh
	void BuildSingleMesh(UEComponents UEComps, int index);

	// Delete Mesh Component
	void DeleteMesh(UEComponents UEComps, int index);
};

