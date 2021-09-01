#include "main.hpp"

#include "UI/SRSettingsViewController.hpp"
using namespace ScoreRequirement::UI;

#include "questui/shared/QuestUI.hpp"
#include "custom-types/shared/register.hpp"

#include "Config/ModConfig.hpp"

static ModInfo modInfo; // Stores the ID and version of our mod, and is sent to the modloader upon startup

// Loads the config from disk using our modInfo, then returns it for use
Configuration& getConfig() {
    static Configuration config(modInfo);
    config.Load();
    return config;
}

// Returns a logger, useful for printing debug messages
Logger& getLogger() {
    static Logger* logger = new Logger(modInfo);
    return *logger;
}

// Called at the early stages of game loading
extern "C" void setup(ModInfo& info) {
    info.id = ID;
    info.version = VERSION;
    modInfo = info;

    getConfig().Load();
    getModConfig().Init(info);
    getConfig().Reload();
    getConfig().Write();

    getLogger().info("Completed setup!");
}

// Called later on in the game loading - a good time to install function hooks
extern "C" void load() {
    il2cpp_functions::Init();

    custom_types::Register::AutoRegister();

    QuestUI::Init();
    QuestUI::Register::RegisterModSettingsViewController<SRSettingsViewController*>(modInfo);

    getLogger().info("Installing hooks...");
    // Install our hooks (none defined yet)
    getLogger().info("Installed all hooks!");
}