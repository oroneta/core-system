#ifndef _BaseDB_H_
#define _BaseDB_H_

#include <iostream>
#include <cstdlib>
#include <string>
#include <pqxx/pqxx>

pqxx::connection DB_connection(const char* ip, int port, const char* user, const char* password);


// bool checkDic(const std::string& dic);

// bool checkAuthCode(const std::string& dic, const std::string& authCode);

// void insert(const std::string& dic , const std::string& ReqBody);

// bool checkCoord(float latitude, float longitude);

#endif