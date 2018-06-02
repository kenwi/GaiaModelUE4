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

#include "AtmosphereParameters.h"
#include "CoreMinimal.h"
#include "ObjectMacros.h"
#include "PlanetAtmosphere.generated.h"

USTRUCT(BlueprintType)
struct FPlanetAtmosphere
{
	GENERATED_BODY()
	FPlanetAtmosphere()
	{
		Size = 0.0;
		Wavelengths = { 0.0 };
		M_Kr = 0.0;
		M_Km = 0.0;
		CorrectGround = true;
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Size;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<float> Wavelengths;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float M_Kr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float M_Km;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool CorrectGround;

	UPROPERTY(EditAnywhere, meta = (DisplayName = "Amosphere Parameters"))
		FAtmosphereParameters Params;
};


