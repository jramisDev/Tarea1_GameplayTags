#pragma once

#include "CoreMinimal.h"
#include "AttackBase.h"
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
	UPROPERTY(EditAnywhere)	FGameplayTag AttackTypeTag;
	UPROPERTY(EditAnywhere)	float Damage;
	UPROPERTY(EditAnywhere)	int32 PP_Max;
};

UENUM(BlueprintType)
enum class EFDamageActor : uint8 {
	None = 0		UMETA(DisplayName = "NONE"),
	Increase = 1	UMETA(DisplayName = "INCREASE"),
	Decrease = 2    UMETA(DisplayName = "DECREASE"),
	NotEffect = 3	UMETA(DisplayName = "NOT EFFECT"),
};

UCLASS(BlueprintType, Blueprintable)
class TAREA1_GAMEPLAYTAGS_API UPokeAttack : public UAttackBase
{
	GENERATED_BODY()
	
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = true ))
	FPokeAttackAttributes* PokeAttackAttributes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pokemon, meta=(AllowPrivateAccess = true ))
	UDataTable* AttackData;

	bool InitializeAttackData();
	float ModifyDamageAttack(float Damage);
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Pokemon, meta=(AllowPrivateAccess = true ))
	int32 PPActual;
	
public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pokemon)
	FGameplayTag AttackIdTag;

	virtual void Attack(AActor* AttackInstigator, AActor* Target) override;
};
