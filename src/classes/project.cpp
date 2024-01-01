#include "project.hpp"
#include "../header/constants.hpp"

/* private: ----------------------------- */

void Project::create_folders() {

    if (std::filesystem::exists(this->path_project)) {
        throw PrjException(this->msg_exist);
    }

    if (!std::filesystem::create_directories(this->path_project)) {
        throw PrjException(this->msg_ws);
    }

    if (!std::filesystem::create_directories(
            this->path_project + (this->fld_bin))) {
        throw PrjException(this->msg_bin);
    }

    if (!std::filesystem::create_directories(
            this->path_project + (this->fld_data))) {
        throw PrjException(this->msg_data);
    }

    if (!std::filesystem::create_directories(
            this->path_project + (this->fld_build))) {
        throw PrjException(this->msg_data);
    }

    if (!std::filesystem::create_directories(
            this->path_project + (this->fld_src))) {
        throw PrjException(this->msg_src);
    }

    if (!std::filesystem::create_directories(
            this->path_project + (this->fld_app))) {
        throw PrjException(this->msg_app);
    }

    if (!std::filesystem::create_directories(
            this->path_project + (this->fld_header))) {
        throw PrjException(this->msg_header);
    }
}

void Project::create_file(const std::string &file_name,
                          const std::string &content) {

    std::ofstream out_file{};
    out_file.open(file_name, std::ios::out);
    if (!out_file.is_open()) {
        throw PrjException(this->msg_write_file);
    }
    out_file << content;
    out_file.close();
    if (file_name.ends_with(this->extension_shell)) {
        std::filesystem::permissions(file_name, std::filesystem::perms::all);
    }
}

void Project::create_files() {

    size_t pos{};
    char s_content_cmake_list[constants::buffer_size];
    char s_content_cmake_script[constants::buffer_size];

    if (this->path_project.contains(constants::slash)) {
        pos = this->path_project.find_last_of(constants::slash);
    } else if (this->path_project.contains(constants::back_slash)) {
        pos = this->path_project.find_last_of(constants::back_slash);
    }

    this->project_name = this->path_project.substr(pos + constants::one);

    sprintf(s_content_cmake_list, content_cmake_list.c_str(), this->project_name.c_str());
    sprintf(s_content_cmake_script, content_cmake_script.c_str(), this->project_name.c_str(),
            this->project_name.c_str(), this->project_name.c_str());

    this->create_file(this->path_project + (this->file_run_sh),
                      this->content_run_script);
    /* -------------------- */
    this->create_file(this->path_project + (this->file_new_sh),
                      this->content_new_script);
    /* -------------------- */
    this->create_file(this->path_project + (this->file_compiler_sh),
                      this->content_compiler_script);
    /* -------------------- */
    this->create_file(this->path_project + (this->file_cmake_txt),
                      s_content_cmake_list);
    /* -------------------- */
    this->create_file(this->path_project + (this->file_cmake_sh),
                      s_content_cmake_script);
    /* -------------------- */
    this->create_file(this->path_project + (this->file_main_cpp),
                      this->content_main_cpp);
    /* -------------------- */
    this->create_file(this->path_project + (this->file_main_001_cpp),
                      this->content_main_cpp);
}

/* public: ----------------------------- */

Project::Project(const std::string &_project_path) {
    this->path_project = _project_path;
}

[[maybe_unused]] Project::Project(const std::string &_project_path, const std::string &_cpp_file,
                                  const std::string &_cpp_001_file, const std::string &_run_script,
                                  const std::string &_new_script, const std::string &_cmake_list,
                                  const std::string &_cmake_script) {
    this->path_project = _project_path;
    this->content_main_cpp = _cpp_file;
    this->content_main_cpp = _cpp_001_file;
    this->content_run_script = _run_script;
    this->content_new_script = _new_script;
    this->content_cmake_list = _cmake_list;
    this->content_cmake_script = _cmake_script;
}

void Project::set_cpp_file(const std::string &_content) {
    this->content_main_cpp = _content;
}

void Project::set_cpp_001_file(const std::string &_content) {
    this->content_main_001_cpp = _content;
}

void Project::set_run_script_file(const std::string &_content) {
    this->content_run_script = _content;
}

void Project::set_new_script_file(const std::string &_content) {
    this->content_new_script = _content;
}

void Project::set_compiler_script_file(const std::string &_content) {
    this->content_compiler_script = _content;
}

void Project::set_cmake_list_file(const std::string &_content) {
    this->content_cmake_list = _content;
}

void Project::set_cmake_script_file(const std::string &_content) {
    this->content_cmake_script = _content;
}

/* ------------------------------- */
////////////////////
[[nodiscard]] [[maybe_unused]] const std::string &Project::get_cpp_file() const {
    return this->file_main_cpp;
}

[[nodiscard]] [[maybe_unused]] const std::string &Project::get_cpp_001_file() const {
    return this->file_main_001_cpp;
}
///////////////////

[[maybe_unused]] const std::string &Project::get_run_script_file() const {
    return this->content_run_script;
}

[[nodiscard]] [[maybe_unused]] const std::string &Project::get_new_script_file() const {
    return this->content_compiler_script;
}

[[nodiscard]] [[maybe_unused]] const std::string &Project::get_compiler_script_file() const {
    return this->content_new_script;
}

[[nodiscard]] [[maybe_unused]] const std::string &Project::get_cmake_list_file() const {
    return this->content_cmake_list;
}

[[nodiscard]] [[maybe_unused]] const std::string &Project::get_cmake_script_file() const {
    return this->content_cmake_script;
}


void Project::create_project() {
    this->create_folders();
    this->create_files();
}
