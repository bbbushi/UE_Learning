// Copyright Epic Games, Inc. All Rights Reserved.

#include "Project_LearnGameMode.h"
#include "Project_LearnCharacter/Project_LearnCharacter.h"
#include "UObject/ConstructorHelpers.h"

AProject_LearnGameMode::AProject_LearnGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
