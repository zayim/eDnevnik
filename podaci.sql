USE e_dnevnik;
INSERT INTO ucenici(ime,prezime,username,password,razred,odjeljenje)
VALUES ('Nadin','Zajimovic','nadin','nadin',4,4);
INSERT INTO ucenici(ime,prezime,username,password,razred,odjeljenje)
VALUES ('Damir','Mujakovic','damir','damir',4,4);
INSERT INTO ucenici(ime,prezime,username,password,razred,odjeljenje)
VALUES ('Dzenan','Mujakovic','dzenan','dzenan',4,4);
INSERT INTO ucenici(ime,prezime,username,password,razred,odjeljenje)
VALUES ('Adis','Hadzic','adis','adis',2,3);
INSERT INTO ucenici(ime,prezime,username,password,razred,odjeljenje)
VALUES ('Amer','Sarajlic','amer','amer',2,3);
INSERT INTO ucenici(ime,prezime,username,password,razred,odjeljenje)
VALUES ('Elmir','Sukanovic','elmir','elmir',2,3);
INSERT INTO ucenici(ime,prezime,username,password,razred,odjeljenje)
VALUES ('Rijad','Hadzic','rijad','hadzic',2,3);
INSERT INTO ucenici(ime,prezime,username,password,razred,odjeljenje)
VALUES ('Mehmed','Jusic','mehmed','mehmed',2,3);

INSERT INTO profesori(ime,prezime,username,password)
VALUES ('Safet','Habibija','safet','safet');

INSERT INTO profesori(ime,prezime,username,password)
VALUES ('Zeljko','Juric','zeljko','zeljko');

INSERT INTO profesori(ime,prezime,username,password)
VALUES ('Esmir','Pilav','esmir','esmir');

INSERT INTO predmeti(ime,profesor_id,razred)
VALUES ('PRA',1,4);

INSERT INTO predmeti(ime,profesor_id,razred)
VALUES ('Racunarske mreze',3,4);

INSERT INTO predmeti(ime,profesor_id,razred)
VALUES ('Strukture podataka',2,4);

INSERT INTO predmeti(ime,profesor_id,razred)
VALUES ('Racunarski sistemi',2,2);

INSERT INTO predmeti(ime,profesor_id,razred)
VALUES ('OOP',2,2);

INSERT INTO predmeti(ime,profesor_id,razred)
VALUES ('Teorija podataka',1,4);


INSERT INTO ucenici_predmeti(ucenik_id,predmet_id)
VALUES (1,1);
INSERT INTO ucenici_predmeti(ucenik_id,predmet_id)
VALUES (2,1);
INSERT INTO ucenici_predmeti(ucenik_id,predmet_id)
VALUES (3,1);
INSERT INTO ucenici_predmeti(ucenik_id,predmet_id)
VALUES (1,2);
INSERT INTO ucenici_predmeti(ucenik_id,predmet_id)
VALUES (2,2);
INSERT INTO ucenici_predmeti(ucenik_id,predmet_id)
VALUES (3,2);
INSERT INTO ucenici_predmeti(ucenik_id,predmet_id)
VALUES (1,3);
INSERT INTO ucenici_predmeti(ucenik_id,predmet_id)
VALUES (2,3);
INSERT INTO ucenici_predmeti(ucenik_id,predmet_id)
VALUES (3,3);
INSERT INTO ucenici_predmeti(ucenik_id,predmet_id)
VALUES (1,6);
INSERT INTO ucenici_predmeti(ucenik_id,predmet_id)
VALUES (2,6);
INSERT INTO ucenici_predmeti(ucenik_id,predmet_id)
VALUES (3,6);

INSERT INTO ucenici_predmeti(ucenik_id,predmet_id)
VALUES (4,4);
INSERT INTO ucenici_predmeti(ucenik_id,predmet_id)
VALUES (5,4);
INSERT INTO ucenici_predmeti(ucenik_id,predmet_id)
VALUES (6,4);
INSERT INTO ucenici_predmeti(ucenik_id,predmet_id)
VALUES (7,4);
INSERT INTO ucenici_predmeti(ucenik_id,predmet_id)
VALUES (8,4);
INSERT INTO ucenici_predmeti(ucenik_id,predmet_id)
VALUES (4,5);
INSERT INTO ucenici_predmeti(ucenik_id,predmet_id)
VALUES (5,5);
INSERT INTO ucenici_predmeti(ucenik_id,predmet_id)
VALUES (6,5);
INSERT INTO ucenici_predmeti(ucenik_id,predmet_id)
VALUES (7,5);
INSERT INTO ucenici_predmeti(ucenik_id,predmet_id)
VALUES (8,5);

INSERT INTO ocjene(ucenik_id,predmet_id,ocjena)
VALUES (1,1,4);
INSERT INTO ocjene(ucenik_id,predmet_id,ocjena)
VALUES (2,1,3);
INSERT INTO ocjene(ucenik_id,predmet_id,ocjena)
VALUES (3,1,3);
INSERT INTO ocjene(ucenik_id,predmet_id,ocjena)
VALUES (1,2,5);
INSERT INTO ocjene(ucenik_id,predmet_id,ocjena)
VALUES (2,2,1);
INSERT INTO ocjene(ucenik_id,predmet_id,ocjena)
VALUES (3,2,4);
INSERT INTO ocjene(ucenik_id,predmet_id,ocjena)
VALUES (1,3,4);
INSERT INTO ocjene(ucenik_id,predmet_id,ocjena)
VALUES (2,3,3);
INSERT INTO ocjene(ucenik_id,predmet_id,ocjena)
VALUES (3,3,5);
INSERT INTO ocjene(ucenik_id,predmet_id,ocjena)
VALUES (1,6,5);
INSERT INTO ocjene(ucenik_id,predmet_id,ocjena)
VALUES (2,6,3);
INSERT INTO ocjene(ucenik_id,predmet_id,ocjena)
VALUES (3,6,4);

INSERT INTO ocjene(ucenik_id,predmet_id,ocjena)
VALUES (4,4,3);
INSERT INTO ocjene(ucenik_id,predmet_id,ocjena)
VALUES (5,4,5);
INSERT INTO ocjene(ucenik_id,predmet_id,ocjena)
VALUES (6,4,4);
INSERT INTO ocjene(ucenik_id,predmet_id,ocjena)
VALUES (7,4,3);
INSERT INTO ocjene(ucenik_id,predmet_id,ocjena)
VALUES (8,4,2);
INSERT INTO ocjene(ucenik_id,predmet_id,ocjena)
VALUES (4,5,1);
INSERT INTO ocjene(ucenik_id,predmet_id,ocjena)
VALUES (5,5,3);
INSERT INTO ocjene(ucenik_id,predmet_id,ocjena)
VALUES (6,5,4);
INSERT INTO ocjene(ucenik_id,predmet_id,ocjena)
VALUES (7,5,4);
INSERT INTO ocjene(ucenik_id,predmet_id,ocjena)
VALUES (8,5,5);
