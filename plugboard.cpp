#include "plugboard.h"
#include "enigmaexception.h"

PlugBoard::PlugBoard(std::map<char, char> plugged_cables)
{
    //m_plugged_cables = plugged_cables; // copy
    m_plugged_cables.swap(plugged_cables);

    for(const auto& cable : m_plugged_cables)
    {
        m_plugged_cables[cable.second] = cable.first;
    }

    for(char letter = 'A'; letter <= 'Z'; letter++)
    {
        if (m_plugged_cables.find(letter) == m_plugged_cables.cend()) // not found
        {
            m_plugged_cables[letter] = letter;
        }
    }
}

char PlugBoard::encrypt(char letter) const
{
    return m_plugged_cables.at(letter);
}

void PlugBoard::plugCable(char a, char b)
{
    if (m_plugged_cables.at(a) != a
         || m_plugged_cables.at(b) != b
         )
        {
            throw EnigmaException{"Cable already plugged!"};
        }

    m_plugged_cables[a] = b;
    m_plugged_cables[b] = a;
}
