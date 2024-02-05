#pragma once
#include "Model.h"

class Game
{
public: 
	Game();
	~Game();

	void menu(Player* model, Scene* activeScene);
	void run();
	
private:

	bool m_Running;

};

