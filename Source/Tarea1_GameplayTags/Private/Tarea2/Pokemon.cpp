#include "Tarea2/Pokemon.h"

#include "Tarea2/PokeAttack.h"

APokemon::APokemon()
{
	PrimaryActorTick.bCanEverTick = true;

	AttackList.SetNum(4);
}

void APokemon::InitializeAttacksData()
{
	if (AttackData && AttackList.Num() > 0)
	{
		TArray<FPokeAttackAttributes*> OutData;
		AttackData->GetAllRows(TEXT(""), OutData);

		if (!OutData.IsEmpty())
		{
			for (FGameplayTag Attack : AttackList)
			{
        
				for (const FPokeAttackAttributes* AttackAttributes : OutData)
				{
					if (AttackAttributes && AttackAttributes->IdTag.MatchesTag(Attack))
					{
						UPokeAttack* AttackInstance = NewObject<UPokeAttack>(GetTransientPackage(), AttackAttributes->AttackClass);
						AttackInstance->Init(*AttackAttributes);
						AttacksSelected.Add(AttackInstance, AttackAttributes->PP_Max);
						break;
					}
				}

				// No consigo que esto me funcione xd asi que
				// // Usamos FindByPredicate para buscar los atributos del ataque
				// FPokeAttackAttributes** Attr = OutData.FindByPredicate([Attack](FPokeAttackAttributes* Row)
				// {
				// 	return Row->IdTag.MatchesTag(Attack);
				// });
				//
				// // Si encontramos una coincidencia, inicializamos el ataque y lo añadimos a la lista seleccionada
				// if (Attr)
				// {
				// 	FPokeAttackAttributes* PokeAttackAttr = *Attr;
				// 	UPokeAttack* AttackInstance = NewObject<UPokeAttack>(GetTransientPackage(), PokeAttackAttr->AttackClass);
				// 	AttackInstance->Init(*PokeAttackAttr);
				// 	AttacksSelected.Add(AttackInstance, PokeAttackAttr->PP_Max);
				// }
			}
		}
	}
}

void APokemon::TryAttack()
{
	if(!PokemonTarget) return;
	
	for (const auto ExecuteAttack : AttacksSelected)
	{
		ExecuteAttack.Key->Attack(this, PokemonTarget);
	}
}

void APokemon::BeginPlay()
{
	Super::BeginPlay();
	
	//checkf(AttackList.Num() > NumAttacks, TEXT("%s - NO PODEMOS TENER MÁS DE CUATRO ATAQUES"), *FString(__FUNCTION__));
	InitializeAttacksData();
	TryAttack();
}