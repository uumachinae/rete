//////////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2024 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: main.hpp
///
/// Author: $author$
///   Date: 12/28/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_PROTOCOL_CLIENT_MAIN_HPP
#define XOS_APP_CONSOLE_PROTOCOL_CLIENT_MAIN_HPP

#include "xos/app/console/protocol/client/main_opt.hpp"

namespace xos {
namespace app {
namespace console {
namespace protocol {
namespace client {

/// class maint
template 
<class TExtends = xos::app::console::protocol::client::main_optt<>,  class TImplements = typename TExtends::implements>

class maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };
    typedef typename extends::string_t string_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;

    typedef typename extends::sequence_char_t sequence_char_t;
    typedef typename extends::char_sequence_t char_sequence_t;
    typedef typename extends::char_seeker_t char_seeker_t;
    typedef typename extends::char_reader_t char_reader_t;
    typedef typename extends::char_writer_t char_writer_t;
    typedef typename extends::reader_string_t reader_string_t;
    typedef typename extends::string_reader_t string_reader_t;

    /// constructor / destructor
    maint(): run_(0) {
    }
    virtual ~maint() {
    }
private:
    maint(const maint &copy) {
        throw exception(exception_unexpected);
    }

protected:
    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::err_writer_t err_writer_t;

    //////////////////////////////////////////////////////////////////////////
    /// run
    int (derives::*run_)(int argc, char_t** argv, char_t** env);
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((run_)) {
            if (!(err = (this->*run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = extends::run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }

    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...on...response_option...
    virtual int default_on_get_response_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = this->input_on_get_response_option(optarg, optind, argc, argv, env)))...");
        if (!(err = this->input_on_get_response_option(optarg, optind, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = this->input_on_get_response_option(optarg, optind, argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = this->input_on_get_response_option(optarg, optind, argc, argv, env)))");
        }
        return err;
    }
    virtual int on_response_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = extends::on_response_option_get(optarg, optind, argc, argv, env)))...");
        if (!(err = extends::on_response_option_get(optarg, optind, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = extends::on_response_option_get(optarg, optind, argc, argv, env)))");
            LOGGER_IS_LOGGED_INFO("(!(err = this->set_process_response_run(argc, argv, env)))...");
            if (!(err = this->set_process_response_run(argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = this->set_process_response_run(argc, argv, env)))");
                LOGGER_IS_LOGGED_INFO("(!(err = this->process_response_run_set(argc, argv, env)))...");
                if (!(err = this->process_response_run_set(argc, argv, env))) {
                    LOGGER_IS_LOGGED_INFO("...(!(" << err << " = this->process_response_run_set(argc, argv, env)))");
                } else {
                    LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = this->process_response_run_set(argc, argv, env)))");
                }
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = this->set_process_response_run(argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = extends::on_response_option_get(optarg, optind, argc, argv, env)))");
        }
        return err;
    }
    virtual int on_response_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = extends::on_response_option_set(optarg, optind, argc, argv, env)))...");
        if (!(err = extends::on_response_option_set(optarg, optind, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = extends::on_response_option_set(optarg, optind, argc, argv, env)))");
            LOGGER_IS_LOGGED_INFO("(!(err = this->set_process_response_run(argc, argv, env)))...");
            if (!(err = this->set_process_response_run(argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!" << err << " = this->set_process_response_run(argc, argv, env)))");
                LOGGER_IS_LOGGED_INFO("(!(err = this->process_response_run_set(argc, argv, env)))...");
                if (!(err = this->process_response_run_set(argc, argv, env))) {
                    LOGGER_IS_LOGGED_INFO("...(!(" << err << " = this->process_response_run_set(argc, argv, env)))");
                } else {
                    LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = this->process_response_run_set(argc, argv, env)))");
                }
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = this->set_process_response_run(argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = extends::on_response_option_set(optarg, optind, argc, argv, env)))");
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
protected:
}; /// class maint 
typedef maint<> main;

} /// namespace client 
} /// namespace protocol 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_PROTOCOL_CLIENT_MAIN_HPP

