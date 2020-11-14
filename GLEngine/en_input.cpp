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

		if ((isMouseDeltaMode) && (mouseDeltaInterval++ % 2 == 0))
			glfwSetCursorPos(window->glfwWindow, (double)window->width / 2.0, (double)window->height / 2.0);
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
	bool Input::MouseState(MouseButton mouseButton)
	{
		if (glfwGetMouseButton(window->glfwWindow, (int32_t)mouseButton) == GLFW_PRESS)
			return true;
		return false;
	}
	Vector2D Input::MousePosition()
	{
		double x = 0.0f;
		double y = 0.0f;
		glfwGetCursorPos(window->glfwWindow, &x, &y);
		return Vector2D((float)x / (float)window->xScale, (float)y / (float)window->yScale);
	}
	Vector2D Input::MouseDelta()
	{
		Vector2D delta = MousePosition() - Vector2D(window->width / 2, window->height / 2);

		if (delta.x != 0.0f)
			delta.x = 1.0f / delta.x;

		if (delta.y != 0.0f)
			delta.y = -(1.0f / delta.y);

		return delta;
	}
	void Input::SetIsMouseDeltaMode(bool state)
	{
		if (state)
		{
			isMouseDeltaMode = true;
			glfwSetInputMode(window->glfwWindow, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
		}
		else
		{
			isMouseDeltaMode = false;
			glfwSetInputMode(window->glfwWindow, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		}
	}
	bool Input::GetIsMouseDeltaMode(bool state)
	{
		return isMouseDeltaMode;
	}
}
