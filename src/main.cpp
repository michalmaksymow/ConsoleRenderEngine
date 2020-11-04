#include <iostream>

#include "ConsoleRenderEngine.h"

int main(void)
{
	cre::ConsoleRenderEngine game;
	int32_t status = game.setupConsole(160, 100, 6, 6);

	std::cin.get();
	return EXIT_SUCCESS;
}