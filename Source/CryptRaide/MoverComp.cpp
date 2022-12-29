// Fill out your copyright notice in the Description page of Project Settings.


#include "MoverComp.h"
#include "Math/UnrealMathUtility.h"

// Sets default values for this component's properties
UMoverComp::UMoverComp()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMoverComp::BeginPlay()
{
	Super::BeginPlay();

	OriginalLocation = GetOwner()->GetActorLocation();
	
}


// Called every frame
void UMoverComp::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FVector CurrentLocation = GetOwner()->GetActorLocation();
	FVector TargetLocation = OriginalLocation + MoveOffset;
	float Speed = FVector::Distance(OriginalLocation, TargetLocation) / MoveTime;

	FVector NewLocation = FMath::VInterpConstantTo(CurrentLocation, TargetLocation, DeltaTime, Speed);
	FVector OldLocation = FMath::VInterpConstantTo(CurrentLocation, OriginalLocation, DeltaTime, Speed);
	if(ShouldMove == true)
	{
		GetOwner()->SetActorLocation(NewLocation);
	}
	else
	{
		GetOwner()->SetActorLocation(OldLocation);
	}	
}
void UMoverComp::SetShouldMove(bool NewShouldMove)
	{
		ShouldMove = NewShouldMove;
	}

