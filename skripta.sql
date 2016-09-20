DROP DATABASE e_dnevnik;
CREATE DATABASE e_dnevnik;
USE e_dnevnik;
CREATE TABLE ucenici
(
	ucenik_id INT AUTO_INCREMENT PRIMARY KEY,
	ime VARCHAR(20),
	prezime VARCHAR(20),
	username VARCHAR(20) NOT NULL,
	password VARCHAR(50) NOT NULL,
	razred INT,
	odjeljenje INT,
	slika LONGBLOB
);
CREATE TABLE profesori
(
	profesor_id INT AUTO_INCREMENT PRIMARY KEY,
	ime VARCHAR(20),
	prezime VARCHAR(20),
	username VARCHAR(20) NOT NULL,
	password VARCHAR(50) NOT NULL,
	slika LONGBLOB
);
CREATE TABLE zadace
(
	zadaca_id INT AUTO_INCREMENT PRIMARY KEY,
	tekst_zadace TEXT,
	format_fajla VARCHAR(10),
	predmet_id INT,
	status INT(1) DEFAULT 0
);
CREATE TABLE predmeti
(
	predmet_id INT AUTO_INCREMENT PRIMARY KEY,
	ime VARCHAR(20),
	profesor_id INT,
	FOREIGN KEY(profesor_id) REFERENCES profesori(profesor_id),
	razred int,
	zadaca_id INT,
	FOREIGN KEY(zadaca_id) REFERENCES zadace(zadaca_id) 
);
CREATE TABLE ucenici_predmeti
(
	ucenik_predmet_id INT AUTO_INCREMENT PRIMARY KEY,
	ucenik_id INT,
	predmet_id INT,
	FOREIGN KEY(ucenik_id) REFERENCES ucenici(ucenik_id),
	FOREIGN KEY(predmet_id) REFERENCES predmeti(predmet_id),
	zadaca_status INT(1) DEFAULT 0
);
CREATE TABLE ocjene
(
	ucenik_id INT,
	predmet_id INT,
	FOREIGN KEY(ucenik_id) REFERENCES ucenici(ucenik_id),
	FOREIGN KEY(predmet_id) REFERENCES predmeti(predmet_id),
	ocjena INT
);
ALTER TABLE zadace ADD CONSTRAINT FOREIGN KEY(predmet_id) REFERENCES predmeti(predmet_id);
SOURCE C:\Users\zayim\Desktop\e-Dnevnik\podaci.sql