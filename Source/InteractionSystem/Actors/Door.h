// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Interfaces/InteractionInterface.h"
#include "Components/TimelineComponent.h"

#include "Door.generated.h"

class UCurveFloat;

UCLASS()
class INTERACTIONSYSTEM_API ADoor : public AActor, public IInteractionInterface
{
	GENERATED_BODY()
	
public:
	
	ADoor();

	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> Door;

	UFUNCTION()
	void ToggleDoor();
	
protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Replicated, Category = "Interaction")
	bool bOpened;

	FTimeline Timeline;

	UPROPERTY(EditAnywhere, Category = "Timeline")
	TObjectPtr<UCurveFloat> CurveFloat;

	UPROPERTY(EditAnywhere, Category = "Timeline")
	float DoorRotateAngle = 90.0f;

	UFUNCTION()
	void OpenDoor(float Value);


public:
	
	virtual void Tick(float DeltaTime) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual bool Interact_Implementation() override;

protected:
	
	virtual void BeginPlay() override;
};
