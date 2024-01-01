#ifndef PRJ_CREATOR_PRJ_EXCEPTION_HPP
#define PRJ_CREATOR_PRJ_EXCEPTION_HPP

#include <exception>
#include <string>

class PrjException final : public std::exception {

private:
    std::string message{};

public:
    PrjException() = default;

    [[maybe_unused]] explicit PrjException(const std::string &msg);

    ~PrjException() override = default;

    [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override;
};


#endif //PRJ_CREATOR_PRJ_EXCEPTION_HPP
