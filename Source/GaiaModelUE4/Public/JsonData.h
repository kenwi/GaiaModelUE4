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
#include "Model/Asteroid.h"
#include "Model/Planet.h"
#include "JsonUtils.h"
#include "ConstructorHelpers.h"
#include "Vector4.h"
#include "GameFramework/Actor.h"
#include "JsonData.generated.h"

UCLASS(BlueprintType)
class AJsonData : public AActor 
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug|Build")
		bool DoLazyUnitTest;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug|Build")
		TArray<FPlanet> Planets;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug|Build")
		TArray<FAsteroid> Asteroids;

	UPROPERTY()
		UClass* YourBPClass;

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void OnConstruction(const FTransform & Transform) override;


public:
	AJsonData() : DoLazyUnitTest(true)
	{
		PrimaryActorTick.bCanEverTick = true;

		/*static ConstructorHelpers::FObjectFinder<UClass> MyBPClass(TEXT("Class'/Game/BPOrbitMovement/Lib/BP_Orbit.BP_Orbit_C'"));
		if (MyBPClass.Object != NULL)
		{
			auto t = MyBPClass.Object;
			
		}*/
	}

	UFUNCTION(BlueprintCallable, Category = "Foo")
		void DoWork();

private:
	void ReadJsonStringFromFile(FString &JsonString, const FString FilePath);
	void RemoveComments(FString &JsonString);
	
	template<typename T>
	void ReadObjectsFromJsonString(FString JsonString, TArray<T>& Objects);
};
