#include "Tarea2/PokeAttack.h"

#include "Tarea2/Pokemon.h"
#include "Engine/DamageEvents.h"

float UPokeAttack::GetEffectiveness(const FGameplayTag& InAttackType, const FGameplayTag& InDefenseType) const
{
	if (!EffectivenessData) return 1.0f; // Valor neutro si no hay tabla

	return 1.0f;

	// // Lambda para buscar la efectividad entre un atacante y un defensor
	// auto FindEffectiveness = [&](const FGameplayTag& Attack, const FGameplayTag& Defense) -> float
	// {
	// 	FTypeEffectiveness* Row = EffectivenessData->FindRow<FTypeEffectiveness>(Attack.GetTagName(), TEXT(""));
	// 	return (Row && Row->Effectiveness.Contains(Defense)) ? Row->Effectiveness[Defense] : 1.0f;
	// };
	//
	// float Effectiveness = 1.0f; // Empezamos con valor neutro
	//
	// // Recorrer todos los tipos de ataque y defensa
	// for (const FGameplayTag& AttackType : AttackType)
	// {
	// 	for (const FGameplayTag& DefenseType : DefenseType)
	// 	{
	// 		Effectiveness *= FindEffectiveness(AttackType, DefenseType);
	// 	}
	// }
	//
	// return Effectiveness;
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

	const float Effectiveness = GetEffectiveness(AttackType,Target->AttributeType);
	
	UE_LOG(LogTemp, Display, TEXT("%s realiza el Ataque %s a %s con daño %f y %d PP"), *Instigator->GetName(), *GetName(), *Target->GetName(), AttackDamage * Effectiveness, AttackPP);
	
	const FDamageEvent DamageEvent;
	Target->TakeDamage(AttackDamage * Effectiveness, DamageEvent, Instigator->GetController(), Instigator);
}
