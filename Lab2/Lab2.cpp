// Lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "methods.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


int main()
{   
    PhoneData phoneCall;
    int choice;
    do {
        cout << "1)Create record" << endl << "2)Read records" << endl << "3)Delete records" << endl << "4)Delete file" <<endl << "0)Quit" << endl;
        cin >> choice;
        if (choice == 1) {
            int inp_choice;
            do {
                cout << "1) Create new record" << endl << "0) Back" << endl;
                cin >> inp_choice;

                if (inp_choice == 1) {
                    inputPhoneData(phoneCall);//введення даних
                    makePrice(phoneCall);//розрахунок ціни
                    if (!isEmpty()) {//якщо файл існує і не пустий
                        writeCall(phoneCall, PhoneDataRecordType::APPEND);//запис даних, добавляючи
                        cout << "Record writed successfully" << endl;
                    }
                    else {
                        writeCall(phoneCall, PhoneDataRecordType::REWRITE);//перезапис даних
                        cout << "File created successfully" << endl;
                        cout << "Record writed successfully" << endl;
                    }
                }
            } while (inp_choice != 0);
        }
        else if (choice == 2) {
            readCall(phoneCall);//Зчитування даних
        }
        else if (choice == 3) {
            if (!isEmpty()) {
                deleteCall(phoneCall);//Видалення записів, розмови яких менше 3 хвилин
                cout << "Successfully deleted calls < 3 minutes" << endl;
            }
            else cout << "File is empty or file doesn't exist" << endl;
        }
        else if (choice == 4) { //Видалення файлу
            if (!isEmpty()) {
                remove("output.dat");
                cout << "File deleted successfully" << endl;
            }
            else cout << "File doesn't exist!" << endl;
        }
    } while (choice != 0);
    
    
    
    
   


    


  
}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
