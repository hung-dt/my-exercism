#pragma once

#include <string>

namespace phone_number {

class phone_number
{
public:
    phone_number(const std::string& dirty) : dirty_{dirty}
    {
        cleanUp();
    }

    const std::string& number() const
    {
        return clean_;
    }

private:
    const std::string& dirty_;
    std::string clean_{};
    size_t current_{};
    
    void cleanUp();

    void consumeNonDigits();
    void consumeCountryCode();
    void get3DigitCode();
    void getSubscriberNumber();

    char peek() const;
    bool isAtEnd() const;
};

}  // namespace phone_number
