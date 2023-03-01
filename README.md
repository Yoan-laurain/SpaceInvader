# SpaceInvader

Bug 1 : 
	Les 3 variables : 
		std::default_random_engine rGen;
		typedef std::uniform_int_distribution<int> intRand;
		typedef std::uniform_real_distribution<float> floatRand;

	sont passés dans une instances pour éviter des référencements de partout

Bug 2 :
	Passer le Update des enfants de GameObject en override.

Bug 3 :
 	alienLaser -> AlienLaser dans PlayerField.cpp dans SpawnLaser
	playerShip -> PlayerShip dans PlayerFiled.cpp dans PlayField::GetPlayerObject()

Bug 4 :
	a.pos.x -> a.pos.y dans main.cpp

Bug 5 : 
	AlienShip n'existe pas dans le constructor c'est Alien

Bug 6 : 
	PlayerField:: Update 
		- On modifiait la collection en ajoutant des lasers en même temps 
		que on itérait dessus maintenant il y a un tableau qui ajoute les lasers après les itérations

Bug 7 :
	PlayerField:: Update 
		- On modifiait la collection en supprimant des lasers en même temps 
		que on itérait dessus maintenant il y a un tableau qui supprime les lasers après les itérations

NB: 
	Mise en place du override sur les méthodes de RndInput 
        - On arrete le jeu quand le joueur meurt -> Alien cpp -> Update et Alien Laser cpp ->Update 
	- Mise en place de decreased health dans player ship hérité de GameObject 
	- Same pour Alien 
	- Delete du player laser que quand on le remove du tableau
        - Création classe better alien herite de alien
	- Si 2 survivants alors remplace tout les aliens par better aliens
	- Ajout de la classe rocher + génération des rochers dans le main + collision des rochers avec les laser dans le update des lasers
	- Remplacement for loop main par while true 
	- Input windows.h dans uneclasse playerInput 
	- Remplacement des vector 2D par sf::vector2f + suppression de la classe vector2d
	- Clean du main ( pop ) est mise en place dans playField
	- Mise en place du clean code dans plusieurs fichiers ( 1 méthode 1 "action" ) 
	- Check des pointeurs aux destructeurs
	- variables de classes m_

	- Partie configurable : 
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

