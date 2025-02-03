#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/Character.h"
#include "Pokemon.generated.h"

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

class UPokeAttack;

UCLASS()
class TAREA1_GAMEPLAYTAGS_API APokemon : public ACharacter
{
	GENERATED_BODY()
	
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = Pokemon, meta=(AllowPrivateAccess = true ))
	int32 NumAttacks = 4;
	
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = Pokemon, meta=(AllowPrivateAccess = true ))
	int32 NumAttributes = 2;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pokemon, meta=(AllowPrivateAccess = true ))
	UDataTable* AttackData;
	
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = Pokemon, meta=(AllowPrivateAccess = true ))
	TArray<FGameplayTag> AttackList;

	bool InitializeAttackData();
	

public:
	APokemon();

	UPROPERTY(VisibleAnywhere, EditInstanceOnly, BlueprintReadWrite, Category = Pokemon)
	APokemon* PokemonTarget;
	
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = Pokemon)
	FGameplayTag AttributeType;

	UFUNCTION(BlueprintCallable)
	virtual void TryAttack();

protected:
	virtual void BeginPlay() override;
};
