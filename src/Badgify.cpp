#include <alphalaneous.badgify/include/Badgify.hpp>
#include "ModHelper.hpp"

using namespace geode::prelude;

$on_mod(Loaded) {
    if (!ModHelper::isBadgifyLoaded())
        return;

    for (auto const& [id, info] : ModHelper::badges) {
        alpha::badgify::registerBadge(
            fmt::format("{}"_spr, id),
            info.name,
            info.description,
            [id, info](alpha::badgify::Badge const& badge) {
                if (id == "star-collector" && badge.user.data()->m_stars < 3000) return;
                if (id == "moon-collector" && badge.user.data()->m_moons < 3000) return;
                if (id == "secret-coin-collector" && badge.user.data()->m_secretCoins < 100) return;
                if (id == "user-coin-collector" && badge.user.data()->m_userCoins < 1000) return;
                
                int const demons = badge.user.data()->m_demons;
                if (id == "demon-slayer" && demons < 100) return;
                if (id == "demon-master" && (demons < 50 || demons > 100)) return;
                if (id == "demon-chaser" && (demons < 25 || demons > 50)) return;
                
                if (id == "creator" && badge.user.data()->m_creatorPoints == 0) return;

                alpha::badgify::showBadge(
                    badge,
                    CCSprite::createWithSpriteFrameName(info.sprite)
                );
            }
        );
    }
}