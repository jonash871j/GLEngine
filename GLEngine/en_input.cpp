#include "en_input.h"
#include "en_window.h"

#include <glfw3.h>

namespace Engine
{
	Input::Input()
	{
	}

	void Input::UpdateProperties(Window* window)
	{
		this->window = window;
	}
	void Input::Update()
	{
		for (int32_t i = 0; i < KeyMapSize; i++)
		{
			if (keyPressedMap[i] == InputState::Triggered)
				keyPressedMap[i] = InputState::Locked;
		}
	}
	bool Input::KeyState(Key key)
	{
		if (glfwGetKey(window->glfwWindow, (int32_t)key) == GLFW_PRESS)
			return true;
		return false;
	}
	bool Input::KeyPressed(Key key)
	{
		if (KeyState(key))
		{
			if (keyPressedMap[(int32_t)key] != InputState::Locked)
			{
				keyPressedMap[(int32_t)key] = InputState::Triggered;
				return true;
			}
		}
		else
		{
			keyPressedMap[(int32_t)key] = InputState::Unlocked;
		}
		return false;
	}
	bool Input::KeyReleased(Key key)
	{
		Console::PrintError("KeyReleased not implemented!");
		return true;
	}
}
