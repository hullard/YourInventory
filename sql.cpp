#include "sql.h"

SQL::SQL(const sql::SQLString& userName, const sql::SQLString& password)
{
    try
    {
        // Create a connection
        sql::Driver* driver = get_driver_instance();
        connection = driver->connect("tcp://127.0.0.1:3306", userName, password);

        // Connect to the MySQL office database
        connection->setSchema("office");
    }
    catch (sql::SQLException &e)
    {
      std::cout << "# ERR: SQLException in " << __FILE__;
      std::cout << "(" << __FUNCTION__ << ") on line "  << __LINE__ << std::endl;
      std::cout << "# ERR: " << e.what();
      std::cout << " (MySQL error code: " << e.getErrorCode();
      std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
    }
}

SQL::SQL(const sql::SQLString& hostName, const sql::SQLString& userName, const sql::SQLString& password, const sql::SQLString& schema)
{
    try
    {
        // connection properties
        properties["hostName"]      = hostName;
        properties["userName"]      = userName;
        properties["password"]      = password;
        properties["schema"]        = schema;
        properties["port"]          = 3306;
        properties["OPT_RECONNECT"] = true;

        // Create a connection
        sql::Driver* driver = get_driver_instance();
        connection = driver->connect(properties);
    }
    catch (sql::SQLException &e)
    {
      std::cout << "# ERR: SQLException in " << __FILE__;
      std::cout << "(" << __FUNCTION__ << ") on line "  << __LINE__ << std::endl;
      std::cout << "# ERR: " << e.what();
      std::cout << " (MySQL error code: " << e.getErrorCode();
      std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
    }
}

SQL::~SQL()
{
    delete connection;
}
