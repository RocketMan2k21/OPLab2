#include "methods.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

void inputPhoneData(PhoneData& arr) { //введення даних
    cout << "Phone number: ";
    cin >> arr.ph_num;
    cout << "Time, when phone call started:";
    cin >> arr.start_call;
    cout << "Time, when call ended: ";
    cin >> arr.end_call;

}
int timeFind(string time) { //перетворення часу в хвилини
    int colon_position = time.find(":");
    string hours_str = time.substr(0, colon_position);
    string minutes_str = time.substr(colon_position + 1);

    int hours = stoi(hours_str);
    int minutes = stoi(minutes_str);

    return hours * 60 + minutes;
}
void makePrice(PhoneData& data) { //розрахунок ціни за дзвінок
    int phoneTime = timeFind(data.end_call) - timeFind(data.start_call);
    if (timeFind(data.start_call) > 540 && timeFind(data.end_call) < 1200) {
        data.call_price = phoneTime * 1.5;
    }
    else data.call_price = phoneTime * 0.9;
}

void deleteCall(PhoneData& data) { //Видалення запису, дзвінки яких менше 3 хвилин
    ifstream readF("output.dat", ios::in | ios::binary);
    ofstream writeF("temp.dat", ios::app | ios::binary);
    readF.read((char*)&data, sizeof(PhoneData));
    while (!readF.eof()) {
        int phoneTime = timeFind(data.end_call) - timeFind(data.start_call);
        if (phoneTime > 3) writeF.write((char*)&data, sizeof(PhoneData));
        readF.read((char*)&data, sizeof(PhoneData));
    }
    readF.close();
    writeF.close();
    remove("output.dat");
    rename("temp.dat", "output.dat");
}
void writeCall(PhoneData& data, PhoneDataRecordType record_type) { //Запис структури у файл
    string file_name = "output.dat";

    if (record_type == PhoneDataRecordType::REWRITE)
    {
        ofstream file(file_name, ios::out | ios::binary);
        file.write((char*)&data, sizeof(PhoneData));
        file.close();
    }
    else if (record_type == PhoneDataRecordType::APPEND)
    {
        ofstream file(file_name, ios::app | ios::binary);
        file.write((char*)&data, sizeof(PhoneData));
        file.close();
    }
}
void readCall(PhoneData& data) { //Считування даних з файлу
    ifstream file("output.dat", ios::in | ios::binary);
    if (!file.is_open()) cout << "Error opening file, or file doesn't exist!" << endl;
    file.read((char*)&data, sizeof(PhoneData));
    while (!file.eof() && file.is_open()) {
        cout << "Phone number: " << data.ph_num << endl;
        cout << "Start T: " << data.start_call << " " << "End T: " << data.end_call << endl;
        cout << "Price: " << data.call_price << endl;
        file.read((char*)&data, sizeof(PhoneData));
    }
    file.close();
}
bool isEmpty() //Перевірка файлу на заповненість
{
    ifstream file("output.dat");
    return file.peek() == std::ifstream::traits_type::eof();
}