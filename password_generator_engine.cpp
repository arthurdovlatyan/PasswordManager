#include "password_generator_engine.h"

#include <set>


namespace  password_generator_engine{

password_generator_engine::
password_generator_engine()
{

}

password_generator_engine &password_generator_engine::create(int l, bool u, bool a, bool s, bool n)
{
    static password_generator_engine res(l,u,a,s,n);
    return res;
}

password_generator_engine::
password_generator_engine(int l, bool u, bool a, bool s, bool n)
    : m_length(l)
    , m_upercase(u)
    , m_lowercase(a)
    , m_special_char(s)
    , m_numbers(n)
{

}

int password_generator_engine::length() const
{
    return m_length;
}

void password_generator_engine::setLength(int newLength)
{
    m_length = newLength;
}

bool password_generator_engine::upercase() const
{
    return m_upercase;
}

void password_generator_engine::setUpercase(bool newUpercase)
{
    m_upercase = newUpercase;
}

bool password_generator_engine::lowercase() const
{
    return m_lowercase;
}

void password_generator_engine::setLowercase(bool newLowercase)
{
    m_lowercase = newLowercase;
}

bool password_generator_engine::special_char() const
{
    return m_special_char;
}

void password_generator_engine::setSpecial_char(bool newSpecial_char)
{
    m_special_char = newSpecial_char;
}

bool password_generator_engine::numbers() const
{
    return m_numbers;
}

void password_generator_engine::setNumbers(bool newNumbers)
{
    m_numbers = newNumbers;
}

const std::string &password_generator_engine::getS_numbers()
{
    return s_numbers;
}

void password_generator_engine::setS_numbers(const std::string &newS_numbers)
{
    s_numbers = newS_numbers;
}

const std::string &password_generator_engine::getS_upper_characters()
{
    return s_upper_characters;
}

void password_generator_engine::setS_upper_characters(const std::string &newS_upper_characters)
{
    s_upper_characters = newS_upper_characters;
}

const std::string &password_generator_engine::getS_lower_characters()
{
    return s_lower_characters;
}

void password_generator_engine::setS_lower_characters(const std::string &newS_lower_characters)
{
    s_lower_characters = newS_lower_characters;
}

const std::string &password_generator_engine::getS_special_characters()
{
    return s_special_characters;
}

void password_generator_engine::setS_special_characters(const std::string &newS_special_characters)
{
    s_special_characters = newS_special_characters;
}

std::string password_generator_engine::generatePassword()
{
    std::string s;
    if (m_numbers) {
        s += s_numbers;
    }
    if (m_upercase) {
        s += s_upper_characters;
    }
    if (m_lowercase) {
        s += s_lower_characters;
    }
    if (m_special_char) {
        s += s_special_characters;
    }

    std::string res;
    for (int i = 0; i < length(); ++i) {
        int k = rand() % s.size();
        res += s[k];
    }
    return res;
}


} // end of namespace password_generator_engine
