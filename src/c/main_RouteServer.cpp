#include <crow.h>
#include <iostream>

int main(){
    //Crear el servidor de Crow
    crow::SimpleApp droneSystem;

    //Manejar la solicitud POST para verificar la ruta
    CROW_ROUTE(droneSystem, "/route/<dic>").methods(crow::HTTPMethod::"POST"_method)([&](const crow::request &req, string dic) {

    //obtener auth-code de la cabecera
    //get_header_value esta predefinido en crow (http_response.h)
    string authCode = req.get_header_value("Authorization") 

    //si no tiene auth-code se devuelve NO authorizado
    if(authCode.empty()){
        return crow::response(401,"No autorizado")
    }

    //si el dron no esta registrado en la BBDD devuelve 404(no existe el dron)
    //falta crear el metodo que comprueba si el dic existe en postgret
    if(!checkDic(dic)){
        return crow::response(404,"No existe el dron")
    } 

    //verificar si el auth-code coincide con el del dron?



    // si existe el dron obtener el cuerpo de la solicitud req
    string requestBody = req.body;

    //comprobar el grado de peligrosidad

    //POR AHORA se va a devolver siempre un HTTP 200 para probar el server
    json responseJson;
    responseJson["status"] = 1;
    responseJson["dangerous_level"] = 1;
    responseJson["message"] = "Route registered";

    //devulvemos el 
    return crow::response(200, responseJon.dump());

    });


    //Iniciar el servidor en el puerto 60000
    app.port(60000).multithreaded().run();

}