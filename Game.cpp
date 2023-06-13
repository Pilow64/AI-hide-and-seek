#include "Game.h"

//priv functions
void Game::initVar(){
	this->endGame = false;
	//game logic
	this->points = 0;
	this->spawnTimeMax = 10.f;
	this->spawnTimer = this->spawnTimeMax;
	
}

//window information
void Game::initWindow(){

	this->videoMode = sf::VideoMode(800, 600);
	this->window = new sf::RenderWindow(this->videoMode, "AI SEEK", sf::Style::Titlebar | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}

//Fonts
void Game::initFonts(){

}

//Text
void Game::initText(){

}

//constructors and destrustors
Game::Game(){

	this->initVar();
	this->initWindow();
	this->initFonts();
	this->initText();
}

Game::~Game(){

	delete this->window;
}

const bool & Game::getEndGame() const{
	
	return this->endGame;
}

//accessors
const bool Game::running() const{

	return this->window->isOpen();
}

//Functions

void Game::pollEvents(){

	//event polling
	while (this->window->pollEvent(this->sfmlEvent)){
	
		switch (this->sfmlEvent.type){
		
			case sf::Event::Closed:
				this->window->close();
				break;
			case sf::Event::KeyPressed:
				if(this->sfmlEvent.key.code == sf::Keyboard::Escape)
					this->window->close();
				break;
			default:
				//get rid of extra warnings
				break;
		}	
	}
}

//game logic and inputs

//mouse position
void Game::updateMousePosition(){

	this->mousePosWindow = sf::Mouse::getPosition(*this->window);

}
/*
//spawns the enemy random place at the top of the screen
void Game::spawnEnemy(){

	this->enemy.setPosition(
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
		0.f
	);
	
	this->enemy.setFillColor(sf::Color::Red);
	
	this->enemies.push_back(this->enemy);
}
//spawns the player in a random place
void Game::spawnPlayer(){

	this->player.setPosition(
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->player.getSize().x)),
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().y - this->player.getSize().y))
	);
	
	this->player.setFillColor(sf::Color::Green);
	
	this->play.push_back(this->player);
}
*/
//enemy stuff
void Game::updateEnemy(){

	this->enemy.update(this->window);
}

//player stuff
void Game::updatePlayer(){

	this->player.update(this->window);	
}

void Game::updateCollision(){

}

void Game::updateGui(){

}


void Game::update(){

	this->pollEvents();
	
	this->updateMousePosition();

	if(this->endGame == false){
		this->updatePlayer();
		this->updateEnemy();
		this->updateCollision();
		this->updateGui();
	}
}

//visuals/rendering them
void Game::renderGui(sf::RenderTarget* target){
	
}

void Game::render(){

	this->window->clear();
	
	//draw objects

	this->enemy.render(this->window);

	this->player.render(this->window);

	this->renderGui(this->window);

	//draw game
	this->window->display();
}
