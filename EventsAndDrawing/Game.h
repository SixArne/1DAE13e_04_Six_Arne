#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "EventsAndDrawing - Six, Arne - 1DAE13e" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
Rectf g_RandomRectangle{};

enum class RectColor
{
	GREY,
	GREEN,
};

struct MousePosition
{
	int x{0};
	int y{0};
};

RectColor g_RectColor{RectColor::GREY};

// Declare your own functions here
bool RectangleClicked(const MousePosition& e, const Rectf& rect);
void CalculateRandomRectangle();

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
