// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SplineComponent.h"
#include "Components/SplineMeshComponent.h"

// Include the necessary library files here
#include "Spline&3DLineLib/Spline.h"
#include "Spline&3DLineLib/ThreeDimentionalLine.h"

#include "runner.generated.h"

UCLASS()
class MYPROJECT2_API Arunner : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	Arunner();

	UPROPERTY(VisibleAnywhere, Category = "Spline")
		USplineComponent* SplineComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spline")
		UStaticMesh* Mesh;

	Spline* s;

	Line3D* Line1;

	Line3D* Line2;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
