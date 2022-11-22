DELIMITER $$
CREATE FUNCTION LargestNumber(a INTEGER, b INTEGER, c INTEGER, d INTEGER)
RETURNS INTEGER
DETERMINISTIC
BEGIN
    DECLARE Output INTEGER;
    SET Output = a;
    IF (b > Output) THEN
        SET Output = b;
    END IF;
    IF (c > Output) THEN
        SET Output = c;
    END IF;
    IF (d > Output) THEN
        SET Output = d;
    END IF;
    SELECT Output;
    RETURN (Output);
END$$
DELIMITER ;
SET @Output = LargestNumber(12, 15, 90, 14);
Select @Output;