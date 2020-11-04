#pragma once

#include <Windows.h>

#include <iostream>
#include <cstdint>
#include <chrono>
#include <vector>
#include <list>
#include <thread>

#ifndef UNICODE
#error In order to compile UNICODE must be enabled!
#endif // !UNICODE

#define CRE_BEGIN namespace cre {
#define CRE_END }

#define RETURN_SUCCESS							0x001;
#define ERROR_BAD_HANDLE						0x002;


CRE_BEGIN
class ConsoleRenderEngine {

public:
	ConsoleRenderEngine();
	~ConsoleRenderEngine();

	int32_t setupConsole(int16_t width, int16_t height, int32_t fontWidth, int32_t fontHeight);

	inline int16_t getScreenWidth() const { return _screenWidth; }
	inline int16_t getScreenHeight() const { return _screenHeight; }


private:
	int16_t _screenWidth;
	int16_t _screenHeight;

	HANDLE _consoleHandle;
	HANDLE _consoleInputHandle;

	SMALL_RECT _rectWindow;
};
CRE_END