#pragma once

#include <string>
#include <exception>

class EnigmaException : public std::exception
{
public:
    EnigmaException(const std::string& message);

    std::string getMessage() const;

private:
    std::string m_message;
};

