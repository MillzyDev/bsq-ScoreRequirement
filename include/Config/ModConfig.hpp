#pragma once

#include "main.hpp"
#include "config-utils/shared/config-utils.hpp"

DECLARE_CONFIG(ModConfig,
               CONFIG_VALUE(isSREnabled, bool, "Score Requirement Enabled", true);
               CONFIG_VALUE(isAccRequirementEnabled, bool, "Accuracy Requirement Enabled", true);
               CONFIG_VALUE(isComboRequirementEnabled, bool, "Combo Requirement Enabled", false);
               CONFIG_VALUE(isPauseLimitEnabled, bool, "Pause Limit Enabled", true);
               CONFIG_VALUE(isMissLimitEnabled, bool, "Miss Limit Enabled", true);
               CONFIG_VALUE(isComboBreakLimitEnabled, bool, "Combo Break Limit Enabled", true);
               CONFIG_VALUE(minimumComboCount, int, "Minimum Combo", 500);
               CONFIG_VALUE(comboBreakLimit, int, "Combo Break Limit", 10);
               CONFIG_VALUE(accRequirement, float, "Accuracy Requirement", 80.0f);
               CONFIG_VALUE(pauseLimit, int, "Pause Limit", 10);
               CONFIG_VALUE(missLimit, int, "Miss Limit", 10);

               CONFIG_INIT_FUNCTION(
                       CONFIG_INIT_VALUE(isSREnabled);
                       CONFIG_INIT_VALUE(isAccRequirementEnabled);
                       CONFIG_INIT_VALUE(isComboRequirementEnabled);
                       CONFIG_INIT_VALUE(isPauseLimitEnabled);
                       CONFIG_INIT_VALUE(isMissLimitEnabled);
                       CONFIG_INIT_VALUE(isComboBreakLimitEnabled);
                       CONFIG_INIT_VALUE(minimumComboCount);
                       CONFIG_INIT_VALUE(comboBreakLimit);
                       CONFIG_INIT_VALUE(accRequirement);
                       CONFIG_INIT_VALUE(pauseLimit);
                       CONFIG_INIT_VALUE(missLimit);
                       )
               )