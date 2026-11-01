#ifndef NODE_H
#define NODE_H

#include <string>
#include <memory>
#include <vector>
#include <utility>

enum class NodeType { Project, Task, Goal, Category };

struct Node {
    int id;
    std::string name;
    NodeType type;

    Node *parent = nullptr;
    std::vector<std::unique_ptr<Node>> children;

    explicit Node(int id, std::string name, NodeType type)
        : id(id), name(std::move(name)), type(type) {}

    // Deep-copy constructor
    Node(const Node &other) : id(other.id), type(other.type), parent(nullptr) {
        children.reserve(other.children.size());

        for (const auto &child : other.children) {
            auto copiedChild = std::make_unique<Node>(*child);

            copiedChild->parent = this;

            children.push_back(std::move(copiedChild));
        }
    }

    // Deep-copy assignment op
    Node &operator=(const Node &other) {
        if (this == &other) {
            return *this;
        }

        id = other.id;
        name = other.name;
        type = other.type;

        // out with the old, in with the new.
        children.clear();
        children.reserve(other.children.size());

        for (const auto &child : other.children) {
            auto copiedChild = std::make_unique<Node>(*child);
            copiedChild->parent = this;

            children.push_back(std::move(copiedChild));
        }
        return *this;
    }
};

#endif