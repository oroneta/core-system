'''
 Tester
'''

import requests, json, os, sys, time, random
from dotenv import dotenv_values

import psycopg2
from psycopg2 import OperationalError
'''

    Common functions

'''
def log(message : str) -> None:
    sys.stderr.write(message + "\n")

def printHelp() -> None:
    # Print in error stream
    log("Usage: python3 pytester.py <option>")
    log("Options:")
    log("\t1 - Services connection test")
    log("\t2 - Database connection test")

if __name__ == '__main__':
    
    if len(sys.argv) < 2:
        printHelp()
        sys.exit(1)

    # import .env file from ../docker/.env
    env = dotenv_values("../docker/.env")

    if sys.argv[1] == '1':
        flag = False
        # Test API connection
        log("Testing API connection")
        log("----")
        log("1. Testing deauth [No data]")
        try:
            response = requests.post(f"http://localhost:{env.get('API_PORT')}/0")
            if response.status_code == 200:
                log("Unexpected response, got 200 but expected 404")
                log("Test failed")
                flag = True
            else:
                log("Test passed")
        except requests.exceptions.RequestException as e:
            log(f"The error '{e}' occurred")
            print('1')
            sys.exit(1)

        log("----")
        log("2. Testing auth [No data]")
        try:
            response = requests.post(f"http://localhost:{env.get('API_PORT')}/0", 
                                    headers={
                                            "Authorization": f"Bearer 0"
                                    })
            if response.status_code == 404:
                log("Unexpected response, got 404 but expected 200")
                log("Test failed")
                flag = True
            else:
                log("Test passed")
        except requests.exceptions.RequestException as e:
            log(f"The error '{e}' occurred")
            print('1')
            sys.exit(1)

        log("----")
        log("3. Testing with data")
        try:
            response = requests.post(f"http://localhost:{env.get('API_PORT')}/0", 
                                    headers={
                                            "Authorization": f"Bearer 0"
                                    },
                                    json={
                                        "type": "waypoint",
                                        "coord": [[0, 0]]
                                    })
            if response.status_code == 404:
                log("Unexpected response, got 404 but expected 200")
                log("Test failed")
                flag = True
            else:
                log("Test passed")
        except requests.exceptions.RequestException as e:
            log(f"The error '{e}' occurred")
            print('1')
            sys.exit(1)


        log("----")
        log("Test finished")
        if flag == True:
            log("Test failed")
            print("1")
            sys.exit(1)
        
        print("0")
        sys.exit(0)

    elif sys.argv[1] == '2':
        # Test PostgreSQL conenction
        log("Testing PostgreSQL connection")
        conn = None
        try:
            conn = psycopg2.connect(
                database=env.get("PG_DBNAME"),
                user=env.get("PG_DBUSER"),
                password=env.get("PG_DBPASS"),
                host="localhost",
                port=env.get("PG_DBPORT"),
            )
            log("Connection established")
            print('0')
            sys.exit(0)
        except OperationalError as e:
            log(f"The error '{e}' occurred")
            print('1')
            sys.exit(1)
    else:
        print("Invalid option\n")
        printHelp()
        sys.exit(1)