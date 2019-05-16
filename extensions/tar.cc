#include "extensions/tar.hpp"
#include <dirent.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

namespace navagraha {
namespace extensions {


tar::tar(std::string tar_name, std::string dir)
    : tar_name(tar_name)
    , dir(dir)
{
    if (access(tar_name.c_str(), F_OK) == 0) {
        remove(tar_name.c_str());
    }
    tar_open(&this->tar_handler, const_cast<char *>(tar_name.c_str()), NULL, O_WRONLY | O_CREAT, 0644, TAR_GNU);
}
tar::~tar()
{
    tar_close(this->tar_handler);
}


void tar::direct_each(std::string direct_name)
{
    DIR * dir = opendir(direct_name.c_str());
    if (dir == NULL) {
        return;
    }
    for (dirent * node = readdir(dir); node; node = readdir(dir)) {
        std::string sub_node = direct_name + "/" + std::string(node->d_name);
        if (node->d_type == DT_DIR && strcmp(node->d_name, ".") != 0 && strcmp(node->d_name, "..") != 0) {
            this->direct_each(sub_node);
        }
        else if (node->d_type != DT_DIR) {
            tar_append_file(this->tar_handler, const_cast<char *>(sub_node.c_str()), const_cast<char *>(sub_node.c_str()));
        }
    }
    closedir(dir);
    tar_append_eof(this->tar_handler);
}

void tar::operator() ()
{
    this->direct_each(this->dir);
}

}
}
