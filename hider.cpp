#include "hider.h"

void Enemy::initVar(){
	this->movementSpeed = 5.f;
}

void Enemy::initShape(){
	this->shape.setFillColor(sf::Color::Red);
	this->shape.setSize(sf::Vector2f(25.f, 25.f));
}

Enemy::Enemy(float x, float y){
	this->shape.setPosition(x, y);

	this->initVar();
	this->initShape();
}

Enemy::~Enemy(){

}

//Accessors
const sf::RectangleShape & Enemy::getShape() const{
	return this->shape;
}

//Functions

	//updates
void Enemy::updateInput(){
		//movment
		if(randomNum == 1){
			//right
			this->shape.move( movementSpeed, 0.0f);
		}else if(randomNum == 2){
			//left
			this->shape.move( -movementSpeed, 0.0f);
		}else if(randomNum == 3){
			//up
			this->shape.move( 0.0f, -movementSpeed);
		}else if(randomNum == 4){
			//down
			this->shape.move( 0.0f, movementSpeed);
		}else if(randomNum == 5){
			//right,up
			this->shape.move( movementSpeed, -movementSpeed);
		}else if(randomNum == 6){
			//right,down
			this->shape.move( movementSpeed, movementSpeed);
		}else if(randomNum == 7){
			//left,up
			this->shape.move( -movementSpeed, -movementSpeed);
		}else if(randomNum == 8){
			//left,down
			this->shape.move( -movementSpeed, movementSpeed);
		}
}
//make sure it doesnt leave the screen
void Enemy::updateWindowBoundsCollision(const sf::RenderTarget* target){
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

void Enemy::update(const sf::RenderTarget* target){

	this->updateInput();
	this->updateWindowBoundsCollision(target);
}

	//rendering
void Enemy::render(sf::RenderTarget* target){
	target->draw(this->shape);
}
