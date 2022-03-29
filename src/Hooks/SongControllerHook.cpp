#include "SRHooks.hpp"

#include "main.hpp"

#include "GlobalNamespace/SongController.hpp"
using namespace GlobalNamespace;

#include "Containers/SRContainer.hpp"
using namespace ScoreRequirement::Containers;

MAKE_HOOK_MATCH(SongController_SendSongDidFinishEvent, &SongController::SendSongDidFinishEvent, void,
    SongController *self
) {
    SongController_SendSongDidFinishEvent(self);
    SRContainer::songFinished();
    getLogger().info("Song Finished");
}

void SongControllerHook(Logger &logger) {
    INSTALL_HOOK(logger, SongController_SendSongDidFinishEvent);
}

ScoreRequirementInstallHooks(SongControllerHook);