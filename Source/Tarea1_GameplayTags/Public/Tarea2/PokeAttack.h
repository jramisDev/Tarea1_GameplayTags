#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Pokemon.h"
#include "PokeAttack.generated.h"

USTRUCT(BlueprintType)
struct FTypeEffectiveness : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag TypeTag; // Tipo de ataque

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FGameplayTag, float> Effectiveness; // Relación con otros tipos
};

struct FPokeAttackAttributes;
class APokemon;
class UPokeAttack;

UCLASS(BlueprintType, Blueprintable)
class TAREA1_GAMEPLAYTAGS_API UPokeAttack : public UObject
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite, Category = Pokemon, meta=(AllowPrivateAccess = true ))
	FGameplayTag AttackType;

	UPROPERTY(BlueprintReadWrite, Category = Pokemon, meta=(AllowPrivateAccess = true ))
	float AttackDamage;
	
	UPROPERTY(BlueprintReadWrite, Category = Pokemon, meta=(AllowPrivateAccess = true ))
	int32 AttackPP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pokemon, meta=(AllowPrivateAccess = true ))
	UDataTable* EffectivenessData;
	
	FTypeEffectiveness* AttackEffectiveness;

	float GetEffectiveness(const FGameplayTag& DefenseType);
	
public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pokemon)
	FGameplayTag AttackIdTag;

	virtual void Init(const FPokeAttackAttributes& PokeAttackAttributes);

	virtual void Attack(APokemon* Instigator, APokemon* Target);
};
