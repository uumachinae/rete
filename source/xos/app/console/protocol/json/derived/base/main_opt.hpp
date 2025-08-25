//////////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2025 $organization$
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
///   Date: 2/23/2025, 3/18/2025
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_OPT_HPP

#include "xos/app/console/protocol/json/base/main.hpp"

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_HELLO_OPT "hello"
#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_HELLO_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_HELLO_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_HELLO_OPTARG ""
#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_HELLO_OPTUSE "hello request"
#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_HELLO_OPTVAL_S "H"
#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_HELLO_OPTVAL_C 'H'
#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_HELLO_OPTION \
   {XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_HELLO_OPT, \
    XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_HELLO_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_HELLO_OPTARG_RESULT, \
    XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_HELLO_OPTVAL_C}, \

#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_RESTART_OPT "restart"
#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_RESTART_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_RESTART_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_RESTART_OPTARG ""
#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_RESTART_OPTUSE "restart request"
#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_RESTART_OPTVAL_S "R"
#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_RESTART_OPTVAL_C 'R'
#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_RESTART_OPTION \
   {XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_RESTART_OPT, \
    XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_RESTART_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_RESTART_OPTARG_RESULT, \
    XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_RESTART_OPTVAL_C}, \

#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_STOP_OPT "stop"
#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_STOP_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_STOP_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_STOP_OPTARG ""
#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_STOP_OPTUSE "stop request"
#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_STOP_OPTVAL_S "S"
#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_STOP_OPTVAL_C 'S'
#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_STOP_OPTION \
   {XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_STOP_OPT, \
    XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_STOP_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_STOP_OPTARG_RESULT, \
    XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_STOP_OPTVAL_C}, \

#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_RESTART_SERVER_OPT XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_RESTART_OPT
#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_RESTART_SERVER_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_RESTART_SERVER_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_RESTART_SERVER_OPTARG XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_RESTART_OPTARG
#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_RESTART_SERVER_OPTUSE XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_RESTART_OPTUSE
#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_RESTART_SERVER_OPTVAL_S "S"
#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_RESTART_SERVER_OPTVAL_C 'S'
#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_RESTART_SERVER_OPTION \
   {XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_RESTART_SERVER_OPT, \
    XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_RESTART_SERVER_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_RESTART_SERVER_OPTARG_RESULT, \
    XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_RESTART_SERVER_OPTVAL_C}, \

#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_STOP_SERVER_OPT XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_STOP_OPT 
#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_STOP_SERVER_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_STOP_SERVER_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_STOP_SERVER_OPTARG XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_STOP_OPTARG
#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_STOP_SERVER_OPTUSE XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_STOP_OPTUSE
#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_STOP_SERVER_OPTVAL_S "T"
#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_STOP_SERVER_OPTVAL_C 'T'
#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_STOP_SERVER_OPTION \
   {XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_STOP_SERVER_OPT, \
    XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_STOP_SERVER_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_STOP_SERVER_OPTARG_RESULT, \
    XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_STOP_SERVER_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_CLIENT_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_HELLO_OPTVAL_S \
   XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_RESTART_SERVER_OPTVAL_S \
   XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_STOP_SERVER_OPTVAL_S \

#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_CLIENT_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_HELLO_OPTION \
   XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_RESTART_SERVER_OPTION \
   XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_STOP_SERVER_OPTION \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_SERVER_OPTIONS_CHARS_EXTEND \
    
#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_SERVER_OPTIONS_OPTIONS_EXTEND \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_HELLO_OPTVAL_S \
   XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_RESTART_OPTVAL_S \
   XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_STOP_OPTVAL_S \

#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_HELLO_OPTION \
   XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_RESTART_OPTION \
   XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_STOP_OPTION \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_CLIENT_OPTIONS_CHARS \
   XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_CLIENT_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_PROTOCOL_JSON_BASE_MAIN_OPTIONS_CHARS \

#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_CLIENT_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_CLIENT_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_PROTOCOL_JSON_BASE_MAIN_OPTIONS_OPTIONS \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_SERVER_OPTIONS_CHARS \
   XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_SERVER_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_PROTOCOL_JSON_BASE_MAIN_OPTIONS_CHARS \

#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_SERVER_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_SERVER_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_PROTOCOL_JSON_BASE_MAIN_OPTIONS_OPTIONS \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_PROTOCOL_JSON_BASE_MAIN_OPTIONS_CHARS \

#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_PROTOCOL_JSON_BASE_MAIN_OPTIONS_OPTIONS \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_ARGS 0
#define XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_ARGV 0,

namespace xos {
namespace app {
namespace console {
namespace protocol {
namespace json {
namespace derived {
namespace base {

/// class main_optt
template 
<class TExtends = xos::app::console::protocol::json::base::maint
 <xos::app::console::protocol::json::base::main_optt
 <xos::app::console::protocol::crlf::base::maint
 <xos::app::console::protocol::crlf::base::main_optt
 <xos::app::console::protocol::base::maint
 <xos::app::console::protocol::base::main_optt<> > > > > >,  class TImplements = typename TExtends::implements>

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
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*run_)(argc, argv, env)))...");
            if (!(err = (this->*run_)(argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*run_)(argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*run_)(argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = extends::run(argc, argv, env)))...");
            if (!(err = extends::run(argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = extends::run(argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(err" << err << " = extends::run(argc, argv, env)))");
            }
        }
        return err;
    }

    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// on...set_to...option...
    virtual int on_set_to_request_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = this->set_output_request_run(argc, argv, env))) {
            if (!(err = this->output_request_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...hello_option...
    virtual int on_set_hello_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        this->set_to_hello_request();
        return err;
    }
    virtual int on_hello_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = on_set_to_request_option_set(optarg, optind, argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int on_hello_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = on_set_hello_option(optarg, optind, argc, argv, env))) {
            if (!(err = on_hello_option_set(optarg, optind, argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual const char_t* hello_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_HELLO_OPTUSE;
        optarg = XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_HELLO_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...restart_option...
    virtual int on_set_restart_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        this->set_to_restart_request();
        return err;
    }
    virtual int on_restart_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = on_set_to_request_option_set(optarg, optind, argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int on_restart_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = on_set_restart_option(optarg, optind, argc, argv, env))) {
            if (!(err = on_restart_option_set(optarg, optind, argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual const char_t* restart_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_RESTART_OPTUSE;
        optarg = XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_RESTART_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...stop_option...
    virtual int on_set_stop_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        this->set_to_stop_request();
        return err;
    }
    virtual int on_stop_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = on_set_to_request_option_set(optarg, optind, argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int on_stop_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = on_set_stop_option(optarg, optind, argc, argv, env))) {
            if (!(err = on_stop_option_set(optarg, optind, argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual const char_t* stop_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_STOP_OPTUSE;
        optarg = XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_STOP_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...restart_server_option...
    virtual int on_set_restart_server_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = on_set_restart_option(optarg, optind, argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int on_restart_server_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = on_restart_option_set(optarg, optind, argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int on_restart_server_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = on_set_restart_server_option(optarg, optind, argc, argv, env))) {
            if (!(err = on_restart_server_option_set(optarg, optind, argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual const char_t* restart_server_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_RESTART_SERVER_OPTUSE;
        optarg = XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_RESTART_SERVER_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...stop_server_option...
    virtual int on_set_stop_server_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = on_set_stop_option(optarg, optind, argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int on_stop_server_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = on_stop_option_set(optarg, optind, argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int on_stop_server_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = on_set_stop_server_option(optarg, optind, argc, argv, env))) {
            if (!(err = on_stop_server_option_set(optarg, optind, argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual const char_t* stop_server_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_STOP_SERVER_OPTUSE;
        optarg = XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_STOP_SERVER_OPTARG;
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

        case XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_HELLO_OPTVAL_C:
            err = this->on_hello_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_RESTART_OPTVAL_C:
            err = this->on_restart_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_STOP_OPTVAL_C:
            err = this->on_stop_option(optval, optarg, optname, optind, argc, argv, env);
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

        case XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_HELLO_OPTVAL_C:
            chars = this->hello_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_RESTART_OPTVAL_C:
            chars = this->restart_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_STOP_OPTVAL_C:
            chars = this->stop_option_usage(optarg, longopt);
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
        static const char_t* chars = XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }
    /// arguments
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
protected:
}; /// class main_optt 
typedef main_optt<> main_opt;

} /// namespace base 
} /// namespace derived 
} /// namespace json 
} /// namespace protocol 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_PROTOCOL_JSON_DERIVED_BASE_MAIN_OPT_HPP

