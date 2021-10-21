#include "pch.h"
#include "Game.h"

#include <ios>
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	//PrintTruthTable();
	//CompareTwoNumbers();
	//CalculatePrice();
	//ConvertDayNumber();
	//CheckLeapYear();
	//ConvertSeconds();
	// initialize game resources here
}

void Draw()
{
	//ClearBackground();

	//PrintTruthTable();
	// Put your own draw statements here

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
	////std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//switch (e.button)
	//{
	//case SDL_BUTTON_LEFT:
	//{
	//	//std::cout << "Left mouse button released\n";
	//	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
	//	break;
	//}
	//case SDL_BUTTON_RIGHT:
	//	//std::cout << "Right mouse button released\n";
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	//std::cout << "Middle mouse button released\n";
	//	break;
	//}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here
void PrintTruthTable()
{
	const bool isTrue{true};
	const bool isFalse{false};

	std::cout << " --- Print truth table --- " << std::endl;

	std::cout << std::boolalpha << "Logically binary AND operator (&&) " << std::endl;
	std::cout << std::boolalpha << "true && true" << " is " << (isTrue && isTrue) << std::endl;
	std::cout << std::boolalpha << "true && false" << " is " << (isTrue && isFalse) << std::endl;
	std::cout << std::boolalpha << "false && true" << " is " << (isFalse && isTrue) << std::endl;
	std::cout << std::boolalpha << "false && false" << " is " << (isFalse && isFalse) << std::endl;

	std::cout << std::boolalpha << "Logically binary OR operator (||) " << std::endl;
	std::cout << std::boolalpha << "true || true" << " is " << (isTrue || isTrue) << std::endl;
	std::cout << std::boolalpha << "true || false" << " is " << (isTrue || isFalse) << std::endl;
	std::cout << std::boolalpha << "false || true" << " is " << (isFalse || isTrue) << std::endl;
	std::cout << std::boolalpha << "false || false" << " is " << (isFalse || isFalse) << std::endl;

	std::cout << std::boolalpha << "Logically binary NOT operator (||) " << std::endl;
	std::cout << std::boolalpha << "!true" << " is " << (!isTrue) << std::endl;
	std::cout << std::boolalpha << "!false" << " is " << (!isFalse) << std::endl;

}

void CompareTwoNumbers()
{
	const int firstNumber{rand() % 11};
	const int secondNumber{rand() % 11};

	if (firstNumber == secondNumber)
		std::cout << "both are the same" << std::endl;
	else if (firstNumber > secondNumber)
		std::cout << "first is bigger" << std::endl;
	else
		std::cout << "second is bigger" << std::endl;
}

void CalculatePrice()
{
	float nrOfBallPoints{};

	std::cout << "Nr of ballpoints" << std::endl;
	std::cin >> nrOfBallPoints;

	if (nrOfBallPoints < 20)
		std::cout << "Total price is: " << nrOfBallPoints * 4.f << std::endl;
	else if (nrOfBallPoints < 50)
		std::cout << "Total price is: " << nrOfBallPoints * 3.5f << std::endl;
	else if (nrOfBallPoints < 101)
		std::cout << "Total price is: " << nrOfBallPoints * 3.25f << std::endl;
	else
		std::cout << "Total price is: " << nrOfBallPoints * 3.1f << std::endl;
}

void ConvertDayNumber()
{
	uint16_t weekDay{};
	std::string message{};

	std::cout << "Day numbers [1, 7] ? 1 " << std::endl;
	std::cin >> weekDay;

	if (weekDay == 1)
		message = "Start of the week";
	else if (weekDay < 5)
		message = "Middle of the week";
	else if (weekDay == 5)
		message = "Nearly weekend";
	else if (weekDay < 8)
		message = "Weekend";
	else
		message = "Wrong day number";

	std::cout << message;
}

void CheckLeapYear()
{
	uint16_t year{};
	std::string message{};

	std::cout << "Enter year " << std::endl;
	std::cin >> year;

	if (
			year % 4 == 0 && 
			year % 100 == 0 && 
			year % 400 == 0
			||
			year % 4 == 0 && 
			year % 100 != 0
		)
	{
		message = "February has 29 days";
	}
	else
	{
		message = "February has 28 days";
	}

	std::cout << message;
}

void ConvertSeconds()
{
	uint32_t seconds{};

	std::cout << "-- Convert seconds --" << std::endl;
	std::cin >> seconds;

	std::cout << seconds / 86000 % 365 << " days " << std::endl;
	std::cout << seconds / 3600 % 24 << " hours " << std::endl;
	std::cout << seconds / 60 % 60 << " minutes " << std::endl;
	std::cout << seconds % 60 << " seconds " << std::endl;
}

void UseActorState()
{
	enum class ActorState
	{
		RUNNING,
		FLYING,
		FALLING,
	};

	ActorState currentState{ActorState((rand() % 4))};

	switch(currentState)
	{
		case ActorState::RUNNING:
			std::cout << "HE IS SANIC" << std::endl;
			break;
		case ActorState::FLYING:
			std::cout << "HE IS MEGA MINDY" << std::endl;
			break;
		case ActorState::FALLING:
			std::cout << "YO FECKING DONKEY, YA MISSED THE JUMP" << std::endl;
			break;
		default:
			std::cout << "wtf are you expecting here?" << std::endl;
	}
}

void UsePoint2f()
{
	Point2f p1;
	Point2f p2{};
	Point2f p3{26, 25};

	std::cout << p2.x << " " << p2.y << std::endl;
	std::cout << p3.x << " " << p3.y << std::endl;

	p1.x = 20;
	p1.y = 3;
	p2 = Point2f{30, 40};
	p3.x++, p3.y++;

	std::cout << p1.x << " " << p1.y << std::endl;
	std::cout << p2.x << " " << p2.y << std::endl;
	std::cout << p3.x << " " << p3.y << std::endl;
}

#pragma endregion ownDefinitions