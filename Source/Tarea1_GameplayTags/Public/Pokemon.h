#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/Character.h"
#include "Pokemon.generated.h"

class UPokeAttack;

UCLASS()
class TAREA1_GAMEPLAYTAGS_API APokemon : public ACharacter
{
	GENERATED_BODY()
	
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = Pokemon, meta=(AllowPrivateAccess = true ))
	int32 NumAttacks = 4;
	
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = Pokemon, meta=(AllowPrivateAccess = true ))
	int32 NumAttributes = 2;	
	
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = Pokemon, meta=(AllowPrivateAccess = true ))
	TArray<FGameplayTag> AttackList;

public:
	APokemon();

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = Pokemon)
	TArray<FGameplayTag> AttributeType;

	UFUNCTION(BlueprintCallable)
	virtual void TryAttack();

protected:
	virtual void BeginPlay() override;
};
