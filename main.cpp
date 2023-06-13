//program for game
#include <iostream>
#include "Game.h"

int main(){
	//Init srand
	std::srand(static_cast<unsigned>(time(NULL)));

	//Init Game engine
	Game game;

	//game loop
	while(game.running()){

		//upadte
		game.update();
		//render
		game.render();
	}
	
	//end of the application
	return 0;
}

