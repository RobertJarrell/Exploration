#pragma once
#include "Scene.h"

class Model {
public:

	std::string local, vKey, hKey;
	int x, y;
	
	virtual ~Model();

	virtual void view();

};

class Portal : public Model {};

class Scenery : public Model {};


class Player : public Model  {
public:
	
	Player(std::string& name, Scene* activeScene, int xPos, int yPos);
	~Player();

	void move(Scene* activeScene);
	void look(Scene* activeScene);
	void status();
	void take(Scene* activeScene);
	void drop(Scene* activeScene);
	void attack();
	void escape();

private:

	std::string m_Name;
	int m_Strength, m_Health, m_Speed;
	

};