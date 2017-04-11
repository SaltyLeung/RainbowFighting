#ifndef SALTY_ENGINE_H
#define SALTY_ENGINE_H
#include<vector>
using namespace std;
class Scene {
public:
	bool enabled;
	Scene():enabled(false) {};
	virtual void Run() {};
};

class Transform {
public:
	int x;
	int y;
	int z;
	int width;
	int length;
	Transform():x(0),y(0),z(0),width(0),length(0) {
	};
};

class GameObject {
public:
	Transform transform;
};

class SaltyEngine {
public:
	//vector<Scene> sceneQueue;
	bool gameRun;
	SaltyEngine() :gameRun(true) {};
	void update();
	virtual void GameLoading() {};
};
extern vector<Scene*>scenePtr;
#endif
