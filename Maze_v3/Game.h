#include "Scene.h";
class Game {
public:
	void Start();
	~Game();
protected:
	bool p_Ended;
	Scene *p_Scene;
private:
	void LoadContent();
	void Init();
	void Update();
	void Draw();
};