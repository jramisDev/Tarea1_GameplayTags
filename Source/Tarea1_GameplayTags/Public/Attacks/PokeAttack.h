#pragma once

#include "CoreMinimal.h"
#include "AttackBase.h"
#include "GameplayTagContainer.h"
#include "PokeAttack.generated.h"

USTRUCT()
struct FPokeAttackAttributes : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)	FName ID;
	UPROPERTY(EditAnywhere)	FText Name;
	UPROPERTY(EditAnywhere)	FText Description;
	UPROPERTY(EditAnywhere)	FGameplayTag AttackTypeTag;
	UPROPERTY(EditAnywhere)	float Damage;
	UPROPERTY(EditAnywhere)	int32 PP_Max;
};

UCLASS(BlueprintType, Blueprintable)
class TAREA1_GAMEPLAYTAGS_API UPokeAttack : public UAttackBase
{
	GENERATED_BODY()
	
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = true ))
	FPokeAttackAttributes* PokeAttackAttributes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = true ))
	UDataTable* AttackData;

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pokemon)
	FName AttackId;

	virtual bool TryAttack(AActor* AttackInstigator) override;
};
