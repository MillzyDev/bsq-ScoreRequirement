#include "SRHooks.hpp"

#include "main.hpp"

#include "GlobalNamespace/MissedNoteEffectSpawner.hpp"
#include "GlobalNamespace/NoteController.hpp"
using namespace GlobalNamespace;

#include "Containers/SRContainer.hpp"
using namespace ScoreRequirement::Containers;

MAKE_HOOK_MATCH(MissedNoteEffectSpawner_HandleNoteMissed, &MissedNoteEffectSpawner::HandleNoteWasMissed, void,
    MissedNoteEffectSpawner *self, NoteController *noteController
) {
    MissedNoteEffectSpawner_HandleNoteMissed(self, noteController);
    SRContainer::noteWasMissed(noteController->noteData);
    getLogger().info("Note was missed");
}

void MissedNoteEffectSpawnerHook(Logger &logger) {
    INSTALL_HOOK(logger, MissedNoteEffectSpawner_HandleNoteMissed);
}

ScoreRequirementInstallHooks(MissedNoteEffectSpawnerHook);