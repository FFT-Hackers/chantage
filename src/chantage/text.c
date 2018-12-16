#include <chantage/impl.h>

void InitText(void)
{
    ReplaceFunction((void*)0x089ba694, &GetTextCompat);
    ReplaceFunction((void*)0x089bafec, &GetTextCompat);
}

const char* GetText(const char* base, uint32_t id)
{
    uint8_t c;
    for (;;)
    {
        if (id == 0)
            return base;
        c = (uint8_t)(*base++);
        if ((c & 0xfe) == 0xfe)
            id--;
    }
}

const char* GetTextCompat(const char* base, uint32_t id)
{
    uint32_t baseMagic = (uint32_t)base;

    /* Catch items */
    if (baseMagic == *(uint32_t*)(0x0974a0e0) || baseMagic == 0x08a935fd || baseMagic == 0x08b0f1a9)
    {
        return GetItemName((uint16_t)id);
    }
    else if (baseMagic == 0x08ab027b)
    {
        return GetItemDescription(id);
    }
    return GetText(base, id);
}

uint32_t GetTextLength(const char* str)
{
    uint32_t i;
    uint8_t c;

    i = 0;
    for (;;)
    {
        c = (uint8_t)(str[i]);
        if ((c & 0xfe) == 0xfe)
            return i;
        ++i;
    }
}