#include "UI/SRSettingsViewController.hpp"
using namespace ScoreRequirement::UI;

#include <functional>

#include "UI/Components/SliderButton.hpp"
using namespace ScoreRequirement::UI::Components;

#include "Config/ModConfig.hpp"

#include "questui/shared/BeatSaberUI.hpp"
using namespace QuestUI::BeatSaberUI;

#include "questui/shared/CustomTypes/Components/Backgroundable.hpp"
using namespace QuestUI;

#include "UnityEngine/Transform.hpp"
#include "UnityEngine/RectOffset.hpp"
using namespace UnityEngine;

#include "UnityEngine/UI/VerticalLayoutGroup.hpp"
#include "UnityEngine/UI/Toggle.hpp"
#include "UnityEngine/UI/HorizontalLayoutGroup.hpp"
#include "UnityEngine/UI/LayoutElement.hpp"
using namespace UnityEngine::UI;

#include "TMPro/TextAlignmentOptions.hpp"
using namespace TMPro;

#define MakeDelegate(DelegateType, varName) (il2cpp_utils::MakeDelegate<DelegateType>(classof(DelegateType), varName))

DEFINE_TYPE(ScoreRequirement::UI, SRSettingsViewController);

//VerticalLayoutGroup* layoutGroup;

HorizontalLayoutGroup* buffer;
    Toggle* enableSR;

VerticalLayoutGroup* settingsLayout;
    HorizontalLayoutGroup* elementLayout;
        Toggle* comboRequirementEnabled;
        SliderSetting* comboRequirement;
        Toggle* breakLimitEnabled;
        SliderSetting* breakLimit;
        Toggle* accRequirementEnabled;
        SliderSetting* accRequirement;
        Toggle* pauseLimitEnabled;
        SliderSetting* pauseLimit;
        Toggle* missLimitEnabled;
        SliderSetting* missLimit;

//Button* leftButton;
//Button* rightButton;

void SRSettingsViewController::DidActivate(bool firstActivation, bool addedToHeirarchy, bool screenSystemEnabling) {
    if (!firstActivation) return;

    buffer = CreateHorizontalLayoutGroup(get_transform());
    //buffer->get_gameObject()->AddComponent<Backgroundable*>()->ApplyBackground(il2cpp_utils::newcsstr("round-rect-panel"));

    settingsLayout = CreateVerticalLayoutGroup(buffer->get_transform());
    //settingsContainer->GetComponentInParent<VerticalLayoutGroup*>()->set_padding(RectOffset::New_ctor(28.0f, 0.0f, 0.0f, 0.0f));

        enableSR = CreateToggle(settingsLayout->get_transform(), "Enable ScoreRequirement", getModConfig().isSREnabled.GetValue(),
            [](bool value) {
            getModConfig().isSREnabled.SetValue(value);

            // TODO: deactivate inputs

            if (comboRequirementEnabled) comboRequirementEnabled->get_transform()->get_parent()->get_gameObject()->set_active(value);
            if (comboRequirement) comboRequirement->get_transform()->get_parent()->get_gameObject()->set_active(value);
            if (breakLimitEnabled) breakLimitEnabled->get_transform()->get_parent()->get_gameObject()->set_active(value);
            if (breakLimit) breakLimit->get_transform()->get_parent()->get_gameObject()->set_active(value);
            if (accRequirementEnabled) accRequirementEnabled->get_transform()->get_parent()->get_gameObject()->set_active(value);
            if (accRequirement) accRequirement->get_transform()->get_parent()->get_gameObject()->set_active(value);
            if (pauseLimitEnabled) pauseLimitEnabled->get_transform()->get_parent()->get_gameObject()->set_active(value);
            if (pauseLimit) pauseLimit->get_transform()->get_parent()->get_gameObject()->set_active(value);
            if (missLimitEnabled) missLimitEnabled->get_transform()->get_parent()->get_gameObject()->set_active(value);
            if (missLimit) missLimit->get_transform()->get_parent()->get_gameObject()->set_active(value);

        });
        AddHoverHint(enableSR->get_gameObject(), "Enables and disables the mod");


        elementLayout = CreateElementLayout();
            comboRequirementEnabled = CreateToggle(elementLayout->get_transform(), "Combo Requirement", getModConfig().isComboRequirementEnabled.GetValue(), [](bool value) {
                getModConfig().isComboRequirementEnabled.SetValue(value);
                comboRequirement->get_gameObject()->set_active(value);
            });
            comboRequirementEnabled->GetComponentInParent<LayoutElement*>()->set_preferredWidth(50.0f);
            AddHoverHint(comboRequirementEnabled->get_gameObject(), "Enables and disables this requirement");
            comboRequirement = CreateSliderSetting(elementLayout->get_transform(), "", 1.0f, getModConfig().minimumComboCount.GetValue(), 0.0f, 1000.0f, [](float value) {
                getModConfig().minimumComboCount.SetValue((int) value);
            });
            comboRequirement->GetComponent<LayoutElement*>()->set_preferredWidth(45.0f);

        elementLayout = CreateElementLayout();
            breakLimitEnabled = CreateToggle(elementLayout->get_transform(), "Combo Break Limit", getModConfig().isComboBreakLimitEnabled.GetValue(), [](bool value) {
                getModConfig().isComboBreakLimitEnabled.SetValue(value);
                breakLimit->get_gameObject()->set_active(value);
            });
            breakLimitEnabled->GetComponentInParent<LayoutElement*>()->set_preferredWidth(50.0f);
            AddHoverHint(breakLimitEnabled->get_gameObject(), "Enables and disables this requirement");
            breakLimit = CreateSliderSetting(elementLayout->get_transform(), "", 0.01f, getModConfig().comboBreakLimit.GetValue(), 0.0f, 20.0f, [](float value) {
                getModConfig().comboBreakLimit.SetValue((int) value);
            });
            breakLimit->GetComponent<LayoutElement*>()->set_preferredWidth(45.0f);

        elementLayout = CreateElementLayout();
            accRequirementEnabled = CreateToggle(elementLayout->get_transform(), "Accuracy Requirement", getModConfig().isAccRequirementEnabled.GetValue(), [](bool value) {
                getModConfig().isAccRequirementEnabled.SetValue(value);
                accRequirement->get_gameObject()->set_active(value);
            });
            accRequirementEnabled->GetComponentInParent<LayoutElement*>()->set_preferredWidth(50.0f);
            AddHoverHint(accRequirementEnabled->get_gameObject(), "Enables and disables this requirement");
            accRequirement = CreateSliderSetting(elementLayout->get_transform(), "", 0.01f, getModConfig().accRequirement.GetValue(), 0.01f, 100.0f, [](float value) {
                getModConfig().accRequirement.SetValue(value);
            });
            accRequirement->GetComponent<LayoutElement*>()->set_preferredWidth(45.0f);

        elementLayout = CreateElementLayout();
            pauseLimitEnabled = CreateToggle(elementLayout->get_transform(), "Pause Limit", getModConfig().isPauseLimitEnabled.GetValue(), [](bool value) {
                getModConfig().isPauseLimitEnabled.SetValue(value);
                pauseLimit->get_gameObject()->set_active(value);
            });
            pauseLimitEnabled->GetComponentInParent<LayoutElement*>()->set_preferredWidth(50.0f);
            pauseLimit = CreateSliderSetting(elementLayout->get_transform(), "", 0.01f, getModConfig().pauseLimit.GetValue(), 0.0f, 100.0f, [](float value) {
                getModConfig().pauseLimit.SetValue((int) value);
            });
            pauseLimit->GetComponent<LayoutElement*>()->set_preferredWidth(45.0f);

        elementLayout = CreateElementLayout();
            missLimitEnabled = CreateToggle(elementLayout->get_transform(), "Max Miss Limit", getModConfig().isMissLimitEnabled.GetValue(), [](bool value) {
                getModConfig().isMissLimitEnabled.SetValue(value);
                missLimit->get_gameObject()->set_active(value);
            });
            missLimitEnabled->GetComponentInParent<LayoutElement*>()->set_preferredWidth(50.0f);
            missLimit = CreateSliderSetting(elementLayout->get_transform(), "", 0.01f, getModConfig().missLimit.GetValue(), 0.0f, 100.0f, [](float value) {
                getModConfig().missLimit.SetValue((int) value);
            });
            missLimit->GetComponent<LayoutElement*>()->set_preferredWidth(45.0f);

        CreateText(
                settingsLayout->get_transform(),
                "\nScoreRequirement : 0.1.0",
                false
                )->set_alignment(TextAlignmentOptions::Center);

        //leftButton = CreateUIButton(layoutGroup->get_transform(), "&lt;");

        //rightButton = CreateUIButton(layoutGroup->get_transform(), "&gt;");

        //SliderButton::Register(GameObject::Instantiate(leftButton)->GetComponent<RectTransform*>(), GameObject::Instantiate(rightButton)->GetComponent<RectTransform*>(), accRequirement, 0.01f);
        //SliderButton::Register(GameObject::Instantiate(leftButton)->GetComponent<RectTransform*>(), GameObject::Instantiate(rightButton)->GetComponent<RectTransform*>(), comboRequirement, 1.0f);
        //SliderButton::Register(GameObject::Instantiate(leftButton)->GetComponent<RectTransform*>(), GameObject::Instantiate(rightButton)->GetComponent<RectTransform*>(), pauseLimit, 1.0f);
        //SliderButton::Register(GameObject::Instantiate(leftButton)->GetComponent<RectTransform*>(), GameObject::Instantiate(rightButton)->GetComponent<RectTransform*>(), breakLimit, 1.0f);
        //SliderButton::Register(GameObject::Instantiate(leftButton)->GetComponent<RectTransform*>(), GameObject::Instantiate(rightButton)->GetComponent<RectTransform*>(), missLimit, 1.0f);
        //GameObject::Destroy(leftButton);
        //GameObject::Destroy(rightButton);
}

HorizontalLayoutGroup* SRSettingsViewController::CreateElementLayout() {
    auto* layout = CreateHorizontalLayoutGroup(settingsLayout->get_transform());
    layout->GetComponent<LayoutElement*>()->set_preferredWidth(100.0f);
    layout->set_childForceExpandWidth(true);
    layout->set_spacing(0);
    return layout;
}