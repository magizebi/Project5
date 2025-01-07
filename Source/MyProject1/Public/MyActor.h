// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class MYPROJECT1_API AMyActor : public AActor
{
	GENERATED_BODY()
	FVector2D now;
	int event_count = 0;
	double total_distance = 0;
private:
	bool randomResult(int percent);
public:	
	// Sets default values for this actor's properties
	AMyActor();
	void move();
	void step();
	void distance(const FVector2D& first, const FVector2D& last);
	void createEvent();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
