// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "MyBlueprintAsyncActionBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMyAsyncNodeResult, int32, Result);
/**
 * 
 */
UCLASS()
class UE_THREAD_API UMyBlueprintAsyncActionBase : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:
	// 蓝图的多节点是通过动态多播来实现
	UPROPERTY(BlueprintAssignable)
		FMyAsyncNodeResult OnSuccess;
	UPROPERTY(BlueprintAssignable)
		FMyAsyncNodeResult OnFail;
	UPROPERTY(BlueprintAssignable)
		FMyAsyncNodeResult OnOther;

	// 定时器
	FTimerHandle TimerHandle;

	// 蓝图异步节点
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
		static UMyBlueprintAsyncActionBase* MyBlueprintAsyncNode(UObject* WorldContextObject, AActor* TestActor);

};
