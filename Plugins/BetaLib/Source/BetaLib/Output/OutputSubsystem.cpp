// Fill out your copyright notice in the Description page of Project Settings.


#include "OutputSubsystem.h"

#include "Kismet/KismetSystemLibrary.h"


void UOutputSubsystem::ContainerPrint(const TArray<FString>& Outputs, const FGameplayTag OutputTag, const FString& SuffixStr, bool bForceOutput)
{
	if (bForceOutput)
	{
		AddOutputTag(OutputTag);
	}
	if (OutputTagContainer.HasTag(OutputTag))
	{
		FString TotalOutputStr = OutputTag.ToString() + SuffixStr;
		for (const auto& Output : Outputs)
		{
			TotalOutputStr.Append(Output);
			TotalOutputStr.Append(SuffixStr);
		}
		UKismetSystemLibrary::PrintString(GetWorld(), TotalOutputStr);
	}
}
