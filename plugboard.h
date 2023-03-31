#pragma once

#include <map>

class PlugBoard
{
public:
    PlugBoard(std::map<char, char> plugged_cables);

    char encrypt(char letter) const;

    void plugCable(char a, char b);
private:
    std::map<char, char> m_plugged_cables;
};

