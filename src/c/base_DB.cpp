#include <iostream>
#include <cstdlib>
#include <string>
#include <libpq-fe.h>


using namespace std;

pqxx::connection DB_connection(const char* ip, int port, const char* user, const char* password) {
    pqxx::connection C;
    try {
        // char* dbname = "core-system.postgres";
        // string conn_str = "dbname = " +  dbname +  " user = " + user + 
        //                         " password = " + password + " hostaddr = " + ip + 
        //                         " port = " + to_string(port);
        string conn_str = "dbname=core-system.postgres user=Oroneta_Admin password=Oroneta_Password hostaddr=127.0.0.1 port=5432";
        C = pqxx::connection(conn_str);
        
        if (C.is_open()) {
            cout << "Opened database successfully" << endl;
        } else {
            cout << "Can't open database" << endl;
        }
    } catch (const std::exception &e) {
        cerr << e.what() << endl;
    }
    return C;
}

//check if drone dic exist in postgres
bool checkDic(const std::string& dic) {
    
    // return true if dic exists in DB
    
    return true;
}

//check if dic and auth-code match
bool checkAuthCode(const std::string& dic, const std::string& authCode) {
   return true;
}

//insert route
void insert(const std::string& dic, const std::string& ReqBody){

    try
    {
        
    }
    catch(const std::exception& e)
    {
        
    }
    
}

// check if route exists

/*
comprobar si existen coordenadas en la bbdd
sera un metodo tipo check(latitude,longitude), que son 2 floats
*/

bool checkCoordinates(float latitude, float longitude) {

    return false;
}