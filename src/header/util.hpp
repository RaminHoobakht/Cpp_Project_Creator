#ifndef PRJ_CREATOR_UTIL_HPP
#define PRJ_CREATOR_UTIL_HPP

#include <string>
#include "../header/constants.hpp"
#include "../classes/prjexception.hpp"

const std::string get_param_content(const std::string &param);

void check_param(const std::string &param);

void check_git_param(const std::string &param);

void set_normal_project(Project &project);

void set_postgres_project(Project &project);

void set_qt_ui_project(Project &project);

void set_qt_console_project(Project &project);


const std::string get_param_content(const std::string &param) {
    // std::cout << "value of param is: " << param <<std::endl;
    size_t index = param.find(constants::colon) + constants::one;
    // std::cout << "value index is: " << index <<std::endl;
    std::string result{param.substr(index)};
    // std::cout << "value result is: " << result <<std::endl;
    // std::cout << "------------------------------" << std::endl;
    return {result};
}

void check_param(const std::string &param) {
    if (param.empty() || param.starts_with(constants::dot))
        throw PrjException(constants::param_error_two);
}

void check_git_param(const std::string &param) {
    if (param.empty() || param.starts_with(constants::dot))
        throw PrjException(constants::param_error_git);
}

void set_normal_project(Project &project) {
    project.set_cpp_file(scripts::script_main_cpp);
    project.set_cpp_001_file(scripts::script_main_001_cpp);
    project.set_asm_001_file(scripts::script_main_001_asm);
    project.set_run_script_file(scripts::script_run_sh);
    project.set_cmake_new_script_file(scripts::cmake_new_script);
    project.set_asm_script_file(scripts::script_asm_sh);
    project.set_new_script_file(scripts::script_new_sh);
    project.set_cmake_script_file(scripts::script_cmake_sh);
    project.set_compiler_script_file(scripts::script_compiler_sh);
    project.set_cmake_list_file(scripts::script_cmake_txt);
    project.set_git_ignore(scripts::git_ignore);
    project.set_clang_tidy(scripts::clang_tidy);
    project.set_work_space(scripts::work_space);
}

void set_postgres_project(Project &project) {
    set_normal_project(project);
    project.set_compiler_script_file(scripts::script_compiler_postgres_sh);
    project.set_cmake_list_file(scripts::script_cmake_postgres_txt);
}

void set_qt_ui_project(Project &project) {
    set_normal_project(project);
    project.set_cpp_file(scripts::script_main_qt_cpp);
    project.set_cmake_list_file(scripts::script_cmake_qt_txt);
}

void set_qt_console_project(Project &project) {
    set_normal_project(project);
    project.set_cpp_file(scripts::script_main_qt_cli_cpp);
    project.set_cmake_list_file(scripts::script_cmake_qt_cli_txt);
}


#endif //PRJ_CREATOR_UTIL_HPP
