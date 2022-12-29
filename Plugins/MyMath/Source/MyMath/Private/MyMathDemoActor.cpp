// Fill out your copyright notice in the Description page of Project Settings.
#include "MyMathDemoActor.h"
#include "MyMathLib.h"

// Sets default values
AMyMathDemoActor::AMyMathDemoActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

static void PrintTextFile(const FString& Path)
{
	// We will use this FileManager to deal with the file.
	IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();
	FString FileContent;
	// Always first check if the file that you want to manipulate exist.
	if (FileManager.FileExists(*Path))
	{
		// We use the LoadFileToString to load the file into
		if (FFileHelper::LoadFileToString(FileContent, *Path, FFileHelper::EHashOptions::None))
		{
			if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Green, FileContent);
		}
		else
		{
			if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("FileManipulation: Did not load text from file."));
		}
	}
	else
	{
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("FileManipulation: ERROR: Can not read the file because it was not found."));
	}
}

// Called when the game starts or when spawned
void AMyMathDemoActor::BeginPlay()
{
	Super::BeginPlay();
	float Sum = MyMathLib::Add(1.0, 2.0);
	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Green, TEXT("Sum: ") + FString::SanitizeFloat(Sum));
	
	const FString Path = FPaths::Combine(FPaths::ProjectPluginsDir(), TEXT("MyMath/Extras/hello.txt"));
	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Yellow, TEXT("Path: ") + Path);
	PrintTextFile(Path);
}

// Called every frame
void AMyMathDemoActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
