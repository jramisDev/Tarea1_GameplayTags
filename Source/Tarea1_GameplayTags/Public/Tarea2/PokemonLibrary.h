#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PokemonLibrary.generated.h"


class UPokeAttack;

UCLASS()
class TAREA1_GAMEPLAYTAGS_API UPokemonLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Pokemon | Utils")
	static UPokeAttack GetClassAttack(FGameplayTag AttackClass, const UDataTable& AttackDataTable);
};
