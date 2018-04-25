#include "task_301_320.h"


std::string task_301_320(const std::string& str)
{
    unsigned __int32 value = static_cast<unsigned __int32>(std::stoul(str));
    value = ~value;
    return std::to_string(value);
}
