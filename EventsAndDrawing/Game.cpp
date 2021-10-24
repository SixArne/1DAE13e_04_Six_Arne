#include "pch.h"
#include "Game.h"

#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	CalculateRandomRectangle();
	// initialize game resources here
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	const Color4f greenColor{0.0f, 0.8f, 0.0f, 1.f};
	const Color4f greyColor{0.0f, 0.0f, 0.0f, 0.5f};

	// termine color code
	const Color4f drawColor = (g_RectColor == RectColor::GREY)? greyColor: greenColor;

	utils::SetColor(drawColor);
	utils::FillRect(g_RandomRectangle);
}

void Update(float elapsedSec)
{
	// process input, do physics 

	// e.g. Check keyboard state
	//const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	//if ( pStates[SDL_SCANCODE_RIGHT] )
	//{
	//	std::cout << "Right arrow key is down\n";
	//}
	//if ( pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
	//{
	//	std::cout << "Left and up arrow keys are down\n";
	//}
}

void End()
{
	// free game resources here
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{

}

void OnKeyUpEvent(SDL_Keycode key)
{
	//switch (key)
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{

}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
	{
		std::cout << "  [" << e.x << ", " << g_WindowHeight - e.y << "]\n";

		const MousePosition mousePosition = {
			e.x,
			int(g_WindowHeight) - e.y
		};

		//ClearBackground();
		if (RectangleClicked(mousePosition, g_RandomRectangle))
		{
			CalculateRandomRectangle();	
		}

		break;
	}
	case SDL_BUTTON_RIGHT:
		//std::cout << "Right mouse button released\n";
		break;
	case SDL_BUTTON_MIDDLE:
		//std::cout << "Middle mouse button released\n";
		break;
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here
bool RectangleClicked(const MousePosition& e, const Rectf& rect)
{
	return (
		// x boundary check
		e.x < (rect.left + rect.width) &&
		e.x > rect.left &&
		// y boundary check
		e.y < (rect.bottom + rect.height) &&
		e.y > rect.bottom
	);
}

void CalculateRandomRectangle()
{
	ClearBackground(1,1,1);

	const float rectMinWidth{60}, rectMinHeight{40};

	const float randomRectWidth{float(rand() % int(g_WindowWidth) + rectMinWidth)};
	const float randomRectHeight{float(rand() % int(g_WindowHeight) + rectMinHeight)};

	const float randomLeftPosition{float(rand() % int(g_WindowWidth - randomRectWidth - 50))};
	const float randomBottomPosition{float(rand() % int(g_WindowHeight - randomRectHeight - 50))};

	g_RandomRectangle = Rectf{
		randomLeftPosition,
		randomBottomPosition,
		randomRectWidth,
		randomRectHeight
	};

	// revise later
	g_RectColor = (g_RectColor == RectColor::GREY)? RectColor::GREEN: RectColor::GREY;
	//
}
#pragma endregion ownDefinitions