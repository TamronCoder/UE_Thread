// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintAsyncActionBase.h"
#include "MyActor.h"

UMyBlueprintAsyncActionBase* UMyBlueprintAsyncActionBase::MyBlueprintAsyncNode(UObject* WorldContextObject, AActor* TestActor)
{
	// 创建异步节点
	UMyBlueprintAsyncActionBase* Node = NewObject<UMyBlueprintAsyncActionBase>();

	AMyActor* MyTestActor = Cast<AMyActor>(TestActor);
	if (!IsValid(MyTestActor))
	{
		return Node;
	}
	// 用于定时调用的Lambda函数
	auto Check = [Node, WorldContextObject, MyTestActor]() {
		UE_LOG(LogTemp, Log, TEXT("TargetCounter first value：%d"), MyTestActor->ActorCounter);

		if (MyTestActor->ActorCounter < 0)
		{
			UE_LOG(LogTemp, Log, TEXT("执行成功路径"));
			Node->OnSuccess.Broadcast(1);
			WorldContextObject->GetWorld()->GetTimerManager().ClearTimer(Node->TimerHandle);
		}
		else if (MyTestActor->ActorCounter >= 0 && MyTestActor->ActorCounter < 10)
		{
			UE_LOG(LogTemp, Log, TEXT("执行失败路径"));
			Node->OnFail.Broadcast(2);
			WorldContextObject->GetWorld()->GetTimerManager().ClearTimer(Node->TimerHandle);
		}
		else if (MyTestActor->ActorCounter >= 10 && MyTestActor->ActorCounter < 20)
		{
			UE_LOG(LogTemp, Log, TEXT("执行其他路径"));
			Node->OnFail.Broadcast(3);
			WorldContextObject->GetWorld()->GetTimerManager().ClearTimer(Node->TimerHandle);
		}
	};
	// 定时调用Lambda函数
	WorldContextObject->GetWorld()->GetTimerManager().SetTimer(Node->TimerHandle, FTimerDelegate::CreateLambda(Check), 0.1f, true);
	return Node;
}