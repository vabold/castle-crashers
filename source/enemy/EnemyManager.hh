#pragma once

#include "source/enemy/EnemyBase.hh"
#include "source/enemy/EnemyId.hh"
#include "source/util/LinkedList.hh"

namespace Enemy {

class EnemyManager {
public:
    static EnemyBase *CreateEnemy(const EnemyId id, const vec2 &position);

    static EnemyManager *CreateInstance();
    static void DestroyInstance();
    static EnemyManager *Instance();
    static Util::List *List();

private:
    EnemyManager();
    ~EnemyManager();

    static Util::List *s_list;
    static EnemyManager *s_instance;
};

} // namespace Enemy
