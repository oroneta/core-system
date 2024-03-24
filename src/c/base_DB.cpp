#include <iostream>
#include <cstdlib>
#include <pqxx/pqxx>

using namespace std;

void DB_connection(const string& ip, int port, const string& user, const string& password) {
    try {
        string conn_str = "dbname = " +  getenv(PG_DBNAME) +  " user = " + user + 
                                " password = " + password + " hostaddr = " + ip + 
                                " port = " + to_string(port);
        connection c(conn_str);
        
        if (c.is_open()) {
            cout << "Opened database successfully" << endl;
        } else {
            cout << "Can't open database" << endl;
        }
    } catch (const std::exception &e) {
        cerr << e.what() << endl;
    }
}



