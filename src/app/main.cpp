#include <iostream>
#include "../classes/prjexception.hpp"
#include "../classes/project.hpp"
#include "../header/filecontents.hpp"
#include "../header/constants.hpp"
#include  "../header/util.hpp"


int main(int argc, char **argv) {

    // std::cout << "step 1 ..." << std::endl;

    std::string final_message{constants::end_msg};
    //std::cout << '\n';
    std::cout << std::endl;

    std::string param_path{};
    std::string param_project{};
    std::string param_git{};
    std::string param_author{constants::def_author};
    std::string param_email{constants::def_email};
    char command[64]{};
    bool git_init{false};

    // std::cout << "step 2 ..." << std::endl;

    try {

        if (argc < constants::three || argc > constants::six) {
            throw PrjException{constants::param_error_one};
        }

        // std::cout << "step 3 ..." << std::endl;

        for (int i = 0; i < argc; i++) {
            std::string param = std::string{argv[i]};
            if (param.starts_with(constants::param_path)) {
                param_path = {param};
            } else if (param.starts_with(constants::pre_param_project)) {
                param_project = {param};
            } else if (param == constants::param_git) {
                param_git = {param};
            } else if (param.starts_with(constants::param_git_author)) {
                param_author = {param};
            } else if (param.starts_with(constants::param_git_email)) {
                param_email = {param};
            }
        }

        // std::cout << "step 4 ..." << std::endl;

        check_param(param_path);
        check_git_param(param_author);
        check_git_param(param_email);

        // std::cout << "step 5 ..." << std::endl;


        const std::string project_path{get_param_content(param_path)};
        const std::string author{get_param_content(param_author)};
        const std::string email{get_param_content(param_email)};

        // std::cout << "step 6 ..." << std::endl;


        Project project{project_path};

        // std::cout << "step 7 ..." << std::endl;

        if (param_project == constants::param_normal) {
            set_normal_project(project);
            project.create_project();
        } else if (param_project == constants::param_postgres) {
            set_postgres_project(project);
            project.create_project();
            final_message = constants::end_msg_postgres;
        } else if (param_project == constants::param_qt_ui) {
            set_qt_ui_project(project);
            project.create_project();
            final_message = constants::end_msg_qt_ui;
        } else if (param_project == constants::param_qt_console) {
            set_qt_console_project(project);
            project.create_project();
            final_message = constants::end_msg_qt_cli;
        }

        // std::cout << "step 8 ..." << std::endl;

        if (param_git == constants::param_git) {
            std::sprintf(command, "git init %s", project_path.c_str());
            system(command);
            git_init = {true};
            std::cout << std::endl;
        }

        // std::cout << "step 9 ..." << std::endl;

        if (param_author != constants::def_author && git_init) {
            std::sprintf(command, "cd %s && git config user.name \"%s\"", project_path.c_str(), author.c_str());
            // std::cout << "value of command is: " << command << std::endl;
            system(command);
        }

        // std::cout << "step 10 ..." << std::endl;

        if (param_email != constants::def_email && git_init) {
            std::sprintf(command, "cd %s && git config user.email \"%s\"", project_path.c_str(), email.c_str());
            // std::cout << "value of command is: " << command << std::endl;
            system(command);
        }

        // std::cout << "step 11 ..." << std::endl;

        std::cout << constants::title;
        std::cout << constants::nl << constants::sp << project_path;
        std::cout << final_message << std::endl;

        // std::cout << "step 12 ..." << std::endl;

    } catch (PrjException &pex) {
        std::cerr << pex.what() << std::endl;
    }

    // std::cout << "step 13 ..." << std::endl;
    // std::cout << "step end ..." << std::endl;
    return EXIT_SUCCESS;
}

