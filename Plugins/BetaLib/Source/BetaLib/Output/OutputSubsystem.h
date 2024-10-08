// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "OutputSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class BETALIB_API UOutputSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="CPrint")
	void ContainerPrint(const TArray<FString>& Outputs, const FGameplayTag OutputTag, const FString& SuffixStr = TEXT("   "), bool bForceOutput = true);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	TArray<FString> GetAllTag() const
	{
		TArray<FString> Result;
		for (auto Tag : TagContainer.GetGameplayTagArray())
		{
			Result.Add(Tag.ToString());
		}
		return Result;
	}

	UFUNCTION(BlueprintCallable)
	void SetOutputTag(const FGameplayTagContainer& Tags)
	{
		OutputTagContainer = Tags;
	}

	UFUNCTION(BlueprintCallable)
	void AddOutputTag(const FGameplayTag& Tag)
	{
		OutputTagContainer.AddTag(Tag);
	}

private:
	UPROPERTY()
	FGameplayTagContainer TagContainer;

	UPROPERTY()
	FGameplayTagContainer OutputTagContainer;
};