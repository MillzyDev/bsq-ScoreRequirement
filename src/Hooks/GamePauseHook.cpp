#include "SRHooks.hpp"

#include "main.hpp"

#include "GlobalNamespace/GamePause.hpp"
using namespace GlobalNamespace;

#include "Containers/SRContainer.hpp"
using namespace ScoreRequirement::Containers;

MAKE_HOOK_MATCH(GamePause_Pause, &GamePause::Pause, void,
    GamePause *self
) {
    GamePause_Pause(self);
    SRContainer::pauseChanged();
    getLogger().info("Game Paused");
}

void GamePauseHook(Logger &logger) {
    INSTALL_HOOK(logger, GamePause_Pause);
}

ScoreRequirementInstallHooks(GamePauseHook);