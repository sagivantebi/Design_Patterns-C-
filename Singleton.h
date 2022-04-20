//
// Created by sagiv on 2/11/2022.
//

#ifndef BRIDGESORTER_SINGLETON_H
#define BRIDGESORTER_SINGLETON_H
#include <string>
#include <iostream>
class Zlatan {
public:
    static Zlatan &getZlatan();

private:
    Zlatan() {std::cout << "HI IM THE ONE AND ONLY ZLATAN IBRAHIMOVIC'!" << std::endl;}
    Zlatan(const Zlatan&);
    const Zlatan& operator=(const Zlatan&);
    ~Zlatan(){}
};
Zlatan &Zlatan::getZlatan() {
    //can lock it with mutex.
    static Zlatan zlatan;
    return zlatan;

}

void runSingletonZlatan(){
    Zlatan &z = Zlatan::getZlatan();
    Zlatan &z2 = Zlatan::getZlatan();
}


#endif //BRIDGESORTER_SINGLETON_H
