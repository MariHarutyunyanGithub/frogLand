#include <chrono>
#include <iostream>

#include "God.h"
#include "frog.h"
#include "sun.h"
#include "tree.h"

///////////////////////  Frog

void Frog::wake_up()
{
    std::cout << std::endl;
    std::cout << "frog :   Good morning, I woke up, kwaaaaa, kwaaaa" << std::endl;
}

void Frog::eat()
{
    std::cout << std::endl;
    std::cout << "frog :   now I eat grass, kwaaaaaa_kwaaaaaaa" << std::endl;
}

void Frog::breathe()
{
    std::cout << std::endl;
    std::cout << "frog :   This is so fresh air, kwaaaaaaa, kwaaaaaa" << std::endl;
}

void Frog::jump()
{
    std::cout << std::endl;
    std::cout << "frog :   kwwwaaaaaa-kwaaaaa" << std::endl <<
    std::endl << "frog :   where is the grass????" << std::endl;
}

void  Frog::sleep()
{
    std::cout << std::endl;
    std::cout << "frog :   Kwaaaaa, I fell asleep, I'm going to sleep" << std::endl;
}

////////////////////////// Tree

 bool Tree::synthez_air()
 {
    std::cout << std::endl;
    std::cout << "tree :   Here is fresh air" << std::endl;
    return true;
 }

bool Tree::stop_synthesizing()
{
    std::cout << std::endl;
    std::cout << "tree :   I got tired of producing air" << std::endl;
    return true;
}

//////////////////////// Sun

bool Sun::shine()
{
    std::cout << std::endl;
    std::cout << "sun  :   Good morning everybody" << std::endl;
    return true;
}

bool Sun::stop_shine()
{   
    std::cout << std::endl;
    std::cout << "sun  :   Good night" << std::endl;
    return true;
}

///////////////// God

void God::agenda_mode()
{
    auto start = std::chrono::system_clock::now();
    Sun sun;
    Frog frog;
    Tree tree;
    if (sun.shine() && tree.synthez_air()) {
        frog.wake_up();
    }
    bool s{};
    while(((std::chrono::system_clock::now() - start).count()) / 1000000000 <= day + night) {
        if (((std::chrono::system_clock::now() - start).count()) / 1000000000 == 1) {
            if (!s) {
                frog.breathe();
                s = true;
            }
        }
        if (((std::chrono::system_clock::now() - start).count()) / 1000000000  == 2) {
            if (s) {
                frog.jump();
                s = false;
            }
        }
        if (((std::chrono::system_clock::now() - start).count()) / 1000000000  == 3) {
            if (!s) {
                frog.eat();
                s = true;
            }
        }
        if (((std::chrono::system_clock::now() - start).count()) / 1000000000  == 4) {
            if (s) {
                frog.jump();
                s = false;
            }
        }
        if (((std::chrono::system_clock::now() - start).count()) / 1000000000  == 5) {
            if (s) {
                frog.jump();
                s = false;
            }
        }
        if (((std::chrono::system_clock::now() - start).count()) / 1000000000  == 6) {
            if (!s) {
                frog.eat();
                s = true;
            }
        }
        if (((std::chrono::system_clock::now() - start).count()) / 1000000000  == day) {
            if (s) {
                if (tree.stop_synthesizing() && sun.stop_shine()) {
                    frog.sleep();
                }
                s = false;
            }
        }
        if (((std::chrono::system_clock::now() - start).count()) / 1000000000  > day &&
        ((std::chrono::system_clock::now() - start).count()) / 1000000000 < day + night ) {
            if (!s) {
                at_night();
                s = true;
            }
        }
    }
}

void God::at_night()
{
    std::cout << "ZZZ ZZZ ZZZ ZZZ ZZZ ZZZ\nZZZ ZZZ ZZZ ZZZ ZZZ ZZZ\nZZZ ZZZ ZZZ ZZZ ZZZ ZZZ " << std::endl;
}