# pa2-spam-co
pa2-spam-co created by GitHub Classroom
Angel Perez: angel.perez97@upr.edu
Darío M. Nazario: dario.nazario@upr.edu

For Phase 1 we created an original Map#4, added random ghosts by pressing g and fixed the number
of lives that pacman can have to 3

For Phase 2 we implemented the abstract Powerup class and a DoubleSpeed Powerup that activates
when you press the spacebar. We also made it possible to pause the game by pressing p and
win when you eat all the entities(fruits and dots)

Finally, for Phase 3 we implemented the Cherry, Strawberry and Random Powerups. The Cherry
teleports you to a random location, Strawberry makes you invicible and invincible to ghosts
and Random summons random fruits every 100 entities eaten. They give you rarndom points 
between 100 and 900. A ChoosePlayerState was also added which let's you change between Pacman and
and Ms. Pacman. The character select menu is accesible in the main menu.


Controls
-------------------------------------
'w'                  Pacman moves up|
'a'                  Pacman moves left|
's'                  Pacman moves down|
'd'                  Pacman moves right|
'g'                  Summons random ghosts
'n'                  Pacman loses a life (debugging purposes)|
'm'                  Pacman gains a life (debugging purposes)|
'y'                  Pacman instantly wins (debugging purpooses)|
'p'                  Pauses the game|
'spacebar'           Activates double speed powerup

Entities
-----------------------------------------
Cherry                 Teleports Pacman to a random location|
Strawberry              makes Pacman invisible and Invincible to ghosts|
Random                  Summons random fruits every 100 entites consumed and gives you
                        random points ranging between 100-900
