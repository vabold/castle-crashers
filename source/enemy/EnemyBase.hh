#pragma once

#include <Common.hh>

namespace Enemy {

#define DMG_MELEE 0
#define DMG_POISON 1
#define DMG_ELEC 2
#define DMG_ICE 3
#define DMG_FIRE 4
#define DMG_OBJECT 5
#define DMG_MAGIC 6

class EnemyBase {
public:
    EnemyBase(const vec2 &position);

    virtual ~EnemyBase();
    virtual void init(const vec2 &position);

protected:
    vec2 m_position;
    vec2 m_unkPosition;
    bool m_active;
};

} // namespace Enemy
