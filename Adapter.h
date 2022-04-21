//
// Created by sagiv on 2/10/2022.
//



class AdapterTask {
    virtual void doTask() = 0;
};

class AdapteeSorter {

};

class BSorter : public AdapteeSorter {
    BSorter() : AdapteeSorter() {}

};

//and now for the BIG implementation!
class sorterTask : public AdapterTask {
    AdapteeSorter *mySorter;

    sorterTask() : AdapterTask() {}

};


