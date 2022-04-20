//
// Created by sagiv on 2/9/2022.
//

#ifndef BRIDGESORTER_BRIDGE_SORTER_H
#define BRIDGESORTER_BRIDGE_SORTER_H
#define ARR_SIZE 10
#include <iostream>
class Comparator {
public:
    Comparator() {}
    virtual ~Comparator(){}
    virtual bool operator()(int x, int y) const = 0;
};

class normalComp : public Comparator {
public:

    virtual bool operator()(int x, int y) const override {
        return x > y;
    }
    virtual ~normalComp(){}
};

class reverseComp : public Comparator{
public:
    virtual ~reverseComp(){}
    virtual bool operator()(int x, int y) const override {
        return x < y;
    }
};

class Sorter {
public:
    Sorter() {}
    virtual ~Sorter(){}
    virtual void sort(int (&arr)[ARR_SIZE], Comparator *c) const = 0;
    void printArray(int (&arr)[ARR_SIZE]){
        for (int i = 0; i < ARR_SIZE; ++i) {
            std::cout << arr[i] << '\t';
        }
        std::cout <<'\n';
    }
};

class BubbleSorter : public Sorter {
public:
    BubbleSorter() : Sorter() {}
    virtual ~BubbleSorter(){}
    void swap(int *xp, int *yp) const {
        int temp = *xp;
        *xp = *yp;
        *yp = temp;
    }

    virtual void sort(int (&arr)[ARR_SIZE], Comparator *c) const override {

        int length = sizeof(arr) / sizeof(arr[0]);
        int i, j;
        for (i = 0; i < length - 1; i++)
            // Last i elements are already in place
            for (j = 0; j < length - i - 1; j++)
                if (c->(arr[j], arr[j + 1]))
                    swap(&arr[j], &arr[j + 1]);
    }
};
void run_Bridge_sorter() {
    int arr[ARR_SIZE] = {9, 6, 5, 4, 2, 3, 1, 7, 8, 0};
    Comparator *c1 = new normalComp();
    Comparator *c2 = new reverseComp();
    Sorter *s = new BubbleSorter();
    std::cout << "before sort" << std::endl;
    s->printArray(arr);
    s->sort(arr, c1);
    std::cout << "first sort output (normal)" << std::endl;
    s->printArray(arr);
    s->sort(arr, c2);
    std::cout << "second sort output (reverse)" << std::endl;
    s->printArray(arr);
    delete (c1);
    delete (c2);
    delete (s);
}
#endif //BRIDGESORTER_BRIDGE_SORTER_H

