# SpaceInvader

Bonjour, vous trouverez dans ce document tous les éléments corrigés et ajoutés au projet.

Il y a pas mal de commentaires dans le code et ici mais j'ai pu oublier des choses.

J'ai essayé d'être le plus exhaustif possible. 

J'ai tout fait jusqu'a la moitié du threshold 2. ( Avant le système de score )

Si vous avez une question n'hésitez pas à me contacter.

Bonne correction.

**`Threshold 1 : Bugs`**

`Bug 1 : `

	Les 3 variables : 

		- std::default_random_engine rGen;
		- typedef std::uniform_int_distribution<int> intRand;
		- typedef std::uniform_real_distribution<float> floatRand;

	sont passées dans une instance pour éviter des référencements croisés et donc
	une erreur de compilation.

`Bug 2 :`
	
	J'ai passé le Update des enfants de la classe GameObject en override.
	Ceci afin que le Update du parent GameObject puisse appeler le Update des enfants.

`Bug 3 :`

 	Renommage de alienLaser -> AlienLaser dans PlayerField::SpawnLaser
	Renommage de playerShip -> PlayerShip dans PlayField::GetPlayerObject()

`Bug 4 :`

	J'ai remplacer la valeur : 
	
		a.pos.x par a.pos.y dans main.cpp

	Pour la modification de la position en y des aliens.
	Il y a avait 2 fois la même ligne pour la position en x.

`Bug 5 : `

	Dans la classe Alien il y avait une erreur de nommage.
	AlienShip n'existe pas dans le constructor c'est Alien

`Bug 6 : `

	Dans la méthode PlayerField::Update 

		On modifiait la collection en ajoutant des lasers en même temps 
		qu'on itérait dessus maintenant il y a un tableau qui ajoute 
		les lasers après les itérations, pareil pour les suppressions.

`Bug 7 : `

	Dorénavant on supprime le player laser que quand il est retiré du tableau d'objets.
	De mémoire il était delete 2 fois et donc crashait.

`Bug 8 : `

	Quand un alien spawn près d'un bord il était bugged 
	Il tomber inexorablement car on le déplacer puis on checkait les borders maintenant 
	c'est inversé dans : Alien::Update
	Il était toujours considéré comme out donc y++

`Bug 9 : `

	On check les spawn et despawn des lasers si ils sont pas déjà en ajout ou en delete
	sinon ya des lasers "fantomes" on gagne des lasers ( les aliens aussi ) 
	ça casse tout dans les méthodes PlayField::SpawnLaser et PlayField::DespawnLaser


`Threshold 1 : Ajout, améliorations`


`BetterAlien`

	- Création de la classe better alien qui hérite de alien

	- Quand il y a x aliens restants ils sont remplacés par des better aliens.
	PlayerField -> UpgradeAliens

	- On supprime les aliens et on les remplace par des better aliens

	- Constructeur perso pour les better aliens

`Ajout de la classe rocher`

	- Génération des rochers dans PlayerShip::PopulateRock
	- Collision des rochers avec les lasers dans le update des lasers
	- Implémentation du constructeur de rocher ( images etc.. )

`Main`
	
	- Clean du main et déplacement d'une partie de son code dans playerShip populateField
	- Mise en place de Playfield dans le main en tant que singleton accessible avec GetGame()
	- Remplacement de la for loop dans le main.cpp par while true
	- Retrait des renderlist item inutiles
	- Possibilité de switch de renderer dans le main avec un int

`Clean du code et optimisation`

	- Création d'une architecture de dossiers, classes etc...
	- Mise en place du clean code dans plusieurs fichiers ( 1 méthode 1 "action" )
	- Check des pointeurs nullptr aux destructeurs
	- Check de tous les pointeurs quand on les utilise
	- Renommage des variables de classe avec m_
	- Optimisation à la volée de plusieurs zones de codes
	- Renommage du projet de Dirty to not Dirty ( Dirty c'est moche )

`Mise en place du renderer SFML`

	- Création de la classe SFMLRenderer
	- Gestion de la scale
	- Création d'une classe IRenderer pour faire hériter les 2 renderers
	- Override des méthodes de IRenderer
	- Ajout de sf::Texture et sf::Sprite dans GameObject
	- Ajout de l'initialisation des textures dans chaque classe fille de GameObject
	- Implémentation de la méthode draw 

`Mise en place des inputs SFML`

	- DefaultKeyBind.h pour les inputs par défaut
	- InputAction.h pour les actions possibles
	- InputManager.h pour la gestion des inputs
	- PlayerInputAction.h pour les actions du joueur
	- PlayerShip::Start pour la configuration des inputs

`- Partie configurable : PlayField.h`

	- Nb aliens
	- Nb rocks
	- Nb aliens lasers
	- Nb players lasers
	- Nb of remaining aliens before tuning them into better aliens

`- Partie configurable : PlayerShip.h`

	- Player health 
	- Player speed
	- Player laser damage and speed

`- Partie configurable : Alien.h et BetterAlien.h`
	
	- Alien laser speed and damage
	- Better alien stats

`Autres`

	- Mise en place du override sur les méthodes de RndInput qui n'étaient pas override.

 	- Arrêt du jeu quand le joueur meurt -> Alien cpp -> Update et Alien Laser cpp ->Update

	- Mise en place de decreased health dans player ship et Alien hérité de GameObject
	afin de pouvoir gérer la vie du joueur et des aliens

	- Amélioration de la détection de la fin de jeu ( collision player ou hors de map en y ) dans Alien::Update()

J'avais commencé à faire les collisions de manière moins bête mais j'ai pas eu le temps de finir ducoup
j'ai rien mis