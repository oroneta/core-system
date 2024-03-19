#include <crow.h>
#include <iostream>

// Dependencies
#include "base_ServerComm.h"


int main(){
    //Create Crow Server
    crow::SimpleApp DroneSystem;

    //Handle the POST request to verify the route
    CROW_ROUTE(DroneSystem, "/route/<dic>").methods(crow::HTTPMethod::"POST"_method)([&](const crow::request &req, string dic) {

    //Get auth-code from the header
    //get_header_value is predefined in crow (http_response.h)
    string authCode = req.get_header_value("Authorization");

    //If auth-code is missing, return unauthorized
    if(authCode.empty()){
        return crow::response(401,"No autorizado");
    }

    //If the drone is not registered in the database, return 404 (drone does not exist)
        //Missing method to check if the record exists in PostgreSQL
    if(!checkDic(dic)){
        return crow::response(404,"No existe el dron");
    } 

    //Verify if the auth-code matches with the drone's

    if (!checkAuthCode(dic, authCode)) {
            return crow::response(401, "Auth-code no coincide con el del dron");
        }

    // If the drone exists, obtain the request body req
    string requestBody = req.body;

    //Check the level of danger

    //g

    //FOR NOW, always return an HTTP 200 to test the server
    json responseJson;
    responseJson["status"] = 1;
    responseJson["dangerous_level"] = 1;
    responseJson["message"] = "Route registered";

    return crow::response(200, responseJon.dump());

    });


    //Start the server on port 60000
    app.port(60000).multithreaded().run();

}