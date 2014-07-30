// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "Firestorm.h"
#include "FirestormGameMode.h"
#include "FirestormHUD.h"

AFirestormGameMode::AFirestormGameMode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Blueprints/MyCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFirestormHUD::StaticClass();
}
