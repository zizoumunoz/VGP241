#include <iostream>
#include <array>
#include <vector>
#include <stack>
#include <chrono>

std::chrono::steady_clock::time_point gStartTime;
void StartAlgorithm()
{
	gStartTime = std::chrono::high_resolution_clock::now();
}

void PrintDuration()
{
	std::chrono::steady_clock::time_point endTime = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - gStartTime).count();
}

// Go to screen functions
void GoToScreen(const std::string& screenName, std::array<std::string, 10>& screens)
{
	for (int i = 0; i < screens.size(); ++i)
	{
		if (screens[i].empty())
		{
			screens[i] = screenName; break;
		}
	}
}

void GoToScreen(const std::string& screenName, std::vector<std::string>& screens)
{
	screens.push_back(screenName);
	std::cout << "Screen Added: " << screenName << "\n";
}

void GoToScreen(const std::string& screenName, std::stack<std::string>& screens)
{
	screens.push(screenName);
	std::cout << "Screen Added: " << screenName << "\n";
}

void Exercise1ScreenFlow()
{

	/*
		Simple screen flow
		Create three containers
			Array
			Vector
			Stack
		Create functions for each of them to
			Go to a screen with an std::string screen
			Go back
		For each:
			Go to main menu
			Go to level setup
			Go to game
			Go to game over
			Return to main menu by going back
			print the time to process each type

	*/
	std::cout << "Screen Flow:\n";
	std::array<std::string, 10> arrayScreens;
	std::vector<std::string> vecScreens;
	std::stack<std::string> vecScreens;
}

int main()
{
	return 0;
}