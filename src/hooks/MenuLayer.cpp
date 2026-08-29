#include <Geode/Geode.hpp>

#include "../ModHelper.hpp"

using namespace geode::prelude;

static bool g_shownBadgifyWarning = false;

#include <Geode/modify/MenuLayer.hpp>
class $modify(MenuLayer) {
    bool init() {
        if (!MenuLayer::init())
            return false;

        log::debug("loaded");

        if (ModHelper::isBadgifyLoaded() && !g_shownBadgifyWarning) {
            Notification::create(
                "Stats Badges will not work with Badgify. Use Badgified instead",
                NotificationIcon::Warning,
                3.f
            )->show();

            g_shownBadgifyWarning = true;
        }
        
        return true;
    }
};