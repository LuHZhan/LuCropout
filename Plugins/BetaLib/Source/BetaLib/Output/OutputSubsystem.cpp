// Fill out your copyright notice in the Description page of Project Settings.


#include "OutputSubsystem.h"

#include "Kismet/KismetSystemLibrary.h"


void UOutputSubsystem::ContainerPrint(const TArray<FString>& Outputs, const FGameplayTag OutputTag, const FString& SuffixStr)
{
	if (OutputTagContainer.HasTag(OutputTag))
	{
		FString TotalOutputStr;
		for (const auto& Output : Outputs)
		{
			TotalOutputStr.Append(Output);
			TotalOutputStr.Append(SuffixStr);
		}
		UKismetSystemLibrary::PrintString(GetWorld(), TotalOutputStr);
	}
}
