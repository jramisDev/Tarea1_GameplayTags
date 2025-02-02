#include "Tarea2/PokeAttack.h"

#include "Tarea2/Pokemon.h"
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

float UPokeAttack::GetEffectiveness(TArray<FGameplayTag>& AttackType, TArray<FGameplayTag>& DefenseType) const
{
	if (!EffectivenessData) return 1.0f; // Valor neutro si no hay tabla

	// Lambda para buscar la efectividad entre un atacante y un defensor
	auto FindEffectiveness = [&](const FGameplayTag& Attack, const FGameplayTag& Defense) -> float
	{
		FTypeEffectiveness* Row = EffectivenessData->FindRow<FTypeEffectiveness>(Attack.GetTagName(), TEXT(""));
		return (Row && Row->Effectiveness.Contains(Defense)) ? Row->Effectiveness[Defense] : 1.0f;
	};

	float Effectiveness = 1.0f; // Empezamos con valor neutro

	// Recorrer todos los tipos de ataque y defensa
	for (const FGameplayTag& AttackType : AttackType)
	{
		for (const FGameplayTag& DefenseType : DefenseType)
		{
			Effectiveness *= FindEffectiveness(AttackType, DefenseType);
		}
	}

	return Effectiveness;
}

void UPokeAttack::Attack(const TSubclassOf<UPokeAttack>& PokeAttack, APokemon& Target)
{
	if(PPActual == 0) return;

	ensureMsgf(PokeAttack, TEXT("%s - AttackInstigator not defined"), ANSI_TO_TCHAR(__FUNCTION__));
	ensureMsgf(&Target, TEXT("%s - Target not defined"), ANSI_TO_TCHAR(__FUNCTION__));
	ensureMsgf(InitializeAttackData(), TEXT("%s - Attack not defined"), ANSI_TO_TCHAR(__FUNCTION__));

	const float Effectiveness = GetEffectiveness(PokeAttack.GetDefaultObject()->PokeAttackAttributes->AttackTypeTag, Target.AttributeType);
	
	const FDamageEvent DamageEvent;
	Target.TakeDamage(PokeAttack.GetDefaultObject()->PokeAttackAttributes->Damage * Effectiveness, DamageEvent, nullptr, nullptr);
	PPActual--;
	
}
