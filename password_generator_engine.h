#ifndef PASSWORD_GENERATOR_ENGINE_H
#define PASSWORD_GENERATOR_ENGINE_H

#include <string>

namespace password_generator_engine
{

class password_generator_engine
{
private:
    // Constructors and destructor
    password_generator_engine();

    /*
     * @brief constructor
     * @param[in] l length of the password
     * @param[in] u uppercase letters
     * @param[in] a lowerercase letters
     * @param[in] s special chars
     * @param[in] n numbers
     */
    password_generator_engine(int l = 10, bool u = true, bool a = true, bool s = true, bool n = true);

    password_generator_engine(const password_generator_engine&) = delete;
    password_generator_engine& operator=(const password_generator_engine&) = delete;

public:
    /*
     * @brief constructor
     * @param[in] l length of the password
     * @param[in] u uppercase letters
     * @param[in] a lowerercase letters
     * @param[in] s special chars
     * @param[in] n numbers
     */
    password_generator_engine& create(int l = 10, bool u = true, bool a = true, bool s = true, bool n = true);

    // getters and setters
    int length() const;
    void setLength(int newLength);

    bool upercase() const;
    void setUpercase(bool newUpercase);

    bool lowercase() const;
    void setLowercase(bool newLowercase);

    bool special_char() const;
    void setSpecial_char(bool newSpecial_char);

    bool numbers() const;
    void setNumbers(bool newNumbers);

    const std::string &getS_numbers();
    void setS_numbers(const std::string &newS_numbers = "0123456789");

    const std::string &getS_upper_characters();
    void setS_upper_characters(const std::string &newS_upper_characters = "ABCDEFGHIJKLMNOQPRSTUYWVZX");

    const std::string &getS_lower_characters();
    void setS_lower_characters(const std::string &newS_lower_characters = "abcdefghijklmnoqprstuvwyzx");

    const std::string &getS_special_characters();
    void setS_special_characters(const std::string &newS_special_characters = "!@#$^&*?");

    // driver func
    std::string generatePassword();

private:
    int m_length;
    bool m_upercase;
    bool m_lowercase;
    bool m_special_char;
    bool m_numbers;
    std::string s_numbers;
    std::string s_upper_characters;
    std::string s_lower_characters;
    std::string s_special_characters;
};


}
#endif // PASSWORD_GENERATOR_ENGINE_H
