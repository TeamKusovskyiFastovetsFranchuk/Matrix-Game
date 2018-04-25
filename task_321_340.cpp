#include "task_321_340.h"

std::string task_321_340(const std::string& str)
{
    uint32_t value = static_cast<uint32_t>(std::stoul(str));
    uint32_t tmp = value;

    char* byte_value = reinterpret_cast<char*>(&value);
    char* byte_tmp = reinterpret_cast<char*>(&tmp);

    byte_value[0] = byte_tmp[1];
    byte_value[1] = byte_tmp[0];
    byte_value[2] = byte_tmp[3];
    byte_value[3] = byte_tmp[2];

    return std::to_string(value);
}
