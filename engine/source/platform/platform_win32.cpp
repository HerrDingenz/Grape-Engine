#include "platform.hpp"

#ifdef GRAPE_PLATFORM_WINDOWS

#include <windows.h>
#include <windowsx.h>

#include <string>

LRESULT CALLBACK WindowProc(HWND hwnd, uint32 msg, WPARAM w_param, LPARAM l_param);

namespace Platform {

    void Init() {

    }

    void Close() {

    }

    namespace Console {
        uint8 LoggerColours[5] = {
            BACKGROUND_RED | 0,                 // FATAL
            FOREGROUND_RED,                     // ERROR 
            FOREGROUND_RED | FOREGROUND_GREEN,  // WARN
            FOREGROUND_INTENSITY,               // INFO
            FOREGROUND_GREEN                    // DEBUG
        };

        void Write(std::string text, uint8 colour) {
            HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
            uint64 length = strlen(text.c_str());
            LPDWORD number_written = 0;

            SetConsoleTextAttribute(console_handle, LoggerColours[colour]);
            WriteConsoleA(console_handle, text.c_str(), (DWORD)length, number_written, 0);

        }

        void WriteError(std::string text, uint8 colour) {
            HANDLE console_handle = GetStdHandle(STD_ERROR_HANDLE);
            uint64 length = strlen(text.c_str());
            LPDWORD number_written = 0;

            SetConsoleTextAttribute(console_handle, LoggerColours[colour]);
            WriteConsoleA(console_handle, text.c_str(), (DWORD)length, number_written, 0);
        }
    }
}

#endif