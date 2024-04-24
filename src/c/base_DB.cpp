#include <stdio.h>
#include <cstdlib>
#include <libpq-fe.h>
#include <cstring>

#include "base_DB.h"

using namespace std;

void do_exit(PGconn *conn) {
    PQfinish(conn);
    exit(1);
}

PGconn* DB_connection(const char* user, const char* password) {

    char conninfo[1024];
    // memset(conninfo, '\0', sizeof(conninfo));
    snprintf(conninfo, sizeof(conninfo), "host=oroneta.core-system.postgres port=5432 dbname=core-system.postgres user=%s password=%s", user, password);

    PGconn *conn = PQconnectdb(conninfo);

    if (PQstatus(conn) !=  CONNECTION_OK) {
        fprintf(stderr, "Connection to database failed: %s\n", PQerrorMessage(conn));
    } else {
        printf("Connection to database done successfully \n");
    }

    return conn;
}

//check if drone dic exist in postgres
bool checkDic(PGconn* conn, char* dic) {
    if (PQstatus(conn) == CONNECTION_OK) {
        char query[256];
        PGresult* result;

        snprintf(query, sizeof(query), "SELECT EXISTS (SELECT 1 FROM drones WHERE dic = '%s')", dic);

        result = PQexec(conn, query);

        if (PQresultStatus(result) != PGRES_TUPLES_OK) {
            printf("Error executing query: %s\n", PQerrorMessage(conn));
            PQclear(result);
        }

        if (strcmp(PQgetvalue(result, 0, 0), "t") == 0) {
            printf("Existe\n");
            PQclear(result);
            return true;
        }
        printf("No existe\n");
    }
    return false;
}