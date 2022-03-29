#pragma once

#include "main.hpp"

#include "config-utils/shared/config-utils.hpp"

#include "custom-types/shared/macros.hpp"

#include "UnityEngine/MonoBehaviour.hpp"
using namespace UnityEngine;

#include "UnityEngine/UI/HorizontalLayoutGroup.hpp"
using namespace UnityEngine::UI;

#include "GlobalNamespace/LevelCollectionNavigationController.hpp"
#include "GlobalNamespace/StandardLevelDetailViewController.hpp"
using namespace GlobalNamespace;

#define GET_FIND_METHOD(mPtr) il2cpp_utils::il2cpp_type_check::MetadataGetter<mPtr>::get()

DECLARE_CLASS_CODEGEN(ScoreRequirement::UI, SRSettingsViewController, MonoBehaviour,
                      DECLARE_STATIC_METHOD(HorizontalLayoutGroup*, CreateElementLayout);

                      DECLARE_INSTANCE_METHOD(void, DidActivate, bool firstActivation);
                      )