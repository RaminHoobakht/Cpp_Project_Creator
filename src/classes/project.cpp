#include "project.hpp"
#include "../header/constants.hpp"

/* private: ----------------------------- */

void Project::create_folders() {

    if (std::filesystem::exists(this->path_project)) {
        char response{};
        std::cout << '\n';
        std::cout << " project name is already exist! ";
        while (response != 'n' && response != 'N' && response != 'y' &&
               response != 'Y') {
            std::cout << " do you want to continue? [y-n]: ";
            std::cin >> response;
        }
        if (response == 'n' || response == 'N') {
            throw PrjException(this->msg_exist);
        }
    }

    if (!std::filesystem::exists(this->path_project))
        if (!std::filesystem::create_directories(this->path_project)) {
            throw PrjException(this->msg_ws);
        }

    if (!std::filesystem::exists(this->path_project + (this->fld_bin)))
        if (!std::filesystem::create_directories(this->path_project +
                                                 (this->fld_bin))) {
            throw PrjException(this->msg_bin);
        }

    if (!std::filesystem::exists(this->path_project + (this->fld_data)))
        if (!std::filesystem::create_directories(this->path_project +
                                                 (this->fld_data))) {
            throw PrjException(this->msg_data);
        }

    if (!std::filesystem::exists(this->path_project + (this->fld_archive)))
        if (!std::filesystem::create_directories(this->path_project +
                                                 (this->fld_archive))) {
            throw PrjException(this->msg_archive);
        }

    if (!std::filesystem::exists(this->path_project + (this->fld_build)))
        if (!std::filesystem::create_directories(this->path_project +
                                                 (this->fld_build))) {
            throw PrjException(this->msg_data);
        }

    if (!std::filesystem::exists(this->path_project + (this->fld_src)))
        if (!std::filesystem::create_directories(this->path_project +
                                                 (this->fld_src))) {
            throw PrjException(this->msg_src);
        }

    if (!std::filesystem::exists(this->path_project + (this->fld_app)))
        if (!std::filesystem::create_directories(this->path_project +
                                                 (this->fld_app))) {
            throw PrjException(this->msg_app);
        }

    if (!std::filesystem::exists(this->path_project + (this->fld_header)))
        if (!std::filesystem::create_directories(this->path_project +
                                                 (this->fld_header))) {
            throw PrjException(this->msg_app);
        }

    if (!std::filesystem::exists(this->path_project + (this->fld_asm)))
        if (!std::filesystem::create_directories(this->path_project +
                                                 (this->fld_asm))) {
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
    out_file.flush();
    out_file.close();
    if (file_name.ends_with(this->extension_shell)) {
        std::filesystem::permissions(file_name, std::filesystem::perms::all);
    }
}

void Project::create_files() {

    size_t pos{};

    if (this->path_project.contains(constants::slash)) {
        pos = this->path_project.find_last_of(constants::slash);
    } else if (this->path_project.contains(constants::back_slash)) {
        pos = this->path_project.find_last_of(constants::back_slash);
    }

    this->project_name = this->path_project.substr(pos);

    Project::replace_all(this->content_cmake_list, constants::place_holder,
                         this->project_name);
    Project::replace_all(this->content_cmake_script, constants::place_holder,
                         this->project_name);

    /* -------------------- */
    this->create_file(this->path_project + (this->file_run_sh),
                      this->content_run_script);
    /* -------------------- */
    this->create_file(this->path_project + (this->file_asm_sh),
                      this->content_asm_script);
    /* -------------------- */
    this->create_file(this->path_project + (this->file_new_sh),
                      this->content_new_script);
    /* -------------------- */
    this->create_file(this->path_project + (this->file_cmake_new_sh),
                      this->content_cmake_new_script);
    /* -------------------- */
    this->create_file(this->path_project + (this->file_compiler_sh),
                      this->content_compiler_script);
    /* -------------------- */
    this->create_file(this->path_project + (this->file_cmake_txt),
                      this->content_cmake_list);
    /* -------------------- */
    this->create_file(this->path_project + (this->file_cmake_sh),
                      this->content_cmake_script);
    /* -------------------- */
    this->create_file(this->path_project + (this->file_main_cpp),
                      this->content_main_cpp);
    /* -------------------- */
    this->create_file(this->path_project + (this->file_main_001_cpp),
                      this->content_main_cpp);
    /* -------------------- */
    this->create_file(this->path_project + (this->file_main_001_asm),
                      this->content_main_001_asm);
    /* -------------------- */
    this->create_file(this->path_project + (this->file_clang_tidy),
                      this->content_clang_tidy);
    /* -------------------- */
    this->create_file(this->path_project + (this->file_git_ignore),
                      this->content_git_ignore);
    /* -------------------- */
    std::string ws{this->project_name.append(this->file_work_space)};

    this->create_file(this->path_project + constants::str_slash + (ws),
                      this->content_work_space);
}

/* public: ----------------------------- */

Project::Project(const std::string &_project_path) {
    this->path_project = _project_path;
}

[[maybe_unused]] Project::Project(
    const std::string &_project_path, const std::string &_cpp_file,
    const std::string &_cpp_001_file, const std::string &_asm_001_file,
    const std::string &_run_script, const std::string &_new_script,
    const std::string &_cmake_new_script, const std::string &_asm_script,
    const std::string &_cmake_list, const std::string &_cmake_script,
    const std::string &_git_ignore, const std::string &_clang_tidy,
    const std::string &_work_space) {

    this->path_project = _project_path;
    this->content_main_cpp = _cpp_file;
    this->content_main_001_cpp = _cpp_001_file;
    this->content_main_001_asm = _asm_001_file;
    this->content_run_script = _run_script;
    this->content_asm_script = _asm_script;
    this->content_new_script = _new_script;
    this->content_cmake_new_script = _cmake_new_script;
    this->content_cmake_list = _cmake_list;
    this->content_cmake_script = _cmake_script;
    this->content_git_ignore = _git_ignore;
    this->content_clang_tidy = _clang_tidy;
    this->content_work_space = _work_space;
}

void Project::set_cpp_file(const std::string &_content) {
    this->content_main_cpp.clear();
    this->content_main_cpp = _content;
}

void Project::set_cpp_001_file(const std::string &_content) {
    this->content_main_001_cpp.clear();
    this->content_main_001_cpp = _content;
}

void Project::set_run_script_file(const std::string &_content) {
    this->content_run_script.clear();
    this->content_run_script = _content;
}

void Project::set_new_script_file(const std::string &_content) {
    this->content_new_script.clear();
    this->content_new_script = _content;
}

void Project::set_compiler_script_file(const std::string &_content) {
    this->content_compiler_script.clear();
    this->content_compiler_script = _content;
}

void Project::set_asm_001_file(const std::string &_content) {
    this->content_main_001_asm.clear();
    this->content_main_001_asm = _content;
}

void Project::set_asm_script_file(const std::string &_content) {
    this->content_asm_script.clear();
    this->content_asm_script = _content;
}

void Project::set_cmake_list_file(const std::string &_content) {
    this->content_cmake_list.clear();
    this->content_cmake_list = _content;
}

void Project::set_cmake_script_file(const std::string &_content) {
    this->content_cmake_script.clear();
    this->content_cmake_script = _content;
}

void Project::set_cmake_new_script_file(const std::string &_content) {
    this->content_cmake_new_script.clear();
    this->content_cmake_new_script = _content;
}

void Project::set_git_ignore(const std::string &_content) {
    this->content_git_ignore.clear();
    this->content_git_ignore = _content;
}

void Project::set_clang_tidy(const std::string &_content) {
    this->content_clang_tidy.clear();
    this->content_clang_tidy = _content;
}

void Project::set_work_space(const std::string &_content) {
    this->content_work_space.clear();
    this->content_work_space = _content;
}

/* ------------------------------- */
[[nodiscard]] [[maybe_unused]] const std::string &
Project::get_cpp_file() const {
    return this->content_main_cpp;
}

[[nodiscard]] [[maybe_unused]] const std::string &
Project::get_cpp_001_file() const {
    return this->content_main_001_cpp;
}

[[maybe_unused]] const std::string &Project::get_run_script_file() const {
    return this->content_run_script;
}

[[nodiscard]] [[maybe_unused]] const std::string &
Project::get_new_script_file() const {
    return this->content_compiler_script;
}

[[nodiscard]] [[maybe_unused]] const std::string &
Project::get_compiler_script_file() const {
    return this->content_new_script;
}

[[nodiscard]] [[maybe_unused]] const std::string &
Project::get_cmake_list_file() const {
    return this->content_cmake_list;
}

[[nodiscard]] [[maybe_unused]] const std::string &
Project::get_cmake_script_file() const {
    return this->content_cmake_script;
}

[[nodiscard]] [[maybe_unused]] const std::string &
Project::get_asm_001_file() const {
    return this->content_main_001_asm;
}

[[nodiscard]] [[maybe_unused]] const std::string &
Project::get_asm_script_file() const {
    return this->content_asm_script;
}

[[nodiscard]] [[maybe_unused]] const std::string &
Project::get_cmake_new_script_file() const {
    return this->content_cmake_new_script;
}

[[nodiscard]] [[maybe_unused]] const std::string &
Project::get_git_ignore_file() const {
    return this->content_git_ignore;
}

[[nodiscard]] [[maybe_unused]] const std::string &
Project::get_clang_tidy_file() const {
    return this->content_clang_tidy;
}

[[nodiscard]] [[maybe_unused]] const std::string &
Project::get_work_space_file() const {
    return this->content_work_space;
}

void Project::create_project() {
    this->create_folders();
    this->create_files();
}

void Project::replace_all(std::string &str, const std::string &str_from,
                          const std::string &str_to) {
    size_t from_length{str_from.size()};
    size_t pos;
    while ((pos = str.find(str_from)) != std::string::npos) {
        str.replace(pos, from_length, str_to);
    }
}
