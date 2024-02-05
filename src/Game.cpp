#include <iostream>
#include "Game.h"

std::string hutName = "Grass Hut";
std::string hutMainD = "It's a grass hutt.";
std::string hutNorthD = "There is a rack of three weapons and a window before you.";
std::string hutSouthD = "There is a door leading out into the field before you.";
std::string hutEastD = "There is but a window before you.";
std::string hutWestD = "There is but a window before you.";
int hWidth = 9;
int hLength = 9;
bool hNExit = false;
bool hSExit = true;
bool hEExit = false;
bool hWExit = false;

Game::Game() 
	: m_Running(false)
{

}

Game::~Game() 
{

}

void Game::menu(Player* model, Scene* activeScene) 
{
	char pick;

	std::cin >> pick;

	switch(pick) 
	{
	case '0':
		std::cout << "1. Move\n" << "2. Look\n" << "3. Take\n" << "4. Drop\n" << "5. Status\n" << "A. Attack\n" << "R. Run\n" << "Q. Quit\n";
		break;
	case '1':
		model->move(activeScene);
		break;
	case '2':
		model->look(activeScene);
		break;
	case '3':
		model->take(activeScene);
		break;
	case '4':
		model->drop(activeScene);
		break;
	case '5':
		model->status();
		break;
	case 'A':
		model->attack();
		break;
	case 'R':
		model->escape();
		break;
	case 'Q':
		std::cout << "Goodbye!\n";
		m_Running = false;
		break;
	default:
		std::cout << "Invalid Choice.\n";
		break;	
	}

}

void Game::run() 
{
	m_Running = true;
	std::string id;

	std::cout << "Enter your name: ";
	std::cin >> id;

	SceneElement hut(hutName, hutMainD, hutNorthD, hutSouthD, hutEastD, hutWestD, hWidth, hLength, hNExit, hSExit, hEExit, hWExit);
	
	Scene* scene = new Scene(hut);
	Player* player = new Player(id, scene, 4, 4);

	std::cout << "Welcome, " << id << "! If you need command hints, type 0.\n";

	while(m_Running) 
	{
		menu(player, scene);
	}

	delete player;
	delete scene;
}

