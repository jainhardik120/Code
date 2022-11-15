DELIMITER $$
CREATE PROCEDURE PrintHello(IN a INTEGER)
BEGIN
    DECLARE i INTEGER;
    SET i = 0;
    printLoop: LOOP
    IF i = a THEN
        LEAVE printLoop;
    END IF;
    SELECT "Hello World";
    SET i = i+1;
    END LOOP printLoop;
END$$
DELIMITER ;
call PrintHello(5);