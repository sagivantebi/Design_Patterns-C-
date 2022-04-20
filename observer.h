//
// Created by sagiv on 2/13/2022.
//

#ifndef BRIDGESORTER_OBSERVER_H
#define BRIDGESORTER_OBSERVER_H

#include <iostream>
#include <iterator>
#include <list>
using namespace std;
class Observable;

class Observer {
public:
    virtual void Update(const std::string &message_from_subject) = 0;
};

class Observable {
public:
    virtual ~Observable()= default;

    virtual void addOb(Observer* o) = 0;

    virtual void removeOb(Observer* o) = 0;

    virtual void notify() = 0;
};

class NetaElChamister : public Observable {
private:
    std::list<Observer*> l;
    std::string massage;
public:
    ~NetaElChamister() override{
        std::cout<<"Bye lovers - I have been Neta"<<std::endl;
    }
    void addOb(Observer* o) override{
        this->l.push_back(o);
    }
    void removeOb(Observer* o) override{
        this->l.remove(o);
    }
    void notify() override{
        std::list<Observer*>::iterator  iter = this->l.begin();
        while(iter!=l.end()){
            (*iter)->Update(this->massage);
            ++iter;
        }
    }
    void createMassage(std::string s){
        this->massage = s;
        notify();
    }
};

class HornyClient : public Observer{
private:
    std::string message_from_Neta_;
    NetaElChamister &subject_;
    int number_;
public:
    HornyClient(NetaElChamister &n, NetaElChamister &subject) : Observer(), subject_(subject) {
        this->subject_ = n;
    }
    void Update(const std::string &message_from_Neta_) override{
        this->message_from_Neta_ = message_from_Neta_;
        std::cout<<"I just got this massage:\t" << this->message_from_Neta_<<std::endl;
}
    void RemoveMeFromTheList() {
        subject_.removeOb(this);
        std::cout << "Observer \"" << number_ << "\" removed from the list.\n";
    }
};


#endif //BRIDGESORTER_OBSERVER_H
