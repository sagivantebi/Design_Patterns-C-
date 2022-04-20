//
// Created by sagiv on 2/11/2022.
//

#ifndef BRIDGESORTER_BUILDERROBOT_H
#define BRIDGESORTER_BUILDERROBOT_H

#include <string>
#include <iostream>

class Robot {
    std::string name;
    int id;
    double mass;
    bool flyable;

public:
    void speak() {

    }
//inside the Robot class
public:
    class RobotBuilder {

        std::string name;
        int id;
        double mass;
        bool flyable;
    public:
        RobotBuilder(std::string name, int id) {
            this->name = name;
            this->id = id;
        }

        void setMass(double d) {
            this->mass = d;
        }

        void setFlyable(bool b) {
            this->flyable = b;
        }

        Robot *build() {
            return new Robot(*this);
        }

        std::string getName() const {
            return this->name;
        }

        int getID() const {
            return this->id;
        }

        double getMass() const {
            return this->mass;
        }

        bool getFlyable() const {
            return this->flyable;
        }

        void speak() const {
            std::cout << "hi my name is: " << this->name << " and my ROBOT ID is: " << this->id;
            if (this->mass) {
                std::cout << "\tmy mass is:" << this->getMass();
            }
            if (this->flyable == true) {
                std::cout << "\tI am flyAble";
            }
            std::cout << "\n";

        }
    };

private:
    Robot(RobotBuilder rb) {
        this->name = rb.getName();
        this->id = rb.getID();
        this->mass = rb.getMass();
        this->flyable = rb.getFlyable();
    }


};

void runBuilder() {
    Robot::RobotBuilder *r1 = new Robot::RobotBuilder("r1", 1);
    r1->setMass(1.5);
    r1->build();
    r1->speak();
    Robot::RobotBuilder *r2 = new Robot::RobotBuilder("r2", 2);
    r2->setFlyable(true);
    r2->build();
    r2->speak();
    delete(r1);
    delete(r2);
}


#endif //BRIDGESORTER_BUILDERROBOT_H
