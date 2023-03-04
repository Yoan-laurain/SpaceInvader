# SpaceInvader

Bonjour, vous trouverez dans ce document tout les elements corrigés et ajoutés au projet.
Si vous avez une question n'hésitez pas à me contacter. Bonne correction.

**`Threshold 1 : Bugs`**

`Bug 1 : `

	Les 3 variables : 

		- std::default_random_engine rGen;
		- typedef std::uniform_int_distribution<int> intRand;
		- typedef std::uniform_real_distribution<float> floatRand;

	sont passés dans une instance pour éviter des référencements croisés et donc
	une erreur de compilation.

`Bug 2 :`
	
	J'ai passer le Update des enfants de la classe GameObject en override.
	Ceci afin que le Update du parent GameObject puissent appeler le Update des enfants.

`Bug 3 :`

 	alienLaser -> AlienLaser dans PlayerField.cpp dans SpawnLaser
	playerShip -> PlayerShip dans PlayerFiled.cpp dans PlayField::GetPlayerObject()

`Bug 4 :`

	J'ai remplacer la valuer : a.pos.x par a.pos.y dans main.cpp
	Pour la modification de la position en y des aliens.
	Il y a avait 2 fois la même ligne pour la position en x.

`Bug 5 : `

	Dans la classe Alien il y avait une erreur de nommage.
	AlienShip n'existe pas dans le constructor c'est Alien

`Bug 6 : `

	Dans la méthode PlayerField::Update 

		On modifiait la collection en ajoutant des lasers en même temps 
		que on itérait dessus maintenant il y a un tableau qui ajoute 
		les lasers après les itérations pareil pour les suppréssions.

`Bug 7 : `

	Dorénavant on supprime le player laser que quand il est retiré du tableau d'objets.

`Bug 8 : `

	A partir de 41 aliens on avait un alien qui spawnait à droite de l'écran 
	Puis tomber inexorablement car on le déplacer puis on checkait les border maintenant 
	c'est inversé dans : Alien::Update

`Threshold 1 : Ajout, améliorations`

Création d'une architecture de dossiers classes etc... 

Mise en place du override sur les méthodes de RndInput qui n'étaient pas override.

Arret du jeu quand le joueur meurt -> Alien cpp -> Update et Alien Laser cpp ->Update

Mise en place de decreased health dans player ship et Alien hérité de GameObject
	afin de pouvoir gérer la vie du joueur et des aliens

Création classe better alien herite de alien

Quand il y a x aliens restants ils sont remplacés par des better aliens.
	PlayerField -> UpgradeAliens

Ajout de la classe rocher + génération des rochers dans PlayerShip::PopulateRock +
 collision des rochers avec les laser dans le update des lasers

Clean du main est déplacement de son code dans playerShip populateField

Remplacement for loop main par while true

Creation d'une classe player Input Action pour gérer les inputs du joueur

Mise en place du clean code dans plusieurs fichiers ( 1 méthode 1 "action" )

Check si nullptr des pointeurs aux destructeurs

Check de tout les pointeurs

Amélioration de la détection de la fin de jeu ( collision player ou hors de map en y ) dans Alien::Update()

Renommage des variables de classe avec m_


`- Partie configurable :` 

	- Nb aliens
	- Nb rocks
	- Nb aliens lasers
	- Nb players lasers
	- Nb of remaining aliens before tuning them into better aliens
	- Alien laser speed and damage
	- Player health 
	- Player speed
	- Player laser damage and speed
	- Better alien stats