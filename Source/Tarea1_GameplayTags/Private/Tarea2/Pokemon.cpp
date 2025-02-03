#include "Tarea2/Pokemon.h"

APokemon::APokemon()
{
	PrimaryActorTick.bCanEverTick = true;

	AttackList.SetNum(4);
	//AttributeType.SetNum(2);
}

bool APokemon::InitializeAttackData()
{
	if(AttackData && AttackList.Num() > 0)
	{
		TArray<FPokeAttackAttributes*> OutData;
		AttackData->GetAllRows(TEXT(""), OutData);

		if(!OutData.IsEmpty())
		{
			FPokeAttackAttributes** Attr = OutData.FindByPredicate([this](FPokeAttackAttributes* Row)
			{
				return Row->IdTag.MatchesTag(AttackIdTag);
			});
			
			if(Attr)
			{
				PokeAttackAttributes = *Attr;
				return true;
			}
		}
	}
	return false;
}

void APokemon::TryAttack()
{
	if(!PokemonTarget) return;
	
	for ( auto Attack : AttackList)
	{
		
	}
	
}

void APokemon::BeginPlay()
{
	Super::BeginPlay();
	
	//checkf(AttributeType.Num() > NumAttributes, TEXT("%s - NO PODEMOS SER MÁS DE DOS TIPOS"), *FString(__FUNCTION__));	
	checkf(AttackList.Num() > NumAttacks, TEXT("%s - NO PODEMOS TENER MÁS DE CUATRO ATAQUES"), *FString(__FUNCTION__));	
}