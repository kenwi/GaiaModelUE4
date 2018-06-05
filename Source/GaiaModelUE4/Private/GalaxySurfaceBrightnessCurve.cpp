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

float UGalaxySurfaceBrightnessCurve::GetSurfaceBrightness(float R) const
{
	float I0, k, a = 0;
	float BulgeRadius = 100;
	
	if (R < BulgeRadius) {
		I0 = GetCentralIntensity(R, I0, k);
	}
	else
	{
		I0 = GetCentralIntensity(BulgeRadius, I0, k);
		I0 = GetOuterIntensity(R - BulgeRadius, I0, a);
	}

	return I0;//return R < BulgeRadius ? GetCentralIntensity(R, I0, k) : GetOuterIntensity(R - BulgeRadius, GetCentralIntensity(BulgeRadius, I0, k), a);
}

float UGalaxySurfaceBrightnessCurve::GetCentralIntensity(float R, float I0, float k) const
{
	return I0 * FMath::Exp(-k * FMath::Pow(R, 0.25));
}

float UGalaxySurfaceBrightnessCurve::GetOuterIntensity(float R, float I0, float a) const
{
	return I0 * FMath::Exp(-R / a);
}