# -*- coding: utf-8 -*-
"""
Éditeur de Spyder

Ceci est un script temporaire.
"""

import numpy as np
import matplotlib.pyplot as plt
import pandas as pan
import scipy.stats.mstats as ms
from pydataset import data
pydata = data()
cars=data('cars')
data('cars', show_doc=True)


"""
1. Calculer la moyenne, variance empirique, variance empirique non-biaisée,
 médiane, écart-type des
variables speed et dist.
2. Calculer les 3 quartiles selon 
la définition du cours.
3. Que fait la fonction cars.describe() ?
4. Selon le type de variables à notre disposition, 
quelle représentation graphique suggérez-vous ?
Tracer l’histogramme de la variable speed. Ajouter un titre, 
et des étiquettes aux axes x et y.
"""
  

mySpeed = np.mean(cars.speed)  
myDist = np.mean(cars.dist)
print ("la moyenne de Speed : ",  mySpeed)
print ("la moyenne de dist : ",  myDist)

Q1 = np.median(cars)

print (Q1)



Quantile_speed = np.quantile(cars.speed, [0.25,0.5,0.75], axis = 0 ,
            interpolation = 'lower')

Quantile_dist = np.quantile(cars.dist, [0.25,0.5,0.75], 
                axis = 0 , 
                interpolation = 'lower')

print ( "Qantile de speed : " , Quantile_speed )

print ( "Qantile de dist : " , Quantile_dist)

cars.describe() 
"""
# Import numpy library
import numpy as np
  
data = [32, 36, 46, 47, 56, 69, 75, 79, 79, 88, 89, 91, 92, 93, 96, 97, 
        101, 105, 112, 116]
  
# First quartile (Q1)
Q1 = np.percentile(data, 25, interpolation = 'midpoint')
  
# Third quartile (Q3)
Q3 = np.percentile(data, 75, interpolation = 'midpoint')
  
# Interquaritle range (IQR)
IQR = Q3 - Q1
  
print(IQR)
"""