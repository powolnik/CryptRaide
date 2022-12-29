// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "MoverComp.h"
#include "MyBoxTrigger.generated.h"


/**
 * 
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CRYPTRAIDE_API UMyBoxTrigger : public UBoxComponent
{
	GENERATED_BODY()

public:
	//Constructor
	UMyBoxTrigger();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void SetMover(UMoverComp* Mover);

private:
	UPROPERTY(EditAnywhere)
	FName AcceptableActorTag;

	UMoverComp* Mover;
	
	AActor* GetAcceptableActor() const;
};
