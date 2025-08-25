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
///   File: main_opt.hpp
///
/// Author: $author$
///   Date: 12/13/2024, 7/24/2025
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_OPT_HPP

#include "xos/app/console/input/base/main.hpp"

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_REQUEST_OPT "request"
#define XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_REQUEST_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_REQUEST_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_REQUEST_OPTARG XOS_APP_CONSOLE_MAIN_OPTARG_STRING_OPTIONAL
#define XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_REQUEST_OPTUSE "request message"
#define XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_REQUEST_OPTVAL_S "r::"
#define XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_REQUEST_OPTVAL_C 'r'
#define XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_REQUEST_OPTION \
   {XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_REQUEST_OPT, \
    XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_REQUEST_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_REQUEST_OPTARG_RESULT, \
    XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_REQUEST_OPTVAL_C}, \

#define XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_RESPONSE_OPT "response"
#define XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_RESPONSE_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_RESPONSE_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_RESPONSE_OPTARG XOS_APP_CONSOLE_MAIN_OPTARG_STRING_OPTIONAL
#define XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_RESPONSE_OPTUSE "response message"
#define XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_RESPONSE_OPTVAL_S "s::"
#define XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_RESPONSE_OPTVAL_C 's'
#define XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_RESPONSE_OPTION \
   {XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_RESPONSE_OPT, \
    XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_RESPONSE_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_RESPONSE_OPTARG_RESULT, \
    XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_RESPONSE_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_REQUEST_OPTVAL_S \
   XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_RESPONSE_OPTVAL_S \

#define XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_REQUEST_OPTION \
   XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_RESPONSE_OPTION \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_INPUT_OPTIONS_CHARS \
   XOS_APP_CONSOLE_INPUT_BASE_MAIN_OPTIONS_CHARS \

#define XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_INPUT_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_INPUT_BASE_MAIN_OPTIONS_OPTIONS \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_INPUT_BASE_MAIN_OPTIONS_CHARS \

#define XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_INPUT_BASE_MAIN_OPTIONS_OPTIONS \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_ARGS 0
#define XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_ARGV 0,

namespace xos {
namespace app {
namespace console {
namespace protocol {
namespace base {

/// class main_optt
template 
<class TExtends = xos::app::console::input::base::maint<>,  class TImplements = typename TExtends::implements>

class main_optt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef main_optt derives;

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
    main_optt(): run_(0) {
    }
    virtual ~main_optt() {
    }
private:
    main_optt(const main_optt &copy) {
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
    /// ...process_request_run
    int (derives::*process_request_run_)(int argc, char_t** argv, char_t** env);
    virtual int process_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (process_request_run_) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*process_request_run_)(argc, argv, env)))...");
            if (!(err = (this->*process_request_run_)(argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*process_request_run_)(argc, argv, env)))");
            } else {
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_process_request_run(argc, argv, env)))...");
            if (!(err = default_process_request_run(argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_process_request_run(argc, argv, env)))");
            } else {
            }
        }
        return err;
    }
    virtual int default_process_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = all_output_response_run(argc, argv, env)))...");
        if (!(err = all_output_response_run(argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = all_output_response_run(argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = all_output_response_run(argc, argv, env)))");
        }
        return err;
    }
    virtual int before_process_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_process_request_run(argc, argv, env))) {
            int err2 = 0;
            err = process_request_run(argc, argv, env);
            if ((err2 = after_process_request_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_process_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_process_request_run;
        return err;
    }
    virtual int process_request_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_process_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int process_request_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...process_response_run
    int (derives::*process_response_run_)(int argc, char_t** argv, char_t** env);
    virtual int process_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (process_response_run_) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*process_response_run_)(argc, argv, env)))...");
            if (!(err = (this->*process_response_run_)(argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*process_response_run_)(argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*process_response_run_)(argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_process_response_run(argc, argv, env)))...");
            if (!(err = default_process_response_run(argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_process_response_run(argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_process_response_run(argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int default_process_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = all_output_response_run(argc, argv, env)))...");
        if (!(err = all_output_response_run(argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = all_output_response_run(argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = all_output_response_run(argc, argv, env)))");
        }
        return err;
    }
    virtual int before_process_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_process_response_run(argc, argv, env))) {
            int err2 = 0;
            err = process_response_run(argc, argv, env);
            if ((err2 = after_process_response_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_process_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_process_response_run;
        return err;
    }
    virtual int process_response_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_process_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int process_response_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...prepare_response_to_request_run
    int (derives::*prepare_response_to_request_run_)(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env);
    virtual int prepare_response_to_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (prepare_response_to_request_run_) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*prepare_response_to_request_run_)(\"" << response << "\", \"" << request << "\", argc, argv, env)))...");
            if (!(err = (this->*prepare_response_to_request_run_)(response, request, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*prepare_response_to_request_run_)(\"" << response << "\", \"" << request << "\", argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*prepare_response_to_request_run_)(\"" << response << "\", \"" << request << "\", argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_prepare_response_to_request_run(\"" << response << "\", \"" << request << "\", argc, argv, env)))...");
            if (!(err = default_prepare_response_to_request_run(response, request, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_prepare_response_to_request_run(\"" << response << "\", \"" << request << "\", argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_prepare_response_to_request_run(\"" << response << "\", \"" << request << "\", argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int default_prepare_response_to_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_prepare_response_to_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_response_to_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_response_to_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_response_to_request_run(response, request, argc, argv, env))) {
            int err2 = 0;
            err = prepare_response_to_request_run(response, request, argc, argv, env);
            if ((err2 = after_prepare_response_to_request_run(response, request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...prepare_response_to_unknown_request_run
    int (derives::*prepare_response_to_unknown_request_run_)(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env);
    virtual int prepare_response_to_unknown_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (prepare_response_to_unknown_request_run_) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*prepare_response_to_unknown_request_run_)(\"" << response << "\", \"" << request << "\", argc, argv, env)))...");
            if (!(err = (this->*prepare_response_to_unknown_request_run_)(response, request, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*prepare_response_to_unknown_request_run_)(\"" << response << "\", \"" << request << "\", argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*prepare_response_to_unknown_request_run_)(\"" << response << "\", \"" << request << "\", argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_prepare_response_to_unknown_request_run(\"" << response << "\", \"" << request << "\", argc, argv, env)))...");
            if (!(err = default_prepare_response_to_unknown_request_run(response, request, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_prepare_response_to_unknown_request_run(\"" << response << "\", \"" << request << "\", argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_prepare_response_to_unknown_request_run(\"" << response << "\", \"" << request << "\", argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int default_prepare_response_to_unknown_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = all_prepare_response_to_echo_request_run(response, request, argc, argv, env)))...");
        if (!(err = all_prepare_response_to_echo_request_run(response, request, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = all_prepare_response_to_echo_request_run(response, request, argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = all_prepare_response_to_echo_request_run(response, request, argc, argv, env)))");
        }
        return err;
    }
    virtual int before_prepare_response_to_unknown_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = set_prepare_response_to_unknown_request_to_output_run(argc, argv, env))) {
            if (!(err = prepare_response_to_unknown_request_to_output_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int after_prepare_response_to_unknown_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_response_to_unknown_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_response_to_unknown_request_run(response, request, argc, argv, env))) {
            int err2 = 0;
            err = prepare_response_to_unknown_request_run(response, request, argc, argv, env);
            if ((err2 = after_prepare_response_to_unknown_request_run(response, request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...prepare_response_to_echo_request_run
    int (derives::*prepare_response_to_echo_request_run_)(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env);
    virtual int prepare_response_to_echo_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (prepare_response_to_echo_request_run_) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*prepare_response_to_echo_request_run_)(response, request, argc, argv, env)))...");
            if (!(err = (this->*prepare_response_to_echo_request_run_)(response, request, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*prepare_response_to_echo_request_run_)(response, request, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*prepare_response_to_echo_request_run_)(response, request, argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_prepare_response_to_echo_request_run(response, request, argc, argv, env)))...");
            if (!(err = default_prepare_response_to_echo_request_run(response, request, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_prepare_response_to_echo_request_run(response, request, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_prepare_response_to_echo_request_run(response, request, argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int default_prepare_response_to_echo_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("response.assign(request = \"" << request << "\")...");
        response.assign(request);
        return err;
    }
    virtual int before_prepare_response_to_echo_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = set_prepare_response_to_echo_request_to_output_run(argc, argv, env))) {
            if (!(err = prepare_response_to_echo_request_to_output_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int after_prepare_response_to_echo_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_response_to_echo_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_response_to_echo_request_run(response, request, argc, argv, env))) {
            int err2 = 0;
            err = prepare_response_to_echo_request_run(response, request, argc, argv, env);
            if ((err2 = after_prepare_response_to_echo_request_run(response, request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...prepare_response_to_hello_request_run
    int (derives::*prepare_response_to_hello_request_run_)(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env);
    virtual int prepare_response_to_hello_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (prepare_response_to_hello_request_run_) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*prepare_response_to_hello_request_run_)(response, request, argc, argv, env)))...");
            if (!(err = (this->*prepare_response_to_hello_request_run_)(response, request, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*prepare_response_to_hello_request_run_)(response, request, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*prepare_response_to_hello_request_run_)(response, request, argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_prepare_response_to_hello_request_run(response, request, argc, argv, env)))...");
            if (!(err = default_prepare_response_to_hello_request_run(response, request, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_prepare_response_to_hello_request_run(response, request, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_prepare_response_to_hello_request_run(response, request, argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int default_prepare_response_to_hello_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_prepare_response_to_hello_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_response_to_hello_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_response_to_hello_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_response_to_hello_request_run(response, request, argc, argv, env))) {
            int err2 = 0;
            err = prepare_response_to_hello_request_run(response, request, argc, argv, env);
            if ((err2 = after_prepare_response_to_hello_request_run(response, request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...prepare_response_to_restart_request_run
    int (derives::*prepare_response_to_restart_request_run_)(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env);
    virtual int prepare_response_to_restart_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (prepare_response_to_restart_request_run_) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*prepare_response_to_restart_request_run_)(response, request, argc, argv, env)))...");
            if (!(err = (this->*prepare_response_to_restart_request_run_)(response, request, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*prepare_response_to_restart_request_run_)(response, request, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*prepare_response_to_restart_request_run_)(response, request, argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_prepare_response_to_restart_request_run(response, request, argc, argv, env)))...");
            if (!(err = default_prepare_response_to_restart_request_run(response, request, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_prepare_response_to_restart_request_run(response, request, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_prepare_response_to_restart_request_run(response, request, argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int default_prepare_response_to_restart_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_prepare_response_to_restart_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_response_to_restart_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_response_to_restart_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_response_to_restart_request_run(response, request, argc, argv, env))) {
            int err2 = 0;
            err = prepare_response_to_restart_request_run(response, request, argc, argv, env);
            if ((err2 = after_prepare_response_to_restart_request_run(response, request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...prepare_response_to_start_request_run
    int (derives::*prepare_response_to_start_request_run_)(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env);
    virtual int prepare_response_to_start_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (prepare_response_to_start_request_run_) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*prepare_response_to_start_request_run_)(response, request, argc, argv, env)))...");
            if (!(err = (this->*prepare_response_to_start_request_run_)(response, request, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*prepare_response_to_start_request_run_)(response, request, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*prepare_response_to_start_request_run_)(response, request, argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_prepare_response_to_start_request_run(response, request, argc, argv, env)))...");
            if (!(err = default_prepare_response_to_start_request_run(response, request, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_prepare_response_to_start_request_run(response, request, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_prepare_response_to_start_request_run(response, request, argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int default_prepare_response_to_start_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_prepare_response_to_start_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_response_to_start_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_response_to_start_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_response_to_start_request_run(response, request, argc, argv, env))) {
            int err2 = 0;
            err = prepare_response_to_start_request_run(response, request, argc, argv, env);
            if ((err2 = after_prepare_response_to_start_request_run(response, request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...prepare_response_to_stop_request_run
    int (derives::*prepare_response_to_stop_request_run_)(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env);
    virtual int prepare_response_to_stop_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (prepare_response_to_stop_request_run_) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*prepare_response_to_stop_request_run_)(response, request, argc, argv, env)))...");
            if (!(err = (this->*prepare_response_to_stop_request_run_)(response, request, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*prepare_response_to_stop_request_run_)(response, request, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*prepare_response_to_stop_request_run_)(response, request, argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_prepare_response_to_stop_request_run(response, request, argc, argv, env)))...");
            if (!(err = default_prepare_response_to_stop_request_run(response, request, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_prepare_response_to_stop_request_run(response, request, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_prepare_response_to_stop_request_run(response, request, argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int default_prepare_response_to_stop_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_prepare_response_to_stop_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_response_to_stop_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_response_to_stop_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_response_to_stop_request_run(response, request, argc, argv, env))) {
            int err2 = 0;
            err = prepare_response_to_stop_request_run(response, request, argc, argv, env);
            if ((err2 = after_prepare_response_to_stop_request_run(response, request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...process_response_run
    int (derives::*process_response_run__)(string_t& response, int argc, char_t** argv, char_t** env);
    virtual int process_response_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (process_response_run__) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*process_response_run__)(\"" << response << "\", argc, argv, env)))...");
            if (!(err = (this->*process_response_run__)(response, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*process_response_run__)(\"" << response << "\", argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*process_response_run__)(\"" << response << "\", argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_process_response_run(\"" << response << "\", argc, argv, env)))...");
            if (!(err = default_process_response_run(response, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_process_response_run(\"" << response << "\", argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_process_response_run(\"" << response << "\", argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int default_process_response_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = all_process_unknown_response_run(\"" << response << "\", argc, argv, env)))...");
        if (!(err = all_process_unknown_response_run(response, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = all_process_unknown_response_run(\"" << response << "\", argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = all_process_unknown_response_run(\"" << response << "\", argc, argv, env)))");
        }
        return err;
    }
    virtual int before_process_response_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_response_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_response_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_process_response_run(response, argc, argv, env))) {
            int err2 = 0;
            err = process_response_run(response, argc, argv, env);
            if ((err2 = after_process_response_run(response, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...process_unknown_response_run
    int (derives::*process_unknown_response_run_)(string_t& response, int argc, char_t** argv, char_t** env);
    virtual int process_unknown_response_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (process_unknown_response_run_) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*process_unknown_response_run_)(\"" << response << "\", argc, argv, env)))...");
            if (!(err = (this->*process_unknown_response_run_)(response, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*process_unknown_response_run_)(\"" << response << "\", argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*process_unknown_response_run_)(\"" << response << "\", argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_process_unknown_response_run(\"" << response << "\", argc, argv, env)))...");
            if (!(err = default_process_unknown_response_run(response, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_process_unknown_response_run(\"" << response << "\", argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_process_unknown_response_run(\"" << response << "\", argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int default_process_unknown_response_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = all_prepare_to_process_unknown_response_run(\"" << response << "\", argc, argv, env)))...");
        if (!(err = all_prepare_to_process_unknown_response_run(response, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = all_prepare_to_process_unknown_response_run(\"" << response << "\", argc, argv, env)))");

            LOGGER_IS_LOGGED_INFO("(!(err = all_output_response_run(\"" << response << "\", argc, argv, env)))...");
            if (!(err = all_output_response_run(response, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = all_output_response_run(\"" << response << "\", argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = all_output_response_run(\"" << response << "\", argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = all_prepare_to_process_unknown_response_run(\"" << response << "\", argc, argv, env)))");
        }
        return err;
    }
    virtual int before_process_unknown_response_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_unknown_response_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_unknown_response_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_process_unknown_response_run(response, argc, argv, env))) {
            int err2 = 0;
            err = process_unknown_response_run(response, argc, argv, env);
            if ((err2 = after_process_unknown_response_run(response, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...prepare_to_process_unknown_response_run
    int (derives::*prepare_to_process_unknown_response_run_)(string_t& response, int argc, char_t** argv, char_t** env);
    virtual int prepare_to_process_unknown_response_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (prepare_to_process_unknown_response_run_) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*prepare_to_process_unknown_response_run_)(response, argc, argv, env)))...");
            if (!(err = (this->*prepare_to_process_unknown_response_run_)(response, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*prepare_to_process_unknown_response_run_)(response, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*prepare_to_process_unknown_response_run_)(response, argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_prepare_to_process_unknown_response_run(response, argc, argv, env)))...");
            if (!(err = default_prepare_to_process_unknown_response_run(response, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_prepare_to_process_unknown_response_run(response, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_prepare_to_process_unknown_response_run(response, argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int default_prepare_to_process_unknown_response_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_prepare_to_process_unknown_response_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_to_process_unknown_response_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_to_process_unknown_response_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_to_process_unknown_response_run(response, argc, argv, env))) {
            int err2 = 0;
            err = prepare_to_process_unknown_response_run(response, argc, argv, env);
            if ((err2 = after_prepare_to_process_unknown_response_run(response, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...output_request_run
    int (derives::*output_request_run_)(int argc, char_t** argv, char_t** env);
    virtual int output_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (output_request_run_) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*output_request_run_)(argc, argv, env)))...");
            if (!(err = (this->*output_request_run_)(argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*output_request_run_)(argc, argv, env)))");
            } else {
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_output_request_run(argc, argv, env)))...");
            if (!(err = default_output_request_run(argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_output_request_run(argc, argv, env)))");
            } else {
            }
        }
        return err;
    }
    virtual int default_output_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = extends::run(argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int before_output_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_request_run(argc, argv, env))) {
            int err2 = 0;
            err = output_request_run(argc, argv, env);
            if ((err2 = after_output_request_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_output_request_run;
        return err;
    }
    virtual int output_request_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_output_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int output_request_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...output_response_run
    int (derives::*output_response_run_)(int argc, char_t** argv, char_t** env);
    virtual int output_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (output_response_run_) {
            err = (this->*output_response_run_)(argc, argv, env);
        } else {
            err = default_output_response_run(argc, argv, env);
        }
        return err;
    }
    virtual int default_output_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        err = extends::run(argc, argv, env);
        return err;
    }
    virtual int before_output_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_response_run(argc, argv, env))) {
            int err2 = 0;
            err = output_response_run(argc, argv, env);
            if ((err2 = after_output_response_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_output_response_run;
        return err;
    }
    virtual int output_response_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_output_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int output_response_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...output_request_run
    virtual int output_request_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = all_prepare_request_to_output_run(\"" << request << "\", argc, argv, env)))...");
        if (!(err = all_prepare_request_to_output_run(request, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = all_prepare_request_to_output_run(\"" << request << "\", argc, argv, env)))");

            LOGGER_IS_LOGGED_INFO("(!(err = all_output_message_run(\"" << request << "\", argc, argv, env)))...");
            if (!(err = all_output_message_run(request, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = all_output_message_run(\"" << request << "\", argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = all_output_message_run(\"" << request << "\", argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = all_prepare_request_to_output_run(\"" << request << "\", argc, argv, env)))");
        }
        return err;
    }
    virtual int before_output_request_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_request_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_request_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_request_run(request, argc, argv, env))) {
            int err2 = 0;
            err = output_request_run(request, argc, argv, env);
            if ((err2 = after_output_request_run(request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...prepare_request_to_output_run
    int (derives::*prepare_request_to_output_run_)(string_t& request, int argc, char_t** argv, char_t** env);
    virtual int prepare_request_to_output_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (prepare_request_to_output_run_) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*prepare_request_to_output_run_)(request, argc, argv, env)))...");
            if (!(err = (this->*prepare_request_to_output_run_)(request, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*prepare_request_to_output_run_)(request, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*prepare_request_to_output_run_)(request, argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_prepare_request_to_output_run(request, argc, argv, env)))...");
            if (!(err = default_prepare_request_to_output_run(request, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_prepare_request_to_output_run(request, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_prepare_request_to_output_run(request, argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int default_prepare_request_to_output_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_prepare_request_to_output_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_request_to_output_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_request_to_output_run(string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_request_to_output_run(request, argc, argv, env))) {
            int err2 = 0;
            err = prepare_request_to_output_run(request, argc, argv, env);
            if ((err2 = after_prepare_request_to_output_run(request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...output_response_run
    int (derives::*output_response_run__)(string_t& response, int argc, char_t** argv, char_t** env);
    virtual int output_response_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (output_response_run__) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*output_response_run__)(\"" << response << "\", argc, argv, env)))...");
            if (!(err = (this->*output_response_run__)(response, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*output_response_run__)(\"" << response << "\", argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*output_response_run__)(\"" << response << "\", argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_output_response_run(response, argc, argv, env)))...");
            if (!(err = default_output_response_run(response, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_output_response_run(response, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_output_response_run(response, argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int default_output_response_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = all_prepare_response_to_output_run(\"" << response << "\", argc, argv, env)))...");
        if (!(err = all_prepare_response_to_output_run(response, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = all_prepare_response_to_output_run(\"" << response << "\", argc, argv, env)))");

            LOGGER_IS_LOGGED_INFO("!(err = all_output_message_run(\"" << response << "\", argc, argv, env))...");
            if (!(err = all_output_message_run(response, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_output_message_run(\"" << response << "\", argc, argv, env))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = all_output_message_run(\"" << response << "\", argc, argv, env))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = all_prepare_response_to_output_run(\"" << response << "\", argc, argv, env)))");
        }
        return err;
    }
    virtual int before_output_response_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_response_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = unset_prepare_response_to_output_run(argc, argv, env))) {
            if (!(err = prepare_response_to_output_run_unset(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int all_output_response_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_response_run(response, argc, argv, env))) {
            int err2 = 0;
            err = output_response_run(response, argc, argv, env);
            if ((err2 = after_output_response_run(response, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual int output_response_to_output_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("!(err = default_output_response_run(\"" << response << "\", argc, argv, env))...");
        if (!(err = default_output_response_run(response, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = default_output_response_run(\"" << response << "\", argc, argv, env))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = default_output_response_run(\"" << response << "\", argc, argv, env))");
        }
        return err;
    }
    virtual int set_output_response_to_output_run() {
        int err = 0;
        output_response_run__ = &derives::output_response_to_output_run;
        return err;
    }
    virtual int output_response_to_output_run_set() {
        int err = 0;
        return err;
    }
    virtual int unset_output_response_to_output_run() {
        int err = 0;
        output_response_run__ = 0;
        return err;
    }
    virtual int output_response_to_output_run_unset() {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...prepare_response_to_output_run
    int (derives::*prepare_response_to_output_run_)(string_t& response, int argc, char_t** argv, char_t** env);
    virtual int prepare_response_to_output_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (prepare_response_to_output_run_) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*prepare_response_to_output_run_)(response, argc, argv, env)))...");
            if (!(err = (this->*prepare_response_to_output_run_)(response, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*prepare_response_to_output_run_)(response, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*prepare_response_to_output_run_)(response, argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_prepare_response_to_output_run(response, argc, argv, env)))...");
            if (!(err = default_prepare_response_to_output_run(response, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_prepare_response_to_output_run(response, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_prepare_response_to_output_run(response, argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int default_prepare_response_to_output_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_prepare_response_to_output_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_response_to_output_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_response_to_output_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_response_to_output_run(response, argc, argv, env))) {
            int err2 = 0;
            err = prepare_response_to_output_run(response, argc, argv, env);
            if ((err2 = after_prepare_response_to_output_run(response, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int unset_prepare_response_to_output_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        prepare_response_to_output_run_ = 0;
        return err;
    }
    virtual int prepare_response_to_output_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...prepare_response_to_echo_request_to_output_run
    virtual int prepare_response_to_echo_request_to_output_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int set_prepare_response_to_echo_request_to_output_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        prepare_response_to_output_run_ = &derives::prepare_response_to_echo_request_to_output_run;
        return err;
    }
    virtual int prepare_response_to_echo_request_to_output_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_prepare_response_to_echo_request_to_output_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        prepare_response_to_output_run_ = 0;
        return err;
    }
    virtual int prepare_response_to_echo_request_to_output_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...prepare_response_to_unknown_request_to_output_run
    virtual int prepare_response_to_unknown_request_to_output_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int set_prepare_response_to_unknown_request_to_output_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        prepare_response_to_output_run_ = &derives::prepare_response_to_unknown_request_to_output_run;
        return err;
    }
    virtual int prepare_response_to_unknown_request_to_output_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_prepare_response_to_unknown_request_to_output_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        prepare_response_to_output_run_ = 0;
        return err;
    }
    virtual int prepare_response_to_unknown_request_to_output_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...output_message_run
    int (derives::*output_message_run_)(string_t& msg, int argc, char_t** argv, char_t** env);
    virtual int output_message_run(string_t& msg, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (output_message_run_) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*output_message_run_)(\"" << msg << "\", argc, argv, env)))...");
            if (!(err = (this->*output_message_run_)(msg, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*output_message_run_)(\"" << msg << "\", argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*output_message_run_)(\"" << msg << "\", argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_output_message_run(\"" << msg << "\", argc, argv, env)))...");
            if (!(err = default_output_message_run(msg, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_output_message_run(\"" << msg << "\", argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_output_message_run(\"" << msg << "\", argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int default_output_message_run(string_t& msg, int argc, char_t** argv, char_t** env) {
        int err = 0;
        const bool output_lf = this->output_lf();
        LOGGER_IS_LOGGED_INFO("(!(err = all_prepare_message_to_output_run(\"" << msg << "\", argc, argv, env)))...");
        if (!(err = all_prepare_message_to_output_run(msg, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = all_prepare_message_to_output_run(\"" << msg << "\", argc, argv, env)))");
            if ((output_lf)) {
                LOGGER_IS_LOGGED_INFO("this->outln(\"" << msg << "\")...");
                this->outln(msg);
            } else {
                LOGGER_IS_LOGGED_INFO("this->out(\"" << msg << "\")...");
                this->out(msg);
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = all_prepare_message_to_output_run(\"" << msg << "\", argc, argv, env)))");
        }
        return err;
    }
    virtual int before_output_message_run(string_t& msg, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_message_run(string_t& msg, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_message_run(string_t& msg, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_message_run(msg, argc, argv, env))) {
            int err2 = 0;
            err = output_message_run(msg, argc, argv, env);
            if ((err2 = after_output_message_run(msg, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int unset_output_message_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_message_run_ = 0;
        return err;
    }
    virtual int output_message_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...raw_output_message_run
    virtual int raw_output_message_run(string_t& msg, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = all_prepare_message_to_output_run(\"" << msg << "\", argc, argv, env)))...");
        if (!(err = all_prepare_message_to_output_run(msg, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = all_prepare_message_to_output_run(\"" << msg << "\", argc, argv, env)))");
            LOGGER_IS_LOGGED_INFO("this->out(\"" << msg << "\")...");
            this->out(msg);
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = all_prepare_message_to_output_run(\"" << msg << "\", argc, argv, env)))");
        }
        return err;
    }
    virtual int set_raw_output_message_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_message_run_ = &derives::raw_output_message_run;
        return err;
    }
    virtual int raw_output_message_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_raw_output_message_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_message_run_ = 0;
        return err;
    }
    virtual int raw_output_message_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...prepare_message_to_output_run
    int (derives::*prepare_message_to_output_run_)(string_t& msg, int argc, char_t** argv, char_t** env);
    virtual int prepare_message_to_output_run(string_t& msg, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (prepare_message_to_output_run_) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*prepare_message_to_output_run_)(\"" << msg << "\", argc, argv, env)))...");
            if (!(err = (this->*prepare_message_to_output_run_)(msg, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*prepare_message_to_output_run_)(\"" << msg << "\", argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*prepare_message_to_output_run_)(\"" << msg << "\", argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_prepare_message_to_output_run(\"" << msg << "\", argc, argv, env)))...");
            if (!(err = default_prepare_message_to_output_run(msg, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_prepare_message_to_output_run(\"" << msg << "\", argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_prepare_message_to_output_run(\"" << msg << "\", argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int default_prepare_message_to_output_run(string_t& msg, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_prepare_message_to_output_run(string_t& msg, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_message_to_output_run(string_t& msg, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_message_to_output_run(string_t& msg, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_message_to_output_run(msg, argc, argv, env))) {
            int err2 = 0;
            err = prepare_message_to_output_run(msg, argc, argv, env);
            if ((err2 = after_prepare_message_to_output_run(msg, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...input_message_run
    int (derives::*input_message_run_)(string_t& msg, int argc, char_t** argv, char_t** env);
    virtual int input_message_run(string_t& msg, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (input_message_run_) {
            if (!(err = (this->*input_message_run_)(msg, argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = all_text_input_message_run(msg, argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int before_input_message_run(string_t& msg, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_input_message_run(string_t& msg, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_input_message_run(string_t& msg, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_input_message_run(msg, argc, argv, env))) {
            int err2 = 0;
            err = input_message_run(msg, argc, argv, env);
            if ((err2 = after_input_message_run(msg, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...text_input_message_run
    virtual int text_input_message_run(string_t& msg, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_text_input_message_run(string_t& msg, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_text_input_message_run(string_t& msg, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_text_input_message_run(string_t& msg, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_text_input_message_run(msg, argc, argv, env))) {
            int err2 = 0;
            err = text_input_message_run(msg, argc, argv, env);
            if ((err2 = after_text_input_message_run(msg, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_text_input_message_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        input_message_run_ = &derives::all_text_input_message_run;
        return err;
    }
    virtual int text_input_message_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_text_input_message_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        input_message_run_ = 0;
        return err;
    }
    virtual int text_input_message_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...hex_input_message_run
    virtual int hex_input_message_run(string_t& msg, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_hex_input_message_run(string_t& msg, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_hex_input_message_run(string_t& msg, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_hex_input_message_run(string_t& msg, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_hex_input_message_run(msg, argc, argv, env))) {
            int err2 = 0;
            err = hex_input_message_run(msg, argc, argv, env);
            if ((err2 = after_hex_input_message_run(msg, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_hex_input_message_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        input_message_run_ = &derives::all_hex_input_message_run;
        return err;
    }
    virtual int hex_input_message_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_hex_input_message_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        input_message_run_ = 0;
        return err;
    }
    virtual int hex_input_message_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...base64_input_message_run
    virtual int base64_input_message_run(string_t& msg, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_base64_input_message_run(string_t& msg, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_base64_input_message_run(string_t& msg, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_base64_input_message_run(string_t& msg, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_base64_input_message_run(msg, argc, argv, env))) {
            int err2 = 0;
            err = base64_input_message_run(msg, argc, argv, env);
            if ((err2 = after_base64_input_message_run(msg, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_base64_input_message_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        input_message_run_ = &derives::all_base64_input_message_run;
        return err;
    }
    virtual int base64_input_message_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_base64_input_message_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        input_message_run_ = 0;
        return err;
    }
    virtual int base64_input_message_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...on...get_request_option...
    int (derives::*on_get_request_option_)(const char_t* optarg, int optind, int argc, char_t** argv, char_t** env);
    virtual int input_on_get_request_option
    (const char_t* optarg, int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int set_input_on_get_request_option(int argc, char_t** argv, char_t** env) {
        int err = 0;
        on_get_request_option_ = &derives::input_on_get_request_option;
        return err;
    }
    virtual int input_on_get_request_option_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_input_on_get_request_option(int argc, char_t** argv, char_t** env) {
        int err = 0;
        on_get_request_option_ = 0;
        return err;
    }
    virtual int input_on_get_request_option_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...on...get_response_option...
    int (derives::*on_get_response_option_)(const char_t* optarg, int optind, int argc, char_t** argv, char_t** env);
    virtual int input_on_get_response_option
    (const char_t* optarg, int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int set_input_on_get_response_option(int argc, char_t** argv, char_t** env) {
        int err = 0;
        on_get_response_option_ = &derives::input_on_get_response_option;
        return err;
    }
    virtual int input_on_get_response_option_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_input_on_get_response_option(int argc, char_t** argv, char_t** env) {
        int err = 0;
        on_get_response_option_ = 0;
        return err;
    }
    virtual int input_on_get_response_option_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...on...set_request_option...
    int (derives::*on_set_request_option_)(const char_t* optarg, int optind, int argc, char_t** argv, char_t** env);
    virtual int file_on_set_request_option
    (const char_t* optarg, int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int set_file_on_set_request_option(int argc, char_t** argv, char_t** env) {
        int err = 0;
        on_set_request_option_ = &derives::file_on_set_request_option;
        return err;
    }
    virtual int file_on_set_request_option_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_file_on_set_request_option(int argc, char_t** argv, char_t** env) {
        int err = 0;
        on_set_request_option_ = 0;
        return err;
    }
    virtual int file_on_set_request_option_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...on...set_response_option...
    int (derives::*on_set_response_option_)(const char_t* optarg, int optind, int argc, char_t** argv, char_t** env);
    virtual int file_on_set_response_option
    (const char_t* optarg, int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int set_file_on_set_response_option(int argc, char_t** argv, char_t** env) {
        int err = 0;
        on_set_response_option_ = &derives::file_on_set_response_option;
        return err;
    }
    virtual int file_on_set_response_option_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_file_on_set_response_option(int argc, char_t** argv, char_t** env) {
        int err = 0;
        on_set_response_option_ = 0;
        return err;
    }
    virtual int file_on_set_response_option_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...on...request_option...
    virtual int on_get_request_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (on_get_request_option_) {
            if (!(err = (this->*on_get_request_option_)(optarg, optind, argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_on_get_request_option(optarg, optind, argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_on_get_request_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_request_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_output_request_run(argc, argv, env))) {
            if (!(err = output_request_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_request_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (on_set_request_option_) {
                if (!(err = (this->*on_set_request_option_)(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
                if (!(err = default_on_set_request_option(optarg, optind, argc, argv, env))) {
                } else {
                }
            }
        } else {
        }
        return err;
    }
    virtual int default_on_set_request_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_request_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = set_output_request_run(argc, argv, env))) {
                if (!(err = output_request_run_set(argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_request_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_request_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_request_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_request_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_request_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* request_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_REQUEST_OPTUSE;
        optarg = XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_REQUEST_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...on...response_option...
    virtual int on_get_response_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (on_get_response_option_) {
            if (!(err = (this->*on_get_response_option_)(optarg, optind, argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_on_get_response_option(optarg, optind, argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_on_get_response_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_response_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_output_response_run(argc, argv, env))) {
            if (!(err = output_response_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_response_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (on_set_response_option_) {
                if (!(err = (this->*on_set_response_option_)(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
                if (!(err = default_on_set_response_option(optarg, optind, argc, argv, env))) {
                } else {
                }
            }
        } else {
        }
        return err;
    }
    virtual int default_on_set_response_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_response_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = set_output_response_run(argc, argv, env))) {
                if (!(err = output_response_run_set(argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_response_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_response_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_response_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_response_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_response_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* response_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_RESPONSE_OPTUSE;
        optarg = XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_RESPONSE_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// on_option
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {

        case XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_REQUEST_OPTVAL_C:
            err = this->on_request_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_RESPONSE_OPTVAL_C:
            err = this->on_response_option(optval, optarg, optname, optind, argc, argv, env);
            break;

        default:
            err = extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// option_usage
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {

        case XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_REQUEST_OPTVAL_C:
            chars = this->request_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_RESPONSE_OPTVAL_C:
            chars = this->response_option_usage(optarg, longopt);
            break;

        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// options
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }
    /// arguments
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// on...raw_output_option...
    virtual int on_raw_output_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = extends::on_raw_output_option_get(optarg, optind, argc, argv, env))) {
            if (!(err = set_raw_output_message_run(argc, argv, env))) {
                if (!(err = raw_output_message_run_set(argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
protected:
}; /// class main_optt 
typedef main_optt<> main_opt;

} /// namespace base 
} /// namespace protocol 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_OPT_HPP

