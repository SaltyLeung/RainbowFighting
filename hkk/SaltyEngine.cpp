#include"SaltyEngine.h"
void  SaltyEngine::update() {
		for (int i = 0;i<=scenePtr.size()-1;++i)
			if((*(scenePtr[i])).enabled==true)(*(scenePtr[i])).Run();
}
