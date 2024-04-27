-- Create tables
CREATE TABLE routes (
    dic VARCHAR PRIMARY KEY,
    auth_code VARCHAR,
    flight JSON
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

CREATE OR REPLACE FUNCTION json_array_elements_text(json)
RETURNS SETOF text AS
$$
SELECT json_array_elements($1)::text;
$$ LANGUAGE sql IMMUTABLE STRICT;

CREATE OR REPLACE FUNCTION json_array_elements_text(json)
RETURNS SETOF text AS
$$
SELECT json_array_elements($1)::text;
$$ LANGUAGE sql IMMUTABLE STRICT;

ALTER TABLE drones
ADD CONSTRAINT fk_drones_registrants
FOREIGN KEY (registrants) REFERENCES registrants(id);

ALTER TABLE routes
ADD CONSTRAINT fk_routes_drones
FOREIGN KEY (dic) REFERENCES drones(dic);


--Create some fictitious datas for testing

-- Insert registrants
INSERT INTO registrants (id, name, country) VALUES
('ZLL', 'Zheng Lin Lei', 'Unknown'),
('EC', 'Elena Clofent', 'Unknown'),
('ZL', 'Zhi Lin Lo', 'Unknown' ),
('MZ', 'Maria Zapata', 'Unknown'),
('HW', 'Haitao Wu', 'Unknown');

-- Insert drones with references to the registrants
INSERT INTO drones (dic, auth_code, registrants, owner_name, owner_identify, owner_email, registered_at) VALUES
('ESP00001-123-0033', 'edd22adf56e73d5ffe8490a513129923', 'ZLL', 'Zheng Lin Lei', 'Unknown', 'llzheng@oroneta.com', CURRENT_TIMESTAMP),
('FRA00001-001-0033', '45ac9f1020665490f8372ee5ef1107fd', 'EC', 'Elena Clofent', 'Unknown', 'eclemuo@oroneta.com', CURRENT_TIMESTAMP),
('ESP00002-123-0033', '699736a280a612c68ae7e5fb5690505d', 'ZL', 'Zhi Lin Lo', 'Unknown', 'zli@oroneta.com', CURRENT_TIMESTAMP),
('AUS78825-778-0001', '808122cbca3396b1977bfdd0166faa95', 'MZ', 'Maria Zapata', 'Unknown', 'mzapale@oroneta.com', CURRENT_TIMESTAMP),
('ESP88712-998-0871', 'cdb0581cae7b0aa6a415800f9d94bbf2', 'HW', 'Haitao Wu', 'Unknown', 'hwu@oroneta.com', CURRENT_TIMESTAMP);


-- INSERT to routes

INSERT INTO routes (dic, auth_code, flight) VALUES
('ESP00001-123-0033', 'edd22adf56e73d5ffe8490a513129923', '[[21,32], [4,-117], [40,-74], [36,-122], [30,-97]]'),
('FRA00001-001-0033', '45ac9f1020665490f8372ee5ef1107fd', '[[48,2], [50,14], [45,9], [52,13], [60,24]]'),
('ESP00002-123-0033', '699736a280a612c68ae7e5fb5690505d', '[[52,-0.13], [40,-3.68], [41,29], [38,-9], [55,-3]]'),
('AUS78825-778-0001', '808122cbca3396b1977bfdd0166faa95', '[[33.86,151.21], [-37.81,144.96], [-31.95,115.86], [-27.47,153.03], [-42.88,147.33]]'),
('ESP88712-998-0871', 'cdb0581cae7b0aa6a415800f9d94bbf2', '[[35.68,139.69], [22.32,114.17], [1.35,103.82], [13.75,100.51], [37.57,126.98]]');


