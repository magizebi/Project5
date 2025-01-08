// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include <random>

bool AMyActor::randomResult(int percent)
{
	std::random_device seed;
	std::mt19937 generator(seed());
	std::uniform_int_distribution<> dist(1, 100);

	return dist(generator) <= percent;
}

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	now.Set(0, 0);
}

void AMyActor::move()
{
	for (int i = 1; i <= 10; i++) {
		UE_LOG(LogTemp, Warning, TEXT("Count : %d"), i);
		FVector2D prev = now;
		step();
		distance(prev, now);
		createEvent();
	}
	UE_LOG(LogTemp, Warning, TEXT("Total Distance : %f"), (float)total_distance);
	UE_LOG(LogTemp, Warning, TEXT("Total Event Count : %d"), event_count);
}

void AMyActor::step()
{
	for(int i = 0; i < 2; i++) if (randomResult(50)) now.XY[i]++;
	UE_LOG(LogTemp, Display, TEXT("Current Position : [%d / %d]"), (int)now.X, (int)now.Y);
}

void AMyActor::distance(const FVector2D& first, const FVector2D& last)
{
	double dist = FVector2D::Distance(first, last);
	UE_LOG(LogTemp, Display, TEXT("Distance : %f"), (float)dist);
	total_distance += dist;
}

void AMyActor::createEvent()
{
	if (randomResult(50)) {
		event_count++;
		UE_LOG(LogTemp, Error, TEXT("new Event!!!"));
	}
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Error, TEXT("owo"));
	move();
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

