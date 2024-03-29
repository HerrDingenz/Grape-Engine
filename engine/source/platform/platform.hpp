#pragma once

#include "../defines.hpp"

#include <string>

namespace Platform {
    void Init();
    void Close();

    namespace Console {
        GRAPE_API void Write(const std::string& text, uint8_t colour);
        GRAPE_API void WriteError(const std::string& text, uint8_t colour);
    };

    namespace Time {
        GRAPE_API std::string GetLocal();
    };
};