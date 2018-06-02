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
#include "Orbit.generated.h"

USTRUCT(BlueprintType)
struct FOrbit
{
	GENERATED_BODY()
	FOrbit()
	{
		Epoch = 0.0;
		MeanAnomaliy = 0.0;
		SemiMajorAxis = 0.0;
		Eccentricity = 0.0;
		ArgofPreiCenter = 0.0;
		AscendingNode = 0.0;
		Period = 0.0;
		Inclination = 0.0;
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Epoch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MeanAnomaliy;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float SemiMajorAxis;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Eccentricity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float ArgofPreiCenter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float AscendingNode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Period;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Inclination;
};


