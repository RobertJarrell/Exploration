#pragma once
#include <vector>
#include <string>

class Model;

struct SceneElement {

	SceneElement(std::string& name, std::string& mDesc, std::string& nDesc, std::string& sDesc, std::string& eDesc, std::string& wDesc,
		int width, int length, bool nExit, bool sExit, bool eExit, bool wExit);

	std::string eName, eMainD, eNorthD, eSouthD, eEastD, eWestD;
	int eWidth, eLength;
	bool eNExit, eSExit, eEExit, eWExit;

};


class Scene {
public:

	std::string name;
	int width, length;
	bool nExit, sExit, wExit, eExit;

	Scene(SceneElement& key);
	~Scene();

	void enter(Scene* activeScen, Scene* nextScene);
	void exit(Scene* activeScene, SceneElement& pkey, SceneElement& key);
	void view(std::string& direction);

private:
	std::string m_MainD, m_NorthD, m_SouthD, m_EastD, m_WestD;
	

};
