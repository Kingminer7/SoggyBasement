#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/SecretLayer3.hpp>
class $modify(SecretLayer3) {
	bool init() {
		if (!SecretLayer3::init()) {
			return false;
    }

    if (auto dungeonbar = getChildByType<DungeonBarsSprite>(0)) {
      if (auto m = getChildByType<CCMenu>(1)) {
        if (auto s = m->getChildByType<CCMenuItemSpriteExtra>(0)) {
          log::info("h");
          return true;
        }
      }
      if (!dungeonbar->isVisible()) {
        dungeonbar->setVisible(true);
        auto sogSprite = CCSprite::create("sog.png"_spr);
        sogSprite->setPosition({dungeonbar->getPositionX(), dungeonbar->getPositionY() - 8});
        sogSprite->setAnchorPoint({0.5, 0.5});
        sogSprite->setZOrder(dungeonbar->getZOrder() - 1);
        sogSprite->setScaleX(0.425);
        sogSprite->setScaleY(0.300);
        sogSprite->setID("sogSprite"_spr);
        addChild(sogSprite);
      }
    }

		return true;
	}
};