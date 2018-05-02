#ifndef SQL_H
#define SQL_H

#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

class SQL
{
public:
    SQL(const sql::SQLString& userName, const sql::SQLString& password);
    SQL(const sql::SQLString& hostName, const sql::SQLString& userName, const sql::SQLString& password, const sql::SQLString& schema);

    virtual ~SQL();

protected:

private:
    sql::Connection* connection;
    sql::ConnectOptionsMap properties;
};

#endif // SQL_H
