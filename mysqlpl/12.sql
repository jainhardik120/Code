create database dv;
use dv;
create table flight(flightid int, source varchar(20), destination varchar(20), totaltickets int, reservedseats int);
create table CancelledFlights(flightid int, source varchar(20), destination varchar(20));
insert into flight values(1,"Delhi", "Mumbai", 30, 20);
insert into flight values(2,"Delhi", "Chennai", 30, 30);
insert into flight values(3,"Mumbai", "Chennai", 30, 20);
insert into flight values(4,"Delhi", "Bangalore", 30, 20);


DROP PROCEDURE IF EXISTS ReservedSeatsLess;
DELIMITER $$
CREATE PROCEDURE ReservedSeatsLess(IN a INTEGER)
BEGIN
    DECLARE  finished  INTEGER DEFAULT 0;
    DECLARE  flightId  INTEGER DEFAULT 0;
    DECLARE  source  varchar(20) DEFAULT "";
    DECLARE  destination  varchar(20) DEFAULT "";
    DECLARE  curSeats
    CURSOR FOR
    SELECT flight.flightid,  flight.source, flight.destination FROM flight where reservedseats<a;
    DECLARE  CONTINUE  HANDLER FOR NOT FOUND SET finished = 1;
    OPEN curSeats;
    canceledloop: LOOP
    FETCH curSeats INTO flightId, source, destination;
    IF finished = 1 THEN
    LEAVE canceledloop;
    END IF;
    INSERT INTO CancelledFlights VALUES (flightId, source, destination);
        END LOOP canceledloop;
CLOSE curSeats;
END$$
DELIMITER ;
call ReservedSeatsLess(25);
Select * from CancelledFlights;