#ifndef _NAVAGRAHA_CLI_PROJECT_INIT_H
#define _NAVAGRAHA_CLI_PROJECT_INIT_H

#include "cli_arg/abstract_process.hpp"
#include "cli_arg/arg.hpp"

namespace navagraha {
namespace cli {

extern char CLI_PROJECT_INIT_PATH[];
extern char CLI_PROJECT_INIT_LANG[];

class project_init : public cli_arg::abstract_process<project_init> {
public:
    cli_arg::arg<CLI_PROJECT_INIT_PATH, 1> arg_path;
    cli_arg::arg<CLI_PROJECT_INIT_LANG, 1> arg_lang;

public:
    virtual void bind(cli_arg::process_helper<project_init> & helper) override;
    virtual int execute() override;
    virtual bool satisfy() const override;
};

}
}

#endif
