#ifndef SQL_H
#define SQL_H

// include MySQL connector/driver headers
#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

// entity of "employe"
struct Employe
{
    std::string firstName;
    std::string lastName;
    unsigned int sex;
    /* sex code as per ISO/IEC 5218,
     0 = not known,
     1 = male,
     2 = female,
     9 = not applicable */
};

// entity of "computer"
struct Computer
{
    std::string name;
    std::string type;
    std::string vendor;
    std::string cpu;
    std::string purchaseDate;
    unsigned int warranty;
};

// SQL database handling class
class SQL
{
public:
    // connect to SQL server by contructor
    SQL(const sql::SQLString& userName, const sql::SQLString& password);

    // connect to SQL server by contructor (overloading)
    SQL(const sql::SQLString& hostName, const sql::SQLString& userName, const sql::SQLString& password, const sql::SQLString& schema);

    // add entry to table "employe"
    void addEmploye(const Employe& employe);

    // add entry to table "computer"
    void addComputer(const Computer& computer);

    // close connection by desctructor
    virtual ~SQL();

protected:

private:
    sql::Connection* connection;
    sql::ConnectOptionsMap properties;
};

#endif // SQL_H
