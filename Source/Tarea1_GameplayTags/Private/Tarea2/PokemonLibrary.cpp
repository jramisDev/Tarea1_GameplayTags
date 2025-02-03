#include "Tarea2/PokemonLibrary.h"

#include "Tarea2/PokeAttack.h"
#include "Tarea2/Pokemon.h"

UPokeAttack UPokemonLibrary::GetClassAttack(FGameplayTag AttackClass, const UDataTable& AttackDataTable)
{
	if(!AttackDataTable) return nullptr;
	TArray<FPokeAttackAttributes*> OutData;
	AttackDataTable->GetAllRows(TEXT(""), OutData);

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
