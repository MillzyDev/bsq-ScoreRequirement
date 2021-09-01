#pragma once

#include "main.hpp"

#include "custom-types/shared/macros.hpp"

#include "UnityEngine/MonoBehaviour.hpp"
#include "UnityEngine/RectTransform.hpp"
using namespace UnityEngine;

#include "UnityEngine/UI/Button.hpp"
using namespace UnityEngine::UI;

#include "questui/shared/CustomTypes/Components/Settings/SliderSetting.hpp"
using namespace QuestUI;

DECLARE_CLASS_CODEGEN(ScoreRequirement::UI::Components, SliderButton, MonoBehaviour,
                      DECLARE_INSTANCE_FIELD(Button*, button);
                      DECLARE_INSTANCE_FIELD(SliderSetting*, slider);
                      DECLARE_INSTANCE_FIELD(float, step);

                      DECLARE_STATIC_METHOD(void, Register, RectTransform* leftButton, RectTransform* rightButton, SliderSetting* slider, float step);

                      DECLARE_INSTANCE_METHOD(void, Setup, SliderSetting* slider, float step);

                      DECLARE_INSTANCE_METHOD(void, OnEnable);

                      DECLARE_INSTANCE_METHOD(void, OnDisable);
                      )