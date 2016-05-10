#pragma once

#include "cocos2d-x.h"

class SequenceEx {
public:
	static cocos2d::Sequence *create(std::initializer_list<cocos2d::FiniteTimeAction *> actions) {
		cocos2d::Vector<cocos2d::FiniteTimeAction *> vec(actions.size());
		for (auto action : actions)
			vec.pushBack(action);
		return cocos2d::Sequence::create(vec);
	}
};
class SpawnEx {
public:
	static cocos2d::Spawn *create(std::initializer_list<cocos2d::FiniteTimeAction *> actions) {
		cocos2d::Vector<cocos2d::FiniteTimeAction *> vec(actions.size());
		for (auto action : actions)
			vec.pushBack(action);
		return cocos2d::Spawn::create(vec);
	}
};
class RepeatEx {
public:
	static cocos2d::Repeat *create(std::initializer_list<cocos2d::FiniteTimeAction *> actions, int n) {
		return cocos2d::Repeat::create(SequenceEx::create(actions), n);
	}
};
class RepeatForeverEx {
public:
	static cocos2d::RepeatForever *create(std::initializer_list<cocos2d::FiniteTimeAction *> actions) {
		return cocos2d::RepeatForever::create(SequenceEx::create(actions));
	}
};
class Delay {
public:
	static cocos2d::Sequence *create(cocos2d::FiniteTimeAction *action, float d) {
		return SequenceEx::create({
			cocos2d::DelayTime::create(d),
			action
		});
	}
	static cocos2d::Sequence *create(std::initializer_list<cocos2d::FiniteTimeAction *> actions, float d) {
		return SequenceEx::create({
			cocos2d::DelayTime::create(d),
			SequenceEx::create(actions)
		});
	}
};
class FadeOutAndRemove {
public:
	static cocos2d::Sequence *create(float d) {
		return SequenceEx::create({
			cocos2d::FadeOut::create(d),
			cocos2d::RemoveSelf::create()
		});
	}
};

#define FADEX_UP(x) cocos2d::Vec2(0, x)
#define FADEX_DOWN(x) cocos2d::Vec2(0, -x)
#define FADEX_LEFT(x) cocos2d::Vec2(-x, 0)
#define FADEX_RIGHT(x) cocos2d::Vec2(x, 0)

class FadeInEx {
public:
	static cocos2d::Spawn *createWithMoveBy(float d, const cocos2d::Vec2 &v) {
		return SpawnEx::create({
			FadeIn::create(d),
			MoveBy::create(d, v)
		});
	}
	static cocos2d::Spawn *createWithScaleBy(float d, float s) {
		return SpawnEx::create({
			FadeIn::create(d),
			ScaleBy::create(d, s)
		});
	}
	static cocos2d::Spawn *createWithScaleTo(float d, float s) {
		return SpawnEx::create({
			FadeIn::create(d),
			ScaleTo::create(d, s)
		});
	}
};
class FadeOutEx {
public:
	static cocos2d::Sequence *createWithMoveBy(float d, const cocos2d::Vec2 &v, bool remove = false) {
		return SequenceEx::create({
			SpawnEx::create({
				FadeOut::create(d),
				MoveBy::create(d, v)
			}),
			remove ? (FiniteTimeAction*)RemoveSelf::create() : DelayTime::create(0)
		});
	}
	static cocos2d::Sequence *createWithScaleBy(float d, float s, bool remove = false) {
		return SequenceEx::create({
			SpawnEx::create({
				FadeOut::create(d),
				ScaleBy::create(d, s)
			}),
			remove ? (FiniteTimeAction*)RemoveSelf::create() : DelayTime::create(0)
		});
	}
	static cocos2d::Sequence *createWithScaleTo(float d, float s, bool remove = false) {
		return SequenceEx::create({
			SpawnEx::create({
				FadeOut::create(d),
				ScaleTo::create(d, s)
			}),
			remove ? (FiniteTimeAction*)RemoveSelf::create() : DelayTime::create(0)
		});
	}
};