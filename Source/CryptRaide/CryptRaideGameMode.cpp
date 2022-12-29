// Copyright Epic Games, Inc. All Rights Reserved.

#include "CryptRaideGameMode.h"

#include "CryptRaideCharacter.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

#include "CollectedWidget.h"
#include "Collectable.h"


ACryptRaideGameMode::ACryptRaideGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;
}

void ACryptRaideGameMode::BeginPlay()
{
	TArray<AActor*> Items;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACollectable::StaticClass(), Items);
	ItemsInLevel = Items.Num();
	
	if (GameWidgetClass)
	{
		GameWidget = Cast<UCollectedWidget>(CreateWidget(GetWorld(), GameWidgetClass));
			if (GameWidget)
			{
				GameWidget->AddToViewport();
				UpdateItemText();
			}
	}
}
void ACryptRaideGameMode::UpdateItemText()
{
	GameWidget->SetItemText(ItemsCollected, ItemsInLevel);
}
void ACryptRaideGameMode::ItemCollected()
{
	ItemsCollected++;
	UpdateItemText();
}