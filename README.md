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

