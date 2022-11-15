DELIMITER $$
CREATE FUNCTION fibonacci2(a INTEGER)
DETERMINISTIC
BEGIN
    DECLARE x INTEGER;
    DECLARE y INTEGER;
    DECLARE temp INTEGER;
    DECLARE i INTEGER;
    SET x = 0;
    SET y = 1;
    SET temp = 0;
    SET i = 0;
    printSeries: LOOP
    IF (i = a) THEN
        LEAVE printSeries;
    END IF;
    SET temp = x;
    SET x = y;
    SET y = y+temp;
    SET i = i+1;
    SELECT x;
    END LOOP printSeries;
END$$
DELIMITER ;
fibonacci2(10);