#include "task_301_320.h"
#include <bitset>


std::string task_301_320(const std::string& str)
{
    uint32_t value = static_cast<uint32_t>(std::stoul(str));

    std::bitset<32> bits(value);
    std::bitset<32> out;

    for (size_t i = 0; i < 32; i++) {
        out.set(i, bits[31 - i]);
    }
    
    return std::to_string(out.to_ulong());
}
