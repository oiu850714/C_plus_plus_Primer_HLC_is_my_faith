#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <string>
#include <vector>

template <unsigned int Height, unsigned int Width>
class Screen {
public:
    Screen(char Background = ' ') : Height_(Height), Width_(Width), Content_(std::string(Height * Width, Background)) {}

private:
    unsigned int Height_;
    unsigned int Width_;
    std::string Content_;
};

#endif