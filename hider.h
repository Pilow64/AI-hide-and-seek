#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include<iostream>
#include<ctime>
#include<stdlib.h>


class Enemy{

private:
	sf::RectangleShape shape;

	float movementSpeed;
	
	int randomNum = rand() % 8 + 1;

	void initVar();
	void initShape();

public:
	//postion
	Enemy(float x = 100.f, float y = 100.f);
	virtual ~Enemy();
	
//Accessors
	const sf::RectangleShape& getShape() const;
	
//Functions
	
	//updating
	void updateInput();
	void updateWindowBoundsCollision(const sf::RenderTarget* target);
	void update(const sf::RenderTarget* target);

	//rendering
	void render(sf::RenderTarget* target);

};
