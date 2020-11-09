#pragma once
#include "en_def.h"

namespace Engine
{
	class Time
	{
		friend class Window;
	private:
		float lastTime = 0.0001f;
		float deltaTime = 0.0001f;
	
	private:
		float fPS = 0.0f;
		float avgFPS = 0.0f;
		float avgFPS_Store = 0.0f;
		uint8_t avgFPS_Interval = 0;

	private:
		Time();

	public:
		void Update();

	public:
		float GetDeltaTime();
		float GetFPS();
		float GetAvgFPS();
	};
}