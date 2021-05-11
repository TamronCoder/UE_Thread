// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTaskClass.h"
#include "MyBlueprintFunctionLibrary.h"

MyTaskClass::MyTaskClass()
{
}

MyTaskClass::~MyTaskClass()
{
}

void MyTaskClass::DoWork()
{
	UMyBlueprintFunctionLibrary::Do(MaxPrime);
}

MyTaskClass::MyTaskClass(int32 MaxPrime)
{
	this->MaxPrime = MaxPrime;
}
