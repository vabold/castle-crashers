#include "EnemyManager.hh"

#include "source/enemy/human/EnemyBarbarian.hh"

namespace Enemy {

EnemyBase *EnemyManager::CreateEnemy(const EnemyId id, const vec2 &position) {
    EnemyBase *enemy = nullptr;
    switch (id) {
    case EnemyId::Barbarian:
        enemy = new EnemyBarbarian(position);
    default:
        break;
    }

    assert(enemy);
    auto *enemyNode = new Util::Node(enemy);
    s_list->append(enemyNode);
    return enemy;
}

Util::List *EnemyManager::List() {
    return s_list;
}

EnemyManager *EnemyManager::CreateInstance() {
    assert(!s_instance);
    return s_instance = new EnemyManager();
}

void EnemyManager::DestroyInstance() {
    assert(s_instance);
    delete s_instance;
    s_instance = nullptr;
}

EnemyManager *EnemyManager::Instance() {
    return s_instance;
}

EnemyManager::EnemyManager() {
    assert(!s_list);
    s_list = new Util::List();
}

EnemyManager::~EnemyManager() {
    assert(s_list);

    for (size_t idx = 0; idx < s_list->size(); idx++) {
        EnemyBase *enemy = reinterpret_cast<EnemyBase *>(s_list->data(idx));
        delete enemy;
    }

    delete s_list;
    s_list = nullptr;
}

Util::List *EnemyManager::s_list = nullptr;
EnemyManager *EnemyManager::s_instance = nullptr;

} // namespace Enemy
