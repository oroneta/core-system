#ifndef _BaseDB_H_
#define _BaseDB_H_

#include <iostream>
#include <cstdlib>
#include <pqxx/pqxx>

void DB_connection(const string& ip, int port, const string& user, const string& password);

#endif