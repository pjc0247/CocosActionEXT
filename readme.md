CocosActionEXT
====

진작 있었어야 했는데 없던 것들

Create action with std::initializer_list
----
__Sequence__
```c++
SequenceEx::create({
  MoveBy::create(1.0f, Vec2(100, 0)),
  MoveBy::create(1.0f, Vec2(-100, 0))});
```
__Spawn__
```c++
SpawnEx::create({
  MoveBy::create(1.0f, Vec2(100, 0)),
  ScaleBy::create(1.0f, 10)});
```
__Repeat__
```c++
RepeatEx::create({
  MoveBy::create(1.0f, Vec2(100, 0)),
  MoveBy::create(1.0f, Vec2(-100, 0))},
  10 /* cnt */);
```
__RepeatForever__
```c++
RepeatForeverEx::create({
  MoveBy::create(1.0f, Vec2(100, 0)),
  MoveBy::create(1.0f, Vec2(-100, 0))});
```
__Ease__
```c++
Ease<EaseBackOut>::create({
  MoveBy::create(1.0f, Vec2(100, 0)),
  MoveBy::create(1.0f, Vec2(-100, 0))});
```

Shortcuts
----
__Delay__
```c++
// with `actions`
Delay::create({
  MoveBy::create(1.0f, Vec2(100, 0)),
  MoveBy::create(1.0f, Vec2(-100, 0))},
  2.0f /* delay */);

// with single `action`
Delay::create(
  MoveBy::create(1.0f, Vec2(100, 0)),
  2.0f /* delay */);
```
__FadeOutAndRemove__
```c++
FadeOutAndRemove::create(1.0f);
```

Combined animations
----
__FadeInEx__
![fadein](img/fadein_with_moveby.gif)
```c++
FadeInEx::createWithMoveBy(1.0f, FADEX_DOWN(20));
```
![fadein](img/fadein_with_scaleto.gif)
```c++
// ScaleBy
FadeInEx::createWithScaleBy(1.0f, 2);

// ScaleTo
FadeInEx::createWithScaleTo(1.0f, 2);
```
__FadeOutEx__
![fadeout](img/fadeout_with_moveby.gif)
```c++
FadeOutEx::createWithMoveBy(1.0f, FADEX_DOWN(20));
```
![fadeout](img/fadeout_with_scaleto.gif)
```c++
// ScaleBy
FadeOutEx::createWithScaleBy(1.0f, 2);

// ScaleTo
FadeOutEx::createWithScaleTo(1.0f, 2);
```