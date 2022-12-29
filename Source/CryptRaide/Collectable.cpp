// Fill out your copyright notice in the Description page of Project Settings.


#include "Collectable.h"
#include "CryptRaideGameMode.h"
#include "CryptRaideCharacter.h"

// Sets default values
ACollectable::ACollectable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;

	Mesh->OnComponentBeginOverlap.AddDynamic(this, &ACollectable::OverlapBegin);
}

// Called when the game starts or when spawned
void ACollectable::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACollectable::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(Cast<ACryptRaideCharacter>(OtherActor) != nullptr)
	{
		Collected();
	}
}
void ACollectable::Collected_Implementation()
{
	ACryptRaideGameMode* GameMode = Cast<ACryptRaideGameMode>(GetWorld()->GetAuthGameMode());

	if (GameMode)
	{
	GameMode->ItemCollected();
	}

}
