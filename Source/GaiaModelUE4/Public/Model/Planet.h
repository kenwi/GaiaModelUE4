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

#include "Orbit.h"
#include "PlanetAtmosphere.h"
#include "PlanetRotation.h"
#include "CoreMinimal.h"
#include "Planet.generated.h"

USTRUCT(BlueprintType)
struct FPlanet
{
	GENERATED_BODY()
	FPlanet()
	{
		Name = "None";
		Color = { 0.0, 0.0, 0.0, 0.0 };
		Size = 1.0;
		AbsMag = 1.0;
		AppMag = 1.0;
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameters")
		FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameters")
		TArray<float> Color;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameters")
		float Size;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameters", meta = (DisplayName = "Absolute Magnitude"))
		float AbsMag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameters", meta = (DisplayName = "Apparent Magnitude"))
		float AppMag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameters")
		FPlanetRotation Rotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameters")
		FPlanetAtmosphere Atmosphere;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameters")
		FOrbit Orbit;
};


