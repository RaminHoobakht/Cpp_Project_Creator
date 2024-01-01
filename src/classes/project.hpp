#ifndef PRJ_CREATOR_PROJECT_HPP
#define PRJ_CREATOR_PROJECT_HPP

#include <filesystem>
#include <fstream>
#include <iostream>
#include "prjexception.hpp"

class Project final {

private:
    const char fld_bin[5]{"/bin"};
    const char fld_data[6]{"/data"};
    const char fld_build[7]{"/build"};
    const char fld_src[5]{"/src"};
    const char fld_app[9]{"/src/app"};
    const char fld_header[12]{"/src/header"};

    const char file_main_cpp[18]{"/src/app/main.cpp"};
    const char file_main_001_cpp[22]{"/src/app/main_001.cpp"};
    const char file_run_sh[8]{"/run.sh"};
    const char file_new_sh[8]{"/new.sh"};
    const char file_cmake_sh[10]{"/cmake.sh"};
    const char file_compiler_sh[13]{"/compiler.sh"};
    const char file_cmake_txt[16]{"/CMakeLists.txt"};
    const char extension_shell[4]{".sh"};

    const char msg_exist[47]{"specified project name was already existed ..."};
    const char msg_ws[30]{"error in create workspace ..."};
    const char msg_bin[31]{"error in create bin folder ..."};
    const char msg_data[32]{"error in create data folder ..."};
    const char msg_src[31]{"error in create src folder ..."};
    const char msg_app[31]{"error in create app folder ..."};
    const char msg_header[34]{"error in create header folder ..."};
    const char msg_write_file[27]{"error in write to file ..."};

    std::string project_name{};
    std::string path_project{};
    std::string content_main_cpp{};
    std::string content_main_001_cpp{};
    std::string content_run_script{};
    std::string content_new_script{};
    std::string content_compiler_script{};
    std::string content_cmake_list{};
    std::string content_cmake_script{};

    void create_folders();

    void create_files();

    void create_file(const std::string &file_name, const std::string &content);

public:
    Project() = default;

    explicit Project(const std::string &_project_path);

    [[maybe_unused]] Project(const std::string &_project_path, const std::string &_cpp_file,
                             const std::string &_cpp_001_file, const std::string &_run_script,
                             const std::string &_new_script, const std::string &_cmake_list,
                             const std::string &_cmake_script);

    Project(const Project &_project) = default;

    virtual ~Project() = default;

    void set_cpp_file(const std::string &_content);

    void set_cpp_001_file(const std::string &_content);

    void set_run_script_file(const std::string &_content);

    void set_new_script_file(const std::string &_content);

    void set_compiler_script_file(const std::string &_content);

    void set_cmake_list_file(const std::string &_content);

    void set_cmake_script_file(const std::string &_content);

    void create_project();

    [[nodiscard]] [[maybe_unused]] const std::string &get_cpp_file() const;

    [[nodiscard]] [[maybe_unused]] const std::string &get_cpp_001_file() const;

    [[nodiscard]] [[maybe_unused]] const std::string &get_run_script_file() const;

    [[nodiscard]] [[maybe_unused]] const std::string &get_new_script_file() const;

    [[nodiscard]] [[maybe_unused]] const std::string &get_compiler_script_file() const;

    [[nodiscard]] [[maybe_unused]] const std::string &get_cmake_script_file() const;

    [[nodiscard]] [[maybe_unused]] const std::string &get_cmake_list_file() const;
};

#endif /* PRJ_CREATOR_PROJECT_HPP */