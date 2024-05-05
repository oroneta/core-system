#ifndef _BaseDB_H_
#define _BaseDB_H_

#include <stdio.h>
#include <cstdlib>
#include <libpq-fe.h>
#include <cstring>

/*!
 * \brief Establishes a connection to the database.
 * \param user : The username for the databse.
 * \param password : The password for the database.
 * 
 * \return A pointer to the connection.
 */
PGconn* DB_connection(const char* user, const char* password);

/*!
 * \brief Checks if a drone exists in the database.
 * \param conn : The database connection.
 * \param dic : The drone identifier code.
 * 
 * \return True if the drone exists, false otherwise.
 */
bool checkDic(PGconn* conn, const char* dic);

/*!
 * \brief Inserts a new route into the database.
 * \param conn : The database connection.
 * \param dic : The drone identification code.
 * \param auth_code : The authentication code for the drone.
 * \param route : The route to insert. The route should be a string with the format: "[[x0,y0],[x1,y1],...]".
 */
void insertRoute(PGconn* conn, const char* dic, const char* auth_code, const char* route);

/*!
 * \brief Checks if the authorization code for a drone is valid.
 * \param dic : The drone identifier code.
 * \param authCode : The authentication code to check.
 * 
 * \return True if the authentication code is correct, false otherwise.
 */
bool checkAuthCode(PGconn* conn, const char* dic, const char* authCode);

/*!
 * \brief Checks for collisions on a given route.
 * \param route : The route to check for collisions. The route should be a string with the format: "[[x0,y0],[x1,y1],...]".
 * 
 * \return The number of potential collisions on the route.
 */
int checkColissions(PGconn* conn, const char* route);

#endif