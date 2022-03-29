#pragma once

#include "GlobalNamespace/SongController.hpp"
#include "GlobalNamespace/ScoreController.hpp"
#include "GlobalNamespace/PauseController.hpp"
#include "GlobalNamespace/IReadonlyBeatmapData.hpp"
#include "GlobalNamespace/AudioTimeSyncController.hpp"
#include "GlobalNamespace/RelativeScoreAndImmediateRankCounter.hpp"
#include "GlobalNamespace/NoteData.hpp"
using namespace GlobalNamespace;

namespace ScoreRequirement::Containers {
    class SRContainer {

    public:
        static SongController *songController;
        static ScoreController *scoreController;
        static PauseController *pauseController;
        static IReadonlyBeatmapData *iReadonlyBeatmapData;
        static AudioTimeSyncController *audioTimeSyncController;
        static RelativeScoreAndImmediateRankCounter *relativeScoreAndImmediateRankCounter;

        static int currentComboBreaks;
        static int currentPauses;
        static int currentMisses;
        static float relativeScore;

        static void checkMaxCombo();
        static void checkPauses();
        static void checkComboBreaks();
        static void checkMisses();
        static void checkAccuracy();

        static void songFinished();

        static void pauseChanged();
        static void scoreChanged();
        static void comboChanged(int combo);
        static void noteWasMissed(NoteData *noteData);
    };
}