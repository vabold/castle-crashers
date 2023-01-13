#pragma once

#include "source/enemy/EnemyBase.hh"

namespace Enemy {

class EnemyBarbarian : public EnemyBase {
public:
    EnemyBarbarian(const vec2 &position);

    ~EnemyBarbarian() override;
    void init(const vec2 &position) override;
};

} // namespace Enemy
