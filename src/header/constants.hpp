
#ifndef PRJ_CREATOR_CONSTANTS_HPP
#define PRJ_CREATOR_CONSTANTS_HPP

#include <string>

namespace constants {

static constexpr char nl = '\n';
static constexpr char slash = '/';
static constexpr char back_slash = '\\';
static constexpr std::string postgresql{"postgresql"};
static constexpr int one = 1;
static constexpr int two = 2;
static constexpr int three = 3;
static constexpr int buffer_size = 4096;

static std::string error_title{"Error: "};
static std::string title{
    "Ramin Hoobakht, C++ project creator v.0.1.2 2024 Jan 1"};
static std::string param_error{"invalid parameter ..."};
static std::string end_msg{"\n(Normal) Project was created successfully ...\n"};
static std::string end_msg_postgres{
    "\n(Postgresql) Project was created successfully ...\n"};

} // namespace constants
#endif // PRJ_CREATOR_CONSTANTS_HPP
