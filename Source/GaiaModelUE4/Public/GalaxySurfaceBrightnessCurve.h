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
#include "Curves/CurveFloat.h"
#include "GalaxySurfaceBrightnessCurve.generated.h"

UCLASS(BlueprintType)
class  UGalaxySurfaceBrightnessCurve : public UCurveFloat
{
	GENERATED_BODY()
	
	UGalaxySurfaceBrightnessCurve() 
		: UCurveFloat()
		, Max(10e4)
		, Min(0)
		, BulgeRadius(1000)
		, Steps(1000)
	{

	}

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Max = 10000;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Min = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float BulgeRadius = 1000;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Steps = 100;

public:
	/** Build up a number of points for the curve, then interpolate between them */
	UFUNCTION(BlueprintCallable, Category = "Math|Curves")
		void Build();

	/** Evaluate this float curve at the specified radius */
	UFUNCTION(BlueprintCallable, Category = "Math|Curves")
		float GetSurfaceBrightness(float R) ;

	/** Vaucouleurs-law: I(R) = I0 * e^(-k * R^(1/4)) */
	UFUNCTION(BlueprintCallable, Category = "Math|Curves")
		float GetCentralIntensity(float R, float I0, float k) const;

	/** Freeman: I(R) = I0 * e ^ (-R / a), a = Intensity drop 50 % */
	UFUNCTION(BlueprintCallable, Category = "Math|Curves")
		float GetOuterIntensity(float R, float I0, float a) const;
};
