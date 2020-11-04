#include "ConsoleRenderEngine.h"

CRE_BEGIN
ConsoleRenderEngine::ConsoleRenderEngine()
	: _screenWidth(80), _screenHeight(30), _rectWindow{ 0, 0, 1, 1 }
{
	_consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	_consoleInputHandle = GetStdHandle(STD_INPUT_HANDLE);
}

ConsoleRenderEngine::~ConsoleRenderEngine()
{
	CloseHandle(_consoleHandle);
	CloseHandle(_consoleInputHandle);
}

int32_t ConsoleRenderEngine::setupConsole(int16_t width, int16_t height, int32_t fontWidth, int32_t fontHeight)
{
	if (_consoleHandle == INVALID_HANDLE_VALUE)
		return ERROR_BAD_HANDLE;

	_screenWidth = width;
	_screenHeight = height;

	// TODO: Add something like WinCall(X) that asserts if it was executed correctly
	COORD coord = { _screenWidth, _screenHeight };
	SetConsoleScreenBufferSize(_consoleHandle, coord);
	SetConsoleActiveScreenBuffer(_consoleHandle);

	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = fontWidth;
	cfi.dwFontSize.Y = fontHeight;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;

	wcscpy_s(cfi.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(_consoleHandle, false, &cfi);

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(_consoleHandle, &csbi);

	_rectWindow = { 0, 0, _screenWidth - 1, _screenHeight - 1 };
	SetConsoleWindowInfo(_consoleHandle, TRUE, &_rectWindow);

	SetConsoleMode(_consoleHandle, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);

	return RETURN_SUCCESS;
}
CRE_END