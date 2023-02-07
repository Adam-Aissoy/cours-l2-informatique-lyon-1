
CREATE TABLE `Miels` (
  `idm` INTEGER,
  `nom` VARCHAR(42),
  `variété` VARCHAR(42),
  `label` VARCHAR(42),
  `année` INT(4),
  PRIMARY KEY (`idm`)
) DEFAULT CHARSET=utf8;

CREATE TABLE `Produire` (
  `idm` INTEGER,
  `ida` INTEGER,
  `saison` VARCHAR(12),
  PRIMARY KEY (`idm`, `ida`)
) DEFAULT CHARSET=utf8;

CREATE TABLE `Abeilles` (
  `ida` INTEGER,
  `espèce` VARCHAR(42),
  `pays` VARCHAR(42),
  `année` INT(4),
  PRIMARY KEY (`ida`)
) DEFAULT CHARSET=utf8;

ALTER TABLE `Produire` ADD FOREIGN KEY (`ida`) REFERENCES `Abeilles` (`ida`);
ALTER TABLE `Produire` ADD FOREIGN KEY (`idm`) REFERENCES `Miels` (`idm`);

INSERT INTO Miels VALUES(1, 'miel de Provence', 'lavande', 'IGP', 2005);
INSERT INTO Miels VALUES(2, 'miel de Provence', 'fleurs', 'IGP', 2005);
INSERT INTO Miels VALUES(3, 'miel des Vosges', 'sapin', 'AOC', 1996);
INSERT INTO Miels VALUES(4, 'miel d\'Alsace', 'fleurs', 'IGP', 2005);
INSERT INTO Miels VALUES(5, 'miel d\'Alsace', 'forêt', 'IGP', 2005);
INSERT INTO Miels VALUES(6, 'miel de Corse', 'maquis', 'AOC', NULL);
INSERT INTO Miels VALUES(7, 'mel de Galicia', 'fleurs', 'IGP', 2007);
INSERT INTO Abeilles VALUES(1, 'abeille noire', NULL, 1758);
INSERT INTO Abeilles VALUES(2, 'abeille jaune', 'Italie', 1806);
INSERT INTO Abeilles VALUES(3, 'abeille asiatique', 'Inde', 1793);
INSERT INTO Abeilles VALUES(4, 'abeille russe', 'Russie', NULL);
INSERT INTO Abeilles VALUES(5, 'abeille carniolienne', 'Slovénie', 1879);
INSERT INTO Abeilles VALUES(6, 'abeille ibérique', 'Portugal', 1999);
INSERT INTO Abeilles VALUES(7, 'abeille tueuse', 'Brésil', 1956);
INSERT INTO Produire VALUES(1, 1, 'été');
INSERT INTO Produire VALUES(1, 2, 'été');
INSERT INTO Produire VALUES(2, 3, 'été');
INSERT INTO Produire VALUES(3, 1, 'printemps');
INSERT INTO Produire VALUES(3, 3, 'printemps');
INSERT INTO Produire VALUES(3, 5, 'été');
INSERT INTO Produire VALUES(3, 7, 'été');
INSERT INTO Produire VALUES(4, 2, 'été');
INSERT INTO Produire VALUES(4, 3, 'été');
INSERT INTO Produire VALUES(4, 6, 'été');
INSERT INTO Produire VALUES(5, 1, 'été');
INSERT INTO Produire VALUES(5, 5, 'printemps');
INSERT INTO Produire VALUES(6, 5, 'été');
INSERT INTO Produire VALUES(6, 6, 'automne');
INSERT INTO Produire VALUES(6, 7, 'printemps');

