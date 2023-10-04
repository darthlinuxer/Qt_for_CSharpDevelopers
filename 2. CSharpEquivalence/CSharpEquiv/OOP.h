#ifndef OOP_H
#define OOP_H

#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <QObject>
#include <QMetaObject>
#include <QMetaMethod>

using namespace std;

/*
 * in C++, assigning = 0 to a virtual function makes it a pure virtual function.
 * This means that the function has no implementation in the base class and must be overridden
 * by any non-abstract derived class. Making a function pure virtual also makes the class abstract,
 * meaning you cannot create an instance of it.
 * */
class IMovable {
public:
    virtual void Move() = 0;
};

class IMakeSound {
public:
    virtual void MakeSound() = 0;
};

class IAnimal: public IMovable, public IMakeSound {};
class IDestroyableAnimal: public IAnimal {
public:
    virtual ~IDestroyableAnimal() = 0;
};

class Janitor : public QObject {
    Q_OBJECT
public slots:
    void HandleAnimalEvent(string name) {
        cout << name << " event handled by Janitor." << endl;
    }
};

//abstract class Animal
class Animal : public QObject, public IAnimal {
    Q_OBJECT
private:
    string _name;
public:
    Animal(string name) : _name(name) {}
    virtual ~Animal() { cout << "Destructor called for " << _name << endl; }
    virtual void MakeSound() { cout << _name << " makes a sound." << endl; }
    virtual void Move() { cout << _name << " moves." << endl; }
    string GetName() { return _name; }
    void SetName(string name) { _name = name; }
signals:
    void AnimalEvent(string name);
};

class Dog : public Animal {
public:
    Dog(string name);
    void MakeSound() override;
    void Move() override;
};

class Cat : public Animal {
public:
    Cat(string name);
    void MakeSound() override;
    void Move() override;
};

class Horse : public IDestroyableAnimal {
private:
    string _name;
public:
    Horse(string name);
    virtual ~Horse() override;
    void MakeSound() override;
    void Move() override;
};

void OOPExample();

#endif // OOP_H
