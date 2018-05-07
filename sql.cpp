#include "sql.h"

// connect to SQL server: username & password passed as parameters
SQL::SQL(const sql::SQLString& userName, const sql::SQLString& password)
{
    try
    {
        // Create a connection (object of sql::Driver will be destroyed by connector object implicitly!)
        sql::Driver* driver = get_driver_instance();
        connection = driver->connect("tcp://127.0.0.1:3306", userName, password);

        // Connect to the MySQL office database
        connection->setSchema("office");
    }
    catch (sql::SQLException &e)
    {
      std::cerr << "# ERR: SQLException in " << __FILE__;
      std::cerr << "(" << __FUNCTION__ << ") on line "  << __LINE__ << std::endl;
      std::cerr << "# ERR: " << e.what();
      std::cerr << " (MySQL error code: " << e.getErrorCode();
      std::cerr << ", SQLState: " << e.getSQLState() << " )" << std::endl;
    }
}

// connect to SQL server: hostname & username & password & schema (database) passed as parameters (constructor overloading)
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
    catch (sql::SQLException& e)
    {
      std::cerr << "# ERR: SQLException in " << __FILE__;
      std::cerr << "(" << __FUNCTION__ << ") on line "  << __LINE__ << std::endl;
      std::cerr << "# ERR: " << e.what();
      std::cerr << " (MySQL error code: " << e.getErrorCode();
      std::cerr << ", SQLState: " << e.getSQLState() << " )" << std::endl;
    }
}

// add entry to table "employe"
void SQL::addEmploye(const Employe& employe)
{
    try
    {
        // insert entry by prepared statement
        sql::PreparedStatement* pstmt;
        pstmt = connection->prepareStatement("INSERT INTO employe(first_name, last_name, sex) VALUES (?, ?, ?)");

        // all the fields of employe except id | id is AUTO_INCREMENT
        pstmt->setString(1, employe.firstName);
        pstmt->setString(2, employe.lastName);
        pstmt->setInt(3, employe.sex);

        pstmt->execute();
        delete pstmt;
    }
    catch (sql::SQLException& e)
    {
        std::cerr << "# ERR: " << e.what();
        std::cerr << "MySQL error code: " << e.getErrorCode() << std::endl;
    }
}

// add entry to table "computer"
void SQL::addComputer(const Computer& computer)
{
    try
    {
        // insert entry by prepared statement
        sql::PreparedStatement* pstmt;
        pstmt = connection->prepareStatement("INSERT INTO computer(name, type, vendor, cpu, purchase_date, warranty) VALUES (?, ?, ?, ?, ?, ?)");
        // all the fields of computer except id & employe_id | id is AUTO_INCREMENT | employe_id separately added
        pstmt->setString(1, computer.name);
        pstmt->setString(2, computer.type);
        pstmt->setString(3, computer.vendor);
        pstmt->setString(4, computer.cpu);
        pstmt->setDateTime(5, computer.purchaseDate);
        pstmt->setInt(6, computer.warranty);

        pstmt->execute();
        delete pstmt;
    }
    catch (sql::SQLException& e)
    {
        std::cerr << "# ERR: " << e.what();
        std::cerr << "MySQL error code: " << e.getErrorCode() << std::endl;
    }
}

// free up space allocated by pointers
SQL::~SQL()
{
    delete connection;

