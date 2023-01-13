#include "LinkedList.hh"

namespace Util {

Node::Node(void *data) : m_data(data), m_next(nullptr), m_prev(nullptr) {}

List::List() {
    init();
}

List::~List() {
    clear();
}

bool List::append(Node *node) {
    if (exists(node)) {
        return false;
    }
    if (!m_head) {
        start(node);
        return true;
    }

    node->m_prev = m_tail;
    m_tail->m_next = node;
    m_tail = node;
    m_count++;
}

void List::clear() {
    while (m_head) {
        remove(m_head);
    }
    init();
}

void List::init() {
    m_head = nullptr;
    m_tail = nullptr;
    m_count = 0;
}

bool List::insert(Node *node, const size_t index) {
    if (exists(node)) {
        return;
    }
    if (index == 0) {
        return prepend(node);
    }
    if (index >= m_count) {
        return append(node);
    }

    Node *prevNode = findByIndex(index - 1);
    Node *nextNode = prevNode->m_next;
    node->m_prev = prevNode;
    node->m_next = nextNode;
    prevNode->m_next = node;
    nextNode->m_prev = node;
    m_count++;
    return true;
}

void List::popFront() {
    if (m_head) {
        remove(m_head);
    }
}

void List::popBack() {
    if (m_tail) {
        remove(m_tail);
    }
}

bool List::prepend(Node *node) {
    if (exists(node)) {
        return false;
    }
    if (!m_head) {
        start(node);
        return true;
    }

    node->m_next = m_head;
    m_head->m_prev = node;
    m_head = node;
    m_count++;
    return true;
}

void List::remove(Node *node) {
    // Check if there's nothing to remove
    if (!m_head) {
        return;
    }

    // Replace node links
    if (node->m_prev) {
        node->m_prev->m_next = node->m_next;
    }
    if (node->m_next) {
        node->m_next->m_prev = node->m_prev;
    }

    // Replace list links
    if (node == m_head) {
        m_head = node->m_next;
    }
    if (node == m_tail) {
        m_tail = node->m_prev;
    }

    m_count--;
    delete node;
}

void List::start(Node *node) {
    m_head = node;
    m_tail = node;
    m_count++;
}

void *List::data(const size_t index) const {
    Node *node = findByIndex(index);
    if (!node) {
        return nullptr;
    }
    return node->m_data;
}

void *List::data(const Node *node) const {
    return node->m_data;
}

bool List::empty() const {
    return !m_head;
}

bool List::exists(const Node *node) const {
    for (const auto *candidate = m_head; candidate; candidate = candidate->m_next) {
        if (candidate == node) {
            return true;
        }
    }
    return false;
}

Node *List::findByData(const void *data) const {
    for (const auto *candidate = m_head; candidate; candidate = candidate->m_next) {
        if (candidate->m_data == data) {
            return candidate;
        }
    }
    return nullptr;
}

Node *List::findByIndex(const size_t index) const {
    if (index >= m_count) {
        return nullptr;
    }

    Node *node = m_head;
    for (size_t i = 0; i < index; i++) {
        node = node->m_next;
    }
    return node;
}

size_t List::size() const {
    return m_count;
}

} // namespace Util
