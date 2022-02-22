-- The script used to create the FLIGHT_PATH table
-- The PostGIS extension is required to use this script (and the app in general)
-- see : https://github.com/M1-SynthesisProject-SmartDrone/pds-global/blob/main/docs/tutos/install_PostgreSQL.txt

CREATE TABLE flight_path (
  id serial PRIMARY KEY,
  name VARCHAR(30),
  path geography(LINESTRINGZ)
);

-- Insertion example

INSERT INTO flight_path(name, path) VALUES (
    'path n°1',
    ST_MakeLine(ARRAY[
        ST_MakePoint(49.2341256, 2.2341345, 84000),
        ST_MakePoint(49.3341256, 2.1341345, 85000),
        ST_MakePoint(49.4341256, 2.0341345, 83000)  
    ])
);

INSERT INTO flight_path(name, path) VALUES (
    'path n°2',
    ST_MakeLine(ARRAY[
        ST_MakePoint(48.2341256, 1.2341345, 84000),
        ST_MakePoint(47.3341256, 1.1341345, 85000),
        ST_MakePoint(46.4341256, 1.0341345, 83000)  
    ])
);

-- Selection example
-- NOTE : not sure about how distance is expressed

-- Display the X, Y coordinates of the first point of each path
select ST_X(ST_PointN(path::geometry,1)) as x, ST_Y(ST_PointN(path::geometry,1)) as y from flight_path;

-- Display all points of all paths formatted (with path name, id and point representation)
-- More complex, but we do have the index of the point in this query
SELECT id, name, (dp).path[1] As index, ST_AsText((dp).geom) As wktnode
    FROM (SELECT id, name, ST_DumpPoints(path::geometry) as dp FROM flight_path) AS s;

-- Display lat, lon & alt coordinates of a path with specified id
SELECT id, name, ST_X(g) AS lat, ST_Y(g) AS lon, ST_Z(g) AS alt
    FROM (SELECT id, name, (ST_DumpPoints(path::geometry)).geom as g FROM flight_path WHERE id = 2) AS q;

-- Display the distance between first point and second point of each path
SELECT ST_3DDISTANCE(ST_PointN(path::geometry, 1), ST_PointN(path::geometry, 2)) AS distance FROM flight_path;

-- Display the distance between the first point and the last point of each path
SELECT ST_3DDISTANCE(ST_StartPoint(path::geometry), ST_EndPoint(path::geometry)) AS distance FROM flight_path;

-- Display the total length of each path (only 2D length)
SELECT ST_3DLength(path::geometry) AS total_distance FROM flight_path;