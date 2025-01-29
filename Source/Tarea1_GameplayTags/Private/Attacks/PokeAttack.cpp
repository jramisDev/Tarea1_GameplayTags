#include "Attacks/PokeAttack.h"

bool UPokeAttack::TryAttack(AActor* AttackInstigator)
{
	if(AttackData)
	{
		TArray<FPokeAttackAttributes*> OutData;
		AttackData->GetAllRows(TEXT(""), OutData);

		if(!OutData.IsEmpty())
		{
			FPokeAttackAttributes** Attr = OutData.FindByPredicate([this](FPokeAttackAttributes* Row)
			{
				return Row->ID.Compare(AttackId);
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
