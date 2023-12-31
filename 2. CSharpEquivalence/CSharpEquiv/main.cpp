#include "Collections.h"
#include "Casting.h"
#include "Generics.h"
#include "Lambdas.h"
#include "Events.h"
#include "Tuples.h"
#include "ErrorAndExceptions.h"
#include "OOP.h"
#include <QCoreApplication>
#include <QTimer>
#include <QDebug> //required for qInfo() command;
#include <iostream> //required for input output
#include <thread>
#include <QThread>

void PrintMenu(){
    QTextStream qin(stdin);
    QTextStream qout(stdout);
    QString menu = "\n Menu: "
                   "\n 0. Exit "
                   "\n 1. Lambdas, Actions and Funcs"
                   "\n 2. Events"
                   "\n 3. Tuples"
                   "\n 4. OOP"
                   "\n 5. Collections"
                   "\n 6. Casting"
                   "\n 7. Try Catch and Exception Handling"
                   "\n 8. Generics"
                   "\n 9. Async Await"
                   "\n 10. Extension Methods"
                   "\n 11. Reflection"
                   "\n 12. Attributes"
                   "\n 13. Linq"
                   "\n Enter your Choice: \n";
    qout << menu;
    qout.flush();
}

void readInput() {
    QTextStream qin(stdin);
    QTextStream qout(stdout);
    int choice=0;
    do {
      system("cls");
      PrintMenu();
      QString input = qin.readLine();
      choice = input.toInt();
      qout << "Chosen option: " << choice;
      switch (choice) {
      case 0:
        QCoreApplication::quit();
        break;
      case 1:
        system("cls"); //cls only works on windows to clear the console
        LambdaExamples();
        break;
      case 2:
        system("cls");
        EventExample();
        break;
      case 3:
        system("cls");
        useTuple();
        break;
      case 4:
        system("cls");
        OOPExample();
        break;
      case 5:
        system("cls");
        CollectionExample();
        break;
      case 6:
        system("cls");
        RunCastingExamples();
        break;
      case 7:
        system("cls");
        ErrorAndExceptionsExample();
        break;
      case 8:
        system("cls");
        GenericsExample();
        break;
      }
      qInfo() << "Press any key to continue...";
      qin.readLine();
    } while (choice != 0);
}

/*!
 Console Program with Menu
 * \brief main
 * \param argc
 * \param argv
 * \return
 */
int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv); //this is automatically added with every new project

    std::string name; //variable definition
    qInfo("Hello, what's your name ?");
    std::cin >> name; //Reading from the terminal. Make sure the project is running in the terminal to work
    qInfo() << "Hello" << QString::fromStdString(name);
    //std::this_thread::sleep_for(std::chrono::seconds(1)); //Time Delay in C++
    QThread::sleep(1); //Time Delay using Qt

    //wanna see how a timer works ?
    QTimer::singleShot(300, &a, [](){ //miliseconds, context, lambda function
        readInput();
    });
    return a.exec();
}
