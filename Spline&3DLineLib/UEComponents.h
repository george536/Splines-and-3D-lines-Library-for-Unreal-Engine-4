
#pragma once

#include "Components/SplineComponent.h"
#include "Components/SplineMeshComponent.h"
#include <cassert>

// This struct will serve as collection of all needed UE object refrences
struct UEComponents {
	USplineComponent* SplineComponent;
	AActor* ParentActor;
};
