#include "task_301_320.h"


std::string task_301_320(const std::string& str)
{
    uint32_t value = static_cast<uint32_t>(std::stoul(str));
    uint32_t result = 0;

    const int COUNT_BITS_UINT32 = sizeof(uint32_t) * 8;

    for (int i = 0; i < COUNT_BITS_UINT32 / 2; i++) {
        result |= (value & (1 << i)) << (COUNT_BITS_UINT32 - 2 * i - 1);
    }
    for (int i = COUNT_BITS_UINT32 / 2; i < COUNT_BITS_UINT32 - 1; i++) {
        result |= (value & (1 << i)) >> (2 * i - COUNT_BITS_UINT32 + 1);
    }
    return std::to_string(result);
}
