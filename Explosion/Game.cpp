#include "pch.h"
#include "Game.h"

#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground();

	DrawExplosion();
	// Put your own draw statements here

}

void Update(float elapsedSec)
{
	UpdateExplosion(elapsedSec);

	g_NrOfFrames++;
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
	//std::cout << "  [" << e.x << ", " << g_WindowHeight - e.y << "]\n";
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
	{
		ProcessMouseClick(e);

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
void ProcessMouseClick(const SDL_MouseButtonEvent& e)
{
	const int mouseX{e.x};
	// inverse mouse because of OS behaviour
	const int mouseY{int(g_WindowHeight) - e.y};

	const bool bombWasClicked{
		mouseX > g_Bomb.left &&
		mouseX < g_Bomb.left + g_Bomb.width &&
		mouseY > g_Bomb.bottom &&
		mouseY < g_Bomb.bottom + g_Bomb.height
	};

	// Set bomb to exploding if bomb has been clicked and isn't currently
	// exploding.
	if (bombWasClicked && g_BombState != BombState::EXPLODING)
	{
		g_BombState = BombState::EXPLODING;
	}
};

void UpdateExplosion(float deltaTime)
{
	constexpr float explosionSpeed{100.f};

	// reset the bomb
	if (ExplosionHasFinished())
	{
		g_BombFragmentBottomLeft = g_Bomb;
		g_BombFragmentBottomRight = g_Bomb;
		g_BombFragmentTopLeft= g_Bomb;
		g_BombFragmentTopRight = g_Bomb;

		g_BombState = BombState::IDLE;
	}

	// calculate the speed
	if (g_BombState == BombState::EXPLODING)
	{
		g_BombFragmentBottomLeft.bottom -= explosionSpeed * deltaTime;
		g_BombFragmentBottomLeft.left -= explosionSpeed * deltaTime;

		g_BombFragmentBottomRight.bottom -= explosionSpeed * deltaTime;
		g_BombFragmentBottomRight.left += explosionSpeed * deltaTime;

		g_BombFragmentTopLeft.bottom += explosionSpeed * deltaTime;
		g_BombFragmentTopLeft.left -= explosionSpeed * deltaTime;

		g_BombFragmentTopRight.bottom += explosionSpeed * deltaTime;
		g_BombFragmentTopRight.left += explosionSpeed * deltaTime;
	}
};

void DrawExplosion()
{
	if (g_BombState == BombState::IDLE)
	{
		utils::SetColor(Color4f{0.f, 0.f, 0.f, 1.f});
		utils::FillRect(g_Bomb);
	}
	else
	{
		utils::SetColor(Color4f{0.f, 0.f, 0.f, 0.6f});
		utils::FillRect(g_Bomb);

		utils::SetColor(Color4f{1.0f, 0.f, 0.f, 1.f});
		utils::FillRect(g_BombFragmentBottomLeft);
		utils::FillRect(g_BombFragmentBottomRight);
		utils::FillRect(g_BombFragmentTopLeft);
		utils::FillRect(g_BombFragmentTopRight);
	}
};

bool ExplosionHasFinished()
{
	// Because the screen is square we know that if 1 is out all are out.

	return (
		g_BombFragmentTopRight.bottom > g_WindowHeight &&
		g_BombFragmentTopRight.left > g_WindowWidth
	);
}
#pragma endregion ownDefinitions