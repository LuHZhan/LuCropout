// Copyright Epic Games, Inc. All Rights Reserved.

#include "BetaLibBPLibrary.h"
#include "BetaLib.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

UBetaLibBPLibrary::UBetaLibBPLibrary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

float UBetaLibBPLibrary::BetaLibSampleFunction(float Param)
{
	return -1;
}

FVector UBetaLibBPLibrary::TraceMove(const FVector Intersection, const FVector PreMouseLocation, USpringArmComponent* Comp, UCameraComponent* Camera)
{
	// 反向的俯仰Pitch高度
	const FVector ReverseLength = Comp->GetForwardVector() * (Comp->TargetArmLength - Comp->SocketOffset.X) * -1.0;
	// 结合SocketOffset的Z轴得到整体的WorldLocation(x轴的值为相反数)
	const FVector TotalVector = ReverseLength + (Comp->GetUpVector() * Comp->SocketOffset.Z) + Comp->GetComponentLocation();
	// 表明CameraArm相对于Camera的偏移，会趋近于零
	const FVector RelativeOffset = TotalVector - Camera->GetComponentLocation();
	// 最后镜头会移动的向量
	return PreMouseLocation - Intersection - RelativeOffset;
}
