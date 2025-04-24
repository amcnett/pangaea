// Fill out your copyright notice in the Description page of Project Settings.


#include "PangaeaGameInstance.h"
#include "Kismet/GameplayStatics.h"

void UPangaeaGameInstance::StartListenServer()
{
	auto world = GEngine->GetCurrentPlayWorld();
	UGameplayStatics::OpenLevel(world, FName(TEXT("/Game/TopDown/Maps/TopDownMap")), true, "?listen");
}

void UPangaeaGameInstance::JoinAsClient(FString IPAddress)
{
	auto world = GEngine->GetCurrentPlayWorld();
	UGameplayStatics::OpenLevel(world, *IPAddress, true, "?join");
}


void UPangaeaGameInstance::LeaveGame()
{
	auto world = GEngine->GetCurrentPlayWorld();
	UGameplayStatics::OpenLevel(world, FName(TEXT("/Game/TopDown/Maps/LobbyMap")));
}
