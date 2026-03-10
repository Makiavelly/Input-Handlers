#include <iostream>
#include "res.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Russian");
    check_num_arg(argc);
    ex(Type_conversion<short>(argv[1]), Type_conversion<unsigned long long>(argv[2]), Type_conversion<short>(argv[3]), Type_conversion<short>(argv[4]));
}
