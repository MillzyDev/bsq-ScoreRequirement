#include "SRHooks.hpp"

#include "main.hpp"

#include "GlobalNamespace/GameCoreSceneSetup.hpp"
#include "GlobalNamespace/SongController.hpp"
using namespace GlobalNamespace;

#include "Containers/SRContainer.hpp"
using namespace ScoreRequirement::Containers;

#include "UnityEngine/Resources.hpp"
using namespace UnityEngine;

MAKE_HOOK_MATCH(GameCoreSceneSetup_InstallBindings, &GameCoreSceneSetup::InstallBindings, void,
    GameCoreSceneSetup *self
) {
    GameCoreSceneSetup_InstallBindings(self);

    SRContainer::songController = Resources::FindObjectsOfTypeAll<SongController *>()->values[0];
    if (SRContainer::songController == nullptr) getLogger().info("SongController is nullptr");

    SRContainer::pauseController = Resources::FindObjectsOfTypeAll<PauseController *>()->values[0];
    if (SRContainer::pauseController == nullptr) getLogger().info("PauseController is nullptr");

    SRContainer::audioTimeSyncController = Resources::FindObjectsOfTypeAll<AudioTimeSyncController *>()->values[0];
    if (SRContainer::audioTimeSyncController == nullptr) getLogger().info("AudioTimeSyncController is nullptr");

    SRContainer::relativeScoreAndImmediateRankCounter = Resources::FindObjectsOfTypeAll<RelativeScoreAndImmediateRankCounter *>()->values[0];
    if (SRContainer::relativeScoreAndImmediateRankCounter == nullptr) getLogger().info("RelativeScoreAndImmediateRankCounter is nullptr");

    SRContainer::scoreController = Resources::FindObjectsOfTypeAll<ScoreController *>()->values[0];
    if (SRContainer::scoreController == nullptr) getLogger().info("scoreController is nullptr");

    getLogger().info("Completed Setup");
}

void GameCoreSceneSetupHook(Logger &logger) {
    INSTALL_HOOK(logger, GameCoreSceneSetup_InstallBindings);
}

ScoreRequirementInstallHooks(GameCoreSceneSetupHook);