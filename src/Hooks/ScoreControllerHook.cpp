#include "SRHooks.hpp"

#include "main.hpp"

#include "GlobalNamespace/ScoreController.hpp"
using namespace GlobalNamespace;

#include "Containers/SRContainer.hpp"
using namespace ScoreRequirement::Containers;

MAKE_HOOK_MATCH(ScoreController_NotifyForChange, &ScoreController::NotifyForChange, void,
    ScoreController *self, bool comboChanged, bool multiplierChanged
) {
    ScoreController_NotifyForChange(self, comboChanged, multiplierChanged);
    SRContainer::comboChanged(self->combo);
    SRContainer::scoreChanged();
}

void ScoreControllerHook(Logger &logger) {
    INSTALL_HOOK(logger, ScoreController_NotifyForChange);
}

ScoreRequirementInstallHooks(ScoreControllerHook);