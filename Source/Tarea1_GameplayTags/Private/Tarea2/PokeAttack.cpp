#include "Tarea2/PokeAttack.h"

#include "Tarea2/Pokemon.h"
#include "Engine/DamageEvents.h"

float UPokeAttack::GetEffectiveness(const FGameplayTag& InDefenseType)
{
	const float Effectiveness = 1.0f; // Empezamos con valor neutro
	
	if (!EffectivenessData) return Effectiveness; // Valor neutro si no hay tabla

	TArray<FTypeEffectiveness*> OutData;
	EffectivenessData->GetAllRows(TEXT(""), OutData);

	if(!OutData.IsEmpty())
	{
		FTypeEffectiveness** Attr = OutData.FindByPredicate([this](FTypeEffectiveness* Row)
		{
			return Row->TypeTag.MatchesTag(AttackType);
		});
			
		if(Attr) AttackEffectiveness = *Attr;
	}

	for(auto MultiplayEffectiveness : AttackEffectiveness->Effectiveness)
	{
		if(MultiplayEffectiveness.Key.MatchesTag(InDefenseType))
		{
			return MultiplayEffectiveness.Value;
		}
	}
	
	return Effectiveness;
}

void UPokeAttack::Init(const FPokeAttackAttributes& PokeAttackAttributes)
{
	AttackType = PokeAttackAttributes.TypeTag;
	AttackDamage = PokeAttackAttributes.Damage;
	AttackPP = PokeAttackAttributes.PP_Max;
}

void UPokeAttack::Attack(APokemon* Instigator, APokemon* Target)
{
	ensureMsgf(&Target, TEXT("%s - Target not defined"), ANSI_TO_TCHAR(__FUNCTION__));

	if(AttackPP == 0) return;

	const float Effectiveness = GetEffectiveness(Target->AttributeType);
	
	UE_LOG(LogTemp, Display, TEXT("%s realiza el Ataque %s (daño %f) tipo %s a %s tipo %s con daño %f (multiplicador %f) y %d PP"),
		*Instigator->GetName(),
		*GetName(),
		AttackDamage,
		*AttackType.ToString(),
		*Target->GetName(),
		*Target->AttributeType.ToString(),
		AttackDamage * Effectiveness,
		Effectiveness,
		AttackPP);
	
	const FDamageEvent DamageEvent;
	Target->TakeDamage(AttackDamage * Effectiveness, DamageEvent, Instigator->GetController(), Instigator);
	AttackPP--;
}
