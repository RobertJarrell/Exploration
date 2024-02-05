#include <iostream>
#include "Model.h"



/*Model::Model(Scene* activeScene, int xPos, int yPos)
	:local(activeScene->name), x(xPos), y(yPos)
{
	if (xPos < (activeScene->width / 2) -1)
		hKey = "West";
	else if (xPos == activeScene->width / 2 || xPos == (activeScene->width / 2) + 1 || xPos == (activeScen->width / 2) - 1)
		hKey = "Central";
	else
		hKey = "East";
	if (yPos < (activeScene->length / 2) - 1)
		vKey = "South";
	else if (yPos == activeScene->width / 2 || xPos == (activeScene->length / 2) + 1 || xPos == (activeScen->length / 2) - 1)
		vKey = "Central";
	else
		vKey = "North";
}*/


Model::~Model() {}

void Model::view() {
	
	std::cout << "Location: " << local << "\n" << vKey << ", " << hKey << "\n" << x << ", " << y << "\n";
}


Player::Player(std::string& name, Scene* activeScene, int xPos, int yPos) 
	: m_Name(name), m_Strength(10), m_Health(100), m_Speed(3)
{
	this->local = activeScene->name;
	this->x = xPos;
	this->y = yPos;
	if (xPos < (activeScene->width / 2) - 1)
		hKey = "West";
	else if (xPos == activeScene->width / 2 || xPos == (activeScene->width / 2) + 1 || xPos == (activeScene->width / 2) - 1)
		hKey = "Central";
	else
		hKey = "East";
	if (yPos < (activeScene->length / 2) - 1)
		vKey = "South";
	else if (yPos == activeScene->width / 2 || xPos == (activeScene->length / 2) + 1 || xPos == (activeScene->length / 2) - 1)
		vKey = "Central";
	else
		vKey = "North";

}


Player::~Player() {}

void Player::move(Scene* activeScene) {

	char walk;
	bool xHasChanged = false;
	bool yHasChanged = false;

	
	std::cout << "Choose a direction.\n" << "1. North  2. South  3. East  4. West  5. Cancel: ";
	std::cin >> walk;
		
	switch (walk) {
	case '1':
		this->y += this->m_Speed;
		yHasChanged = true;
		std::cout << "You walk north " << m_Speed << " spaces.\n";
		break;
	case '2':
		this->y -= this->m_Speed;
		yHasChanged = true;
		std::cout << "You walk south " << m_Speed << " spaces.\n";
		break;
	case '3':
		this->x += this->m_Speed;
		xHasChanged = true;
		std::cout << "You walk east " << m_Speed << " spaces.\n";
		break;
	case '4':
		this->x -= this->m_Speed;
		xHasChanged = true;
		std::cout << "You walk west " << m_Speed << " spaces.\n";
		break;
	default:
		break;
	}

	if (xHasChanged && x < (activeScene->width / 2) - 1) {

		this->hKey = "West";

		if (x < 0) {
			//if (activeScene->wExit ? std::cout << activeScene->wExitMessage : std::cout << activeScene->westBoundary);
			std::cout << "The west wall blocks your path; you'll need to find a better exit than the window.\n";
			this->x = 0;
		}

	}

	else if (xHasChanged && x == activeScene->width / 2 || x == (activeScene->width / 2) + 1 || x == (activeScene->width / 2) - 1) {
		this->hKey = "Central";
	}
	
	else if (xHasChanged && x > (activeScene->width / 2) + 1) {
		
		this->hKey = "East";
		
		if (x > activeScene->width) {
			//if (activeScene->eExit ? std::cout << activeScene->eExitMessage : std::cout << activeScene->eastBoundary);
			std::cout << "The east wall blocks your path; you'll need to find a better exit than the window.\n";
			this->x = activeScene->width;

		}

	}
	else if (yHasChanged && y < (activeScene->length / 2) - 1) {
		
		this->vKey = "South";
		
		if (y < 0) {
			//if (activeScene->sExit ? std::cout << activeScene->sExitMessage : std::cout << activeScene->southBoundary);
			std::cout << "Adventuare beckons; use the door to enter the fields outside.\n";
			this->y = 0;
		}

	}

	else if (yHasChanged && y == activeScene->length / 2 || y == (activeScene->length / 2) + 1 || y == (activeScene->length / 2) - 1) {

		this->vKey = "Central";
	}
		
	else if (yHasChanged && y > (activeScene->length / 2) + 1) {

		this->vKey = "North";

		if (y > activeScene->length) {
			//if (activeScene->nExit ? std::cout << activeScene->nExitMessage : std::cout << activeScene->northBoundary);
			std::cout << "The north wall blocks your path; you'll need to find a better exit than the window.\n";
			this->y = activeScene->length;

		}

	}
	
}

void Player::look(Scene* activeScene) {
	
	std::string target;

	std::cout << "What would you like to look at? ";
	std::cin >> target;

	if (target == "North" || target == "South" || target == "East" || target == "West" || target == "around")
		activeScene->view(target);
	else
		std::cout << "You can't find that.\n";

}

void Player::status() {

	std::cout << "Name: " << m_Name << "\n";
	//std::cout << "Location: " << local << "\n" << "Position: " << key << "\n" << x << ", " << y << "\n";
	view();

	std::cout << "Status:\n" << "Strength: " << m_Strength << "\n" << "Health: " << m_Health << "\n" << "Speed: " << m_Speed << "\n";

}

void Player::take(Scene* activeScene) {

	std::cout << "There is nothing to take.\n";

}

void Player::drop(Scene* activeScene) {

	std::cout << "You have nothing to drop.\n";

}

void Player::attack() {

	std::cout << "There is nothing to attack.\n";

}

void Player::escape() {

	std::cout << "There is nothing to run from.\n";

}

