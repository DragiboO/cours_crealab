# Notre Projet Crealab ! 

### Dans un premier temps notre équipe était composée de Théa Blachon, Ambroise Piétu et de Julien Grenouilleau.

---

>### Notre projet consiste en un équivalent de radar de recul, comme ceux dans les voitures.
>
>- Le système est composé d'une carte arduino qui gère toutes les interactions des différents composants avec le code à l'interieur.
>
>- D'un capteur a ultra son qui permet de déctecter à quelle distance se trouve l'obstacle qui se situe devant lui.
>
>- D'un potentiomètre qui nous permet de gérer la sensibilité du capteur de distance.
>
>- Et enfin de 7 leds et résistance qui nous permettent d'avoir un affichage graduel de la distance.

### Explication / Fonctionnement

>- Tout commence avec le capteur, il envoie son retour de valeur à l'arduino qui les traites et grace au code, la distance est calculé.
>- Puis avec la valeur de distance récupérée, la suite de l'algorithme est lu par la carte et en fonction de la valeur de la distance, certaines conditions sont remplies ou non.
>- Enfin en fonction de ces conditions ce sont les leds qui s'allument pour représenter la distance.
>
>> Fonctionnement
>>
>>- La led blanche s'allume = obstacle à 1m
>>- La led bleu s'allume = obstacle à 50cm
>>- La led verte s'allume = obstacle à 25cm
>>- La led jaune s'allume = obstacle à 15cm
>>- La 1re led rouge s'allume = obstacle à 10cm
>>- La 2ème led rouge s'allume et clignote = obstacle à 7,5cm
>>- La 3ème led rouge s'allume et clignote vite = obstacle à 5cm
>
>> Multiplicateur avec le potentiomètre :
>>
>> - De base les valeurs sont celles du dessus mais on peut les multiplier jusqu'à 4 fois avec le potentiomètre a fond.

