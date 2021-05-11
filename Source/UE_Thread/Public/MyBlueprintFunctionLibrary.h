// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyBlueprintFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class UE_THREAD_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "Thread Test")
		static void MultiThreadDo(int32 MaxPrime);
	UFUNCTION(BlueprintCallable, Category = "Thread Test")
		static void SingleThreadDo(int32 MaxPrime);
	static void Do(int32 MaxPrime);

	static void CreateAutoDeleteAsyncTask(int32 MaxPrime);
};
