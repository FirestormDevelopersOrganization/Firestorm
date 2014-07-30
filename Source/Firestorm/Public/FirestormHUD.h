// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
#pragma once 

#include "FirestormHUD.generated.h"

UCLASS()
class AFirestormHUD : public AHUD
{
	GENERATED_UCLASS_BODY()

public:

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	UTexture2D* CrosshairTex;

};

