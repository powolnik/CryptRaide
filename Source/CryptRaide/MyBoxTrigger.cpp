// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBoxTrigger.h"

	//Constructor
UMyBoxTrigger::UMyBoxTrigger()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UMyBoxTrigger::BeginPlay()
{
	Super::BeginPlay();
}

void UMyBoxTrigger::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    
    AActor* Actor = GetAcceptableActor();
    if (Actor != nullptr)
    {
        UPrimitiveComponent* Component = Cast<UPrimitiveComponent>(Actor->GetRootComponent());
        if (Component != nullptr)
        {
            Component->SetSimulatePhysics(false);
        }
        Actor->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
        Mover->SetShouldMove(true);
    }
    else
    {
       Mover->SetShouldMove(false);
    }    

}

void UMyBoxTrigger::SetMover(UMoverComp* NewMover)
{
    Mover = NewMover;
}

AActor* UMyBoxTrigger::GetAcceptableActor() const
{
    TArray<AActor*> Actors;
    GetOverlappingActors(Actors);
    for(AActor* Actor : Actors)
    {
        
        if(Actor->ActorHasTag(AcceptableActorTag) && !Actor->ActorHasTag("Grabbed"))
        {
            return Actor;
        }
        
    }  
    return nullptr;
}

