#include "Scene.h"
#include <iostream>
#include <memory>

SceneElement::SceneElement (std::string& name, std::string& mDesc, std::string& nDesc, std::string& sDesc, std::string& eDesc, std::string& wDesc,
	int width, int length, bool nExit, bool sExit, bool eExit, bool wExit) 
	: eName(name), eMainD(mDesc), eNorthD(nDesc), eSouthD(sDesc), eEastD(eDesc), eWestD(wDesc), eWidth(width), eLength(length),
	eNExit(nExit), eSExit(sExit), eEExit(eExit), eWExit(wExit)
{
	
}

Scene::Scene (SceneElement& key) 
	: name(key.eName), m_MainD(key.eMainD), m_NorthD(key.eNorthD), m_SouthD(key.eSouthD), m_EastD(key.eEastD), m_WestD(key.eWestD), 
	width(key.eWidth), length(key.eLength), nExit(key.eNExit), sExit(key.eSExit), eExit(key.eEExit), wExit(key.eWExit)
{
	
}

Scene::~Scene () {}

void Scene::enter(Scene* activeScene, Scene* nextScene) 
{
	activeScene = nextScene;

	std::cout << "You have entered: " << name << "\n";
	std::cout << m_MainD << "\n";

}

void Scene::exit(Scene* activeScene, SceneElement& pkey, SceneElement& key) 
{
	Scene* previousScene = new Scene(pkey);
	Scene* newScene = new Scene(key);

	std::cout << "You are leaving: " << name << "\n";

	newScene->enter(activeScene, newScene);

	delete newScene;
}

void Scene::view(std::string& direction) {

	if (direction == "North")
		std::cout << m_NorthD << "\n";
	else if (direction == "South")
		std::cout << m_SouthD << "\n";
	else if (direction == "East")
		std::cout << m_EastD << "\n";
	else if (direction == "West")
		std::cout << m_WestD << "\n";
	else
		std::cout << m_MainD << "\n";

}

