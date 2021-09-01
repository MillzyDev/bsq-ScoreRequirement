#pragma once

#include "main.hpp"

#include "config-utils/shared/config-utils.hpp"

#include "custom-types/shared/macros.hpp"

#include "HMUI/ViewController.hpp"
using namespace HMUI;

#include "UnityEngine/UI/HorizontalLayoutGroup.hpp"
using namespace UnityEngine::UI;

#include "GlobalNamespace/LevelCollectionNavigationController.hpp"
#include "GlobalNamespace/StandardLevelDetailViewController.hpp"
using namespace GlobalNamespace;

#define GET_FIND_METHOD(mPtr) il2cpp_utils::il2cpp_type_check::MetadataGetter<mPtr>::get()

DECLARE_CLASS_CODEGEN(ScoreRequirement::UI, SRSettingsViewController, ViewController,
                      DECLARE_STATIC_METHOD(HorizontalLayoutGroup*, CreateElementLayout);

                      DECLARE_OVERRIDE_METHOD(void, DidActivate, GET_FIND_METHOD(&ViewController::DidActivate), bool firstActivation, bool addedToHeirarchy, bool screenSystemEnabling);
                      )