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
#include "JsonData.h"
#include "Json.h"
#include "JsonReader.h"
#include "JsonObjectConverter.h"

void AJsonData::BeginPlay()
{
	Super::BeginPlay();
}

void AJsonData::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AJsonData::OnConstruction(const FTransform & Transform)
{
	Super::OnConstruction(Transform);
	
	Planets.Empty();
	Asteroids.Empty();
	if(DoLazyUnitTest)
		DoWork();
}

void DumpToCSV(const TArray<FAsteroid> &Objects)
{
	FString CsvData;
	const FString FilePath = FPaths::ConvertRelativePathToFull(FPaths::ProjectContentDir(), "asteroids.csv");

	for (auto Asteroid : Objects)
	{

	}

	FFileHelper::SaveStringToFile(CsvData, *FilePath);
	CsvData.Empty();
}

void AJsonData::DoWork()
{
	FString Json;
	FString Path = FPaths::ConvertRelativePathToFull(FPaths::ProjectContentDir(), "planets.json");
	ReadJsonStringFromFile(Json, Path);
	ReadObjectsFromJsonString<FPlanet>(Json, Planets);

	/*Path = FPaths::ConvertRelativePathToFull(FPaths::ProjectContentDir(), "asteroids.json");
	ReadJsonStringFromFile(Json, Path);
	ReadObjectsFromJsonString<FAsteroid>(Json, Asteroids);
	*/
	Json.Empty();
	Path.Empty();
}

void AJsonData::ReadJsonStringFromFile(FString &JsonString, const FString FilePath)
{
	check(!FilePath.IsEmpty());

	FFileHelper::LoadFileToString(JsonString, *FilePath);
	RemoveComments(JsonString);
}

void AJsonData::RemoveComments(FString &JsonString)
{
	check(!JsonString.IsEmpty())

	TArray<FString> Lines;
	JsonString.ParseIntoArrayLines(Lines, false);

	JsonString.Empty();
	for (auto Line : Lines)
	{
		if (Line.TrimStart().StartsWith("//")) continue;
		JsonString.Append(Line.Append("\n"));
	}

	Lines.Empty();
	check(!JsonString.IsEmpty());
}

template<typename T>
void AJsonData::ReadObjectsFromJsonString(FString JsonString, TArray<T>& Objects)
{
	FJsonUtils::Deserialize<T>(JsonString, Objects);
}
