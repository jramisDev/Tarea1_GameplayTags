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
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pokemon, meta=(AllowPrivateAccess = true ))
	TArray<TSubclassOf<UPokeAttack>> AttackList;

public:
	APokemon();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Pokemon)
	FGameplayTagContainer AttributeType;

protected:
	virtual void BeginPlay() override;

};
