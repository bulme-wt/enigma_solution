#include "enigmaexception.h"

EnigmaException::EnigmaException(const std::string& message)
    : m_message{message}
{

}

std::string EnigmaException::getMessage() const
{
    return m_message;
}
