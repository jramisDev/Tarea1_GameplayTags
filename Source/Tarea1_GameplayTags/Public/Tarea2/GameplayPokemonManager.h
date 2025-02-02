#pragma once
#include "GameplayTagContainer.h"
#include "GameplayTagsManager.h"

class FGameplayPokemonManager : public FNoncopyable
{

	static FGameplayPokemonManager* Singleton;
	
public:
	
	//Lazy load
	static FGameplayPokemonManager& Get()
	{
		if(!Singleton)
			Singleton = new FGameplayPokemonManager();

		return *Singleton;
	}

	void InitGameplayTags()
	{
		//Tipos
		Tag_Pokemon_Type_Agua				=	UGameplayTagsManager::Get().AddNativeGameplayTag(TEXT("Gameplay.Pokemon.Type.Agua"));
		Tag_Pokemon_Type_Fuego				=	UGameplayTagsManager::Get().AddNativeGameplayTag(TEXT("Gameplay.Pokemon.Type.Fuego"));
		Tag_Pokemon_Type_Electrico			=	UGameplayTagsManager::Get().AddNativeGameplayTag(TEXT("Gameplay.Pokemon.Type.Electrico"));
		Tag_Pokemon_Type_Tierra				=	UGameplayTagsManager::Get().AddNativeGameplayTag(TEXT("Gameplay.Pokemon.Type.Tierra"));
		Tag_Pokemon_Type_Hoja				=	UGameplayTagsManager::Get().AddNativeGameplayTag(TEXT("Gameplay.Pokemon.Type.Hoja"));
	
		//Ataques
		Tag_Pokemon_Attacks_Ascuas			=	UGameplayTagsManager::Get().AddNativeGameplayTag(TEXT("Gameplay.Pokemon.Attacks.Ascuas"));
		Tag_Pokemon_Attacks_AtaqueRapido	=	UGameplayTagsManager::Get().AddNativeGameplayTag(TEXT("Gameplay.Pokemon.Attacks.AtaqueRapido"));
		Tag_Pokemon_Attacks_Impactrueno		=	UGameplayTagsManager::Get().AddNativeGameplayTag(TEXT("Gameplay.Pokemon.Attacks.Impactrueno"));
		Tag_Pokemon_Attacks_LanzaRocas		=	UGameplayTagsManager::Get().AddNativeGameplayTag(TEXT("Gameplay.Pokemon.Attacks.LanzaRocas"));
		Tag_Pokemon_Attacks_LatigoCepa		=	UGameplayTagsManager::Get().AddNativeGameplayTag(TEXT("Gameplay.Pokemon.Attacks.LatigoCepa"));
		Tag_Pokemon_Attacks_PistolaAgua		=	UGameplayTagsManager::Get().AddNativeGameplayTag(TEXT("Gameplay.Pokemon.Attacks.PistolaAgua"));
	}
	
	//Tipos
	FGameplayTag Tag_Pokemon_Type_Agua;
	FGameplayTag Tag_Pokemon_Type_Fuego;
	FGameplayTag Tag_Pokemon_Type_Electrico;
	FGameplayTag Tag_Pokemon_Type_Tierra;
	FGameplayTag Tag_Pokemon_Type_Hoja;
	
	//Ataques
	FGameplayTag Tag_Pokemon_Attacks_Ascuas;
	FGameplayTag Tag_Pokemon_Attacks_AtaqueRapido;
	FGameplayTag Tag_Pokemon_Attacks_Impactrueno;
	FGameplayTag Tag_Pokemon_Attacks_LanzaRocas;
	FGameplayTag Tag_Pokemon_Attacks_LatigoCepa;
	FGameplayTag Tag_Pokemon_Attacks_PistolaAgua;
};
