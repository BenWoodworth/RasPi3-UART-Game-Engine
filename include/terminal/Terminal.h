#ifndef TERMINAL_H_
#define TERMINAL_H_

#include <string>
#include <stdint.h>

class Terminal {
public:
    /// Prints a character to the terminal.
    virtual void printChar(uint8_t ch) = 0;

    /// Prints a string to the terminal.
    virtual void printStr(std::string str) = 0;

    /// Print a decimal number.
    virtual void printNumDec(int32_t num) = 0;

    /// Reads a character from the terminal buffer.
    /// Will not wait for a character to be entered.
    /// If there is no character to read, returns -1.
    virtual int readChar() = 0;

    /// Clear the terminal.
    void clear();

    /// Reset Select Graphic Rendition parameters.
    void resetStyling();

    /// Move the cursor.
    void moveCursor(int down, int right);

    /// Set the cursor position.
    void setCursorPosition(int row, int col);

    /// Set the foreground color.
    void setForegroundColor(uint8_t red, uint8_t green, uint8_t blue);

    /// Set the background color.
    void setBackgroundColor(uint8_t red, uint8_t green, uint8_t blue);
};

#endif
