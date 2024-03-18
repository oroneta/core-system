-- Create tables
CREATE TABLE routes (
    dic VARCHAR PRIMARY KEY,
    auth_code VARCHAR,
    flight BYTEA
);

CREATE TABLE registrants (
    id VARCHAR PRIMARY KEY,
    name VARCHAR,
    country VARCHAR
);

CREATE TABLE drones (
    dic VARCHAR PRIMARY KEY,
    auth_code VARCHAR,
    registrants VARCHAR,
    owner_name VARCHAR,
    owner_identify VARCHAR,
    owner_email VARCHAR,
    registered_at TIMESTAMP,
    FOREIGN KEY (registrants) REFERENCES registrants(id)
);

ALTER TABLE drones
ADD CONSTRAINT fk_drones_registrants
FOREIGN KEY (registrants) REFERENCES registrants(id);

ALTER TABLE routes
ADD CONSTRAINT fk_routes_drones
FOREIGN KEY (dic) REFERENCES drones(dic);


--Create some fictitious datas for testing

-- INSERT to registrants

-- INSERT to drones

-- INSERT to routes
