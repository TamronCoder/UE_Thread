// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Core/Public/Async/AsyncWork.h"

/**
 * 
 */
class UE_THREAD_API MyTaskClass : public FNonAbandonableTask
{
public:
	MyTaskClass();
	~MyTaskClass();
	friend class FAutoDeleteAsyncTask<MyTaskClass>;
	FORCEINLINE TStatId GetStatId() const
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(MyTaskClass, STATGROUP_ThreadPoolAsyncTasks);
	}

	void DoWork();
	int32 MaxPrime;
	MyTaskClass(int32 MaxPrime);//补充一个构造函数用于赋值
};
