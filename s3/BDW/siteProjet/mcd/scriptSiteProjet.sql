CREATE TABLE GroupeDeMusique(
   IdG INT,
   NomG VARCHAR(50)  NOT NULL,
   DateFormationG DATE,
   DateSeparationG DATE NOT NULL,
   PRIMARY KEY(IdG)
);

CREATE TABLE Musicien(
   IdM INT,
   NomM VARCHAR(50) ,
   PrenomM VARCHAR(50) ,
   NomSceneM VARCHAR(50) ,
   PRIMARY KEY(IdM)
);

CREATE TABLE Periode(
   DebutP DATE,
   FinP DATE,
   PRIMARY KEY(DebutP, FinP)
);

CREATE TABLE Chanson(
   IdC INT,
   TitreC VARCHAR(50) ,
   DateCreationC DATE,
   IdG INT NOT NULL,
   PRIMARY KEY(IdC),
   FOREIGN KEY(IdG) REFERENCES GroupeDeMusique(IdG)
);

CREATE TABLE TypeDeGenre(
   NomGenreG VARCHAR(50) ,
   PRIMARY KEY(NomGenreG)
);

CREATE TABLE TypeDeRelation(
   NomRelationR VARCHAR(50) ,
   PRIMARY KEY(NomRelationR)
);

CREATE TABLE FichierAudio(
   IdFA VARCHAR(50) ,
   TypeVersionFA VARCHAR(50) ,
   DureeFA TIME,
   DateFA DATE,
   NomFichierFA VARCHAR(50) ,
   LibelleFA VARCHAR(50) ,
   IdC INT NOT NULL,
   PRIMARY KEY(IdFA),
   FOREIGN KEY(IdC) REFERENCES Chanson(IdC)
);

CREATE TABLE ListeDeLecture(
   IdLDL INT,
   TitreLDL VARCHAR(50) ,
   DateLDL DATE,
   PRIMARY KEY(IdLDL)
);

CREATE TABLE Album(
   IdA INT,
   TitreA VARCHAR(50)  NOT NULL,
   SortieA DATE,
   ProducteurA VARCHAR(50) ,
   PRIMARY KEY(IdA)
);

CREATE TABLE Lives(
   IdA INT,
   PRIMARY KEY(IdA),
   FOREIGN KEY(IdA) REFERENCES Album(IdA)
);

CREATE TABLE Compilation(
   IdA INT,
   Description VARCHAR(50) ,
   PRIMARY KEY(IdA),
   FOREIGN KEY(IdA) REFERENCES Album(IdA)
);

CREATE TABLE Studio(
   IdA INT,
   IngenieurDuSon VARCHAR(50) ,
   PRIMARY KEY(IdA),
   FOREIGN KEY(IdA) REFERENCES Album(IdA)
);

CREATE TABLE Lieu(
   IdL INT,
   NomL VARCHAR(50) ,
   CoordoneeL GEOMETRY,
   PRIMARY KEY(IdL)
);

CREATE TABLE DateEnregistrement(
   DateE DATE,
   PRIMARY KEY(DateE)
);

CREATE TABLE SeProduire(
   IdA INT,
   IdL INT,
   DateE DATE,
   PRIMARY KEY(IdA, IdL, DateE),
   FOREIGN KEY(IdA) REFERENCES Lives(IdA),
   FOREIGN KEY(IdL) REFERENCES Lieu(IdL),
   FOREIGN KEY(DateE) REFERENCES DateEnregistrement(DateE)
);

CREATE TABLE FairePartie(
   IdG INT,
   DebutP DATE,
   FinP DATE,
   IdM INT,
   Role VARCHAR(50) ,
   Fondateur BOOLEAN,
   PRIMARY KEY(IdG, DebutP, FinP, IdM),
   FOREIGN KEY(IdG) REFERENCES GroupeDeMusique(IdG),
   FOREIGN KEY(DebutP, FinP) REFERENCES Periode(DebutP, FinP),
   FOREIGN KEY(IdM) REFERENCES Musicien(IdM)
);

CREATE TABLE AvoirPourGenre(
   IdC INT,
   NomGenreG VARCHAR(50) ,
   PRIMARY KEY(IdC, NomGenreG),
   FOREIGN KEY(IdC) REFERENCES Chanson(IdC),
   FOREIGN KEY(NomGenreG) REFERENCES TypeDeGenre(NomGenreG)
);

CREATE TABLE AvoirPourParent(
   NomGenreG VARCHAR(50) ,
   NomGenreG_1 VARCHAR(50) ,
   PRIMARY KEY(NomGenreG, NomGenreG_1),
   FOREIGN KEY(NomGenreG) REFERENCES TypeDeGenre(NomGenreG),
   FOREIGN KEY(NomGenreG_1) REFERENCES TypeDeGenre(NomGenreG)
);

CREATE TABLE EtreEnRelation(
   IdC INT,
   IdC_1 INT,
   NomRelationR VARCHAR(50) ,
   PRIMARY KEY(IdC, IdC_1, NomRelationR),
   FOREIGN KEY(IdC) REFERENCES Chanson(IdC),
   FOREIGN KEY(IdC_1) REFERENCES Chanson(IdC),
   FOREIGN KEY(NomRelationR) REFERENCES TypeDeRelation(NomRelationR)
);

CREATE TABLE InclureListe(
   IdFA VARCHAR(50) ,
   IdLDL INT,
   PRIMARY KEY(IdFA, IdLDL),
   FOREIGN KEY(IdFA) REFERENCES FichierAudio(IdFA),
   FOREIGN KEY(IdLDL) REFERENCES ListeDeLecture(IdLDL)
);

CREATE TABLE InclureAlbum(
   IdFA VARCHAR(50) ,
   IdA INT,
   NumeroPiste VARCHAR(50) ,
   PRIMARY KEY(IdFA, IdA),
   FOREIGN KEY(IdFA) REFERENCES FichierAudio(IdFA),
   FOREIGN KEY(IdA) REFERENCES Album(IdA)
);

CREATE TABLE Enregistrer(
   IdG INT,
   IdA INT,
   PRIMARY KEY(IdG, IdA),
   FOREIGN KEY(IdG) REFERENCES GroupeDeMusique(IdG),
   FOREIGN KEY(IdA) REFERENCES Album(IdA)
);

CREATE TABLE Inviter(
   IdG INT,
   IdM INT,
   IdA INT,
   Commentaire VARCHAR(50) ,
   PRIMARY KEY(IdG, IdM, IdA),
   FOREIGN KEY(IdG) REFERENCES GroupeDeMusique(IdG),
   FOREIGN KEY(IdM) REFERENCES Musicien(IdM),
   FOREIGN KEY(IdA) REFERENCES Album(IdA)
);

CREATE TABLE Interpreter(
   IdG INT,
   IdFA VARCHAR(50) ,
   PRIMARY KEY(IdG, IdFA),
   FOREIGN KEY(IdG) REFERENCES GroupeDeMusique(IdG),
   FOREIGN KEY(IdFA) REFERENCES FichierAudio(IdFA)
);
