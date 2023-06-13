#pragma once

#include<iostream>
#include<vector>
#include<ctime>
#include<sstream>

#include "seeker.h"
#include "hider.h"
/*
	Class that handles as the game engine
	Wrapper class
 */

class Game{
	private:
		//var
		//windows
		sf::RenderWindow* window;
		sf::VideoMode videoMode;
		sf::Event sfmlEvent;
		
		Player player;
		Enemy enemy;

		sf::Font font;
		sf::Text guiText;
		sf::Text endGameText;

		//Mouse position
		sf::Vector2i mousePosWindow;
		
		//Game logic
		bool endGame;
		int points;
		float spawnTimer;
		float spawnTimeMax;

		//private functions
		void initVar();
		void initWindow();
		void initFonts();
		void initText();
		
	public:
		//construtors / destructors
		Game();
		~Game();

		//accessors
		const bool& getEndGame() const;
		
		//functions
		//probs wont need this 
		const bool running() const;
		void pollEvents();

		void updateMousePosition();
		void updatePlayer();
		void updateEnemy();
		void updateCollision();
		void updateGui();
		void update();

		void renderGui(sf::RenderTarget* target);
		void render();
};


