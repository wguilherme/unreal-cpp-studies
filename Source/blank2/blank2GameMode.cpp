// Copyright Epic Games, Inc. All Rights Reserved.

#include "blank2GameMode.h"
#include "blank2Character.h"
#include "UObject/ConstructorHelpers.h"

Ablank2GameMode::Ablank2GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
