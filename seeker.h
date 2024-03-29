#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Player{

private:
	sf::RectangleShape shape;

	float movementSpeed;

	void initVar();
	void initShape();

public:
	Player(float x = 0.f, float y = 0.f);
	virtual ~Player();

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
