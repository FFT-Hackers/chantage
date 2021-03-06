#include <chantage/impl.h>
#define REGISTER(a) RegisterFunction(#a, &a)

void HookFunctions()
{
    REGISTER(LoadFunction);
    REGISTER(ReplaceFunction);
    REGISTER(RegisterFunction);

    REGISTER(GetItemData);
    REGISTER(IsItemValid);
    REGISTER(ItemCount);
    REGISTER(CreateItem);
}
