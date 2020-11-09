#include "en_time.h"
#include "glfw3.h"

namespace Engine
{
	Time::Time()
	{
	}

	void Time::Update()
	{
		float time = (float)glfwGetTime();
		deltaTime = time - lastTime;
		lastTime = time;

		fPS = 1.0f / (deltaTime / 2.0f);
		avgFPS_Store += fPS;
		avgFPS_Interval++;
		if (avgFPS_Interval >= 100)
		{
			avgFPS = avgFPS_Store / 100.0f;
			avgFPS_Store = 0.0f;
			avgFPS_Interval = 0;
		}
	}
	float Time::GetDeltaTime()
	{
		return deltaTime;
	}
	float Time::GetFPS()
	{
		return fPS;
	}
	float Time::GetAvgFPS()
	{
		return avgFPS;
	}
}
