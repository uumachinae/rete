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
///   File: main.hpp
///
/// Author: $author$
///   Date: 5/26/2025
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_LF_BASE_MAIN_HPP
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_LF_BASE_MAIN_HPP

#include "xos/app/console/network/sockets/protocol/lf/base/main_opt.hpp"

#define XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_LF_ACCEPT_PORT 2222
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_LF_CONNECT_PORT XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_LF_ACCEPT_PORT
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_LF_RELAY_PORT XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_LF_CONNECT_PORT

namespace xos {
namespace app {
namespace console {
namespace network {
namespace sockets {
namespace protocol {
namespace lf {
namespace base {

/// class maint
template 
<class TExtends = xos::app::console::network::sockets::protocol::lf::base::main_optt<>,  class TImplements = typename TExtends::implements>

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
    maint()
    : run_(0),
      accept_port_(XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_LF_ACCEPT_PORT), 
      connect_port_(XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_LF_CONNECT_PORT),
      relay_port_(XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_LF_RELAY_PORT) {
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
    /// ...receive_message_run
    virtual int default_receive_message_run(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = all_receive_lf(\"" << r << "\", c, cn, argc, argv, env)))...");
        if (!(err = all_receive_lf(r, c, cn, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = all_receive_lf(\"" << r << "\", c, cn, argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = all_receive_lf(\"" << r << "\", c, cn, argc, argv, env)))");
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...lf_prepare_message_received_run
    virtual int lf_prepare_message_received_run(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        const string_t& endof_message = this->lf_endof_message();
        size_t endof_length = endof_message.length(), length = 0;
        const char_t* chars = 0;
        if ((chars = r.has_chars(length)) && (length >= endof_length)) {
            const string_t prepare(r);
            if ((chars = prepare.has_chars(length)) && (length >= endof_length)) {
                r.assign(chars, (length-endof_length));
            } else {
            }
        } else {
        }
        LOGGER_IS_LOGGED_INFO("(!(err = this->unset_prepare_message_received_run(argc, argv, env)))...");
        if (!(err = this->unset_prepare_message_received_run(argc, argv, env))) {            
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = this->unset_prepare_message_received_run(argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = this->unset_prepare_message_received_run(argc, argv, env)))");
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...<lf>
    /// ...
    /// ...on_recv_lf
    virtual int on_recv_lf(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = this->set_lf_prepare_message_received_run(argc, argv, env)))...");
        if (!(err = this->set_lf_prepare_message_received_run(argc, argv, env))) {            
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = this->set_lf_prepare_message_received_run(argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = this->set_lf_prepare_message_received_run(argc, argv, env)))");
        }
        return err;
    }
    /// ...receive_lf
    virtual int receive_lf(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        ssize_t amount = 0, count = 0;
        while (0 < (amount = cn.recv(&c, 1))) {
            switch (c) {
            case '\r':
                LOGGER_IS_LOGGED_INFO("...case '\\r':");
                LOGGER_IS_LOGGED_INFO("(0 < (count = " << count << "))...");
                if (0 < (count)) {
                    LOGGER_IS_LOGGED_INFO("...(0 < (count = " << count << "))");
                    LOGGER_IS_LOGGED_INFO("r.append('\\r', 1)...");
                    r.append(&c, 1);
                } else {
                    LOGGER_IS_LOGGED_INFO("...failed on (0 < (count = " << count << "))");
                }
                break;
            case '\n':
                LOGGER_IS_LOGGED_INFO("...case '\\n':");
                LOGGER_IS_LOGGED_INFO("r.append('\\n', 1)...");
                r.append(&c, 1);
                LOGGER_IS_LOGGED_INFO("(!(err = on_recv_lf(\"" << r << "\", '\\n', cn, argc, argv, env)))...");
                if (!(err = on_recv_lf(r, c, cn, argc, argv, env))) {
                    LOGGER_IS_LOGGED_INFO("...(!(" << err << " = on_recv_lf(\"" << r << "\", '\\n', cn, argc, argv, env)))");
                } else {
                    LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = on_recv_lf(\"" << r << "\", '\\n', cn, argc, argv, env)))");
                }
                return err;
                break;
            default:
                r.append(&c, 1);
                break;
            }
            count += amount;
        }
        return err;
    }
    virtual int before_receive_lf(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_receive_lf(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_receive_lf(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_receive_lf(r, c, cn, argc, argv, env))) {
            int err2 = 0;
            err = receive_lf(r, c, cn, argc, argv, env);
            if ((err2 = after_receive_lf(r, c, cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...
    /// ...<lf>
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ..host / ..port
    /// ...
    /// ...accept_host / ...accept_port
    virtual short& accept_port() const {
        return (short&)accept_port_;
    }
    /// ...connect_host / ...connect_port
    virtual short& connect_port() const {
        return (short&)connect_port_;
    }
    /// ...relay_host / ...relay_port
    virtual short& relay_port() const {
        return (short&)relay_port_;
    }
    /// ...
    /// ..host / ..port
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
protected:
    short accept_port_, connect_port_, relay_port_;
}; /// class maint 
typedef maint<> main;

} /// namespace base 
} /// namespace lf 
} /// namespace protocol 
} /// namespace sockets 
} /// namespace network 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_LF_BASE_MAIN_HPP
