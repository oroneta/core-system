#include <crow.h>
#include <iostream>
#include <string>
#include <json/json.h>


// Dependencies
#include "base_DB.h"

//variables
#define MAX_COLLISION 2

using namespace std;

int main(){

    //conection to the ddbb
    PGconn *conn = DB_connection("Oroneta_Admin", "Oroneta_Password");

    crow::SimpleApp DroneSystem;

    //Handle the POST request to verify the route
    CROW_ROUTE(DroneSystem, "/route/<string>").methods(crow::HTTPMethod::POST)([&conn](const crow::request &req, std::string dic) {

        //Get auth-code from the header
        //get_header_value is predefined in crow (http_response.h)
        string authCode = req.get_header_value("Authorization");

        //If auth-code is missing, return unauthorized
        if(authCode.empty()){
            return crow::response(401,"Unauthorized");
        }

        //If the drone is not registered in the database, return 404 (drone does not exist)

        if(!checkDic(conn, dic.c_str())){
            return crow::response(404,"Drone does not exist");
        }

        //Verify if the auth-code matches with the drone's

        if (!checkAuthCode(conn, dic.c_str(), authCode.c_str())) {
                return crow::response(401, "Auth-code incorrect");
            }

        // If the drone exists, obtain the request body req
        string requestBody = req.body;
        

        //Parse the Json from the request body
      
        crow::json::rvalue CoordData;
        try{
             CoordData = crow::json::load(requestBody);
        }catch(const std::exception& e){
            return crow::response(400, "Error parsing JSON");
        }

        //check if the coord filed exists
        if(!CoordData.has("coord")){
            return crow::response(400, "Empty coord field");
        }

        int collisionsCount = 0;
        
        auto coordsArray = CoordData["coord"];

        //manual conversion json to string
        ostringstream os;  
        os << "[";
        for (size_t i = 0; i < coordsArray.size(); ++i) {
            os << "[" << coordsArray[i][0].d() << "," << coordsArray[i][1].d() << "]";
            if (i < coordsArray.size() - 1) {
                os << ", ";
            }
        }
        os << "]";

        string coordsString = os.str();


        //check collisions
        collisionsCount = checkColissions(conn, coordsString.c_str());

        if(collisionsCount > MAX_COLLISION) {
            crow::json::wvalue responseJson;
            responseJson["status"] = 0;
            responseJson["message"] = "Route is very dangerous to be used";
            return crow::response(200, responseJson);
        }
        


        //Insert drone data and coordinates
        insertRoute(conn, dic.c_str(),authCode.c_str(), coordsString.c_str());
        crow::json::wvalue responseJson;
        responseJson["status"] = 1;
        //responseJson["dangerous_level"] = 1;
        responseJson["message"] = "Route registered";
        return crow::response(200, responseJson);

    });


    //Start the server on port 60000
    DroneSystem.port(60000).multithreaded().run();

    return 0;
}