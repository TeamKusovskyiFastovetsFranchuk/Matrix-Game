#include "task_321_340.h"

uint32_t setBit(uint32_t source, int n, bool state);
bool getBit(uint32_t source, int n);

std::string task_321_340(const std::string& str)
{
    uint32_t value = static_cast<uint32_t>(std::stoul(str));
    uint32_t tmp = value;

    value = setBit(value, 0, getBit(tmp, 1));
    value = setBit(value, 1, getBit(tmp, 0));
    value = setBit(value, 2, getBit(tmp, 3));
    value = setBit(value, 3, getBit(tmp, 2));

    return std::to_string(value);
}


uint32_t setBit(uint32_t source, int n, bool state)
{
    if (state) {
        source |= (1 << n);
    }
    else {
        source &= ~(1 << n);
    }
    return source;
}

bool getBit(uint32_t source, int n)
{
    return source & (1 << n);
}
