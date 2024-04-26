#ifndef _BaseDB_H_
#define _BaseDB_H_

#include <stdio.h>
#include <cstdlib>
#include <libpq-fe.h>
#include <cstring>


PGconn* DB_connection(const char* user, const char* password);

bool checkDic(PGconn* conn, char* dic);

void insertRoute(PGconn* conn, char* dic, char* auth_code, char* route);

bool checkAuthCode(PGconn* conn, char* dic, char* authCode);

int checkColissions(PGconn* conn, char* dic, char* route);

#endif