#include "ModHelper.hpp"

using namespace geode::prelude;

#include <Geode/modify/ProfilePage.hpp>
class $modify(StatsBadgesProfilePage, ProfilePage) {
    struct Fields {
        std::unordered_map<std::string_view, SEL_MenuHandler const> const m_callbacks = {
            { "star-collector", menu_selector(StatsBadgesProfilePage::onStarCollectorBadge) },
            { "moon-collector", menu_selector(StatsBadgesProfilePage::onMoonCollectorBadge) },
            { "secret-coin-collector", menu_selector(StatsBadgesProfilePage::onGoldCoinCollectorBadge) },
            { "user-coin-collector", menu_selector(StatsBadgesProfilePage::onSilverCoinCollectorBadge) },
            { "demon-slayer", menu_selector(StatsBadgesProfilePage::onDemonSlayerBadge) },
            { "demon-master", menu_selector(StatsBadgesProfilePage::onDemonMasterBadge) },
            { "demon-chaser", menu_selector(StatsBadgesProfilePage::onDemonChaserBadge) },
            { "creator", menu_selector(StatsBadgesProfilePage::onCreatorBadge) }
        };
        int m_badgesAdded = 0;
        CCMenu *m_usernameMenu;
    };

    void addProfileBadge(std::string const& type) {
        if (!ModHelper::isBadgesApiLoaded() && m_fields->m_badgesAdded >= 1)
            return;

        auto& info = ModHelper::badges.at(type);
        auto& callback = m_fields->m_callbacks.at(type);
        
        auto id = fmt::format("{}-badge"_spr, type);
        if (ModHelper::isBadgesApiLoaded()) id += fmt::format(":{}", info.priority);

        // If it already exists don't add it again
        if (static_cast<CCMenuItemSpriteExtra *>(m_fields->m_usernameMenu->getChildByIDRecursive(id)))
            return;

        auto *badgeSprite = CCSprite::createWithSpriteFrameName(info.sprite);
        if (info.scale != 1.f)
            badgeSprite->setScale(info.scale);

        auto *badge = CCMenuItemSpriteExtra::create(badgeSprite, this, callback);
        badge->setID(id);
        m_fields->m_usernameMenu->addChild(badge);
        m_fields->m_badgesAdded++;
    }

    void loadPageFromUserInfo(GJUserScore *score) {
        ProfilePage::loadPageFromUserInfo(score);

        if (ModHelper::isBadgifyLoaded())
            return;

        // Get the menu to add the badges to
        m_fields->m_usernameMenu = static_cast<CCMenu *>(m_mainLayer->getChildByIDRecursive("username-menu"));
        if (!m_fields->m_usernameMenu) return;

        // This is just to make the mod badge first
        if (auto *modBadge = static_cast<CCSprite *>(m_fields->m_usernameMenu->getChildByIDRecursive("mod-badge"))) {
            if (ModHelper::isBadgesApiLoaded()) modBadge->setID("mod-badge:10");
            m_fields->m_badgesAdded++;
        }

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
        auto& info = ModHelper::badges.at("star-collector");
        FLAlertLayer::create(info.name, info.description, "OK")->show();
    };
    void onMoonCollectorBadge(CCObject *) {
        auto& info = ModHelper::badges.at("moon-collector");
        FLAlertLayer::create(info.name, info.description, "OK")->show();
    };
    void onGoldCoinCollectorBadge(CCObject *) {
        auto& info = ModHelper::badges.at("secret-coin-collector");
        FLAlertLayer::create(info.name, info.description, "OK")->show();
    };
    void onSilverCoinCollectorBadge(CCObject *) {
        auto& info = ModHelper::badges.at("user-coin-collector");
        FLAlertLayer::create(info.name, info.description, "OK")->show();
    };
    void onDemonSlayerBadge(CCObject *) {
        auto& info = ModHelper::badges.at("demon-slayer");
        FLAlertLayer::create(info.name, info.description, "OK")->show();
    };
    void onDemonMasterBadge(CCObject *) {
        auto& info = ModHelper::badges.at("demon-master");
        FLAlertLayer::create(info.name, info.description, "OK")->show();
    };
    void onDemonChaserBadge(CCObject *) {
        auto& info = ModHelper::badges.at("demon-chaser");
        FLAlertLayer::create(info.name, info.description, "OK")->show();
    };
    void onCreatorBadge(CCObject *) {
        auto& info = ModHelper::badges.at("creator");
        FLAlertLayer::create(info.name, info.description, "OK")->show();
    };
};