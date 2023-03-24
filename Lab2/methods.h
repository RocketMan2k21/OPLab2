#include "structures.h"
#include <string>

void inputPhoneData(PhoneData& arr);
  
int timeFind(std::string time);

void makePrice(PhoneData & data);
  
void deleteCall(PhoneData & data);

void writeCall(PhoneData& data, PhoneDataRecordType record_type);

void readCall(PhoneData & data);
  
bool isEmpty();
