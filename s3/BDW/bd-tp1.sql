DROP TABLE IF EXISTS `Forêts`;
DROP TABLE IF EXISTS `Gestionnaires`;

CREATE TABLE `Forêts` (
  `idf` INTEGER,
  `nomf` VARCHAR(100),
  `superficie` INTEGER,
  `département` VARCHAR(50),
  `idg` INTEGER,
  PRIMARY KEY (`idf`)
) DEFAULT CHARSET=utf8;

CREATE TABLE `Gestionnaires` (
  `idg` INTEGER,
  `nomg` VARCHAR(50),
  `type` VARCHAR(50),
  PRIMARY KEY (`idg`)
) DEFAULT CHARSET=utf8;

ALTER TABLE `Forêts` ADD FOREIGN KEY (`idg`) REFERENCES `Gestionnaires` (`idg`);

INSERT INTO Gestionnaires VALUES(1, 'ONF', 'public');
INSERT INTO Gestionnaires VALUES(2, 'SIO', 'privé');
INSERT INTO Gestionnaires VALUES(3, 'Champfromier', 'communal');
INSERT INTO Gestionnaires VALUES(4, 'CST', 'communal');
INSERT INTO Gestionnaires VALUES(5, 'ONF, autres', 'mixte');
INSERT INTO Gestionnaires VALUES(6, 'COFOR', NULL);

INSERT INTO Forêts VALUES(1, 'forêt de Grande Chartreuse', 42500, 'Isère', 1);
INSERT INTO Forêts VALUES(2, 'forêt des Pays-de-Monts', 2280, 'Vendée', 1);
INSERT INTO Forêts VALUES(3, 'forêt du Cratère', 435, 'La Réunion', 1);
INSERT INTO Forêts VALUES(4, 'forêt de la Guerche', 3228, 'Ille-et-Vilaine', 2);
INSERT INTO Forêts VALUES(5, 'forêt de Champfromier', 1600, 'Ain', 3);
INSERT INTO Forêts VALUES(6, 'forêt de Taillard', 3000, 'Loire', 4);
INSERT INTO Forêts VALUES(7, 'forêt de Bonnevaux', 8500, 'Isère', 5);



