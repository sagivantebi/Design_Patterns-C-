//
// Created by sagiv on 2/10/2022.
//

#ifndef BRIDGESORTER_FACTORY_H
#define BRIDGESORTER_FACTORY_H

#include <iostream>
#include <unordered_map>
#include <functional>

class Worker {
public:
    Worker() = default;
    virtual void speak() const= 0 ;
};

class Teacher : public Worker {
public:

     Teacher() : Worker() {
        std::cout << "new Teacher\n";
    }
    virtual void speak()const {
        std::cout << "hi im Teacher" << std::endl;
    }
};

class TA : public Worker {
public:
     TA() : Worker() {
        std::cout << "new TA\n";
    }

    virtual void speak()const {
        std::cout << "hi im TA" << std::endl;
    }
};

class WorkerFactory {
public:
    std::unordered_map<std::string, std::function<Worker *()>> hash;

    WorkerFactory() {
        hash["ta"] = []() { return new TA(); };
        hash["Teacher"] = []() { return new Teacher(); };
    }

    Worker *newWorker(std::string s) {
       return hash[s]();
    }
};

void runFactory() {
    WorkerFactory *wf = new WorkerFactory();
    Worker *a = wf->newWorker("ta");
    a->speak();
    Worker *b = wf->newWorker("Teacher");
    b->speak();
    delete(a);
    delete(b);
}


#endif //BRIDGESORTER_FACTORY_H
