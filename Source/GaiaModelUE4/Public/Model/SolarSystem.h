/*
MIT License

Copyright (c) 2018 Kenneth Wilhelmsen

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once

#include "CoreMinimal.h"
#include "ObjectMacros.h"
#include "GameFramework/Actor.h"
#include "JsonData.h"
#include "Model/Planet.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "ScriptMacros.h"
#include "SolarSystem.generated.h"


UCLASS(BlueprintType)
class ASolarSystem : public AActor
{
	GENERATED_BODY()

public:
	ASolarSystem() 
		: MaxWorldRadiusMeters(10000)
		, UnitsPrMeter(100)
		, SunRadius(695508000)
		, SunMass(1.989e30)
		, ScaleMultiplier(1.0)
	{
		PrimaryActorTick.bCanEverTick = true;

		MaxWorldRadiusUnits = UnitsPrMeter * MaxWorldRadiusMeters;
		SunRadiusScaled = SunRadius / ScaleMultiplier;
		SunMassScaled = SunMass / ScaleMultiplier;

		auto Sun = CreateDefaultSubobject<USphereComponent>(FName("Sphere"));
		Sun->InitSphereRadius(SunRadiusScaled);
		Sun->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		Sun->SetCollisionResponseToAllChannels(ECR_Ignore);
		RootComponent = Sun;
	}

	UFUNCTION(BlueprintCallable)
		void UpdateForces(float DeltaTime);

	void UpdatePositions(const TArray<FPlanet>& Planets, TArray<FVector> Positions, float DeltaTime);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		TArray<FPlanet> Planets;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float SunRadius;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float ScaleMultiplier;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float SunMass;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float SunRadiusScaled;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float SunMassScaled;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		FVector SunPosition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scaling")
		float MaxWorldRadiusMeters;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Scaling")
		float MaxWorldRadiusUnits;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scaling")
		float UnitsPrMeter;

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void OnConstruction(const FTransform & Transform) override;

private:
	UPROPERTY()
		AJsonData *Data;
};


