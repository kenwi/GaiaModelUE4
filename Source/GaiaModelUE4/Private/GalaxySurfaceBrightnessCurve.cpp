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
#include "GalaxySurfaceBrightnessCurve.h"

void UGalaxySurfaceBrightnessCurve::Build()
{
	const float h = (Max - Min) / Steps;

	FloatCurve.Reset();
	for (int i = 0; i < Steps; i++)
	{
		const float R = i * h;
		const float Intensity = GetSurfaceBrightness(R);
		FloatCurve.AddKey(R, Intensity);
	}
}

float UGalaxySurfaceBrightnessCurve::GetSurfaceBrightness(float R) 
{
	float I0 = 1.0;
	float k = 0.02;
	float a = Max / 3;
	
	return R < BulgeRadius ? GetCentralIntensity(R, I0, k) : GetOuterIntensity(R - BulgeRadius, GetCentralIntensity(BulgeRadius, I0, k), a);
}

float UGalaxySurfaceBrightnessCurve::GetCentralIntensity(float R, float I0, float k) const
{
	return I0 * FMath::Exp(-k * FMath::Pow(R, 0.25));
}

float UGalaxySurfaceBrightnessCurve::GetOuterIntensity(float R, float I0, float a) const 
{
	return I0 * FMath::Exp(-R / a);
}