#include <iostream>
#include <mysql.h>
using namespace std;

int main()
{
    MYSQL *connection;
    connection = mysql_init(0);

    if (connection == nullptr)
    {
        cerr << "failed to initialize mysql" << endl;
        return 1;
    }

    connection = mysql_real_connect(connection, "localhost", "root", "Deepu@8686", "db1", 3306, NULL, 0);
    if (connection)
    {
        string insert_query = "INSERT INTO student VALUES(1,'sumadeep',22,75)";
        int query_state = mysql_query(connection, insert_query.c_str());

        if (query_state != 0)
        {
            cerr << "insert query failed" << endl;
        }

        string update_query = "UPDATE student SET s_grade=88 WHERE s_id=1";
        query_state = mysql_query(connection, update_query.c_str());

        if (query_state != 0)
        {
            cerr << "update query failed" << endl;
        }

        string delete_query = "DELETE FROM student WHERE s_id=4";
        query_state = mysql_query(connection, delete_query.c_str());

        if (query_state != 0)
        {
            cerr << "delete query failed" << endl;
        }

        string select_query = "SELECT * FROM student";
        query_state = mysql_query(connection, select_query.c_str());

        if (query_state == 0)
        {
            MYSQL_RES *result = mysql_store_result(connection);

            if (result)
            {
                while (MYSQL_ROW row = mysql_fetch_row(result))
                {
                    cout << row[0] << " " << row[1] << " " << row[2] << " " << row[3] << endl;
                }
                mysql_free_result(result);
            }
            else
            {
                cerr << "failed to store the result" << endl;
            }
        }
        else
        {
            cerr << "select query failed" << endl;
        }

        mysql_close(connection);
        return 0;
    }
    else
    {
        cerr << "failed to connect to the database" << endl;
        return 1;
    }
}
