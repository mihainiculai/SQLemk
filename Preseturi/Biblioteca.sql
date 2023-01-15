CREATE TABLE carti (id, INT, 4, 0), (titlu, CHAR, 40, Necunoscut), (autor, CHAR, 30, Anonim), (gen, CHAR, 15, Necunoscut), (numar_pagini, INT, 3, 100), (an_publicatie, INT, 4, 2022)
INSERT INTO carti (1, Alice_in_Tara_Minunilor, Lewis_Carroll, Fantezie, 200, 1865)
INSERT INTO carti (2, Harry_Potter_si_Piatra_Filozofala, JK_Rowling, Fantezie, 223, 1997)
INSERT INTO carti (3, Harry_Potter_si_Camera_Secretelor, JK_Rowling, Fantezie, 251, 1998)
INSERT INTO carti (4, The_Witcher, Andrzej_Sapkowski, Fantezie, 300, 1992)
INSERT INTO carti (5, The_Witcher_2, Andrzej_Sapkowski, Fantezie, 350, 1993)
INSERT INTO carti (6, The_Lord_of_the_Rings, JRR_Tolkien, Fantezie, 500, 1954)
INSERT INTO carti (7, The_Hobbit, JRR_Tolkien, Fantezie, 300, 1937)
INSERT INTO carti (8, The_Lord_of_the_Rings_2, JRR_Tolkien, Fantezie, 600, 1955)
INSERT INTO carti (9, Conan_the_Barbarian, Robert_E_Howard, Fantezie, 200, 1932)
INSERT INTO carti (10, Metro_2033, Dmitry_Glukhovsky, Fantezie, 300, 2005)
CREATE TABLE abonati  (id, INT, 4, 0), (nume, CHAR, 30, Anonim), (prenume, CHAR, 30, Anonim), (telefon, INT, 10, Necunoscut), (email, CHAR, 30, Necunoscut)
INSERT INTO abonati (1, Popescu, Ion, 0782436159, popescui@gmail.com)
INSERT INTO abonati (2, Ionescu, Maria, 0791375642, ionescum@gmail.com)
INSERT INTO abonati (3, Popa, Vasile, 0761584973, popav@gmail.com)
INSERT INTO abonati (4, Popa, Maria, 0712386574, popam@gmail.com)
INSERT INTO abonati (5, Ionescu, Vasile, 0730549786, ionescuv@gmail.com)
INSERT INTO abonati (6, Popescu, Maria, 0745963218, popescum@gmail.com)
INSERT INTO abonati (7, Neculai, Sorin, 0771986532, neculaisorin@gmail.com)
INSERT INTO abonati (8, Nita, Bodgan, 0790432658, nitabogdan@gmail.com)
INSERT INTO abonati (9, Neacsu, Ana, 0763829107, neascuana@gmail.com)
INSERT INTO abonati (10, Moise, Razavan, 0725146938, moiser@gmail.com)
CREATE TABLE imprumuturi (id, INT, 4, 0), (nume_abonat, CHAR, 30, Anonim), (prenume_abonat, CHAR, 30, Anonim), (data_imprumut, CHAR, 10, 01-01-2022), (data_returnare, CHAR, 10, 01-01-2022)
INSERT INTO imprumuturi (1, Popescu, Ion, 03-01-2022, 21-01-2022) 
INSERT INTO imprumuturi (2, Ionescu, Maria, 05-01-2022, 17-01-2022)
INSERT INTO imprumuturi (3, Popa, Vasile, 01-02-2022, 01-03-2022)
INSERT INTO imprumuturi (4, Popa, Maria, 15-07-2022, 02-08-2022)
INSERT INTO imprumuturi (5, Ionescu, Vasile, 25-01-2022, 04-05-2022)
INSERT INTO imprumuturi (6, Popescu, Maria, 11-05-2022, 21-05-2022)
INSERT INTO imprumuturi (7, Neculai, Sorin, 12-08-2022, 21-08-2022)
INSERT INTO imprumuturi (8, Nita, Bodgan, 23-08-2022, 01-09-2022)
INSERT INTO imprumuturi (9, Neacsu, Ana, 01-09-2022, 10-09-2022)
INSERT INTO imprumuturi (10, Moise, Razavan, 03-10-2022, 19-10-2022)