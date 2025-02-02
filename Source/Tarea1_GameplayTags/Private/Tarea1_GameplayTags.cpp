// Copyright Epic Games, Inc. All Rights Reserved.

#include "Tarea1_GameplayTags.h"

#include "Tarea2/GameplayPokemonManager.h"
#include "GameplayTagsManager.h"
#include "Modules/ModuleManager.h"

DEFINE_LOG_CATEGORY(LogTarea1_GameplayTags)
IMPLEMENT_MODULE(FTarea1_GameplayTags_Module, Tarea1_GameplayTags_Module)

void FTarea1_GameplayTags_Module::StartupModule()
{
	UGameplayTagsManager::OnLastChanceToAddNativeTags().AddLambda([]()
	{
		FGameplayPokemonManager::Get().InitGameplayTags();		
	});
}

void FTarea1_GameplayTags_Module::ShutdownModule()
{
	IModuleInterface::ShutdownModule();
}