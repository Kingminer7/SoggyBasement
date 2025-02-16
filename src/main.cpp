#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/SecretLayer3.hpp>
class $modify(SecretLayer3) {
	bool init() {
		if (!SecretLayer3::init()) {
			return false;
    }

    if (auto bars = getChildByID("bars")) {
      if (!bars->isVisible()) {
        if (!GameStatsManager::sharedState()->isSpecialChestUnlocked("0002")) {
          return true;
        }
        bars->setVisible(true);
        auto sogSprite = CCSprite::create("sog.png"_spr);
        sogSprite->setPosition({bars->getPositionX(), bars->getPositionY() - 8});
        sogSprite->setAnchorPoint({0.5, 0.5});
        sogSprite->setScaleX(0.425);
        sogSprite->setScaleY(0.300);
        sogSprite->setID("sogSprite"_spr);
        addChild(sogSprite, bars->getZOrder() - 1);
      }
    }

		return true;
	}
};