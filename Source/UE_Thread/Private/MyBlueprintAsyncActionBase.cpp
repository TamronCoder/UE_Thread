// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintAsyncActionBase.h"
#include "MyActor.h"

UMyBlueprintAsyncActionBase* UMyBlueprintAsyncActionBase::MyBlueprintAsyncNode(UObject* WorldContextObject, AActor* TestActor)
{
	// �����첽�ڵ�
	UMyBlueprintAsyncActionBase* Node = NewObject<UMyBlueprintAsyncActionBase>();

	AMyActor* MyTestActor = Cast<AMyActor>(TestActor);
	if (!IsValid(MyTestActor))
	{
		return Node;
	}
	// ���ڶ�ʱ���õ�Lambda����
	auto Check = [Node, WorldContextObject, MyTestActor]() {
		UE_LOG(LogTemp, Log, TEXT("TargetCounter first value��%d"), MyTestActor->ActorCounter);

		if (MyTestActor->ActorCounter < 0)
		{
			UE_LOG(LogTemp, Log, TEXT("ִ�гɹ�·��"));
			Node->OnSuccess.Broadcast(1);
			WorldContextObject->GetWorld()->GetTimerManager().ClearTimer(Node->TimerHandle);
		}
		else if (MyTestActor->ActorCounter >= 0 && MyTestActor->ActorCounter < 10)
		{
			UE_LOG(LogTemp, Log, TEXT("ִ��ʧ��·��"));
			Node->OnFail.Broadcast(2);
			WorldContextObject->GetWorld()->GetTimerManager().ClearTimer(Node->TimerHandle);
		}
		else if (MyTestActor->ActorCounter >= 10 && MyTestActor->ActorCounter < 20)
		{
			UE_LOG(LogTemp, Log, TEXT("ִ������·��"));
			Node->OnFail.Broadcast(3);
			WorldContextObject->GetWorld()->GetTimerManager().ClearTimer(Node->TimerHandle);
		}
	};
	// ��ʱ����Lambda����
	WorldContextObject->GetWorld()->GetTimerManager().SetTimer(Node->TimerHandle, FTimerDelegate::CreateLambda(Check), 0.1f, true);
	return Node;
}