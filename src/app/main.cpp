#include <iostream>
#include "../classes/prjexception.hpp"
#include "../classes/project.hpp"
#include "../header/filecontents.hpp"
#include "../header/constants.hpp"

int main(int argc, char **argv) {

    std::cout << '\n';
    std::cout << constants::title;
    std::cout << std::endl;

    try {

        if (argc < constants::two || argc > constants::three) {
            throw PrjException(constants::param_error);
        }

        if (argc == 3 && *(argv + constants::two) != constants::postgresql) {
            throw PrjException(constants::param_error);
        }

        std::string project_path{*(argv + constants::one)};

        Project project{project_path};

        project.set_cpp_file(scripts::script_main_cpp);
        project.set_cpp_001_file(scripts::script_main_001_cpp);
        project.set_run_script_file(scripts::script_run_sh);
        project.set_new_script_file(scripts::script_new_sh);
        project.set_cmake_script_file(scripts::script_cmake_sh);

        if (argc == constants::three) {
            project.set_compiler_script_file(scripts::script_compiler_postgres_sh);
            project.set_cmake_list_file(scripts::script_cmake_postgres_txt);

        } else {
            project.set_compiler_script_file(scripts::script_compiler_sh);
            project.set_cmake_list_file(scripts::script_cmake_txt);
        }

        project.create_project();

        std::cout << constants::nl << project_path;
        if (argc == constants::three) {
            std::cout << constants::end_msg_postgres << std::endl;
        } else {
            std::cout << constants::end_msg << std::endl;
        }

    } catch (PrjException &pex) {
        std::cerr << pex.what() << std::endl;
    }
    return EXIT_SUCCESS;
}