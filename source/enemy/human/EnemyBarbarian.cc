#include "EnemyBarbarian.hh"

namespace Enemy {

EnemyBarbarian::EnemyBarbarian(const vec2 &position) : EnemyBase(position) {
    init(position);
}

EnemyBarbarian::~EnemyBarbarian() = default;

void EnemyBarbarian::init(const vec2 &position) {
    EnemyBase::init(position);
}

} // namespace Enemy
