#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AttackBase.generated.h"

class APokemon;

UCLASS()
class TAREA1_GAMEPLAYTAGS_API UAttackBase : public UObject
{
	GENERATED_BODY()

public:
	virtual void Attack(AActor* AttackInstigator, AActor* Target);
};
