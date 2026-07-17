#include "ModHelper.hpp"

using namespace geode::prelude;

std::unordered_map<std::string, ModHelper::BadgeInfo> const ModHelper::badges = {
    { "star-collector", {
        "Star Collector",
        "This player has collected over <cy>3,000 stars</c>!",
        "GJ_bigStar_noShadow_001.png",
        60,
        92.f / 164.f
    } },
    { "moon-collector", {
        "Moon Collector",
        "This player has collected over <cl>3,000 moons</c>!",
        "GJ_bigMoon_noShadow_001.png",
        50,
        92.f / 142.f,
    } },
    { "secret-coin-collector", {
        "Secret coin collector",
        "This player has collected over <co>100 secret coins</c>!",
        "GJ_coinsIcon_001.png",
        70,
        1.f,
    } },
    { "user-coin-collector", {
        "User coin collector",
        "This player has collected over <cj>1,000 user coins</c>!",
        "GJ_coinsIcon2_001.png",
        80,
        1.f,
    } },
    { "demon-slayer", {
        "Demon slayer",
        "This player has completed over <cr>100 demon levels</c>!",
        "diffIcon_10_btn_001.png",
        20,
        92.f / 160.f,
    } },
    { "demon-master", {
        "Demon master",
        "This player has completed over <cr>50 demon levels</c>!",
        "diffIcon_06_btn_001.png",
        40,
        92.f / 134.f,
    } },
    { "demon-chaser", {
        "Demon chaser",
        "This player has completed over <cr>25 demon levels</c>!",
        "diffIcon_07_btn_001.png",
        90,
        92.f / 132.f,
    } },
    { "creator", {
        "Creator badge",
        "This player has been awarded with <cb>creator points</c> by <cb>RobTop</c>!",
        "GJ_hammerIcon_001.png",
        30,
        92.f / 100.f,
    } }
};

bool ModHelper::isBadgifyLoaded() {
    static bool isBadgifyLoaded = Loader::get()->isModLoaded("alphalaneous.badgify");
    return isBadgifyLoaded;
}

bool ModHelper::isBadgesApiLoaded() {
    static bool isBadgesApiLoaded = Loader::get()->isModLoaded("jouca.badgesapi");
    return isBadgesApiLoaded;
}