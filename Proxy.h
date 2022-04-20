//
// Created by sagiv on 2/12/2022.
//

#ifndef BRIDGESORTER_PROXY_H
#define BRIDGESORTER_PROXY_H

#include <iostream>

class Subject {
public:
    virtual void Request() const = 0;
};

class RealSubject : public Subject {
public:
    void Request() const {
        std::cout << "am I real?!" << std::endl;
    }
};

class Proxy : Subject{
private:
    RealSubject* r;
    bool checkAccess() const{
        std::cout<<"Proxy check"<<std::endl;
        return true;
    }
    void LogAccess() const{
        std::cout<<"Proxy logged in"<<std::endl;
    }
public:
    Proxy(RealSubject *real_subject) {
        this->r = new RealSubject(*r);
    }

    ~Proxy() {
        delete r;
    }
    void Request() const override {
        if (this->checkAccess()) {
            this->r->Request();
            this->LogAccess();
        }
    }
};


#endif //BRIDGESORTER_PROXY_H
