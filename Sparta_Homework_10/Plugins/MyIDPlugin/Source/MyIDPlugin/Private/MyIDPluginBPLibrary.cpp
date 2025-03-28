// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyIDPluginBPLibrary.h"
#include "MyIDPlugin.h"

FString UMyIDPluginBPLibrary::UserName = TEXT("Unknown");

UMyIDPluginBPLibrary::UMyIDPluginBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

void UMyIDPluginBPLibrary::SetUserName(const FString& NewName)
{
	UserName = NewName;
	UE_LOG(LogTemp, Log, TEXT("UserName set to: %s"), *UserName);
}

FString UMyIDPluginBPLibrary::GetUserName()
{
	return UserName;
}