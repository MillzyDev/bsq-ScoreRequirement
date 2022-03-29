#include "Containers/SRContainer.hpp"
using namespace ScoreRequirement::Containers;

#include "GlobalNamespace/ColorType.hpp"
using namespace GlobalNamespace;

#include "bs-utils/shared/utils.hpp"

#include "main.hpp"

#include "fmt/fmt/include/fmt/core.h"

#define FORMAT(formatt, args...) fmt::format(formatt, args)

SongController *SRContainer::songController = nullptr;
ScoreController *SRContainer::scoreController = nullptr;
PauseController *SRContainer::pauseController = nullptr;
IReadonlyBeatmapData *SRContainer::iReadonlyBeatmapData = nullptr;
AudioTimeSyncController *SRContainer::audioTimeSyncController = nullptr;
RelativeScoreAndImmediateRankCounter *SRContainer::relativeScoreAndImmediateRankCounter = nullptr;

int SRContainer::currentComboBreaks = 0;
int SRContainer::currentPauses = 0;
int SRContainer::currentMisses = 0;
float SRContainer::relativeScore = 1.0f;

void SRContainer::checkMaxCombo() {
    if (!getModConfig().isComboRequirementEnabled.GetValue()) return;

    getLogger().info("[MIN COMBO] %i of %i has been reached!", scoreController->maxCombo, getModConfig().minimumComboCount.GetValue());

    if (!(scoreController->maxCombo > getModConfig().minimumComboCount.GetValue())) {
        bs_utils::Submission::disable(modInfo);
        getLogger().info("Disabled score submission: Combo was too low");
    }
}

void SRContainer::checkPauses() {
    if (!getModConfig().isPauseLimitEnabled.GetValue()) return;

    getLogger().info("[PAUSES] %i of %i has been reached!", currentPauses, getModConfig().pauseLimit.GetValue());

    if (currentPauses > getModConfig().pauseLimit.GetValue()) {
        bs_utils::Submission::disable(modInfo);
        getLogger().info("Disabled score submission: Too many pauses");
    }
}

void SRContainer::checkComboBreaks() {
    if (!getModConfig().isComboBreakLimitEnabled.GetValue()) return;

    getLogger().info("[COMBO BREAKS] %i of %i has been reached!", currentComboBreaks, getModConfig().comboBreakLimit.GetValue());

    if (currentComboBreaks > getModConfig().comboBreakLimit.GetValue()) {
        bs_utils::Submission::disable(modInfo);
        getLogger().info("Disabled score submission: Too many combo breaks");
    }
}

void SRContainer::checkMisses() {
    if (!getModConfig().isMissLimitEnabled.GetValue()) return;

    getLogger().info("[MISSES] %i of %i has been reached!", currentMisses, getModConfig().missLimit.GetValue());

    if (currentMisses > getModConfig().missLimit.GetValue()) {
        bs_utils::Submission::disable(modInfo);
        getLogger().info("Disabled score submission: Too many misses");
    }
}

void SRContainer::checkAccuracy() {
    if (!getModConfig().isAccRequirementEnabled.GetValue()) return;

    getLogger().info("[ACCURACY] %f of %f has been reached!", relativeScore, getModConfig().accRequirement.GetValue());

    if (relativeScore > getModConfig().accRequirement.GetValue() / 100.0f) {
        bs_utils::Submission::disable(modInfo);
        getLogger().info("Disabled score submission: Accuracy was too low");
    }
}

void SRContainer::songFinished() {
    checkMaxCombo();
    checkPauses();
    checkComboBreaks();
    checkMisses();
    checkAccuracy();

    currentComboBreaks = 0;
    currentPauses = 0;
    currentMisses = 0;
    relativeScore = 0;
}

void SRContainer::pauseChanged() {
    currentPauses++;
}

void SRContainer::scoreChanged() {
    relativeScore = relativeScoreAndImmediateRankCounter->relativeScore;
}

void SRContainer::comboChanged(int combo) {
    if (combo == 0) currentComboBreaks++;
}

void SRContainer::noteWasMissed(NoteData *noteData) {
    if (noteData->colorType == ColorType::None) return;
    currentMisses++;
}