//
// Created by sagiv on 2/10/2022.
//

#ifndef BRIDGESORTER_COMPOSITE_H
#define BRIDGESORTER_COMPOSITE_H
#include <list>
#include "Bridge_sorter.h"
class Component {
    Component *parent_;
public:
    virtual ~Component() {}

    void SetParent(Component *parent) {
        this->parent_ = parent;
    }

    Component *GetParent() const {
        return this->parent_;
    }

    virtual void Add(Component *component) {}

    virtual void Remove(Component *component) {}

    virtual bool IsComposite() const {
        return false;
    }
    virtual std::string Operation() const = 0;
};

class Leaf : public Component{
public:
    std::string Operation() const override {
        return "Leaf";
    }
};

class Composite : public Component{
protected:
    std::list<Component *> children_;
public:
    void Add(Component* component) override{
        this->children_.push_back(component);
        component->SetParent(this);
    }
    void Remove(Component* component) override{
        this->children_.remove(component);
        component->SetParent(nullptr);
    }
    bool IsComposite() const override {
        return true;
    }
    std::string Operation() const override {
        std::string result;
        for (const Component *c : children_) {
            if (c == children_.back()) {
                result += c->Operation();
            } else {
                result += c->Operation() + "+";
            }
        }
        return "Branch(" + result + ")";
    }


};

#endif //BRIDGESORTER_COMPOSITE_H
