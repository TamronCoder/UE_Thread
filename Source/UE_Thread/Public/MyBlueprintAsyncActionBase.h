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
	// ��ͼ�Ķ�ڵ���ͨ����̬�ಥ��ʵ��
	UPROPERTY(BlueprintAssignable)
		FMyAsyncNodeResult OnSuccess;
	UPROPERTY(BlueprintAssignable)
		FMyAsyncNodeResult OnFail;
	UPROPERTY(BlueprintAssignable)
		FMyAsyncNodeResult OnOther;

	// ��ʱ��
	FTimerHandle TimerHandle;

	// ��ͼ�첽�ڵ�
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
		static UMyBlueprintAsyncActionBase* MyBlueprintAsyncNode(UObject* WorldContextObject, AActor* TestActor);

};
