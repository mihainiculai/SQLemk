DROP TABLE angajati
CREATE TABLE angajati (nume, CHAR, 10, anonim), (varsta, INT, 3, 18), (salariu, FLOAT, 6, 0.0)
DISPLAY TABLE angajati
INSERT INTO angajati (Edy, 18, 5000.0)
INSERT INTO angajati (Mihai, 18, 7000.0)
INSERT INTO angajati (Karim, 20, 6000.0)
INSERT INTO angajati (Bogdan, 30, 9000.0)
INSERT INTO angajati (Andrei, 18, 2550.0)
INSERT INTO angajati (George, 1987, 9999.0)
SELECT * FROM angajati
SELECT varsta, nume FROM angajati
DELETE FROM angajati WHERE varsta = 18
UPDATE angajati SET varsta = 20 WHERE nume = Bogdan
SELECT * FROM angajati
DROP TABLE angajati