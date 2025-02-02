#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "PokeAttack.generated.h"

class UPokeAttack;

USTRUCT()
struct FPokeAttackAttributes : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)	FGameplayTag IdTag;
	UPROPERTY(EditAnywhere)	FText Name;
	UPROPERTY(EditAnywhere)	FText Description;
	UPROPERTY(EditAnywhere)	TArray<FGameplayTag> AttackTypeTag;
	UPROPERTY(EditAnywhere)	float Damage;
	UPROPERTY(EditAnywhere)	int32 PP_Max;
};

USTRUCT(BlueprintType)
struct FTypeEffectiveness : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag Type; // Tipo de ataque

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FGameplayTag, float> Effectiveness; // Relación con otros tipos
};

UENUM(BlueprintType)
enum class EFDamageActor : uint8 {
	None = 0		UMETA(DisplayName = "NONE"),
	Increase = 1	UMETA(DisplayName = "INCREASE"),
	Decrease = 2    UMETA(DisplayName = "DECREASE"),
	NotEffect = 3	UMETA(DisplayName = "NOT EFFECT"),
};

UCLASS(BlueprintType, Blueprintable)
class TAREA1_GAMEPLAYTAGS_API UPokeAttack : public UObject
{
	GENERATED_BODY()
	
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = true ))
	FPokeAttackAttributes* PokeAttackAttributes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pokemon, meta=(AllowPrivateAccess = true ))
	UDataTable* AttackData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pokemon, meta=(AllowPrivateAccess = true ))
	UDataTable* EffectivenessData;

	bool InitializeAttackData();
	float GetEffectiveness(TArray<FGameplayTag>& AttackType, TArray<FGameplayTag>& DefenseType) const;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Pokemon, meta=(AllowPrivateAccess = true ))
	int32 PPActual;
	
public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pokemon)
	FGameplayTag AttackIdTag;

	virtual void Attack(const TSubclassOf<UPokeAttack>& PokeAttack, APokemon& Target);
};
