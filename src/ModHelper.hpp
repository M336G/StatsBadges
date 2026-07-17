#pragma once

class ModHelper {
public:
    struct BadgeInfo {
        char const *name;
        char const *description;
        char const *sprite;
        int priority;
        float scale; // 92.f (badge resolution) / <highest between width or height>
    };
    
    static const std::unordered_map<std::string, BadgeInfo> badges;

    static bool isBadgifyLoaded();
    static bool isBadgesApiLoaded();
};