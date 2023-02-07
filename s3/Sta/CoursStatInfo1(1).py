#conda install pandas
#conda install  matplotlib
#conda install scipy
#conda install seaborn
#conda install statsmodels
#pip install Image


import pandas as pan #pour les données :gestion des data.frame
import numpy as np
import matplotlib.pyplot as plt

f=pan.read_csv("/home/Enseignement/Cours/StatInfo/Python/nutriageSimplifie.csv",sep="\t")
print(f)

df=f.copy()
print(df.iloc[2,4])

#Typage des données: Python ne peut pas deviner l'encodage, par défaut il ne trouve pas les bons typages
f.dtypes
#Out[86]: 
#sexe       object
#the         int64
#cafe        int64
#taille      int64
#poids       int64
#age         int64
#viande      int64
#poisson     int64
#matgras     int64

#Exemple simple

Listecol=["bleu", "bleu","vert","bleu", "bleu","marron","marron"]
col=pan.Series(Listecol,dtype='category')
print(col)
yeux=pan.DataFrame({"col":Listecol},dtype='category')
print(yeux.col)

ListeMatGras=["beurre","margarine","arachide","tournesol","olive","Melange","colza","canard"]
df['matgras']=df['matgras'].astype('category')
df['matgras'].cat.categories=ListeMatGras
table=pan.crosstab(df["sexe"],df["matgras"],margins=True)#cela crée la table de contingence avec les effectifs.
print(table)
print(pan.crosstab(df["sexe"],df["sexe"]))

#########Typage des données  de df########
df['sexe']=df['sexe'].astype('category')
df['sexe'].cat.categories=["Femme","Homme"]
print(f['sexe'])
#Name: sexe, Length: 226, dtype: object
print(df['sexe'])
#Name: sexe, Length: 226, dtype: category
"Categories (2, object): [F, H]

df['matgras']=df['matgras'].astype('category')
df['matgras'].cat.categories=["beurre","margarine","arachide","tournesol","olive","Melange","colza","canard"]
print(df['matgras'])

df['viande']=df['viande'].astype('category')
freq=["jamais","<1/sem.","1/sem.","2-3/sem.","4-6/sem.","1/jour"]
freq_type=pan.CategoricalDtype(categories=freq,ordered=True)
df['viande'].cat.categories=freq
df['viande']=df['viande'].astype(freq_type)
print(df['viande'])
df['poisson']=df['poisson'].astype('category')
df['poisson'].cat.categories=freq
df['poisson']=df['poisson'].astype(freq_type)
print(df['poisson'])

df['taille']=df['taille'].astype('float64')
df['poids']=df['poids'].astype('float64')
df['age']=df['age'].astype('float64')

df.dtypes
#sexe       category
#the           int64
#cafe          int64
#taille      float64
#poids       float64
#age         float64
#viande     category
#poisson    category
#matgras    category
#dtype: object

#########Notion d' Effectifs ########
df["sexe"].size
TCsexe=df["sexe"].value_counts()
print(TCsexe)

df["matgras"].size
df["matgras"].value_counts()


print(df)

 #     sexe  the  cafe  taille  poids  age    viande   poisson    matgras
#0    Femme    0     0     151     58   72  4-6/sem.  2-3/sem.    Melange
#1    Femme    1     1     162     60   68    1/jour    1/sem.  tournesol
#2    Femme    0     4     162     75   78  2-3/sem.   <1/sem.  tournesol
#3    Femme    0     0     154     45   91    jamais  4-6/sem.  margarine
#4    Femme    2     1     154     50   65    1/jour  2-3/sem.  margarine

print((df['poids']/100))

#Table de contingence pour sexe et matgras
table=pan.crosstab(df["sexe"],df["matgras"])
print(table)
tableFreq=pan.crosstab(df["sexe"],df["matgras"],normalize=True,margins=True)
print(tableFreq)

#########méthode diagramme camembert avec fonction pie de pandas########
df["matgras"].value_counts().plot.pie(y='matgras',figsize=(5,5),colors=col,title='Diagramme circulaire de matgras')
plt.savefig('/home/Enseignement/Cours/StatInfo/DiagCirc3.png')
plt.show(plot)

import matplotlib.pyplot as plt #pour les dessins
#Autre solution
plot=plt.pie(df["matgras"].value_counts(), labels=df['matgras'].cat.categories)
plt.savefig('/home/Enseignement/Cours/StatInfo/Python/DiagCirc4.png')
plt.show(plot)


#méthode diagramme pie avec matplotlit
fig1, ax1 = plt.subplots()
#ax1.pie(matgrasFreq.values, labels=matgrasFreq.index, autopct='%1.1f%%',shadow=True, startangle=90)
col=["#0099FF", "#33FF99","#FF9900", "#9900FF", "#99FF33","#FF3399","#000000", "#9933FF"]
ax1.pie(df["matgras"].value_counts(), labels=df['matgras'].cat.categories,colors=col)
fig1.suptitle('Diagramme circulaire de matgras')
plt.savefig('/home/Enseignement/Cours/StatInfo/Python/DiagCirc2.png')
plt.show(ax1)



df['viande']=df['viande'].astype('category')

#########Digramme en Tuyau d'orgue (ou barre ) avec pandas########
tableViande=pan.crosstab(index = df["viande"],columns="Consommation de Viande",normalize=True)
plotViande=tableViande.plot.bar(figsize=(6,6),title="Diagramme en tuyau  d'orgue et fonction de répartition de viande")
plt.savefig('/home/Enseignement/Cours/StatInfo/Python/TuyauOrgueViande.png')
plt.show(plotViande)



########Digramme en Tuyau d'orgue + cumulatif avec matplotlib########
import matplotlib.pyplot as plt
import numpy as np #librairie pour les calculs de bases

tableViande=pan.crosstab(index = df["viande"],columns="freq",normalize=True)
l=len(tableViande);x = np.arange(l);width=0.7

fig, ax = plt.subplots()
ax.set_ylim(0,0.4)
ax.bar(x,np.reshape(tableViande.values,l), width=width,color=col)
ax2=ax.twinx()
ax2.tick_params(axis='y', labelcolor='b')
ax2.set_ylim(0,1)
ax2.plot(x,tableViande.cumsum(),color='b')
#ax.set_ylabel('Scores')
fig.suptitle("Diagramme en tuyau  d'orgue et fonction de répartition de viande")
ax.set_xticks(x)
ax.set_xticklabels(tableViande.index)
ax.legend(frameon=False)

#print(tableViande.index)
#print(np.reshape(tableViande.values,len(tableViande)))
#print(tableViande.cumsum())
plt.savefig('/home/Enseignement/Cours/StatInfo/Python/BarPlotViande.png')
plt.show(ax)

#########Variables discrètes Café et Thé########
tC=pan.crosstab(index =df["cafe"],columns="cafe")
tableCafe=pan.DataFrame({'Cafe': np.reshape(tC.values,newshape=len(tC))})
axes=tableCafe.plot.bar(width=0.05)
plt.savefig('/home/Enseignement/Cours/StatInfo/Python/BatonCafePan.png')

#Autre méthode
print(tableCafe)#vecteur colonne
xCafe = np.arange(len(tableCafe))
yCafe=np.reshape(tableCafe.values,len(tableCafe))
print(yCafe)#vecteur ligne

figCafe, axCafe = plt.subplots()
axCafe.bar(xCafe,np.reshape(tableCafe.values,len(tableCafe)), width=0.05,color="#556b2f")
axCafe.set_xticks(x)
axCafe.set_xticklabels(tableCafe.index)
axCafe.legend(frameon=False)
figCafe.suptitle("Diagramme en bâton de la variable Café")
plt.savefig('/home/Enseignement/Cours/StatInfo/Python/BatonCafe.png')
plt.show(axCafe)
# Cumulatif pour le thé
tableThe=pan.crosstab(index = df["the"],columns="freq",normalize=True).cumsum()
print(tableThe)
xThe = np.array([-1,*(tableThe.index)])#abcisses aux valeurs et -1

figThe, axThe = plt.subplots()
val=np.reshape(tableThe.values,len(tableThe))
axThe.step(xThe,np.array([0,*val]), where='post',color="#556b2f")#trace le diagramme en escalier en ajoutant un point de départ à valeur 0
axThe.plot(tableThe.index, val, 'C2o', alpha=0.5)#trace les points de sauts
axThe.set_xticks(xThe)
axThe.set_xticklabels(xThe)
axThe.legend(frameon=False)
figThe.suptitle("Fonction de répartition empirique de la variable thé")
plt.savefig('/home/Enseignement/Cours/StatInfo/Python/ECDFThe.png')
plt.show(axThe)

#Diagramme baton binomiale
import matplotlib.path as path
import scipy.stats as st
SampleBinom=st.binom.rvs(20,0.25,size=10000)
tableBinom=pan.crosstab(index = SampleBinom,columns="freq",normalize=True)

l=len(tableBinom);xBinom = np.arange(l)
BinomTheorique=st.binom.pmf(xBinom,20,0.25)#probability mass function

figBinom, axBinom = plt.subplots()
axBinom.bar(xBinom,np.reshape(tableBinom.values,len(tableBinom)), width=0.05,color="#556b2f")
axBinom.plot(xBinom,BinomTheorique, '.')
figBinom.suptitle("Diagramme en bâton d'une variable B(20,0.25)")
plt.savefig('/home/Enseignement/Cours/StatInfo/Python/BatonBinomiale.png')
plt.show(axBinom)


#Hstogramme de poids (avec pandas, peu esthétique, comme d'habitude)
print(df["poids"])
plotPoids=df["poids"].plot.hist(title='Histogramme de poids')
plt.savefig('/home/Enseignement/Cours/StatInfo/Python/HistoPoids.png')
plt.show(plotPoids)

plotPoids=df["poids"].plot.hist(title='Histogramme de poids',density=True)
plt.savefig('/home/Enseignement/Cours/StatInfo/Python/HistoPoids2.png')
plt.show(plotPoids)


#Histogramme de poids (Defaut)
figPoids, axPoids = plt.subplots()
axPoids.hist(df["poids"],13, color=col[1],histtype='bar')
#axPoids.legend(prop={'size': 13})
axPoids.set_ylabel('Effectifs')
axPoids.legend(frameon=False)
figPoids.suptitle("Histogramme de la variable poids")
plt.savefig('/home/Enseignement/Cours/StatInfo/Python/HistoPoids3.png')
plt.show(axPoids)


#Histogramme de poids
figPoids, axPoids = plt.subplots()
bins=35+np.arange(14)*5
axPoids.hist(df["poids"],bins, color=col[2],histtype='bar')
axPoids.legend(prop={'size': 13})
axPoids.set_ylabel('Effectifs')
axPoids.legend(frameon=False)
figPoids.suptitle("Histogramme de la variable poids")
plt.savefig('/home/Enseignement/Cours/StatInfo/Python/HistoPoids3.png')
plt.show(axPoids)

#Histogramme de Age
figAge, axAge = plt.subplots()
binsAge=[*(65+np.arange(10)*2),87,91]
axAge.hist(df["age"],binsAge, color=col[3],histtype='bar',rwidth=0.95,density=True)
axAge.legend(prop={'size': 11})
axAge.set_ylabel('Densité')
axAge.legend(frameon=False)
figAge.suptitle("Histogramme de la variable age")
plt.savefig('/home/Enseignement/Cours/StatInfo/Python/HistoAge.png')
plt.show(axAge)

#Diagramme en bâton d'une B(100,0.25)
SBinom=st.binom.rvs(100,0.25,size=10000)
TBinom=pan.crosstab(index = SBinom,columns="freq",normalize=True)

l=len(TBinom);xBinom = np.arange(np.min(SBinom),np.min(SBinom)+l)

figBinom, axBinom = plt.subplots()
axBinom.bar(xBinom,np.reshape(TBinom.values,l), width=0.2,color="#556b2f")
#axBinom.plot(xBinom,NormT, col="red")
figBinom.suptitle("Diagramme en bâton d'une variable B(100,0.25)")
plt.savefig('/home/Enseignement/Cours/StatInfo/Python/BatonBinomiale100.png')
plt.show(axBinom)

#avec comparaison à la limite normale
SBinom=st.binom.rvs(100,0.25,size=10000)
TBinom=pan.crosstab(index = SBinom,columns="freq",normalize=True)

l=len(TBinom);xBinom = np.arange(np.min(SBinom),np.min(SBinom)+l)
xNorm=np.linspace(0,45,100)
NormT=st.norm.pdf(xNorm,loc=25,scale=np.sqrt(18.75))#probability density function


figBinom, axBinom = plt.subplots()
axBinom.bar(xBinom,np.reshape(TBinom.values,l), width=0.2,color="#556b2f")
axBinom.plot(xNorm,NormT, color="red")
figBinom.suptitle("Diagramme en bâton d'une variable B(100,0.25)")
plt.savefig('/home/Enseignement/Cours/StatInfo/Python/BatonBinomialeNormale.png')
plt.show(axBinom)

#Simulation d'une loi normale N(25,18.75)
SNorm=st.norm.rvs(25,np.sqrt(18.75),size=10000)
xNorm=np.linspace(0,45,100)
NormT=st.norm.pdf(xNorm,loc=25,scale=np.sqrt(18.75))#probability density function

figBinom, axBinom = plt.subplots()
axBinom.hist(SNorm,color="#556b2f",density=True,bins=50)
axBinom.plot(xNorm,NormT, color="red")
figBinom.suptitle("Diagramme en bâton d'une variable N(25,18.75)")
plt.savefig('/home/Enseignement/Cours/StatInfo/Python/HistNormale.png')
plt.show(axBinom)


#Illustration Moyenne
figAge, axAge = plt.subplots()
axAge.hist(df["age"],[*(65+np.arange(10)*2),90,92], color=col[1],rwidth=0.95,density=True)
ax2=axAge.twinx()
ax2.bar(np.mean(df["age"]),0.08,color='blue',width=.2)
axAge.legend(prop={'size': 11})
axAge.set_ylabel('Densité')
axAge.legend(frameon=False)
figAge.suptitle("Histogramme de la variable age avec Moyenne (en bleu)")
plt.savefig('/home/Enseignement/Cours/StatInfo/Python/HistoAgeMean.png')
plt.show(axAge)

#Variance
np.var(df["age"])#variance empirique
np.var(df["age"],ddof=1)#variance empirique non biaisée
np.std(df["age"],ddof=1)#écart-type

#Illustration Moyenne-écart-type
figAge, axAge = plt.subplots()
axAge.hist(df["age"],[*(65+np.arange(10)*2),90,92], color=col[1],rwidth=0.95,density=True)
ax2=axAge.twinx()
ax2.bar(np.mean(df["age"]),0.08,color='blue',width=.2)
ax2.plot([np.mean(df["age"])-np.std(df["age"]),np.mean(df["age"])+np.std(df["age"])],[0.04,0.04],color='red')
axAge.legend(prop={'size': 11})
axAge.set_ylabel('Densité')
axAge.legend(frameon=False)
figAge.suptitle("Histogramme de la variable age avec Moyenne (en bleu)")
plt.savefig('/home/Enseignement/Cours/StatInfo/Python/HistoAgeMeanSD.png')
plt.show(axAge)

#Quantile

print(np.quantile(df['poids'],[0,0.25,0.5,0.75,1],axis=0,interpolation='lower'))#[38 57 66 75 96]
print(np.quantile(df['age'],[0,0.25,0.5,0.75,1],axis=0,interpolation='lower'))#[65 70 74 78 91]
print(np.quantile(df['cafe'],[0,0.25,0.5,0.75,1],axis=0,interpolation='lower'))#[0 1 2 2 5]

np.quantile([1,2,3,4,5,6,7,8],[0,0.25,0.5,0.75,1],axis=0,interpolation='lower')

np.quantile([1,2,3,4,5,6,7,8],[0,0.25,0.5,0.75,1],axis=0)#pas la définition du cours

np.quantile([1,2,2,2,4,5,5.5,10],[0,0.25,0.5,0.75,1],axis=0,interpolation='lower')
np.quantile([1,2,2,2,4,5,5.5,10],[0,0.25,0.5,0.75,1],axis=0)


exbox=pan.DataFrame({'data':[1,2,2,2,4,5,5.5,10]})
exbox.boxplot(vert=False)
np.quantile(exbox,[0,0.25,0.5,0.75,1],axis=0,interpolation='lower')
plt.savefig('/home/Enseignement/Cours/StatInfo/Python/BoxExemple.png')
plt.show(box)

#Boxplot selon définition du cours (Facultatif)

pip install rpy2#la première fois, après installation de Rbase sur votre ordi
import rpy2
from rpy2.robjects.packages import importr
import rpy2.robjects as ro
from rpy2.robjects import pandas2ri
from rpy2.robjects.conversion import localconverter

base = importr("base")
qb=importr("qboxplot")
r=ro.r
rqboxplot=ro.r['qboxplot']
rquantile=ro.r['quantile']
with localconverter(ro.default_converter + pandas2ri.converter):
    rbox=ro.conversion.py2rpy(exbox)#conversion du DataFrame Pandas en un dataFrame de R
rquantile(robjects.FloatVector([1,2,2,2,4,5,5.5,10]),type=1)#calcul des quantiles
rqboxplot(rbox,qtype=1,horizontal=True,main="Un Diagramme à moustache selon le cours")#dessin du boxplot


#Boxplot avec pandas (premier potable !)
box=df.boxplot(column=['age','poids','taille'])
box.set_title('Diagramme à moustache de age, poids et taille')
plt.savefig('/home/Enseignement/Cours/StatInfo/Python/BoxAge.png')
plt.show(box)

#Boxplot avec matplotlib

figBox, axesBox = plt.subplots(figsize=(5, 4))

# rectangular box plot
all_data=(df.iloc[:,1:3].values)
bplot=axesBox.boxplot(all_data,vert=True,patch_artist=True,labels=['the','cafe']) 
axesBox.set_title('Diagramme à moustache de thé et café')
plt.savefig('/home/Enseignement/Cours/StatInfo/Python/BoxPLotTheCafe.png')
plt.show(axesBox)
