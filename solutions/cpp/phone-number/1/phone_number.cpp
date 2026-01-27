#include "phone_number.h"

#include <stdexcept>
#include <cctype>

namespace phone_number {

void phone_number::cleanUp()
{
    if (dirty_.empty()) {
        throw std::domain_error("Invalid phone number: empty!");
    }

    // check for country code (empty or 1 or +1)
    consumeCountryCode();

    consumeNonDigits();

    // get 3-digit area code
    get3DigitCode();

    // get 3-digit exchange code
    get3DigitCode();

    // get 4-digit subscriber number
    getSubscriberNumber();

    if (!isAtEnd() && std::isdigit(peek())) {
        throw std::domain_error("Invalid phone number: 11-digit number does not start with 1.");
    }
}

// Consume country code (+1 or 1)
void phone_number::consumeCountryCode()
{
    if (isAtEnd()) {
        throw std::domain_error("Invalid phone number.");
    }

    // assert(current_ == 0);
    auto c = peek();
    if (c == '+') {
        current_++;
        if (!isAtEnd() && peek() == '1') {
            current_++;
            return;
        }
        throw std::domain_error("Invalid phone number: invalid country code!");
    }
    if (c == '1') {
        current_++;
        return;
    }
}

void phone_number::consumeNonDigits()
{
    while (!isAtEnd() && !std::isdigit(peek())) {
        current_++;
    }
}

// get three-digit code
void phone_number::get3DigitCode()
{
    size_t count{};
    auto c = peek();
    while (!isAtEnd() && std::isdigit(c) && count++ < 3) {
        if (c < '2' || c > '9') {
            throw std::domain_error("Invalid phone number: first digit of code is not [2..9]");
        }
        clean_ += c;
        current_++;
        c = peek();
    }
    if (count < 2) {
        throw std::domain_error("Invalid phone number: invalid area code!");
    }
    consumeNonDigits();
}

void phone_number::getSubscriberNumber()
{
    size_t count{};
    while (!isAtEnd() && std::isdigit(peek()) && count++ < 4) {
        clean_ += peek();
        current_++;
    }
    if (count < 3) {
        throw std::domain_error("Invalid phone number: invalid subscriber number!");
    }
    consumeNonDigits();
}

char phone_number::peek() const
{
    return dirty_[current_];
}

bool phone_number::isAtEnd() const
{
    return current_ >= dirty_.length();
}
}  // namespace phone_number
