#include "Attacks/PokeAttack.h"

#include "Engine/DamageEvents.h"

bool UPokeAttack::InitializeAttackData()
{
	if(AttackData)
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

float UPokeAttack::ModifyDamageAttack(float Damage)
{
	return 0.0f;
}

void UPokeAttack::Attack(AActor* AttackInstigator, AActor* Target)
{
	Super::Attack(AttackInstigator, Target);

	if(PPActual == 0) return;

	ensureMsgf(AttackInstigator, TEXT("%s - AttackInstigator not defined"), ANSI_TO_TCHAR(__FUNCTION__));
	ensureMsgf(Target, TEXT("%s - Target not defined"), ANSI_TO_TCHAR(__FUNCTION__));
	ensureMsgf(InitializeAttackData(), TEXT("%s - Attack not defined"), ANSI_TO_TCHAR(__FUNCTION__));
	
	const FDamageEvent DamageEvent;
	Target->TakeDamage(ModifyDamageAttack(PokeAttackAttributes->Damage), DamageEvent, AttackInstigator->GetInstigatorController(), AttackInstigator);
	PPActual--;
	
}
