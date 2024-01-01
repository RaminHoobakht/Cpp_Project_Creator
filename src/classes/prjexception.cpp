#include "prjexception.hpp"
#include "../header/constants.hpp"

const char *PrjException::what() const noexcept {
    return this->message.c_str();
}

[[maybe_unused]] PrjException::PrjException(const std::string &msg) {
    this->message = constants::nl + constants::error_title + msg + constants::nl;
}
