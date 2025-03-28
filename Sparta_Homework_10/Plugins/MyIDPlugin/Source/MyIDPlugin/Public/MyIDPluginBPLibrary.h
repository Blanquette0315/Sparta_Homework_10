// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyIDPluginBPLibrary.generated.h"

/* 
*	Function library class.
*	Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.
*
*	When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.
*	BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.
*	BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.
*	DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.
*				Its lets you name the node using characters not allowed in C++ function names.
*	CompactNodeTitle - the word(s) that appear on the node.
*	Keywords -	the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. 
*				Good example is "Print String" node which you can find also by using keyword "log".
*	Category -	the category your node will be under in the Blueprint drop-down menu.
*
*	For more info on custom blueprint nodes visit documentation:
*	https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation
*/
UCLASS()
class UMyIDPluginBPLibrary : public UBlueprintFunctionLibrary
{
	// 라이브러리 전역에서 공유할 사용자 이름을 저장하는 정적 변수다.
	GENERATED_UCLASS_BODY()
	static FString UserName;

	// 정적 함수들은 어디서든 동일한 정적 변수를 공유한다.
	// 따라서 멀티플레이어나 다른 오브젝트 별로 다른 이름을 관리해야 한다면,
	// 이 방법 대신 인스턴스 기반의 컴포넌트나 Singleton 패턴 등 다른 구조를 고려하는게 좋아보인다.
	UFUNCTION(BlueprintCallable)
	static void SetUserName(const FString& NewName);
	
	UFUNCTION(BlueprintCallable, BlueprintPure)
	static FString GetUserName();
};
