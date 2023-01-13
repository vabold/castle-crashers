#include "EnemyBase.hh"

namespace Enemy {

EnemyBase::EnemyBase(const vec2 &position) {
    init(position);
}

EnemyBase::~EnemyBase() = default;

void EnemyBase::init(const vec2 &position) {
    m_position = position;
    m_unkPosition = position;
}

} // namespace Enemy
