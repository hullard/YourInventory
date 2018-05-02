/* Standard C++ includes */
#include <stdlib.h>
#include <iostream>

#include "sql.h"

int main()
{
    // new instance of SQL class to initiate connection
    SQL* Sql = new SQL("inventory", "1234");

    // insert new entry to "employe" table
    employe_t employe1;
    employe1.firstName  = "Janos";
    employe1.lastName   = "Nagy";
    employe1.sex        =  1;

    Sql->addEmploye(employe1);

    // insert new entry to "computer" table
    computer_t computer1;
    computer1.name          = "OFFICE01";
    computer1.type          = "desktop";
    computer1.vendor        = "ASUS";
    computer1.cpu           = "Intel Core i5-4570";
    computer1.purchaseDate  = "2017-03-22";
    computer1.warranty      = 3;

    Sql->addComputer(computer1);

    std::cout << "Two entries added to Inventory" << std::endl;

    return 0;
}
