// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/Door.h"

#include "Net/UnrealNetwork.h"

ADoor::ADoor()
{
	PrimaryActorTick.bCanEverTick = true;
	Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	Door->SetupAttachment(GetRootComponent());

	bReplicates = true;
}

void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Timeline.TickTimeline(DeltaTime);
	ToggleDoor();
}

void ADoor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	DOREPLIFETIME(ADoor, bOpened);
}

bool ADoor::Interact_Implementation()
{
	bOpened = !bOpened;

	return true;
}

void ADoor::BeginPlay()
{
	Super::BeginPlay();

	if (CurveFloat)
	{
		FOnTimelineFloat TimelineProgress;
		TimelineProgress.BindDynamic(this, &ADoor::OpenDoor);
		Timeline.AddInterpFloat(CurveFloat, TimelineProgress);
	}
}

void ADoor::OpenDoor(float Value)
{
	FRotator Rot = FRotator(0.f, DoorRotateAngle * Value, 0.f);
	Door->SetRelativeRotation(Rot);
}

void ADoor::ToggleDoor()
{
	if (bOpened)
	{
		Timeline.Play();
	}
	else
	{
		Timeline.Reverse();
	}
}


