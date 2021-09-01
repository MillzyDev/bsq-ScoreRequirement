#include "main.hpp"

#include <functional>

#include "UI/Components/SliderButton.hpp"
using namespace ScoreRequirement::UI::Components;

#include "UnityEngine/GameObject.hpp"
#include "UnityEngine/Vector3.hpp"
using namespace UnityEngine;

#include "UnityEngine/Events/UnityAction.hpp"
using namespace UnityEngine::Events;

#include "UnityEngine/UI/Button_ButtonClickedEvent.hpp"
using namespace UnityEngine::UI;

#include "HMUI/NoTransitionsButton.hpp"
using namespace HMUI;

DEFINE_TYPE(ScoreRequirement::UI::Components, SliderButton);

#define MakeDelegate(DelegateType, varName) (il2cpp_utils::MakeDelegate<DelegateType>(classof(DelegateType), varName))

void SliderButton::Register(RectTransform* leftButton, RectTransform* rightButton, SliderSetting* slider, float step) {
    leftButton->get_gameObject()->set_active(true);
    leftButton->SetParent(slider->get_transform()->Find(il2cpp_utils::newcsstr("QuestUISliderSetting")));
    leftButton->set_localPosition(Vector3(-41.5f, 0.0f, 0.0f));
    leftButton->set_localScale(Vector3(0.5f, 1.0f, 1.0f));
    SliderButton* sliderButton = leftButton->get_gameObject()->AddComponent<SliderButton*>();
    sliderButton->Setup(slider, -step);

    rightButton->get_gameObject()->set_active(true);
    rightButton->SetParent(slider->get_transform()->Find(il2cpp_utils::newcsstr("QuestUISliderSetting")));
    rightButton->set_localPosition(Vector3(1.5f, 0.0f, 0.0f));
    rightButton->set_localScale(Vector3(0.5f, 1.0f, 1.0f));
    sliderButton = rightButton->get_gameObject()->AddComponent<SliderButton*>();
    sliderButton->Setup(slider, step);
}

void SliderButton::Setup(SliderSetting *slider, float step) {
    this->slider = slider;
    this->step = step;
}

void SliderButton::OnEnable() {
    button = this->get_gameObject()->GetComponent<NoTransitionsButton*>();
    if (button) {
        button->get_onClick()->AddListener(MakeDelegate(UnityAction*, (std::function<void()>) [this]() {
            if (slider) {
                slider->slider->set_value(slider->slider->get_value() + step);
                slider->slider->HandleNormalizedValueDidChange(slider->slider, slider->slider->NormalizeValue(slider->slider->get_value()));
            }
        }));
    }
}

void SliderButton::OnDisable() {
    if (button) {
        button->set_onClick(Button::ButtonClickedEvent::New_ctor());
    }
}