#include <Geode/modify/ProfilePage.hpp>

using namespace geode::prelude;

class $modify(MyProfilePage, ProfilePage) {
private:
    struct BadgeInfo {
        char const* sprite;
        int const priority;
        float const scale; // 92.f (badge resolution) / <highest between width or height>
        SEL_MenuHandler const callback;
    };

public:    
    struct Fields {
        std::unordered_map<std::string_view, BadgeInfo> const m_badges = {
            { "star-collector", {
                "GJ_bigStar_noShadow_001.png",
                60,
                92.f / 164.f,
                menu_selector(MyProfilePage::onStarCollectorBadge)
            } },
            { "moon-collector", {
                "GJ_bigMoon_noShadow_001.png",
                50,
                92.f / 142.f,
                menu_selector(MyProfilePage::onMoonCollectorBadge)
            } },
            { "secret-coin-collector", {
                "GJ_coinsIcon_001.png",
                70,
                1.f,
                menu_selector(MyProfilePage::onGoldCoinCollectorBadge)
            } },
            { "user-coin-collector", {
                "GJ_coinsIcon2_001.png",
                80,
                1.f,
                menu_selector(MyProfilePage::onSilverCoinCollectorBadge)
            } },
            { "demon-slayer", {
                "diffIcon_10_btn_001.png",
                20,
                92.f / 160.f,
                menu_selector(MyProfilePage::onDemonSlayerBadge)
            } },
            { "demon-master", {
                "diffIcon_06_btn_001.png",
                40,
                92.f / 134.f,
                menu_selector(MyProfilePage::onDemonMasterBadge)
            } },
            { "demon-chaser", {
                "diffIcon_07_btn_001.png",
                90,
                92.f / 132.f,
                menu_selector(MyProfilePage::onDemonChaserBadge)
            } },
            { "creator", {
                "GJ_hammerIcon_001.png",
                30,
                92.f / 100.f,
                menu_selector(MyProfilePage::onCreatorBadge)
            } }
        };

        CCMenu* m_usernameMenu;
    };

    void addProfileBadge(std::string_view type) {
        auto& [spriteName, priority, scale, callback] = m_fields->m_badges.at(type);
        auto const id = fmt::format("{}-badge:{}"_spr, type, priority);

        // If it already exists don't add it again
        if (static_cast<CCMenuItemSpriteExtra*>(
            m_fields->m_usernameMenu->getChildByIDRecursive(id)))
            return;

        auto* sprite = CCSprite::createWithSpriteFrameName(spriteName);
        if (scale != 1.f)
            sprite->setScale(scale);            

        auto* badge = CCMenuItemSpriteExtra::create(
            sprite,
            this,
            callback
        );

        badge->setID(id);
        m_fields->m_usernameMenu->addChild(badge);
    };

    void loadPageFromUserInfo(GJUserScore* score) {
        ProfilePage::loadPageFromUserInfo(score);

        // Get the menu to add the badges to
        m_fields->m_usernameMenu = static_cast<CCMenu*>(
            m_mainLayer->getChildByIDRecursive("username-menu"));
        if (!m_fields->m_usernameMenu) return;

        // This is just to make the mod badge first
        auto* modBadge = static_cast<CCSprite*>(
            m_fields->m_usernameMenu->getChildByIDRecursive("mod-badge"));
        if (modBadge) modBadge->setID("mod-badge:10");

        if (score->m_stars >= 3000) addProfileBadge("star-collector");
        if (score->m_moons >= 3000) addProfileBadge("moon-collector");
        if (score->m_secretCoins >= 100) addProfileBadge("secret-coin-collector");
        if (score->m_userCoins >= 1000) addProfileBadge("user-coin-collector");

        if (score->m_demons >= 100) addProfileBadge("demon-slayer");
        else if (score->m_demons >= 50) addProfileBadge("demon-master");
        else if (score->m_demons >= 25) addProfileBadge("demon-chaser");

        if (score->m_creatorPoints) addProfileBadge("creator");

        m_fields->m_usernameMenu->updateLayout();
    };

    void onStarCollectorBadge(CCObject*) {
        FLAlertLayer::create(
            "Star collector!",
            "This player has collected over <cy>3,000 stars</c>!",
            "OK"
        )->show();
    };
    void onMoonCollectorBadge(CCObject*) {
        FLAlertLayer::create(
            "Moon collector!",
            "This player has collected over <cl>3,000 moons</c>!",
            "OK"
        )->show();
    };
    void onGoldCoinCollectorBadge(CCObject*) {
        FLAlertLayer::create(
            "Secret coin collector!",
            "This player has collected over <co>100 secret coins</c>!",
            "OK"
        )->show();
    };
    void onSilverCoinCollectorBadge(CCObject*) {
        FLAlertLayer::create(
            "User coin collector!",
            "This player has collected over <cj>1,000 user coins</c>!",
            "OK"
        )->show();
    };
    void onDemonSlayerBadge(CCObject*) {
        FLAlertLayer::create(
            "Demon slayer!",
            "This player has completed over <cr>100 demon levels</c>!",
            "OK"
        )->show();
    };
    void onDemonMasterBadge(CCObject*) {
        FLAlertLayer::create(
            "Demon master!",
            "This player has completed over <cr>50 demon levels</c>!",
            "OK"
        )->show();
    };
    void onDemonChaserBadge(CCObject*) {
        FLAlertLayer::create(
            "Demon chaser!",
            "This player has completed over <cr>25 demon levels</c>!",
            "OK"
        )->show();
    };
    void onCreatorBadge(CCObject*) {
        FLAlertLayer::create(
            "Creator badge!",
            "This player has been awarded with <cb>creator points</c> by <cb>RobTop</c>!",
            "OK"
        )->show();
    };
};