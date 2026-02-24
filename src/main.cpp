#include <Geode/modify/ProfilePage.hpp>

class $modify(MyProfilePage, ProfilePage) {
    struct BadgeInfo {
        const char *sprite;
        int priority;
        cocos2d::SEL_MenuHandler callback;
    };

    struct Fields {
        const std::unordered_map<std::string, BadgeInfo> m_badges = {
            { "star-collector", {
                "SB_starBadge_001.png"_spr,
                60,
                menu_selector(MyProfilePage::onStarCollectorBadge)
            } },
            { "moon-collector", {
                "SB_moonBadge_001.png"_spr,
                50,
                menu_selector(MyProfilePage::onMoonCollectorBadge)
            } },
            { "secret-coin-collector", {
                "GJ_coinsIcon_001.png",
                70,
                menu_selector(MyProfilePage::onGoldCoinCollectorBadge)
            } },
            { "user-coin-collector", {
                "GJ_coinsIcon2_001.png",
                80,
                menu_selector(MyProfilePage::onSilverCoinCollectorBadge)
            } },
            { "demon-slayer", {
                "SB_demonBadge_003.png"_spr,
                20,
                menu_selector(MyProfilePage::onDemonSlayerBadge)
            } },
            { "demon-master", {
                "SB_demonBadge_002.png"_spr,
                40,
                menu_selector(MyProfilePage::onDemonMasterBadge)
            } },
            { "demon-chaser", {
                "SB_demonBadge_001.png"_spr,
                90,
                menu_selector(MyProfilePage::onDemonChaserBadge)
            } },
            { "creator", {
                "SB_creatorBadge_001.png"_spr,
                30,
                menu_selector(MyProfilePage::onCreatorBadge)
            } }
        };

        cocos2d::CCMenu *m_usernameMenu;
    };

    void addProfileBadge(std::string type) {
        auto [sprite, priority, callback] = m_fields->m_badges.at(type);

        auto *badge = CCMenuItemSpriteExtra::create(
            cocos2d::CCSprite::createWithSpriteFrameName(sprite),
            this,
            callback
        );

        badge->setID(fmt::format("{}-badge:{}"_spr, type, priority));
        m_fields->m_usernameMenu->addChild(badge);
    };

    void loadPageFromUserInfo(GJUserScore *score) {
        ProfilePage::loadPageFromUserInfo(score);

        // Get the menu to add the badges to
        auto *layer = m_mainLayer;
        m_fields->m_usernameMenu = static_cast<cocos2d::CCMenu *>(
            layer->getChildByIDRecursive("username-menu"));
        if (!m_fields->m_usernameMenu) return;

        // This is just to make the mod badge first
        auto *modBadge = static_cast<cocos2d::CCSprite *>(
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

    void onStarCollectorBadge(CCObject *) {
        FLAlertLayer::create(
            "Star collector!",
            "This player has collected over <cy>3,000 stars</c>!",
            "OK"
        )->show();
    };
    void onMoonCollectorBadge(CCObject *) {
        FLAlertLayer::create(
            "Moon collector!",
            "This player has collected over <cl>3,000 moons</c>!",
            "OK"
        )->show();
    };
    void onGoldCoinCollectorBadge(CCObject *) {
        FLAlertLayer::create(
            "Secret coin collector!",
            "This player has collected over <co>100 secret coins</c>!",
            "OK"
        )->show();
    };
    void onSilverCoinCollectorBadge(CCObject *) {
        FLAlertLayer::create(
            "User coin collector!",
            "This player has collected over <cj>1,000 user coins</c>!",
            "OK"
        )->show();
    };
    void onDemonSlayerBadge(CCObject *) {
        FLAlertLayer::create(
            "Demon slayer!",
            "This player has completed over <cr>100 demon levels</c>!",
            "OK"
        )->show();
    };
    void onDemonMasterBadge(CCObject *) {
        FLAlertLayer::create(
            "Demon master!",
            "This player has completed over <cr>50 demon levels</c>!",
            "OK"
        )->show();
    };
    void onDemonChaserBadge(CCObject *) {
        FLAlertLayer::create(
            "Demon chaser!",
            "This player has completed over <cr>25 demon levels</c>!",
            "OK"
        )->show();
    };
    void onCreatorBadge(CCObject *) {
        FLAlertLayer::create(
            "Creator badge!",
            "This player has been awarded with <cb>creator points</c> by <cb>RobTop</c>!",
            "OK"
        )->show();
    };
};