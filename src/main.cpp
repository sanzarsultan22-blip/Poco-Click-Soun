
#include <Geode/Geode.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>
#include <Geode/binding/FMODAudioEngine.hpp>

using namespace geode::prelude;

namespace {
    void playSound(char const* fileName) {
        auto path = Mod::get()->getResourcesDir() / fileName;

        if (auto audio = FMODAudioEngine::get()) {
            audio->playEffect(path.string());
        }
    }
}

class $modify(POCOClickLayer, GJBaseGameLayer) {
    void handleButton(bool down, int button, bool isPlayer1) {
        GJBaseGameLayer::handleButton(down, button, isPlayer1);

        if (button != 1) return;

        if (down) {
            playSound("press.wav");
        }
        else if (Mod::get()->getSettingValue<bool>("enable-release")) {
            playSound("release.wav");
        }
    }
};
