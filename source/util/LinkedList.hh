#pragma once

#include <Common.hh>

namespace Util {

class Node {
    friend class List;

public:
    Node(void *data);

private:
    void *m_data;
    Node *m_next;
    Node *m_prev;
};

class List {
public:
    List();
    ~List();

    bool append(Node *node);
    void clear();
    void init();
    bool insert(Node *node, const size_t index);
    void popFront();
    void popBack();
    bool prepend(Node *node);
    void remove(Node *node);
    void start(Node *node);

    void *data(const size_t index) const;
    void *data(const Node *node) const;
    bool empty() const;
    bool exists(const Node *node) const;
    Node *findByData(const void *data) const;
    Node *findByIndex(const size_t index) const;
    size_t size() const;

private:
    size_t m_count;
    Node *m_head;
    Node *m_tail;
};

} // namespace Util
