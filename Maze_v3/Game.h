#pragma once
#include "Scene.h";
class Game {
public:
	void Start();
	Game();
	~Game();
private:
	bool p_Ended;
	Scene* p_Scene;
	void LoadContent();
	void Init();
	void Update();
	void Draw();
};