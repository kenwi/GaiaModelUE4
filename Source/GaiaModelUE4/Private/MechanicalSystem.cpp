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

#include "MechanicalSystem.h"


UMechanicalSystem::UMechanicalSystem()
{

}

void UMechanicalSystem::Initialize()
{
}

FVector UMechanicalSystem::CalculateForces(const TArray<FVector> &InForces, float DeltaTime)
{
	FVector NetForce = FVector(0);
	uint32 Interations = 0;
	
	for (int i = 0; i < InForces.Num(); i++)
	{
		for (int j = i + 1; j < InForces.Num(); j++, Interations++)
		{
			// Calculate forces by square law
			const FVector dXdY = InForces[i] - InForces[j];
			const float R = FMath::Sqrt(FMath::Pow(dXdY.X, 2) + FMath::Pow(dXdY.Y, 2) + FMath::Pow(dXdY.Z, 2)) * DeltaTime;			
			NetForce += FVector(R);
		}
	}	
	
	return NetForce;
}
