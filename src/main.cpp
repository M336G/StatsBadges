#include <alphalaneous.badgify/include/Badgify.hpp>

using namespace geode::prelude;

$on_mod(Loaded) {
    alpha::badgify::registerBadge(
        "star-collector"_spr,
        "Star collector!",
        "This player has collected over <cy>3,000 stars</c>!",
        [] (const alpha::badgify::Badge& badge) {
            if (badge.user.data()->m_stars < 3000) return;

            CCSprite* badgeSpr = CCSprite::createWithSpriteFrameName("GJ_bigStar_noShadow_001.png");

            alpha::badgify::showBadge(badge, badgeSpr);
        }
    );
    alpha::badgify::registerBadge(
        "moon-collector"_spr,
        "Moon collector!",
        "This player has collected over <cl>3,000 moons</c>!",
        [] (const alpha::badgify::Badge& badge) {
            if (badge.user.data()->m_moons < 3000) return;

            CCSprite* badgeSpr = CCSprite::createWithSpriteFrameName("GJ_bigMoon_noShadow_001.png");

            alpha::badgify::showBadge(badge, badgeSpr);
        }
    );
    alpha::badgify::registerBadge(
        "secret-coin-collector"_spr,
        "Secret coin collector!",
        "This player has collected over <co>100 secret coins</c>!",
        [] (const alpha::badgify::Badge& badge) {
            if (badge.user.data()->m_secretCoins < 100) return;

            CCSprite* badgeSpr = CCSprite::createWithSpriteFrameName("GJ_coinsIcon_001.png");

            alpha::badgify::showBadge(badge, badgeSpr);
        }
    );
    alpha::badgify::registerBadge(
        "user-coin-collector"_spr,
        "User coin collector!",
        "This player has collected over <cj>1,000 user coins</c>!",
        [] (const alpha::badgify::Badge& badge) {
            if (badge.user.data()->m_userCoins < 1000) return;

            CCSprite* badgeSpr = CCSprite::createWithSpriteFrameName("GJ_coinsIcon2_001.png");

            alpha::badgify::showBadge(badge, badgeSpr);
        }
    );
    alpha::badgify::registerBadge(
        "demon-slayer"_spr,
        "Demon slayer!",
        "This player has completed over <cr>100 demon levels</c>!",    
        [] (const alpha::badgify::Badge& badge) {
            if (badge.user.data()->m_demons < 100) return;

            CCSprite* badgeSpr = CCSprite::createWithSpriteFrameName("diffIcon_10_btn_001.png");

            alpha::badgify::showBadge(badge, badgeSpr);
        }
    );
    alpha::badgify::registerBadge(
        "demon-master"_spr,
        "Demon master!",
        "This player has completed over <cr>50 demon levels</c>!",
        [] (const alpha::badgify::Badge& badge) {
            const int demons = badge.user.data()->m_demons;
            if (demons < 50 || demons > 100) return;

            CCSprite* badgeSpr = CCSprite::createWithSpriteFrameName("diffIcon_06_btn_001.png");

            alpha::badgify::showBadge(badge, badgeSpr);
        }
    );
    alpha::badgify::registerBadge(
        "demon-chaser"_spr,
        "Demon chaser!",
        "This player has completed over <cr>25 demon levels</c>!",
        [] (const alpha::badgify::Badge& badge) {
            const int demons = badge.user.data()->m_demons;
            if (demons < 25 || demons > 49) return;

            CCSprite* badgeSpr = CCSprite::createWithSpriteFrameName("diffIcon_07_btn_001.png");

            alpha::badgify::showBadge(badge, badgeSpr);
        }
    );
    alpha::badgify::registerBadge(
        "creator"_spr,
        "Creator badge!",
        "This player has been awarded with <cb>creator points</c> by <cb>RobTop</c>!",
        [] (const alpha::badgify::Badge& badge) {
            if (badge.user.data()->m_creatorPoints > 0) return;

            CCSprite* badgeSpr = CCSprite::createWithSpriteFrameName("GJ_hammerIcon_001.png");

            alpha::badgify::showBadge(badge, badgeSpr);
        }
    );
}