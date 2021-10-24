#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Explosion - Six, Arne - 1DAE13e" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 500 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
enum class BombState
{
	IDLE,
	EXPLODING,
};

BombState g_BombState{BombState::IDLE};
int g_NrOfFrames{};

Rectf g_Bomb{
	(g_WindowWidth / 2) - 20,
	(g_WindowHeight / 2) - 20,
	40,
	40
};

Rectf g_BombFragmentBottomLeft{g_Bomb};
Rectf g_BombFragmentBottomRight{g_Bomb};
Rectf g_BombFragmentTopLeft{g_Bomb};
Rectf g_BombFragmentTopRight{g_Bomb};

// Declare your own functions here
void ProcessMouseClick(const SDL_MouseButtonEvent& e);
void UpdateExplosion(float elapsedSeconds);
bool ExplosionHasFinished();
void DrawExplosion();
#pragma endregion ownDeclarations

#pragma region gameFunctions											
void Start();
void Draw();
void Update(float elapsedSec);
void End();
#pragma endregion gameFunctions

#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key);
void OnKeyUpEvent(SDL_Keycode key);
void OnMouseMotionEvent(const SDL_MouseMotionEvent& e);
void OnMouseDownEvent(const SDL_MouseButtonEvent& e);
void OnMouseUpEvent(const SDL_MouseButtonEvent& e);
#pragma endregion inputHandling
