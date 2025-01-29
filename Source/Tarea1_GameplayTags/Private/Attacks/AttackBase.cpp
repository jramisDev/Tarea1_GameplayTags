#include "Tarea1_GameplayTags/Public/Attacks/AttackBase.h"

bool UAttackBase::TryAttack(AActor* AttackInstigator)
{
	UE_LOG(LogTemp, Display, TEXT("Try execute Attack"));

	return true;
}
