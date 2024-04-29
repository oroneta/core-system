#ifndef _BaseDB_H_
#define _BaseDB_H_

#include <stdio.h>
#include <cstdlib>
#include <libpq-fe.h>
#include <cstring>


PGconn* DB_connection(const char* user, const char* password);

bool checkDic(PGconn* conn, const char* dic);

void insertRoute(PGconn* conn, const char* dic, const char* auth_code, const char* route);

bool checkAuthCode(PGconn* conn, const char* dic, const char* authCode);

int checkColissions(PGconn* conn, const char* dic, const char* route);

#endif