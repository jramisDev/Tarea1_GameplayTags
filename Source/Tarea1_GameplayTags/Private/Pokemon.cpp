#include "Pokemon.h"

APokemon::APokemon()
{
	PrimaryActorTick.bCanEverTick = true;

	AttackList.SetNum(4);
}

void APokemon::BeginPlay()
{
	Super::BeginPlay();
	
	checkf(AttributeType.Num() > 2, TEXT("%s - NO PODEMOS SER MÁS DE DOS TIPOS"), *FString(__FUNCTION__));
}

