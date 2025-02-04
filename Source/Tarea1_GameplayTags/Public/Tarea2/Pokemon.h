#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/Character.h"
#include "Pokemon.generated.h"

class UPokeAttack;

USTRUCT()
struct FPokeAttackAttributes : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)	FGameplayTag IdTag;
	UPROPERTY(EditAnywhere)	FText Name;
	UPROPERTY(EditAnywhere)	FText Description;
	UPROPERTY(EditAnywhere)	FGameplayTag TypeTag;
	UPROPERTY(EditAnywhere)	TSubclassOf<UPokeAttack> AttackClass;
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
	
	void InitializeAttacksData();

public:
	APokemon();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Pokemon, meta=(AllowPrivateAccess = true ))
	TMap<UPokeAttack*, int32> AttacksSelected;	

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = Pokemon)
	APokemon* PokemonTarget;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pokemon)
	TArray<FGameplayTag> AttackList;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pokemon)
	FGameplayTag AttributeType;

	UFUNCTION(BlueprintCallable)
	virtual void TryAttack();

protected:
	virtual void BeginPlay() override;
};
