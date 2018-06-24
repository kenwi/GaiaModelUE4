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

#include "SolarSystem.h"

void ASolarSystem::BeginPlay()
{
	Super::BeginPlay();
}

void ASolarSystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UpdateForces(DeltaTime);
}

void ASolarSystem::UpdateForces(float DeltaTime)
{
	for (int i = 0; i < Planets.Num(); i++)
	{
		auto &Planet = Planets[i];
	}
}

void ASolarSystem::UpdatePositions(const TArray<FPlanet> &Planets, TArray<FVector> Positions, float DeltaTime)
{
	for (int i = 0; i < Planets.Num(); i++)
	{
		auto &Planet = Planets[i];
	}
}

void ASolarSystem::OnConstruction(const FTransform & Transform)
{
	Super::OnConstruction(Transform);

	if (Planets.Num() > 0) 
	{
		Planets.Empty();
	}

	Data = NewObject<AJsonData>(this);	
	Data->DoWork();
	Planets = Data->Planets;

	TArray<FVector> Positions;
	UpdatePositions(Planets, Positions, 0);
}
