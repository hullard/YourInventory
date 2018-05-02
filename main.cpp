/* Standard C++ includes */
#include <stdlib.h>
#include <iostream>

#include "sql.h"

int main()
{
    SQL Sql("inventory", "1234");

    std::cout << "Hello Inventory" << std::endl;

    return 0;
}
