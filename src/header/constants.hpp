
#ifndef PRJ_CREATOR_CONSTANTS_HPP
#define PRJ_CREATOR_CONSTANTS_HPP

#include <string>

namespace constants {

    static constexpr char nl = '\n';
    static constexpr char sp = '\x20';
    static constexpr char slash = '/';
    static constexpr char dot = '\\.';
    static constexpr char back_slash = '\\';
    static constexpr char colon = ':';
    static constexpr std::string str_slash = "/";

    static constexpr std::string def_author = "default";
    static constexpr std::string def_email = "default";

    static const std::string param_path{"--path:"};
    static const std::string param_postgres{"--project-postgresql"};
    static const std::string param_normal{"--project-normal"};
    static const std::string param_qt_ui{"--project-qt-ui"};
    static const std::string param_qt_console{"--project-qt-console"};
    static const std::string param_git{"--git-init"};
    static const std::string param_git_author{"--author:"};
    static const std::string param_git_email{"--email:"};
    static const std::string pre_param_project{"--project-"};

    static constexpr int one = 1;
    static constexpr int two = 2;
    static constexpr int three = 3;
    static constexpr int four = 4;
    static constexpr int five = 5;
    static constexpr int six = 6;
    static constexpr int seven = 7;
    static constexpr int eight = 8;
    static constexpr int nine = 9;
    static constexpr int ten = 10;
    static constexpr int buffer_size = 4096;

    static constexpr std::string error_title{" Error: "};

    static const std::string title{
            " Ramin Hoobakht, C++ project creator v.0.1.25 2024 Apr 10"};

    static const std::string param_error_one{" invalid parameter ..."};

    static const std::string param_error_two{" invalid path or project name ..."};

    static const std::string param_error_git{" invalid git parameter ..."};

    static const std::string end_msg{" C++ Project was created successfully ...\n"};

    static const std::string end_msg_postgres{
            " C++ Postgresql Project was created successfully ...\n"};

    static const std::string end_msg_qt_ui{
            " C++ Qt Ui Project was created successfully ...\n"};

    static const std::string end_msg_qt_cli{
            " C++ Qt Console Project was created successfully ...\n"};

    static constexpr std::string place_holder{"[replace]"};


} // namespace constants
#endif // PRJ_CREATOR_CONSTANTS_HPP
