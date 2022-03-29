#pragma once

#include "beatsaber-hook/shared/utils/hooking.hpp"

namespace ScoreRequirement {
    class Hooks {
    private:
        inline static std::vector<void (*)(Logger &logger)> installFuncs;
    public:
        static void AddInstallFunc(void (*installFunc)(Logger &logger)) {
            installFuncs.push_back(installFunc);
        }

        static void InstallHooks(Logger &logger) {
            for (auto installFunc : installFuncs) {
                installFunc(logger);
            }
        }
    };
}

#define ScoreRequirementInstallHooks(func) \
struct __ScoreRequirementRegister##func { \
    __ScoreRequirementRegister##func() { \
        ScoreRequirement::Hooks::AddInstallFunc(func); \
    } \
}; \
static __ScoreRequirementRegister##func __ScoreRequirementInstance##func;