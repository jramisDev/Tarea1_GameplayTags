#include "Pokemon.h"

APokemon::APokemon()
{
	PrimaryActorTick.bCanEverTick = true;

	AttackList.SetNum(4);
	AttributeType.SetNum(2);
}

void APokemon::TryAttack()
{
	for ( auto Attack : AttackList)
	{
		
	}
	
}

void APokemon::BeginPlay()
{
	Super::BeginPlay();
	
	checkf(AttributeType.Num() > NumAttributes, TEXT("%s - NO PODEMOS SER MÁS DE DOS TIPOS"), *FString(__FUNCTION__));	
	checkf(AttackList.Num() > NumAttacks, TEXT("%s - NO PODEMOS TENER MÁS DE CUATRO ATAQUES"), *FString(__FUNCTION__));	
}