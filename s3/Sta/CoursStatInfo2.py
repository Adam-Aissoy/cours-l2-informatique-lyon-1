import pandas as pan #pour les données :gestion des data.frame
import numpy as np
import matplotlib.pyplot as plt
#import statsmodels.api as sm

import scipy.stats.mstats as ms

url="http://math.univ-lyon1.fr/homes-www/dabrowski/enseignement/StatInfo/nutriageSimplifie.csv"
df=pan.read_csv(url,sep="\t")#on charge les données


#Nuages de points
figNuages, axNuages = plt.subplots()
axNuages.plot(df["poids"], df["taille"], 'C2o')#trace les points de sauts
axNuages.set_xlabel("poids")
axNuages.set_ylabel("taille")
figNuages.suptitle("Nuages de points pour les variables taille et poids")
plt.savefig('/home/Enseignement/Cours/StatInfo/Python/Nuage.png')
plt.show(axNuages)

#####Première Régression####
x=df["taille"].iloc[[*(np.arange(188,198))]]
y=df["poids"].iloc[[*(np.arange(188,198))]]
rl=ms.linregress(x,y)
print(rl.slope,rl.intercept)


#Fonction pour tracer une droite comme dans R dans l'objet graphique axes
def abline(slope, intercept,axes,col="red"):
    axes = plt.gca()
    x_vals = np.array(axes.get_xlim())
    y_vals = intercept + slope * x_vals
    axes.plot(x_vals, y_vals, '--',color=col)

fig, axes = plt.subplots(figsize=(5, 4))
axes.plot(x,y, '.')
abline(rl[0],rl[1],axes)
fig.suptitle('Nuage de points et régression linéaire')
axes.set_xlabel("poids")
axes.set_ylabel("taille")
plt.savefig('/home/Enseignement/Cours/StatInfo/Python/RegLin.png')
plt.show(axes)


#####Régression complète#######
lr=ms.linregress(df["taille"],df["poids"])
fig, axes = plt.subplots(figsize=(6, 5))
axes.plot(df["taille"],df["poids"], '.')
abline(rl[0],rl[1],axes)
abline(lr[0],lr[1],axes,col="blue")
fig.suptitle('Nuage de points de poids et taille et régression linéaire (bleue)')
axes.set_xlabel("poids");axes.set_ylabel("taille")
plt.savefig('/home/Enseignement/Cours/StatInfo/Python/RegLinComplet.png')
plt.show(axes)


