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
///   Date: 3/10/2025, 8/23/2025
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPT_HPP

#include "xos/app/console/network/base/main.hpp"
#include "xos/app/console/protocol/crlf/base/main.hpp"

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_ACCEPT_HOST "*"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_ACCEPT_PORT 8080

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_CONNECT_HOST "localhost"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_CONNECT_PORT 80

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_RELAY_HOST XOS_APP_CONSOLE_NETWORK_SOCKETS_CONNECT_HOST
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_RELAY_PORT XOS_APP_CONSOLE_NETWORK_SOCKETS_CONNECT_PORT

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_MAIN_ACCEPT_HOST_OPTARG "[{ * | name | ddd.ddd.ddd.ddd | ...}[:{ 0..2^16-1 }]]"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_MAIN_CONNECT_HOST_OPTARG "[{ name | ddd.ddd.ddd.ddd | ...}[:{ 0..2^16-1 }]]"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_MAIN_RELAY_HOST_OPTARG \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_MAIN_CONNECT_HOST_OPTARG

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_HOST_OPTARG "[{ name | ddd.ddd.ddd.ddd | ...}]"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_PORT_OPTARG "[{ 0..2^16-1 }]"

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPT "host"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTARG XOS_APP_CONSOLE_NETWORK_SOCKETS_HOST_OPTARG
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTUSE "hostname or address"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTVAL_S "o::"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTVAL_C 'o'
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTION \
   {XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTARG_RESULT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTVAL_C}, \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPT "port"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTARG XOS_APP_CONSOLE_NETWORK_SOCKETS_PORT_OPTARG
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTUSE "port number"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTVAL_S "p::"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTVAL_C 'p'
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTION \
   {XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTVAL_C}, \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPT "relay-host"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTARG XOS_APP_CONSOLE_NETWORK_SOCKETS_HOST_OPTARG
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTUSE "relay hostname or address"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTVAL_S "O::"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTVAL_C 'O'
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTION \
   {XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTARG_RESULT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTVAL_C}, \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPT "relay-port"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTARG XOS_APP_CONSOLE_NETWORK_SOCKETS_PORT_OPTARG
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTUSE "relay port number"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTVAL_S "P::"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTVAL_C 'P'
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTION \
   {XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTVAL_C}, \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_BASE_MAIN_CRLF2_OPT "crlf2"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_BASE_MAIN_CRLF2_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_BASE_MAIN_CRLF2_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_BASE_MAIN_CRLF2_OPTARG XOS_APP_CONSOLE_MAIN_OPTARG_ONOFF_OPTIONAL
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_BASE_MAIN_CRLF2_OPTUSE "send crlf2 endof message"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_BASE_MAIN_CRLF2_OPTVAL_S "2::"
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_BASE_MAIN_CRLF2_OPTVAL_C '2'
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_BASE_MAIN_CRLF2_OPTION \
   {XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_BASE_MAIN_CRLF2_OPT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_BASE_MAIN_CRLF2_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_BASE_MAIN_CRLF2_OPTARG_RESULT, \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_BASE_MAIN_CRLF2_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_CLIENT_NO_CRLF2_OPTIONS_CHARS_EXTEND \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTVAL_S \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTVAL_S \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_CLIENT_NO_CRLF2_OPTIONS_OPTIONS_EXTEND \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTION \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTION \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_NO_CRLF2_OPTIONS_CHARS_EXTEND \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTVAL_S \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTVAL_S \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTVAL_S \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTVAL_S \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_NO_CRLF2_OPTIONS_OPTIONS_EXTEND \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTION \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTION \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTION \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTION \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_CLIENT_OPTIONS_CHARS_EXTEND \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTVAL_S \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTVAL_S \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_BASE_MAIN_CRLF2_OPTVAL_S \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_CLIENT_OPTIONS_OPTIONS_EXTEND \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTION \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTION \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_BASE_MAIN_CRLF2_OPTION \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPTIONS_CHARS_EXTEND \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTVAL_S \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTVAL_S \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTVAL_S \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTVAL_S \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_BASE_MAIN_CRLF2_OPTVAL_S \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTION \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTION \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTION \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTION \
    XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_BASE_MAIN_CRLF2_OPTION \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_NO_CRLF2_OPTIONS_CHARS \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_NO_CRLF2_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_BASE_MAIN_OPTIONS_CHARS \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_NO_CRLF2_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_NO_CRLF2_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_BASE_MAIN_OPTIONS_OPTIONS \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_BASE_MAIN_OPTIONS_CHARS \

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_BASE_MAIN_OPTIONS_OPTIONS \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ARGS 0
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ARGV 0,

namespace xos {
namespace app {
namespace console {
namespace network {
namespace sockets {
namespace base {

/// class main_optt
template 
<class TExtends = xos::app::console::network::base::maint
 <xos::app::console::network::base::main_optt
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
    /// ...sockets_server_run
    int (derives::*sockets_server_run_)(int argc, char_t** argv, char_t** env);
    virtual int sockets_server_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (sockets_server_run_) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*sockets_server_run_)(argc, argv, env)))...");
            if (!(err = (this->*sockets_server_run_)(argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*sockets_server_run_)(argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*sockets_server_run_)(argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_sockets_server_run(argc, argv, env)))...");
            if (!(err = default_sockets_server_run(argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_sockets_server_run(argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_sockets_server_run(argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int default_sockets_server_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = extends::run(argc, argv, env)))...");
        if (!(err = extends::run(argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = extends::run(argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = extends::run(argc, argv, env)))");
        }
        return err;
    }
    virtual int before_sockets_server_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_sockets_server_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_sockets_server_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_sockets_server_run(argc, argv, env))) {
            int err2 = 0;
            err = sockets_server_run(argc, argv, env);
            if ((err2 = after_sockets_server_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_sockets_server_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_sockets_server_run;
        return err;
    }
    virtual int sockets_server_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_sockets_server_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int sockets_server_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...sockets_run
    int (derives::*sockets_run_)(int argc, char_t** argv, char_t** env);
    virtual int sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (sockets_run_) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*sockets_run_)(argc, argv, env)))...");
            if (!(err = (this->*sockets_run_)(argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*sockets_run_)(argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*sockets_run_)(argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_sockets_run(argc, argv, env)))...");
            if (!(err = default_sockets_run(argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_sockets_run(argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_sockets_run(argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int default_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = extends::run(argc, argv, env)))...");
        if (!(err = extends::run(argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = extends::run(argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = extends::run(argc, argv, env)))");
        }
        return err;
    }
    virtual int before_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_sockets_run(argc, argv, env))) {
            int err2 = 0;
            err = sockets_run(argc, argv, env);
            if ((err2 = after_sockets_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_sockets_run;
        return err;
    }
    virtual int sockets_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int sockets_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...connect_run
    int (derives::*connect_run_)(int argc, char_t** argv, char_t** env);
    virtual int connect_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (connect_run_) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*connect_run_)(argc, argv, env)))...");
            if (!(err = (this->*connect_run_)(argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*connect_run_)(argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*connect_run_)(argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_connect_run(argc, argv, env)))...");
            if (!(err = default_connect_run(argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_connect_run(argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_connect_run(argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int default_connect_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = extends::run(argc, argv, env)))...");
        if (!(err = extends::run(argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = extends::run(argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = extends::run(argc, argv, env)))");
        }
        return err;
    }
    virtual int before_connect_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_connect_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_connect_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_connect_run(argc, argv, env))) {
            int err2 = 0;
            err = connect_run(argc, argv, env);
            if ((err2 = after_connect_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_connect_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = set_sockets_run(argc, argv, env))) {
            if (!(err = sockets_run_set(argc, argv, env))) {
                sockets_run_ = &derives::all_connect_run;
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int connect_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_connect_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = unset_sockets_run(argc, argv, env))) {
            if (!(err = sockets_run_unset(argc, argv, env))) {
                sockets_run_ = 0;
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int connect_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...accept_run
    int (derives::*accept_run_)(int argc, char_t** argv, char_t** env);
    virtual int accept_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (accept_run_) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*accept_run_)(argc, argv, env)))...");
            if (!(err = (this->*accept_run_)(argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*accept_run_)(argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*accept_run_)(argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_accept_run(argc, argv, env)))...");
            if (!(err = default_accept_run(argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_accept_run(argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_accept_run(argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int default_accept_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = extends::run(argc, argv, env)))...");
        if (!(err = extends::run(argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = extends::run(argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = extends::run(argc, argv, env)))");
        }
        return err;
    }
    virtual int before_accept_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_accept_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_accept_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_accept_run(argc, argv, env))) {
            int err2 = 0;
            err = accept_run(argc, argv, env);
            if ((err2 = after_accept_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_accept_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = set_sockets_server_run(argc, argv, env))) {
            if (!(err = sockets_server_run_set(argc, argv, env))) {
                sockets_run_ = &derives::all_accept_run;
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int accept_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_accept_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = unset_sockets_run(argc, argv, env))) {
            if (!(err = sockets_run_unset(argc, argv, env))) {
                sockets_run_ = 0;
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int accept_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...accept_one_run
    int (derives::*accept_one_run_)(int argc, char_t** argv, char_t** env);
    virtual int accept_one_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (accept_one_run_) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*accept_one_run_)(argc, argv, env)))...");
            if (!(err = (this->*accept_one_run_)(argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*accept_one_run_)(argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*accept_one_run_)(argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_accept_one_run(argc, argv, env)))...");
            if (!(err = default_accept_one_run(argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_accept_one_run(argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_accept_one_run(argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int default_accept_one_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = extends::run(argc, argv, env)))...");
        if (!(err = extends::run(argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = extends::run(argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = extends::run(argc, argv, env)))");
        }
        return err;
    }
    virtual int before_accept_one_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_accept_one_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_accept_one_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_accept_one_run(argc, argv, env))) {
            int err2 = 0;
            err = accept_one_run(argc, argv, env);
            if ((err2 = after_accept_one_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_accept_one_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = set_sockets_server_run(argc, argv, env))) {
            if (!(err = sockets_server_run_set(argc, argv, env))) {
                sockets_run_ = &derives::all_accept_one_run;
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int accept_one_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_accept_one_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = unset_sockets_run(argc, argv, env))) {
            if (!(err = sockets_run_unset(argc, argv, env))) {
                sockets_run_ = 0;
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int accept_one_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...host_run
    int (derives::*host_run_)(int argc, char_t** argv, char_t** env);
    virtual int host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (host_run_) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*host_run_)(argc, argv, env)))...");
            if (!(err = (this->*host_run_)(argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*host_run_)(argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*host_run_)(argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_host_run(argc, argv, env)))...");
            if (!(err = default_host_run(argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_host_run(argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_host_run(argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int default_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = extends::run(argc, argv, env)))...");
        if (!(err = extends::run(argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = extends::run(argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = extends::run(argc, argv, env)))");
        }
        return err;
    }
    virtual int before_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_host_run(argc, argv, env))) {
            int err2 = 0;
            err = host_run(argc, argv, env);
            if ((err2 = after_host_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_host_run;
        return err;
    }
    virtual int host_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int host_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...port_run
    int (derives::*port_run_)(int argc, char_t** argv, char_t** env);
    virtual int port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (port_run_) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*port_run_)(argc, argv, env)))...");
            if (!(err = (this->*port_run_)(argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*port_run_)(argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*port_run_)(argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_port_run(argc, argv, env)))...");
            if (!(err = default_port_run(argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_port_run(argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_port_run(argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int default_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = extends::run(argc, argv, env)))...");
        if (!(err = extends::run(argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = extends::run(argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = extends::run(argc, argv, env)))");
        }
        return err;
    }
    virtual int before_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_port_run(argc, argv, env))) {
            int err2 = 0;
            err = port_run(argc, argv, env);
            if ((err2 = after_port_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_port_run;
        return err;
    }
    virtual int port_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int port_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...relay_host_run
    int (derives::*relay_host_run_)(int argc, char_t** argv, char_t** env);
    virtual int relay_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (relay_host_run_) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*relay_host_run_)(argc, argv, env)))...");
            if (!(err = (this->*relay_host_run_)(argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*relay_host_run_)(argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*relay_host_run_)(argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_relay_host_run(argc, argv, env)))...");
            if (!(err = default_relay_host_run(argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_relay_host_run(argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_relay_host_run(argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int default_relay_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = extends::run(argc, argv, env)))...");
        if (!(err = extends::run(argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = extends::run(argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = extends::run(argc, argv, env)))");
        }
        return err;
    }
    virtual int before_relay_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_relay_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_relay_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_relay_host_run(argc, argv, env))) {
            int err2 = 0;
            err = relay_host_run(argc, argv, env);
            if ((err2 = after_relay_host_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_relay_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_relay_host_run;
        return err;
    }
    virtual int relay_host_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_relay_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int relay_host_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...relay_port_run
    int (derives::*relay_port_run_)(int argc, char_t** argv, char_t** env);
    virtual int relay_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (relay_port_run_) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*relay_port_run_)(argc, argv, env)))...");
            if (!(err = (this->*relay_port_run_)(argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*relay_port_run_)(argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*relay_port_run_)(argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_relay_port_run(argc, argv, env)))...");
            if (!(err = default_relay_port_run(argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_relay_port_run(argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_relay_port_run(argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int default_relay_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = extends::run(argc, argv, env)))...");
        if (!(err = extends::run(argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = extends::run(argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = extends::run(argc, argv, env)))");
        }
        return err;
    }
    virtual int before_relay_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_relay_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_relay_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_relay_port_run(argc, argv, env))) {
            int err2 = 0;
            err = relay_port_run(argc, argv, env);
            if ((err2 = after_relay_port_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_relay_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_relay_port_run;
        return err;
    }
    virtual int relay_port_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_relay_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int relay_port_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// on...host_option...
    virtual int on_get_host_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_host_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_host_run(argc, argv, env))) {
            if (!(err = host_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_host_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_host_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = set_host_run(argc, argv, env))) {
                if (!(err = host_run_set(argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_host_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_host_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_host_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_host_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_host_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* host_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTUSE;
        optarg = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...port_option...
    virtual int on_get_port_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_port_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_port_run(argc, argv, env))) {
            if (!(err = port_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_port_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_port_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = set_port_run(argc, argv, env))) {
                if (!(err = port_run_set(argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_port_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_port_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_port_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_port_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_port_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* port_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTUSE;
        optarg = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...relay_host_option...
    virtual int on_get_relay_host_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_relay_host_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_relay_host_run(argc, argv, env))) {
            if (!(err = relay_host_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_relay_host_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_relay_host_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = set_relay_host_run(argc, argv, env))) {
                if (!(err = relay_host_run_set(argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_relay_host_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_relay_host_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_relay_host_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_relay_host_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_relay_host_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* relay_host_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTUSE;
        optarg = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...relay_port_option...
    virtual int on_get_relay_port_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_relay_port_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_relay_port_run(argc, argv, env))) {
            if (!(err = relay_port_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_relay_port_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_relay_port_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = set_relay_port_run(argc, argv, env))) {
                if (!(err = relay_port_run_set(argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_relay_port_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_relay_port_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_relay_port_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_relay_port_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_relay_port_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* relay_port_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTUSE;
        optarg = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...crlf2_option...
    virtual int on_get_crlf2_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_crlf2_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_crlf2_endof_message_to_send(argc, argv, env))) {
            if (!(err = crlf2_endof_message_to_send_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_crlf2_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_crlf2_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = set_crlf_endof_message_to_send(argc, argv, env))) {
                if (!(err = crlf_endof_message_to_send_set(argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_crlf2_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_crlf2_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_crlf2_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_crlf2_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_crlf2_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* crlf2_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_BASE_MAIN_CRLF2_OPTUSE;
        optarg = XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_BASE_MAIN_CRLF2_OPTARG;
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

        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTVAL_C:
            err = this->on_host_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTVAL_C:
            err = this->on_port_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTVAL_C:
            err = this->on_relay_host_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTVAL_C:
            err = this->on_relay_port_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_BASE_MAIN_CRLF2_OPTVAL_C:
            err = this->on_crlf2_option(optval, optarg, optname, optind, argc, argv, env);
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

        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HOST_OPTVAL_C:
            chars = this->host_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_PORT_OPTVAL_C:
            chars = this->port_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_HOST_OPTVAL_C:
            chars = this->relay_host_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_RELAY_PORT_OPTVAL_C:
            chars = this->relay_port_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_BASE_MAIN_CRLF2_OPTVAL_C:
            chars = this->crlf2_option_usage(optarg, longopt);
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
        static const char_t* chars = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }
    /// arguments
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...endof_message_to_send
    const string_t& (derives::*endof_message_to_send_)() const;
    virtual const string_t& endof_message_to_send() const {
        if (endof_message_to_send_) {
            LOGGER_IS_LOGGED_INFO("(this->*endof_message_to_send_)()...");
            return (this->*endof_message_to_send_)();
        } else {
            LOGGER_IS_LOGGED_INFO("return default_endof_message_to_send()...");
            return default_endof_message_to_send();
        }
        LOGGER_IS_LOGGED_INFO("return default_endof_message_to_send()...");
        return default_endof_message_to_send();
    }
    virtual const string_t& default_endof_message_to_send() const {
        const string_t& endof_message = this->crlf_endof_message();
        LOGGER_IS_LOGGED_INFO("(!(endof_message = extends::run(argc, argv, env)))...");
        return endof_message;
    }
    virtual int unset_endof_message_to_send(int argc, char_t** argv, char_t** env) {
        int err = 0;
        endof_message_to_send_ = 0;
        return err;
    }
    virtual int endof_message_to_send_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...crlf2_endof_message_to_send
    virtual const string_t& crlf2_endof_message_to_send() const {
        const string_t& endof_message = this->crlf2_endof_message();
        return endof_message;
    }
    virtual int set_crlf2_endof_message_to_send(int argc, char_t** argv, char_t** env) {
        int err = 0;
        endof_message_to_send_ = &derives::crlf2_endof_message_to_send;
        return err;
    }
    virtual int crlf2_endof_message_to_send_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_crlf2_endof_message_to_send(int argc, char_t** argv, char_t** env) {
        int err = 0;
        endof_message_to_send_ = 0;
        return err;
    }
    virtual int crlf2_endof_message_to_send_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...crlf_endof_message_to_send
    virtual const string_t& crlf_endof_message_to_send() const {
        const string_t& endof_message = this->crlf_endof_message();
        return endof_message;
    }
    virtual int set_crlf_endof_message_to_send(int argc, char_t** argv, char_t** env) {
        int err = 0;
        endof_message_to_send_ = &derives::crlf_endof_message_to_send;
        return err;
    }
    virtual int crlf_endof_message_to_send_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_crlf_endof_message_to_send(int argc, char_t** argv, char_t** env) {
        int err = 0;
        endof_message_to_send_ = 0;
        return err;
    }
    virtual int crlf_endof_message_to_send_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...cr_endof_message_to_send
    virtual const string_t& cr_endof_message_to_send() const {
        const string_t& endof_message = this->cr_endof_message();
        return endof_message;
    }
    virtual int set_cr_endof_message_to_send(int argc, char_t** argv, char_t** env) {
        int err = 0;
        endof_message_to_send_ = &derives::cr_endof_message_to_send;
        return err;
    }
    virtual int cr_endof_message_to_send_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_cr_endof_message_to_send(int argc, char_t** argv, char_t** env) {
        int err = 0;
        endof_message_to_send_ = 0;
        return err;
    }
    virtual int cr_endof_message_to_send_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...lf_endof_message_to_send
    virtual const string_t& lf_endof_message_to_send() const {
        const string_t& endof_message = this->lf_endof_message();
        return endof_message;
    }
    virtual int set_lf_endof_message_to_send(int argc, char_t** argv, char_t** env) {
        int err = 0;
        endof_message_to_send_ = &derives::lf_endof_message_to_send;
        return err;
    }
    virtual int lf_endof_message_to_send_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_lf_endof_message_to_send(int argc, char_t** argv, char_t** env) {
        int err = 0;
        endof_message_to_send_ = 0;
        return err;
    }
    virtual int lf_endof_message_to_send_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...no_endof_message_to_send
    virtual const string_t& no_endof_message_to_send() const {
        const string_t& endof_message = this->no_endof_message();
        return endof_message;
    }
    virtual int set_no_endof_message_to_send(int argc, char_t** argv, char_t** env) {
        int err = 0;
        endof_message_to_send_ = &derives::no_endof_message_to_send;
        return err;
    }
    virtual int no_endof_message_to_send_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_no_endof_message_to_send(int argc, char_t** argv, char_t** env) {
        int err = 0;
        endof_message_to_send_ = 0;
        return err;
    }
    virtual int no_endof_message_to_send_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
protected:
}; /// class main_optt 
typedef main_optt<> main_opt;

} /// namespace base 
} /// namespace sockets 
} /// namespace network 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_OPT_HPP

