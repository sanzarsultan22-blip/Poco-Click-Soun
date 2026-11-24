#include <Geode/Geode.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>
#include <cocos2d.h>
#include <SimpleAudioEngine.h>

using namespace geode::prelude;

namespace {
    void playSound(char const* fileName) {
        auto path = (Mod::get()->getResourcesDir() / fileName).string();
        CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(path.c_str());
    }
}

class $modify(POCOClickLayer, GJBaseGameLayer) {
    void handleButton(bool down, int button, bool isPlayer1) {
        // Call the original game handler first so gameplay remains unchanged.
        GJBaseGameLayer::handleButton(down, button, isPlayer1);
        if (button != 1) return;
        if (down) playSound("press.wav");
        else if (Mod::get()->getSettingValue<bool>("enable-release"))
            playSound("release.wav");
    }
};
