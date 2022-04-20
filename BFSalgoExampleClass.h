//
// Created by sagiv on 2/10/2022.
//

#ifndef BRIDGESORTER_BFSALGOEXAMPLECLASS_H
#define BRIDGESORTER_BFSALGOEXAMPLECLASS_H


#include <list>
#include<cstring>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
#define SPACE " "


template<class T>
class State {
public:
    T state;
    double cost;
    State<T> *cameFrom;

    State(T state) {
        this->state = state;
    }

    ~State() = default;;
};

template<class T>
class ISearchable {
public:
    virtual State<T>* getInitialState() = 0;

    virtual State<T>* getGoalState() = 0;

    virtual std::list<State<T>> getAllPossibleStates(State<T> s) = 0;

    virtual ~ISearchable() = default;
};

class EightPuzzle : public ISearchable<string> {
public:
    State<string> *eightPuzzleArr;
    State<string> *goal;

    ~EightPuzzle() override = default;

    EightPuzzle(State<string> *eightPuzzleArr, State<string> *goal) : ISearchable<string>() {
        this->eightPuzzleArr = eightPuzzleArr;
        this->goal = goal;
    };

    State<string>* getInitialState() override {
        return eightPuzzleArr;
    }

    State<std::string>* getGoalState() override {
        return goal;
    }

    list<State<string>> getAllPossibleStates(State<std::string> s) override {
        auto *newList = new list<State<string>>;
        string tempLeft = s.state;
        string tempRight = s.state;
        string tempAbove = s.state;
        string tempUnder = s.state;
        string charToReplace;
        int spaceIndex = s.state.find(SPACE);
        int changeIndex = spaceIndex;
        cout << spaceIndex << endl;

        //left
        if (spaceIndex != 0 && spaceIndex != 3 && spaceIndex != 6) {
            changeIndex--;
            tempLeft.replace(changeIndex, 1, SPACE);
            charToReplace = s.state[changeIndex];
            tempLeft.replace(spaceIndex, 1, charToReplace);
            newList->push_back(tempLeft);
        }
        //right
        if (spaceIndex != 2 && spaceIndex != 5 && spaceIndex != 8) {
            changeIndex++;
            tempRight.replace(changeIndex, 1, SPACE);
            charToReplace = s.state[changeIndex];
            tempRight.replace(spaceIndex, 1, charToReplace);
            newList->push_back(tempRight);
        }
        //above
        if (spaceIndex + 3 <= 8) {
            changeIndex += 3;
            tempAbove.replace(changeIndex, 1, SPACE);
            charToReplace = s.state[changeIndex];
            tempAbove.replace(spaceIndex, 1, charToReplace);
            newList->push_back(tempAbove);
        }
        //under
        if (spaceIndex - 3 >= 0) {
            changeIndex -= 3;
            tempUnder.replace(changeIndex, 1, SPACE);
            charToReplace = s.state[changeIndex];
            tempUnder.replace(spaceIndex, 1, charToReplace);
            newList->push_back(tempUnder);
        }

        return *newList;
    }

};

template<class T>
class ISearcher {
private:
    priority_queue<State<T>*> openList;
    int evaluatedNodes;
protected:
    State<T> *popOpenList() {
        this->evaluatedNodes++;
        return openList.pop();
    }
public:
    ISearchable<T> *s;

    ISearcher() {
        this->evaluatedNodes = 0;

    };

    virtual ~ISearcher() = default;



    virtual int getNumberOfNodesEvaluated() {
        return this->evaluatedNodes;
    };

    int OpenListSize() {
        return this->openList.size();
    }
    void addToOpenList(State<T>* s){
        this->openList.push(s);
    }

//    virtual list<State<T>> search(ISearchable<T> *searchable) {
//        addToOpenList(searchable->getInitialState());
//        list<State<T>*>* closed = new list<State<T>*>;
//        while(OpenListSize()>0){
//            State<T>* n = popOpenList();
//            closed->push_back(n);
//            if(n == searchable->getGoalState()){
//                some func
//            }
//        }
//    }
};

template<class T>
class algoBFS : public ISearcher<T> {
public:
    algoBFS<T> *s;

    algoBFS() : ISearcher<T>() {}

    ~algoBFS() override = default;

};


void print(list<State<string>> const &list) {
    for (auto const &i: list) {
        std::cout << i.state << std::endl;
    }
}

void runBFS(){
    State<std::string> *a = new State<std::string>("1234 5678");
    State<std::string> *b = new State<std::string>("B");
    State<std::string> *goal = new State<std::string>(" 12345678");
    ISearchable<string> *searchable = new EightPuzzle(a, goal);
    list<State<string>> l = searchable->getAllPossibleStates((basic_string<char>) "1234 5678");
    print(l);
    ISearcher<string> *searcher = new algoBFS<string>;
    //the solution
//    list<State<string>> solution = searcher->search(searchable);
//    int n = searcher->getNumberOfNodesEvaluated();


    delete (a);
    delete (b);
    delete (goal);
    delete (searchable);
    delete (searcher);
}
#endif //BRIDGESORTER_BFSALGOEXAMPLECLASS_H
