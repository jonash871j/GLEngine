#include "en_console.h"
#include <stdio.h>
#include <Windows.h>
#define VPRINT(format) SetConsoleTextAttribute(hConsole, 0xf);  \
					   va_list arglist;							\
					   va_start(arglist, format);				\
					   vprintf(format, arglist);				\
					   va_end(arglist);							\

namespace Engine
{
	static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	void Console::Initalize()
	{
		// Sets custom colors
		CONSOLE_SCREEN_BUFFER_INFOEX csbiInfo;
		csbiInfo.cbSize = sizeof(csbiInfo);
		GetConsoleScreenBufferInfoEx(hConsole, &csbiInfo);
		csbiInfo.ColorTable[0x4] = RGB(224, 32, 32);
		csbiInfo.ColorTable[0x7] = RGB(224, 127, 127);
		csbiInfo.ColorTable[0xa] = RGB(32, 224, 32);
		csbiInfo.ColorTable[0xb] = RGB(32, 224, 224);
		csbiInfo.ColorTable[0xc] = RGB(255, 192, 0);
		csbiInfo.ColorTable[0xe] = RGB(255, 255, 32);
		SetConsoleScreenBufferInfoEx(hConsole, &csbiInfo);
	}

	void Console::PrintError(const char* format, ...)
	{
		SetConsoleTextAttribute(hConsole, 0x4);
		printf("  <ERROR> ");
		VPRINT(format);
		printf("\n");
	}
	void Console::PrintReason(const char* format, ...)
	{
		SetConsoleTextAttribute(hConsole, 0x7);
		printf(" <REASON> ");
		VPRINT(format);
		printf("\n");
	}
	void Console::PrintWarning(const char* format, ...)
	{
		SetConsoleTextAttribute(hConsole, 0xe);
		printf("<WARNING> ");
		VPRINT(format);
		printf("\n");
	}
	void Console::PrintSuccess(const char* format, ...)
	{
		SetConsoleTextAttribute(hConsole, 0xa);
		printf("<SUCCESS> ");
		VPRINT(format);
		printf("\n");
	}

	void Console::PrintBuffer(char* buffer, int32_t length)
	{
		SetConsoleTextAttribute(hConsole, 0xf);

		bool isNewLine = false;
		for (int32_t i = 0; i < length; i++)
		{
			if (buffer[i] == 0)
			{
				continue;
			}


			if (i == 0)
				printf("       -> ");

			if (buffer[i] != '\n')
			{
				isNewLine = true;
				putchar((int)buffer[i]);
			}
			else
			{
				isNewLine = false;
				if ((i + 1 < length) && (buffer[i+1] != 0))
					printf("\n       -> ");
				else
					printf("\n");
			}
		}
		if (isNewLine)
			printf("\n");
	}

	void Console::PrintMsg(const char* format, ...)
	{
		SetConsoleTextAttribute(hConsole, 0xb);
		printf("<MESSAGE> ");
		VPRINT(format);
		printf("\n");
	}
}

