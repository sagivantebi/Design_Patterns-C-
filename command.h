//
// Created by sagiv on 2/13/2022.
//

#ifndef BRIDGESORTER_COMMAND_H
#define BRIDGESORTER_COMMAND_H

#include <iostream>
//the command interface
class Command{
public:
    virtual void execute() = 0;
};

//the invoker
class Switch {
    Command* flipUpCommand;
    Command* flipDownCommand;

public:
    Switch(Command* flipUp,Command* flipDown){
        this->flipDownCommand = flipDown;
        this->flipUpCommand = flipUp;
    }
    void flipUp(){
        this->flipUpCommand->execute();
    }
    void flipDown(){
        this->flipDownCommand->execute();
    }
};


//receiver class
class Light{
public:
    Light(){}
    void turnOn(){
        std::cout<<"The light is on"<<std::endl;
    }

    void turnOff(){
        std::cout<<"The light is off"<<std::endl;
    }
};


//concrete command 1
class FlipUpCommand:public Command{
private:
    Light *light;
public:
    FlipUpCommand(Light* l){
        this->light = l;
    }
    void execute(){
        this->light->turnOn();
    }

};


//concrete command 2
class FlipDownCommand:public Command{
private:
    Light *light;
public:
    FlipDownCommand(Light* l){
        this->light = l;
    }
    void execute(){
        this->light->turnOff();
    }

};

void pressSwitch() {
    Light *lamp = new Light();
    Command *turnUp = new FlipUpCommand(lamp);
    Command *turnDown = new FlipDownCommand(lamp);
    Switch *s = new Switch(turnUp, turnDown);
    s->flipUp();
    s->flipDown();
    delete (s);
    delete (turnDown);
    delete (turnDown);
    delete (lamp);
}
#endif //BRIDGESORTER_COMMAND_H
