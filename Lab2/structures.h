#include <string>

//��������� ��������� �������
struct PhoneData
{
    std::string ph_num;
    std::string start_call;
    std::string end_call;
    double call_price;
};
//��� ������ ���� ������ � ���� ��� ������� �������
enum class PhoneDataRecordType
{
    REWRITE,
    APPEND
};