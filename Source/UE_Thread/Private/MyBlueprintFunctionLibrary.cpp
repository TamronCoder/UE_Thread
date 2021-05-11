// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"
#include "MyTaskClass.h"

void UMyBlueprintFunctionLibrary::MultiThreadDo(int32 MaxPrime)
{
	CreateAutoDeleteAsyncTask(MaxPrime);
}

void UMyBlueprintFunctionLibrary::SingleThreadDo(int32 MaxPrime)
{
	Do(MaxPrime);
}

void UMyBlueprintFunctionLibrary::Do(int32 MaxPrime)
{
	for (int32 i = 1; i <= MaxPrime; i++)
	{
		bool isPrime = true;
		for (int32 j = 2; j <= i / 2; j++)
		{
			if (FMath::Fmod(i, j) == 0)
			{
				isPrime = false;
				break;
			}
		}
		if (isPrime)
			GLog->Log("Prime number #" + FString::FromInt(i) + ": " + FString::FromInt(i));
	}
}

void UMyBlueprintFunctionLibrary::CreateAutoDeleteAsyncTask(int32 MaxPrime)
{
	// FAutoDeleteAsyncTask��
	auto task = new FAutoDeleteAsyncTask<MyTaskClass>(MaxPrime);
	if (task)
	{
		// �Զ��½�һ���̣߳����ҵ��ø����dowork����
		task->StartBackgroundTask();

		// �ڵ�ǰ�߳�ִ��dowork
		// task->StartSynchronousTask();
	}

	// FAsyncTask��
	/*auto task = new FAsyncTask<MyTaskClass>(MaxPrime);
	if (task)
	{
		// �Զ��½�һ���̣߳����ҵ��ø����dowork����
		task->StartBackgroundTask();

		// �ڵ�ǰ�߳�ִ��dowork
		// task->StartSynchronousTask();
	}
	if (task->IsDone())
	{
	}
	task->EnsureCompletion();
	delete task;*/
}
