#pragma once

#ifdef __unix__

#include "Console.h"

#include <string>

namespace aod {

    class UnixConsole : public Console
    {
    public:
        UnixConsole();

        virtual void SetWindowTitle(const std::string &title) override;
        virtual void MoveCursor(int x, int y) override;
        virtual void SetColor(Color color) override;
        virtual void SetColor(Color fgColor, Color bgColor) override;
        virtual void ClearScreen() override;
        virtual void SetCursorVisibility(bool visibility) override;

    private:
        static std::string getANSIFgColor(Color color);
        static std::string getANSIBgColor(Color color);
    };

} // namespace aod

#endif
