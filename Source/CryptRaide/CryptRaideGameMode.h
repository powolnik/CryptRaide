// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CryptRaideGameMode.generated.h"

class UCollectedWidget;

UCLASS()
class ACryptRaideGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ACryptRaideGameMode();

	void ItemCollected();

protected:
	int32 ItemsCollected = 0;
	int32 ItemsInLevel = 0;

	virtual void BeginPlay() override;
	void UpdateItemText();

	UPROPERTY()
	UCollectedWidget* GameWidget;	

	UPROPERTY(EditAnywhere, Category="Widgets")
	TSubclassOf<class UUserWidget> GameWidgetClass;
};



