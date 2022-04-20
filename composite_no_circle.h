//
// Created by sagiv on 2/10/2022.
//

#ifndef BRIDGESORTER_COMPOSITE_NO_CIRCLE_H
#define BRIDGESORTER_COMPOSITE_NO_CIRCLE_H

#include <iostream>
#include <algorithm>
#include "list"

using namespace std;

class CycleException {/*...*/};

class Employee {
public:
    virtual void print() {
        std::cout << "Employee" << endl;
    }

    virtual ~Employee() {}
};

class Engineer : public Employee {
public:
    virtual void print() {
        cout << "Engineer" << endl;
    }
};

list<Employee *> hasAManager;

class Manager : public Employee {
    list<Employee *> emps;
public:
    virtual void print() {
        cout << "Manager" << endl;
    }

    void addEmployee(Employee *emp) {
        if (find(emp) || findMe(emp))
            throw CycleException();
        emps.push_back(emp);
        hasAManager.push_back(emp);
    }

    virtual ~Manager() {
        for_each(emps.begin(), emps.end(), [](Employee *e) { delete e; });
    }

private:
    bool find(Employee *e) {
        list<Employee *>::iterator it = hasAManager.begin();
        while (it != hasAManager.end()) {
            if (e == *it)
                return true;
            it++;
        }
        return false;
    }

    bool findMe(Employee *e) {
        if (this == e)
            return true;
        Manager *m = dynamic_cast<Manager *>(e);
        if (m) {
            list<Employee *>::iterator it = m->emps.begin();
            while (it != m->emps.end()) {
                if (findMe(*it))
                    return true;
                it++;
            }
        }
        return false;
    }
};

#endif //BRIDGESORTER_COMPOSITE_NO_CIRCLE_H
