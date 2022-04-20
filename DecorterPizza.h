//
// Created by sagiv on 2/10/2022.
//

#ifndef BRIDGESORTER_DECORTERPIZZA_H
#define BRIDGESORTER_DECORTERPIZZA_H

class Pizza {
public:
    virtual std::string Operation() const {
        return "Pizza with";
    }

    virtual ~Pizza() {}
};

class Cheese : public Pizza {
public:
    virtual std::string Operation() const override {
        return " - \t mmmmm pizza!";
    }

};

class Decorator : public Pizza {
protected:
    Pizza *p;
public:
    Decorator(Pizza *p) : Pizza() {
        this->p = p;
    }

    std::string Operation() const override {
        return this->p->Operation();
    }

};

class Tomato : public Decorator {
public:
    Tomato(Pizza *p) : Decorator(p) {}

    std::string Operation() const override {
        return "Tomato " + Decorator::Operation() + " ";
    }
};

class MushroomS : public Decorator {
public:
    MushroomS(Pizza *p) : Decorator(p) {}

    std::string Operation() const override {
        return "MushroomS " + Decorator::Operation() + " ";
    }
};

class Tuna : public Decorator {
public:
    Tuna(Pizza *p) : Decorator(p) {}

    std::string Operation() const override {
        return "Tuna " + Decorator::Operation() + " ";
    }
};

void printDecoratorPizza(){
    Pizza *p = new Tuna(new MushroomS(new Tomato(new Cheese())));
    std::string s ="Pizza With " +  p->Operation();
    std::cout<<s;

}

#endif //BRIDGESORTER_DECORTERPIZZA_H
