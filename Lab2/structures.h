#include <string>

//структура телефонної розмови
struct PhoneData
{
    std::string ph_num;
    std::string start_call;
    std::string end_call;
    double call_price;
};
//для вибору типу запису у файл при виклику функції
enum class PhoneDataRecordType
{
    REWRITE,
    APPEND
};