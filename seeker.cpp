#include "seeker.h"

void Player::initVar(){
	this->movementSpeed = 5.f;
}

void Player::initShape(){
	this->shape.setFillColor(sf::Color::Green);
	this->shape.setSize(sf::Vector2f(25.f, 25.f));
}

Player::Player(float x, float y){
	this->shape.setPosition(x, y);

	this->initVar();
	this->initShape();
}

Player::~Player(){

}

//Accessors
const sf::RectangleShape & Player::getShape() const{
	return this->shape;
}

//Functions

	//updates
void Player::updateInput(){
	//keyboard inputes
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		this->shape.move(0.0f, 0.0f);
		
	}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		this->shape.move(0.0f, 0.0f);

	}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		this->shape.move(-movementSpeed, -movementSpeed);

	}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		this->shape.move(-movementSpeed, movementSpeed);

	}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		this->shape.move(movementSpeed, -movementSpeed);

	}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		this->shape.move(movementSpeed, movementSpeed);

	}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		this->shape.move(-movementSpeed, 0.0f);

	}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		this->shape.move(movementSpeed, 0.0f);

	}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		this->shape.move(0.0f, movementSpeed);

	}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		this->shape.move(0.0f, -movementSpeed);
		}
}

void Player::updateWindowBoundsCollision(const sf::RenderTarget* target){
//bounderies
	//left
	if(this->shape.getGlobalBounds().left <= 0.f)
		this->shape.setPosition(0.f, this->shape.getGlobalBounds().top);

	//right
	if(this->shape.getGlobalBounds().left + this->shape.getGlobalBounds().width >= target->getSize().x)
		this->shape.setPosition(target->getSize().x - this->shape.getGlobalBounds().width, this->shape.getGlobalBounds().top);

	//top
	if(this->shape.getGlobalBounds().top <= 0.f)
		this->shape.setPosition(this->shape.getGlobalBounds().left, 0.f);
	//bottom
	if(this->shape.getGlobalBounds().top + this->shape.getGlobalBounds().height >= target->getSize().y)
		this->shape.setPosition(this->shape.getGlobalBounds().left, target->getSize().y - this->shape.getGlobalBounds().height);
}

void Player::update(const sf::RenderTarget* target){
	this->updateInput();

	this->updateWindowBoundsCollision(target);
}

	//rendering
void Player::render(sf::RenderTarget* target){
	target->draw(this->shape);
}
