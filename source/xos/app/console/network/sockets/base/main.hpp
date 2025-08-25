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
///   Date: 3/10/2025, 3/17/2025
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HPP
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HPP

#include "xos/app/console/network/sockets/base/main_opt.hpp"

#include "xos/network/sockets/os/interfaces.hpp"
#include "xos/network/sockets/os/interface.hpp"
#include "xos/network/sockets/interface.hpp"
#include "xos/network/sockets/reader.hpp"
#include "xos/network/sockets/writer.hpp"

#include "xos/network/sockets/ip/v4/endpoint.hpp"
#include "xos/network/sockets/ip/v4/tcp/transport.hpp"
#include "xos/network/sockets/ip/v4/udp/transport.hpp"

#if !defined(WINSOCK_1)
#include "xos/network/sockets/ip/v6/endpoint.hpp"
#include "xos/network/sockets/ip/v6/tcp/transport.hpp"
#include "xos/network/sockets/ip/v6/udp/transport.hpp"
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)

namespace xos {
namespace app {
namespace console {
namespace network {
namespace sockets {
namespace base {

/// class maint
template 
<class TExtends = xos::app::console::network::sockets::base::main_optt<>,  class TImplements = typename TExtends::implements>

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
      accept_one_(false), accept_done_(false), accept_restart_(false),
      accept_host_(XOS_APP_CONSOLE_NETWORK_SOCKETS_ACCEPT_HOST), 
      connect_host_(XOS_APP_CONSOLE_NETWORK_SOCKETS_CONNECT_HOST),
      relay_host_(XOS_APP_CONSOLE_NETWORK_SOCKETS_RELAY_HOST),
      accept_port_(XOS_APP_CONSOLE_NETWORK_SOCKETS_ACCEPT_PORT), 
      connect_port_(XOS_APP_CONSOLE_NETWORK_SOCKETS_CONNECT_PORT),
      relay_port_(XOS_APP_CONSOLE_NETWORK_SOCKETS_RELAY_PORT) {
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
    /// ...sockets_server_run
    virtual int default_sockets_server_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("do {...");
        do {
            LOGGER_IS_LOGGED_INFO("set_accept_restart(false)...");
            set_accept_restart(false);
            LOGGER_IS_LOGGED_INFO("(!(err = this->all_sockets_run(argc, argv, env)))...");
            if (!(err = this->all_sockets_run(argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = this->all_sockets_run(argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = this->all_sockets_run(argc, argv, env)))");
            }
        } while(true == (accept_restart()));
        LOGGER_IS_LOGGED_INFO("...} while(true == (accept_restart()))");
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...sockets_run
    virtual int default_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = this->all_connect_run(argc, argv, env)))...");
        if (!(err = this->all_connect_run(argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = this->all_connect_run(argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = this->all_connect_run(argc, argv, env)))");
        }
        return err;
    }
    virtual int before_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        xos::network::sockets::os::interfaces sockets;
        LOGGER_IS_LOGGED_INFO("in...");
        LOGGER_IS_LOGGED_INFO("sockets.startup()...");
        if (!(sockets.startup())) {
            LOGGER_IS_LOGGED_ERROR("...failed on sockets.startup()");
            err = 1;
        } else {
            LOGGER_IS_LOGGED_INFO("...sockets.startup()");
        }
        LOGGER_IS_LOGGED_INFO("...out");
        return err;
    }
    virtual int after_sockets_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        xos::network::sockets::os::interfaces sockets;
        LOGGER_IS_LOGGED_INFO("in...");
        LOGGER_IS_LOGGED_INFO("sockets.cleanup()...");
        if (!(sockets.cleanup())) {
            LOGGER_IS_LOGGED_ERROR("...failed on sockets.cleanup()");
            err = 1;
        } else {
            LOGGER_IS_LOGGED_INFO("...sockets.cleanup()");
        }
        LOGGER_IS_LOGGED_INFO("...out");
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...connect_run
    virtual int default_connect_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const xos::network::sockets::sockstring_t& host = this->connect_host();
        const xos::network::sockets::sockport_t& port = this->connect_port();
        xos::network::sockets::endpoint& ep = this->connect_ep();
        xos::network::sockets::transport& tp = this->connect_tp();
        xos::network::sockets::interface &cn = this->connect_iface();

        LOGGER_IS_LOGGED_INFO("ep.attach(host = \"" << host.chars() << "\", port = " << unsigned_to_string(port).chars() << ")...");
        if (!(ep.attach(host, port))) {
            LOGGER_IS_LOGGED_ERROR("...failed on ep.attach(host = \"" << host.chars() << "\", port = " << unsigned_to_string(port).chars() << ")...");
        } else {
            LOGGER_IS_LOGGED_INFO("...ep.attach(host = \"" << host.chars() << "\", port = " << unsigned_to_string(port).chars() << ")");

            LOGGER_IS_LOGGED_INFO("cn.open(tp)...");
            if (!(cn.open(tp))) {
                LOGGER_IS_LOGGED_ERROR("...failed on ");
            } else {
                LOGGER_IS_LOGGED_INFO("...cn.open(tp)");
                
                LOGGER_IS_LOGGED_INFO("cn.connect(ep)...");
                if (!(cn.connect(ep))) {
                    LOGGER_IS_LOGGED_ERROR("...failed on ");
                } else {
                    LOGGER_IS_LOGGED_INFO("...cn.connect(ep)");
                    
                    this->all_connect(cn, argc, argv, env);
                }
                LOGGER_IS_LOGGED_INFO("cn.close()...");
                cn.close();
            }
            LOGGER_IS_LOGGED_INFO("ep.detach()...");
            ep.detach();
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...accept_run
    virtual int default_accept_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const xos::network::sockets::sockstring_t& host = this->accept_host();
        const xos::network::sockets::sockport_t& port = this->accept_port();
        xos::network::sockets::endpoint& ep = this->accept_ep();
        xos::network::sockets::transport& tp = this->accept_tp();
        xos::network::sockets::interface &ac = this->accept_iface(), 
                                         &cn = this->connect_iface();
        xos::network::sockets::sockaddr_t& ad = this->connect_addr();
        xos::network::sockets::socklen_t& al = this->connect_addrlen();

        LOGGER_IS_LOGGED_INFO("ep.attach(host = \"" << host << "\", port = " << unsigned_to_string(port) << ")...");
        if ((ep.attach(host, port))) {
            LOGGER_IS_LOGGED_INFO("...ep.attach(host = \"" << host << "\", port = " << unsigned_to_string(port) << ")");

            LOGGER_IS_LOGGED_INFO("ac.open(tp)...");
            if ((ac.open(tp))) {
                LOGGER_IS_LOGGED_INFO("...ac.open(tp)");
                
                LOGGER_IS_LOGGED_INFO("ac.listen(ep)...");
                if ((ac.listen(ep))) {
                    LOGGER_IS_LOGGED_INFO("...ac.listen(ep)");

                    LOGGER_IS_LOGGED_INFO("do {...");
                    do {
                        LOGGER_IS_LOGGED_INFO("ac.accept(cn, &ad, al)...");
                        if ((ac.accept(cn, &ad, al))) {
                            LOGGER_IS_LOGGED_INFO("...ac.accept(cn, &ad, al)");

                            LOGGER_IS_LOGGED_INFO("(!(err = this->all_accept(cn, argc, argv, env)))...");
                            if (!(err = this->all_accept(cn, argc, argv, env))) {
                                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = this->all_accept(cn, argc, argv, env)))");
                            } else {
                                LOGGER_IS_LOGGED_INFO("failed on ...(!(" << err << " = this->all_accept(cn, argc, argv, env)))");
                            }
                            LOGGER_IS_LOGGED_INFO("cn.close()...");
                            cn.close();
                        }
                    } while (!(this->accept_one() || this->accept_done() || this->accept_restart()));
                    LOGGER_IS_LOGGED_INFO("...while (!(this->accept_one() || this->accept_done() || this->accept_restart()))");
                }
                LOGGER_IS_LOGGED_INFO("ac.close()...");
                ac.close();
            }
            LOGGER_IS_LOGGED_INFO("ep.detach()...");
            ep.detach();
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...accept_one_run
    virtual int default_accept_one_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        bool accepted_one = this->accept_one();
        LOGGER_IS_LOGGED_INFO("this->set_accept_one(" << true << ")...");
        this->set_accept_one(true);
        LOGGER_IS_LOGGED_INFO("(!(err = this->all_accept_run(argc, argv, env)))...");
        if (!(err = this->all_accept_run(argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("(!(" << err << " = this->all_accept_run(argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = this->all_accept_run(argc, argv, env)))");
        }
        LOGGER_IS_LOGGED_INFO("this->set_accept_one(" << accepted_one << ")...");
        this->set_accept_one(accepted_one);        
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...host_run
    virtual int default_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const string_t& host = this->get_host();
        const char_t* chars = 0; size_t length = 0;
        if ((chars = host.has_chars(length))) {
            bool output_lf = this->output_lf ();
            if ((output_lf )) {
                this->outln(chars, length);
            } else {
                this->out(chars, length);
            }
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...port_run
    virtual int default_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const short& port = this->get_port();
        if (0 < (port)) {
            unsigned_to_string port_string(port);
            const char_t* chars = 0; size_t length = 0;
            if ((chars = port_string.has_chars(length))) {
                bool output_lf = this->output_lf ();
                if ((output_lf )) {
                    this->outln(chars, length);
                } else {
                    this->out(chars, length);
                }
            } else {
            }
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...relay_host_run
    virtual int default_relay_host_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const string_t& relay_host = this->get_relay_host();
        const char_t* chars = 0; size_t length = 0;
        if ((chars = relay_host.has_chars(length))) {
            bool output_lf = this->output_lf ();
            if ((output_lf )) {
                this->outln(chars, length);
            } else {
                this->out(chars, length);
            }
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...relay_port_run
    virtual int default_relay_port_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const short& relay_port = this->get_relay_port();
        if (0 < (relay_port)) {
            unsigned_to_string relay_port_string(relay_port);
            const char_t* chars = 0; size_t length = 0;
            if ((chars = relay_port_string.has_chars(length))) {
                bool output_lf = this->output_lf ();
                if ((output_lf )) {
                    this->outln(chars, length);
                } else {
                    this->out(chars, length);
                }
            } else {
            }
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...connect... / ...accept...
    /// ...
    /// ...connect
    int (derives::*connect_)(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env);
    virtual int connect(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (connect_) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*connect_)(cn, argc, argv, env)))...");
            if (!(err = (this->*connect_)(cn, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*connect_)(cn, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*connect_)(cn, argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_connect(cn, argc, argv, env)))...");
            if (!(err = default_connect(cn, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_connect(cn, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_connect(cn, argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int default_connect(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = this->all_send_request(cn, argc, argv, env)))...");
        if (!(err = this->all_send_request(cn, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = this->all_send_request(cn, argc, argv, env)))");
            LOGGER_IS_LOGGED_INFO("(!(err = this->all_receive_response(cn, argc, argv, env)))...");
            if (!(err = this->all_receive_response(cn, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = this->all_receive_response(cn, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = this->all_receive_response(cn, argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = this->all_send_request(cn, argc, argv, env)))");
        }
        return err;
    }
    virtual int before_connect(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_connect(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_connect(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_connect(cn, argc, argv, env))) {
            int err2 = 0;
            err = connect(cn, argc, argv, env);
            if ((err2 = after_connect(cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...accept
    int (derives::*accept_)(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env);
    virtual int accept(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (accept_) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*accept_)(cn, argc, argv, env)))...");
            if (!(err = (this->*accept_)(cn, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*accept_)(cn, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*accept_)(cn, argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_accept(cn, argc, argv, env)))...");
            if (!(err = default_accept(cn, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_accept(cn, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_accept(cn, argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int default_accept(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = this->all_receive_request(cn, argc, argv, env)))...");
        if (!(err = this->all_receive_request(cn, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = this->all_receive_request(cn, argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = this->all_receive_request(cn, argc, argv, env)))");
        }
        return err;
    }
    virtual int before_accept(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_accept(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_accept(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_accept(cn, argc, argv, env))) {
            int err2 = 0;
            err = accept(cn, argc, argv, env);
            if ((err2 = after_accept(cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...
    /// ...connect... / ...accept...
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...send... / ...receive...
    /// ...
    /// ...send_request
    int (derives::*send_request_)(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env);
    virtual int send_request(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (send_request_) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*send_request_)(cn, argc, argv, env)))...");
            if (!(err = (this->*send_request_)(cn, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*send_request_)(cn, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*send_request_)(cn, argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_send_request(cn, argc, argv, env)))...");
            if (!(err = default_send_request(cn, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_send_request(cn, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_send_request(cn, argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int default_send_request(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        string_t& request = this->request();
        LOGGER_IS_LOGGED_INFO("(!(err = this->all_send_request(cn, \"" << request << "\", argc, argv, env)))...");
        if (!(err = this->all_send_request(cn, request, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = this->all_send_request(cn, \"" << request << "\", argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = this->all_send_request(cn, \"" << request << "\", argc, argv, env)))");
        }
        return err;
    }
    virtual int before_send_request(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_send_request(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_send_request(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_send_request(cn, argc, argv, env))) {
            int err2 = 0;
            err = send_request(cn, argc, argv, env);
            if ((err2 = after_send_request(cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...receive_request
    int (derives::*receive_request_)(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env);
    virtual int receive_request(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (receive_request_) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*receive_request_)(cn, argc, argv, env)))...");
            if (!(err = (this->*receive_request_)(cn, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*receive_request_)(cn, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*receive_request_)(cn, argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_receive_request(cn, argc, argv, env)))...");
            if (!(err = default_receive_request(cn, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_receive_request(cn, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_receive_request(cn, argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int default_receive_request(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        string_t& request = this->request();
        LOGGER_IS_LOGGED_INFO("(!(err = this->all_receive_request(request, cn, rgc, argv, env)))...");
        if (!(err = this->all_receive_request(request, cn, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = this->all_receive_request(\"" << request << "\", cn, argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = this->all_receive_request(\"" << request << "\", cn, argc, argv, env)))");
        }
        return err;
    }
    virtual int before_receive_request(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_receive_request(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_receive_request(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_receive_request(cn, argc, argv, env))) {
            int err2 = 0;
            err = receive_request(cn, argc, argv, env);
            if ((err2 = after_receive_request(cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...receive_response
    int (derives::*receive_response_)(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env);
    virtual int receive_response(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (receive_response_) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*receive_response_)(cn, argc, argv, env)))...");
            if (!(err = (this->*receive_response_)(cn, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*receive_response_)(cn, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*receive_response_)(cn, argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_receive_response(cn, argc, argv, env)))...");
            if (!(err = default_receive_response(cn, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_receive_response(cn, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_receive_response(cn, argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int default_receive_response(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        string_t& response = this->response();
        LOGGER_IS_LOGGED_INFO("(!(err = this->all_receive_response(response, cn, argc, argv, env)))...");
        if (!(err = this->all_receive_response(response, cn, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = this->all_receive_response(\"" << response << "\", cn, argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = this->all_receive_response(response, cn, argc, argv, env)))");
        }
        return err;
    }
    virtual int before_receive_response(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_receive_response(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_receive_response(xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_receive_response(cn, argc, argv, env))) {
            int err2 = 0;
            err = receive_response(cn, argc, argv, env);
            if ((err2 = after_receive_response(cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...
    /// ...send... / ...receive...
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...request...
    /// ...
    /// ...send_request
    int (derives::*send_request__)(xos::network::sockets::interface& cn, string_t& request, int argc, char_t** argv, char_t** env);
    virtual int send_request(xos::network::sockets::interface& cn, string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (send_request__) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*send_request__)(cn, \"" << request << "\", argc, argv, env)))...");
            if (!(err = (this->*send_request__)(cn, request, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*send_request__)(cn, \"" << request << "\", argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*send_request__)(cn, \"" << request << "\", argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_send_request(cn, \"" << request << "\", argc, argv, env)))...");
            if (!(err = default_send_request(cn, request, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_send_request(cn, \"" << request << "\", argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_send_request(cn, \"" << request << "\", argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int default_send_request(xos::network::sockets::interface& cn, string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = this->all_prepare_request_to_send(cn, \"" << request << "\", argc, argv, env)))...");
        if (!(err = this->all_prepare_request_to_send(cn, request, argc, argv, env))) {
            size_t length = 0; const char_t* chars = 0;
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = this->all_prepare_request_to_send(cn, \"" << request << "\", argc, argv, env)))");
            LOGGER_IS_LOGGED_INFO("((chars = request.has_chars(length)))...");
            if ((chars = request.has_chars(length))) {
                LOGGER_IS_LOGGED_INFO("...((\"" << chars << "\" = request.has_chars(" << length << ")))...");
                LOGGER_IS_LOGGED_INFO("cn.send(\"" << chars << "\", " << length << ")...");
                cn.send(chars, length);
                LOGGER_IS_LOGGED_INFO("...cn.send(\"" << chars << "\", " << length << ")");
            } else {
                LOGGER_IS_LOGGED_INFO("failed on ((chars = request.has_chars(" << length << ")))...");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = this->all_prepare_request_to_send(cn, \"" << request << "\", argc, argv, env)))");
        }
        return err;
    }
    virtual int before_send_request(xos::network::sockets::interface& cn, string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_send_request(xos::network::sockets::interface& cn, string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_send_request(xos::network::sockets::interface& cn, string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_send_request(cn, request, argc, argv, env))) {
            int err2 = 0;
            err = send_request(cn, request, argc, argv, env);
            if ((err2 = after_send_request(cn, request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...prepare_request_to_send
    int (derives::*prepare_request_to_send_)(xos::network::sockets::interface& cn, string_t& request, int argc, char_t** argv, char_t** env);
    virtual int prepare_request_to_send(xos::network::sockets::interface& cn, string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (prepare_request_to_send_) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*prepare_request_to_send_)(cn, \"" << request << "\", argc, argv, env)))...");
            if (!(err = (this->*prepare_request_to_send_)(cn, request, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*prepare_request_to_send_)(cn, \"" << request << "\", argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*prepare_request_to_send_)(cn, \"" << request << "\", argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_prepare_request_to_send(cn, \"" << request << "\", argc, argv, env)))...");
            if (!(err = default_prepare_request_to_send(cn, request, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_prepare_request_to_send(cn, \"" << request << "\", argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_prepare_request_to_send(cn, \"" << request << "\", argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int default_prepare_request_to_send(xos::network::sockets::interface& cn, string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = all_prepare_message_to_send(cn, \"" << request << "\", argc, argv, env)))...");
        if (!(err = all_prepare_message_to_send(cn, request, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = all_prepare_message_to_send(cn, \"" << request << "\", argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = all_prepare_message_to_send(cn, \"" << request << "\", argc, argv, env)))");
        }
        return err;
    }
    virtual int before_prepare_request_to_send(xos::network::sockets::interface& cn, string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_request_to_send(xos::network::sockets::interface& cn, string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_request_to_send(xos::network::sockets::interface& cn, string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_request_to_send(cn, request, argc, argv, env))) {
            int err2 = 0;
            err = prepare_request_to_send(cn, request, argc, argv, env);
            if ((err2 = after_prepare_request_to_send(cn, request, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...receive_request
    int (derives::*receive_request__)(string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env);
    virtual int receive_request(string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (receive_request__) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*receive_request__)(request, cn, argc, argv, env)))...");
            if (!(err = (this->*receive_request__)(request, cn, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*receive_request__)(request, cn, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*receive_request__)(request, cn, argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_receive_request(request, cn, argc, argv, env)))...");
            if (!(err = default_receive_request(request, cn, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_receive_request(request, cn, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_receive_request(request, cn, argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int default_receive_request(string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        char_t c = 0;
        LOGGER_IS_LOGGED_INFO("request.clear()...");
        request.clear();
        LOGGER_IS_LOGGED_INFO("(!(err = this->all_receive_message(request, c, cn, argc, argv, env)))...");
        if (!(err = this->all_receive_message(request, c, cn, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = this->all_receive_message(\"" << request << "\", c, cn, argc, argv, env)))");

            LOGGER_IS_LOGGED_INFO("(!(err = this->all_prepare_message_received(\"" << request << "\", c, cn, argc, argv, env)))...");
            if (!(err = this->all_prepare_message_received(request, c, cn, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = this->all_prepare_message_received(\"" << request << "\", c, cn, argc, argv, env)))");

                LOGGER_IS_LOGGED_INFO("(!(err = this->all_process_request(\"" << request << "\", cn, argc, argv, env)))...");
                if (!(err = this->all_process_request(request, cn, argc, argv, env))) {
                    LOGGER_IS_LOGGED_INFO("...(!(" << err << " = this->all_process_request(\"" << request << "\", cn, argc, argv, env)))");
                } else {
                    LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = this->all_process_request(\"" << request << "\", cn, argc, argv, env)))");
                }
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = this->all_prepare_message_received(\"" << request << "\", c, cn, argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = this->all_receive_message(request, c, cn, argc, argv, env)))");
        }
        return err;
    }
    virtual int before_receive_request(string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_receive_request(string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_receive_request(string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_receive_request(request, cn, argc, argv, env))) {
            int err2 = 0;
            err = receive_request(request, cn, argc, argv, env);
            if ((err2 = after_receive_request(request, cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...process_request
    int (derives::*process_request_)(string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env);
    virtual int process_request(string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (process_request_) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*process_request_)(request, cn, argc, argv, env)))...");
            if (!(err = (this->*process_request_)(request, cn, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*process_request_)(request, cn, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*process_request_)(request, cn, argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_process_request(request, cn, argc, argv, env)))...");
            if (!(err = default_process_request(request, cn, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_process_request(request, cn, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_process_request(request, cn, argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int default_process_request(string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        string_t& response = this->response();
        LOGGER_IS_LOGGED_INFO("(!(err = this->all_process_request(response, \"" << request << "\", cn, argc, argv, env)))...");
        if (!(err = this->all_process_request(response, request, cn, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = this->all_process_request(\"" << response << "\", \"" << request << "\", cn, argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = this->all_process_request(response, \"" << request << "\", cn, argc, argv, env)))");
        }
        return err;
    }
    virtual int before_process_request(string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_request(string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_request(string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_process_request(request, cn, argc, argv, env))) {
            int err2 = 0;
            err = process_request(request, cn, argc, argv, env);
            if ((err2 = after_process_request(request, cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...process_request
    int (derives::*process_request__)(string_t& response, string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env);
    virtual int process_request(string_t& response, string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (process_request__) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*process_request__)(response, request, cn, argc, argv, env)))...");
            if (!(err = (this->*process_request__)(response, request, cn, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*process_request__)(response, request, cn, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*process_request__)(response, request, cn, argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_process_request(response, request, cn, argc, argv, env)))...");
            if (!(err = default_process_request(response, request, cn, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_process_request(response, request, cn, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_process_request(response, request, cn, argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int default_process_request(string_t& response, string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = this->all_prepare_response_to_request_run(response, \"" << request << "\", argc, argv, env)))...");
        if (!(err = this->all_prepare_response_to_request_run(response, request, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = this->all_prepare_response_to_request_run(\"" << response << "\", \"" << request << "\", argc, argv, env)))");

            LOGGER_IS_LOGGED_INFO("(!(err = this->all_send_response(cn, \"" << response << "\", argc, argv, env)))...");
            if (!(err = this->all_send_response(cn, response, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = this->all_send_response(cn, \"" << response << "\", argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = this->all_send_response(cn, \"" << response << "\", argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = this->all_prepare_response_to_request_run(response, \"" << request << "\", argc, argv, env)))");
        }
        return err;
    }
    virtual int before_process_request(string_t& response, string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_request(string_t& response, string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_request(string_t& response, string_t& request, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_process_request(response, request, cn, argc, argv, env))) {
            int err2 = 0;
            err = process_request(response, request, cn, argc, argv, env);
            if ((err2 = after_process_request(response, request, cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...
    /// ...request...
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...response...
    /// ...
    /// ...send_response
    int (derives::*send_response__)(xos::network::sockets::interface& cn, string_t& response, int argc, char_t** argv, char_t** env);
    virtual int send_response(xos::network::sockets::interface& cn, string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (send_response__) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*send_response__)(cn, \"" << response << "\", argc, argv, env)))...");
            if (!(err = (this->*send_response__)(cn, response, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*send_response__)(cn, \"" << response << "\", argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*send_response__)(cn, \"" << response << "\", argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_send_response(cn, \"" << response << "\", argc, argv, env)))...");
            if (!(err = default_send_response(cn, response, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_send_response(cn, \"" << response << "\", argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_send_response(cn, \"" << response << "\", argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int default_send_response(xos::network::sockets::interface& cn, string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = this->all_prepare_response_to_send(cn, \"" << response << "\", argc, argv, env)))...");
        if (!(err = this->all_prepare_response_to_send(cn, response, argc, argv, env))) {
            size_t length = 0; const char_t* chars = 0;
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = this->all_prepare_response_to_send(cn, \"" << response << "\", argc, argv, env)))");
            LOGGER_IS_LOGGED_INFO("((chars = response.has_chars(length)))...");
            if ((chars = response.has_chars(length))) {
                LOGGER_IS_LOGGED_INFO("...((\"" << chars << "\" = response.has_chars(" << length << ")))...");
                LOGGER_IS_LOGGED_INFO("cn.send(\"" << chars << "\", " << length << ")...");
                cn.send(chars, length);
                LOGGER_IS_LOGGED_INFO("...cn.send(\"" << chars << "\", " << length << ")");
            } else {
                LOGGER_IS_LOGGED_INFO("failed on ((chars = response.has_chars(" << length << ")))...");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = this->all_prepare_response_to_send(cn, \"" << response << "\", argc, argv, env)))");
        }
        return err;
    }
    virtual int before_send_response(xos::network::sockets::interface& cn, string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_send_response(xos::network::sockets::interface& cn, string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_send_response(xos::network::sockets::interface& cn, string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_send_response(cn, response, argc, argv, env))) {
            int err2 = 0;
            err = send_response(cn, response, argc, argv, env);
            if ((err2 = after_send_response(cn, response, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...prepare_response_to_send
    int (derives::*prepare_response_to_send_)(xos::network::sockets::interface& cn, string_t& response, int argc, char_t** argv, char_t** env);
    virtual int prepare_response_to_send(xos::network::sockets::interface& cn, string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (prepare_response_to_send_) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*prepare_response_to_send_)(cn, \"" << response << "\", argc, argv, env)))...");
            if (!(err = (this->*prepare_response_to_send_)(cn, response, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*prepare_response_to_send_)(cn, \"" << response << "\", argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*prepare_response_to_send_)(cn, \"" << response << "\", argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_prepare_response_to_send(cn, \"" << response << "\", argc, argv, env)))...");
            if (!(err = default_prepare_response_to_send(cn, response, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_prepare_response_to_send(cn, \"" << response << "\", argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_prepare_response_to_send(cn, \"" << response << "\", argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int default_prepare_response_to_send(xos::network::sockets::interface& cn, string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = all_prepare_message_to_send(cn, \"" << response << "\", argc, argv, env)))...");
        if (!(err = all_prepare_message_to_send(cn, response, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = all_prepare_message_to_send(cn, \"" << response << "\", argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = all_prepare_message_to_send(cn, \"" << response << "\", argc, argv, env)))");
        }
        return err;
    }
    virtual int before_prepare_response_to_send(xos::network::sockets::interface& cn, string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_response_to_send(xos::network::sockets::interface& cn, string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_response_to_send(xos::network::sockets::interface& cn, string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_response_to_send(cn, response, argc, argv, env))) {
            int err2 = 0;
            err = prepare_response_to_send(cn, response, argc, argv, env);
            if ((err2 = after_prepare_response_to_send(cn, response, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...receive_response
    int (derives::*receive_response__)(string_t& response, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env);
    virtual int receive_response(string_t& response, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (receive_response__) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*receive_response__)(response, cn, argc, argv, env)))...");
            if (!(err = (this->*receive_response__)(response, cn, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*receive_response__)(response, cn, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*receive_response__)(response, cn, argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_receive_response(response, cn, argc, argv, env)))...");
            if (!(err = default_receive_response(response, cn, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_receive_response(response, cn, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_receive_response(response, cn, argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int default_receive_response(string_t& response, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        char_t c = 0;
        LOGGER_IS_LOGGED_INFO("response.clear()...");
        response.clear();
        LOGGER_IS_LOGGED_INFO("(!(err = this->all_receive_message(response, c, cn, argc, argv, env)))...");
        if (!(err = this->all_receive_message(response, c, cn, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = this->all_receive_message(\"" << response << "\", c, cn, argc, argv, env)))");

            LOGGER_IS_LOGGED_INFO("(!(err = this->all_prepare_message_received(\"" << response << "\", c, cn, argc, argv, env)))...");
            if (!(err = this->all_prepare_message_received(response, c, cn, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = this->all_prepare_message_received(\"" << response << "\", c, cn, argc, argv, env)))");

                LOGGER_IS_LOGGED_INFO("(!(err = this->all_process_response(\"" << response << "\", cn, argc, argv, env)))...");
                if (!(err = this->all_process_response(response, cn, argc, argv, env))) {
                    LOGGER_IS_LOGGED_INFO("...(!(" << err << " = this->all_process_response(\"" << response << "\", cn, argc, argv, env)))");
                } else {
                    LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = this->all_process_response(\"" << response << "\", cn, argc, argv, env)))");
                }
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = this->all_prepare_message_received(\"" << response << "\", c, cn, argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = this->all_receive_message(response, c, cn, argc, argv, env)))");
        }
        return err;
    }
    virtual int before_receive_response(string_t& response, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_receive_response(string_t& response, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_receive_response(string_t& response, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_receive_response(response, cn, argc, argv, env))) {
            int err2 = 0;
            err = receive_response(response, cn, argc, argv, env);
            if ((err2 = after_receive_response(response, cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...process_response
    int (derives::*process_response_)(string_t& response, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env);
    virtual int process_response(string_t& response, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (process_response_) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*process_response_)(\"" << response << "\", cn, argc, argv, env)))...");
            if (!(err = (this->*process_response_)(response, cn, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*process_response_)(\"" << response << "\", cn, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*process_response_)(\"" << response << "\", cn, argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_process_response(\"" << response << "\", cn, argc, argv, env)))...");
            if (!(err = default_process_response(response, cn, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_process_response(\"" << response << "\", cn, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_process_response(\"" << response << "\", cn, argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int default_process_response(string_t& response, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = this->all_process_response_run(\"" << response << "\", argc, argv, env)))...");
        if (!(err = this->all_process_response_run(response, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = this->all_process_response_run(\"" << response << "\", argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = this->all_process_response_run(\"" << response << "\", argc, argv, env)))");
        }
        return err;
    }
    virtual int before_process_response(string_t& response, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_response(string_t& response, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_response(string_t& response, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_process_response(response, cn, argc, argv, env))) {
            int err2 = 0;
            err = process_response(response, cn, argc, argv, env);
            if ((err2 = after_process_response(response, cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...
    /// ...response...
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...send...
    /// ...
    /// ...prepare_message_to_send
    int (derives::*prepare_message_to_send_)(xos::network::sockets::interface& cn, string_t& msg, int argc, char_t** argv, char_t** env);
    virtual int prepare_message_to_send(xos::network::sockets::interface& cn, string_t& msg, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (prepare_message_to_send_) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*prepare_message_to_send_)(cn, msg, argc, argv, env)))...");
            if (!(err = (this->*prepare_message_to_send_)(cn, msg, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*prepare_message_to_send_)(cn, msg, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*prepare_message_to_send_)(cn, msg, argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_prepare_message_to_send(cn, msg, argc, argv, env)))...");
            if (!(err = default_prepare_message_to_send(cn, msg, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_prepare_message_to_send(cn, msg, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_prepare_message_to_send(cn, msg, argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int default_prepare_message_to_send(xos::network::sockets::interface& cn, string_t& msg, int argc, char_t** argv, char_t** env) {
        int err = 0;
        const string_t& endof_message = this->endof_message_to_send();
        LOGGER_IS_LOGGED_INFO("msg.append(\"" << endof_message << "\")...");
        msg.append(endof_message);
        LOGGER_IS_LOGGED_INFO("...msg.append(\"" << endof_message << "\")");
        return err;
    }
    virtual int before_prepare_message_to_send(xos::network::sockets::interface& cn, string_t& msg, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_message_to_send(xos::network::sockets::interface& cn, string_t& msg, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_message_to_send(xos::network::sockets::interface& cn, string_t& msg, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_message_to_send(cn, msg, argc, argv, env))) {
            int err2 = 0;
            err = prepare_message_to_send(cn, msg, argc, argv, env);
            if ((err2 = after_prepare_message_to_send(cn, msg, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...
    /// ...send...
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...receive...
    /// ...
    /// ...receive_message
    int (derives::*receive_message_)(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env);
    virtual int receive_message(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (receive_message_) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*receive_message_)(r, c, cn, argc, argv, env)))...");
            if (!(err = (this->*receive_message_)(r, c, cn, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*receive_message_)(r, c, cn, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*receive_message_)(r, c, cn, argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_receive_message(r, c, cn, argc, argv, env)))...");
            if (!(err = default_receive_message(r, c, cn, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_receive_message(r, c, cn, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_receive_message(r, c, cn, argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int default_receive_message(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = all_receive_cr(r, c, cn, argc, argv, env)))...");
        if (!(err = all_receive_cr(r, c, cn, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = all_receive_cr(r, c, cn, argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = all_receive_cr(r, c, cn, argc, argv, env)))");
        }
        return err;
    }
    virtual int before_receive_message(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_receive_message(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_receive_message(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_receive_message(r, c, cn, argc, argv, env))) {
            int err2 = 0;
            err = receive_message(r, c, cn, argc, argv, env);
            if ((err2 = after_receive_message(r, c, cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...prepare_message_received
    int (derives::*prepare_message_received_)(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env);
    virtual int prepare_message_received(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (prepare_message_received_) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*prepare_message_received_)(r, c, cn, argc, argv, env)))...");
            if (!(err = (this->*prepare_message_received_)(r, c, cn, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*prepare_message_received_)(r, c, cn, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*prepare_message_received_)(r, c, cn, argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_prepare_message_received(r, c, cn, argc, argv, env)))...");
            if (!(err = default_prepare_message_received(r, c, cn, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_prepare_message_received(r, c, cn, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_prepare_message_received(r, c, cn, argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int default_prepare_message_received(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_prepare_message_received(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_message_received(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_message_received(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_message_received(r, c, cn, argc, argv, env))) {
            int err2 = 0;
            err = prepare_message_received(r, c, cn, argc, argv, env);
            if ((err2 = after_prepare_message_received(r, c, cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int unset_prepare_message_received(int argc, char_t** argv, char_t** env) {
        int err = 0;
        prepare_message_received_ = 0;
        return err;
    }
    virtual int prepare_message_received_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual int cr_receive_message(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = all_receive_cr(r, c, cn, argc, argv, env)))...");
        if (!(err = all_receive_cr(r, c, cn, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = all_receive_cr(r, c, cn, argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = all_receive_cr(r, c, cn, argc, argv, env)))");
        }
        return err;
    }
    virtual int set_cr_receive_message(int argc, char_t** argv, char_t** env) {
        int err = 0;
        receive_message_ = &derives::cr_receive_message;
        return err;
    }
    virtual int cr_receive_message_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_cr_receive_message(int argc, char_t** argv, char_t** env) {
        int err = 0;
        receive_message_ = 0;
        return err;
    }
    virtual int cr_receive_message_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...cr_prepare_message_received
    virtual int cr_prepare_message_received(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        const string_t& endof_message = this->cr_endof_message();
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
        LOGGER_IS_LOGGED_INFO("(!(err = unset_prepare_message_received(argc, argv, env)))...");
        if (!(err = unset_prepare_message_received(argc, argv, env))) {            
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = unset_prepare_message_received(argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = unset_prepare_message_received(argc, argv, env)))");
        }
        return err;
    }
    virtual int set_cr_prepare_message_received(int argc, char_t** argv, char_t** env) {
        int err = 0;
        prepare_message_received_ = &derives::cr_prepare_message_received;
        return err;
    }
    virtual int cr_prepare_message_received_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_cr_prepare_message_received(int argc, char_t** argv, char_t** env) {
        int err = 0;
        prepare_message_received_ = 0;
        return err;
    }
    virtual int cr_prepare_message_received_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...cr_endof_message_to_send...
    virtual int cr_endof_message_to_send_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = set_cr_receive_message(argc, argv, env)))...");
        if (!(err = set_cr_receive_message(argc, argv, env))) {            
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = set_cr_receive_message(argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = set_cr_receive_message(argc, argv, env)))");
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...receive_cr
    /// ...<cr>
    /// ...on_recv_cr
    virtual int on_recv_cr(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = set_cr_prepare_message_received(argc, argv, env)))...");
        if (!(err = set_cr_prepare_message_received(argc, argv, env))) {            
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = set_cr_prepare_message_received(argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = set_cr_prepare_message_received(argc, argv, env)))");
        }
        return err;
    }
    virtual int receive_cr(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        ssize_t amount = 0, count = 0;
        while (0 < (amount = cn.recv(&c, 1))) {
            switch (c) {
            case '\r':
                LOGGER_IS_LOGGED_INFO("...case '\\r':");
                LOGGER_IS_LOGGED_INFO("r.append('\\r', 1)...");
                r.append(&c, 1);
                LOGGER_IS_LOGGED_INFO("(!(err = on_recv_cr(\"" << r << "\", '\\r', cn, argc, argv, env)))...");
                if (!(err = on_recv_cr(r, c, cn, argc, argv, env))) {
                    LOGGER_IS_LOGGED_INFO("...(!(" << err << " = on_recv_cr(\"" << r << "\", '\\r', cn, argc, argv, env)))");
                } else {
                    LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = on_recv_cr(\"" << r << "\", '\\r', cn, argc, argv, env)))");
                }
                return err;
                break;
            case '\n':
                LOGGER_IS_LOGGED_INFO("...case '\\n':");
                LOGGER_IS_LOGGED_INFO("(0 < (count = " << count << "))...");
                if (0 < (count)) {
                    LOGGER_IS_LOGGED_INFO("...(0 < (count = " << count << "))");
                    LOGGER_IS_LOGGED_INFO("r.append('\\n', 1)...");
                    r.append(&c, 1);
                } else {
                    LOGGER_IS_LOGGED_INFO("...failed on (0 < (count = " << count << "))");
                }
                break;
            default:
                r.append(&c, 1);
                break;
            }
            count += amount;
        }
        return err;
    }
    virtual int before_receive_cr(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_receive_cr(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_receive_cr(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_receive_cr(r, c, cn, argc, argv, env))) {
            int err2 = 0;
            err = receive_cr(r, c, cn, argc, argv, env);
            if ((err2 = after_receive_cr(r, c, cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual int lf_receive_message(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = all_receive_lf(r, c, cn, argc, argv, env)))...");
        if (!(err = all_receive_lf(r, c, cn, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = all_receive_lf(r, c, cn, argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = all_receive_lf(r, c, cn, argc, argv, env)))");
        }
        return err;
    }
    virtual int set_lf_receive_message(int argc, char_t** argv, char_t** env) {
        int err = 0;
        receive_message_ = &derives::lf_receive_message;
        return err;
    }
    virtual int lf_receive_message_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_lf_receive_message(int argc, char_t** argv, char_t** env) {
        int err = 0;
        receive_message_ = 0;
        return err;
    }
    virtual int lf_receive_message_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...lf_prepare_message_received
    virtual int lf_prepare_message_received(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
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
        LOGGER_IS_LOGGED_INFO("(!(err = unset_prepare_message_received(argc, argv, env)))...");
        if (!(err = unset_prepare_message_received(argc, argv, env))) {            
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = unset_prepare_message_received(argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = unset_prepare_message_received(argc, argv, env)))");
        }
        return err;
    }
    virtual int set_lf_prepare_message_received(int argc, char_t** argv, char_t** env) {
        int err = 0;
        prepare_message_received_ = &derives::lf_prepare_message_received;
        return err;
    }
    virtual int lf_prepare_message_received_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_lf_prepare_message_received(int argc, char_t** argv, char_t** env) {
        int err = 0;
        prepare_message_received_ = 0;
        return err;
    }
    virtual int lf_prepare_message_received_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...lf_endof_message_to_send...
    virtual int lf_endof_message_to_send_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = set_lf_receive_message(argc, argv, env)))...");
        if (!(err = set_lf_receive_message(argc, argv, env))) {            
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = set_lf_receive_message(argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = set_lf_receive_message(argc, argv, env)))");
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...receive_lf
    /// ...<lf>
    /// ...on_recv_lf
    virtual int on_recv_lf(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = set_lf_prepare_message_received(argc, argv, env)))...");
        if (!(err = set_lf_prepare_message_received(argc, argv, env))) {            
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = set_lf_prepare_message_received(argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = set_lf_prepare_message_received(argc, argv, env)))");
        }
        return err;
    }
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
    //////////////////////////////////////////////////////////////////////////
    virtual int crlf_receive_message(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = all_receive_crlf(r, c, cn, argc, argv, env)))...");
        if (!(err = all_receive_crlf(r, c, cn, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = all_receive_crlf(r, c, cn, argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = all_receive_crlf(r, c, cn, argc, argv, env)))");
        }
        return err;
    }
    virtual int set_crlf_receive_message(int argc, char_t** argv, char_t** env) {
        int err = 0;
        receive_message_ = &derives::crlf_receive_message;
        return err;
    }
    virtual int crlf_receive_message_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_crlf_receive_message(int argc, char_t** argv, char_t** env) {
        int err = 0;
        receive_message_ = 0;
        return err;
    }
    virtual int crlf_receive_message_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...crlf_prepare_message_received
    virtual int crlf_prepare_message_received(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        const string_t& endof_message = this->crlf_endof_message();
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
        LOGGER_IS_LOGGED_INFO("(!(err = unset_prepare_message_received(argc, argv, env)))...");
        if (!(err = unset_prepare_message_received(argc, argv, env))) {            
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = unset_prepare_message_received(argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = unset_prepare_message_received(argc, argv, env)))");
        }
        return err;
    }
    virtual int set_crlf_prepare_message_received(int argc, char_t** argv, char_t** env) {
        int err = 0;
        prepare_message_received_ = &derives::crlf_prepare_message_received;
        return err;
    }
    virtual int crlf_prepare_message_received_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_crlf_prepare_message_received(int argc, char_t** argv, char_t** env) {
        int err = 0;
        prepare_message_received_ = 0;
        return err;
    }
    virtual int crlf_prepare_message_received_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...crlf_endof_message_to_send...
    virtual int crlf_endof_message_to_send_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = set_crlf_receive_message(argc, argv, env)))...");
        if (!(err = set_crlf_receive_message(argc, argv, env))) {            
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = set_crlf_receive_message(argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = set_crlf_receive_message(argc, argv, env)))");
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...receive_crlf
    /// ...<cr><lf>
    virtual int on_recv_crlf(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = set_crlf_prepare_message_received(argc, argv, env)))...");
        if (!(err = set_crlf_prepare_message_received(argc, argv, env))) {            
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = set_crlf_prepare_message_received(argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = set_crlf_prepare_message_received(argc, argv, env)))");
        }
        return err;
    }
    virtual int receive_crlf(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        ssize_t amount = 0;
        enum { ch, cr } s = ch;

        while (0 < (amount = cn.recv(&c, 1))) {
            r.append(&c, 1);
            switch (c) {
            case '\r':
                LOGGER_IS_LOGGED_INFO("...case '\\r':");
                switch (s) {
                case ch:
                case cr:
                    s = cr;
                    break;
                default:
                    LOGGER_IS_LOGGED_ERROR("...unexpected s = " << int_to_string(s));
                    return err = 1;
                }
                break;
            case '\n':
                LOGGER_IS_LOGGED_INFO("...case '\\n':");
                switch (s) {
                case ch:
                    s = ch;
                    break;
                case cr:
                    LOGGER_IS_LOGGED_INFO("err = on_recv_crlf(\"" << r << "\", c, cn, argc, argv, env)...");
                    err = on_recv_crlf(r, c, cn, argc, argv, env);
                    return err;
                default:
                    LOGGER_IS_LOGGED_ERROR("...unexpected s = " << int_to_string(s));
                    return err = 1;
                }
                break;
            default:
                s = ch;
                break;
            }
        }
        return err;
    }
    virtual int before_receive_crlf(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_receive_crlf(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_receive_crlf(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_receive_crlf(r, c, cn, argc, argv, env))) {
            int err2 = 0;
            err = receive_crlf(r, c, cn, argc, argv, env);
            if ((err2 = after_receive_crlf(r, c, cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual int crlf2_receive_message(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = all_receive_crlf2(r, c, cn, argc, argv, env)))...");
        if (!(err = all_receive_crlf2(r, c, cn, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = all_receive_crlf2(r, c, cn, argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = all_receive_crlf2(r, c, cn, argc, argv, env)))");
        }
        return err;
    }
    virtual int set_crlf2_receive_message(int argc, char_t** argv, char_t** env) {
        int err = 0;
        receive_message_ = &derives::crlf2_receive_message;
        return err;
    }
    virtual int crlf2_receive_message_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_crlf2_receive_message(int argc, char_t** argv, char_t** env) {
        int err = 0;
        receive_message_ = 0;
        return err;
    }
    virtual int crlf2_receive_message_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...crlf2_prepare_message_received
    virtual int crlf2_prepare_message_received(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t crlf2_length = 4, length = 0;
        const char_t* chars = 0;
        if ((chars = r.has_chars(length)) && (length >= crlf2_length)) {
            const string_t prepare(r);
            if ((chars = prepare.has_chars(length)) && (length >= crlf2_length)) {
                r.assign(chars, (length-crlf2_length));
            } else {
            }
        } else {
        }
        LOGGER_IS_LOGGED_INFO("(!(err = unset_prepare_message_received(argc, argv, env)))...");
        if (!(err = unset_prepare_message_received(argc, argv, env))) {            
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = unset_prepare_message_received(argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = unset_prepare_message_received(argc, argv, env)))");
        }
        return err;
    }
    virtual int set_crlf2_prepare_message_received(int argc, char_t** argv, char_t** env) {
        int err = 0;
        prepare_message_received_ = &derives::crlf2_prepare_message_received;
        return err;
    }
    virtual int crlf2_prepare_message_received_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_crlf2_prepare_message_received(int argc, char_t** argv, char_t** env) {
        int err = 0;
        prepare_message_received_ = 0;
        return err;
    }
    virtual int crlf2_prepare_message_received_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...crlf2_endof_message_to_send...
    virtual int crlf2_endof_message_to_send_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = set_crlf2_receive_message(argc, argv, env)))...");
        if (!(err = set_crlf2_receive_message(argc, argv, env))) {            
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = set_crlf2_receive_message(argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = set_crlf2_receive_message(argc, argv, env)))");
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...receive_crlf2
    /// ...<cr><lf><cr><lf>
    virtual int on_recv_crlf2(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t**env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = set_crlf2_prepare_message_received(argc, argv, env)))...");
        if (!(err = set_crlf2_prepare_message_received(argc, argv, env))) {            
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = set_crlf2_prepare_message_received(argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = set_crlf2_prepare_message_received(argc, argv, env)))");
        }
        return err;
    }
    virtual int receive_crlf2(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        ssize_t amount = 0;
        enum { ch, cr, lf, lfcr } s = ch;

        while (0 < (amount = cn.recv(&c, 1))) {
            r.append(&c, 1);
            switch (c) {
            case '\r':
                LOGGER_IS_LOGGED_INFO("...case '\\r':");
                switch (s) {
                case ch:
                case cr:
                    s = cr;
                    break;
                case lf:
                    s = lfcr;
                    break;
                case lfcr:
                    s = cr;
                    break;
                default:
                    LOGGER_IS_LOGGED_ERROR("...unexpected s = " << int_to_string(s));
                    return err = 1;
                }
                break;
            case '\n':
                LOGGER_IS_LOGGED_INFO("...case '\\n':");
                switch (s) {
                case ch:
                case lf:
                    s = ch;
                    break;
                case cr:
                    s = lf;
                    break;
                case lfcr:
                    LOGGER_IS_LOGGED_INFO("err = on_recv_crlf2(\"" << r << "\", c, cn, argc, argv, env)...");
                    err = on_recv_crlf2(r, c, cn, argc, argv, env);
                    return err;
                default:
                    LOGGER_IS_LOGGED_ERROR("...unexpected s = " << int_to_string(s));
                    return err = 1;
                }
                break;
            default:
                s = ch;
                break;
            }
        }
        return err;
    }
    virtual int before_receive_crlf2(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_receive_crlf2(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_receive_crlf2(string_t& r, char_t& c, xos::network::sockets::interface& cn, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_receive_crlf2(r, c, cn, argc, argv, env))) {
            int err2 = 0;
            err = receive_crlf2(r, c, cn, argc, argv, env);
            if ((err2 = after_receive_crlf2(r, c, cn, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    /// ...
    /// ...receive...
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// on...host_option... / on...port_option...
    /// ...
    /// on...host_option...
    virtual int on_set_host_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            LOGGER_IS_LOGGED_INFO("this->set_host(" << optarg << ");...");
            this->set_host(optarg);
        } else {
        }
        return err;
    }
    virtual int on_set_relay_host_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            LOGGER_IS_LOGGED_INFO("this->set_relay_host(" << optarg << ");...");
            this->set_relay_host(optarg);
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...port_option...
    virtual int on_set_port_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            string_t arg(optarg);
            unsigned port = arg.to_unsigned();
            LOGGER_IS_LOGGED_INFO("(0 < (port = " << port << "))...");
            if (0 < (port)) {
                LOGGER_IS_LOGGED_INFO("this->set_port(" << port << ");...");
                this->set_port(port);
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (0 < (port = " << port << "))");
            }
        } else {
        }
        return err;
    }
    virtual int on_set_relay_port_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            string_t arg(optarg);
            unsigned relay_port = arg.to_unsigned();
            LOGGER_IS_LOGGED_INFO("(0 < (relay_port = " << relay_port << "))...");
            if (0 < (relay_port)) {
                LOGGER_IS_LOGGED_INFO("this->set_relay_port(" << relay_port << ");...");
                this->set_relay_port(relay_port);
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (0 < (relay_port = " << relay_port << "))");
            }
        } else {
        }
        return err;
    }
    /// ...
    /// on...host_option... / on...port_option...
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ..host / ..port
    /// ...
    /// ...host / ...port
    virtual string_t& set_host(const string_t& to) {
        this->set_accept_host(to);
        this->set_connect_host(to);
        return this->host();
    }
    virtual string_t& set_host(const char_t* to) {
        this->set_accept_host(to);
        this->set_connect_host(to);
        return this->host();
    }
    virtual const string_t& get_host() const {
        return this->host();
    }
    virtual string_t& host() const {
        return this->connect_host();
    }
    virtual short& set_port(const short& to) {
        this->set_accept_port(to);
        this->set_connect_port(to);
        return this->port();
    }
    virtual const short& get_port() const {
        return this->port();
    }
    virtual short& port() const {
        return this->connect_port();
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...accept_host / ...accept_port
    virtual string_t& set_accept_host(const string_t& to) {
        const char_t* chars = to.has_chars();
        return set_accept_host(chars);
    }
    virtual string_t& set_accept_host(const char_t* to) {
        string_t& accept_host = this->accept_host();
        if ((to)) accept_host.assign(to);
        else accept_host.clear();
        return accept_host;
    }
    virtual const string_t& get_accept_host() const {
        return this->accept_host();
    }
    virtual string_t& accept_host() const {
        return (string_t&)accept_host_;
    }
    virtual short& set_accept_port(const short& to) {
        short& accept_port = this->accept_port();
        accept_port = to;
        return accept_port;
    }
    virtual const short& get_accept_port() const {
        return this->accept_port();
    }
    virtual short& accept_port() const {
        return (short&)accept_port_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...accept_one / ...accept_done / ...accept_restart
    virtual bool& set_accept_one(const bool& to) {
        bool& accept_one = this->accept_one();
        accept_one = to;
        return accept_one;
    }
    virtual const bool& get_accept_one() const {
        return this->accept_one();
    }
    virtual bool& accept_one() const {
        return (bool&)accept_one_;
    }
    /// ...accept_done
    virtual bool& set_accept_done(const bool& to) {
        bool& accept_done = this->accept_done();
        accept_done = to;
        return accept_done;
    }
    virtual const bool& get_accept_done() const {
        return this->accept_done();
    }
    virtual bool& accept_done() const {
        return (bool&)accept_done_;
    }
    virtual bool& stop_set(const bool& to) {
        bool& stop = this->stop();
        LOGGER_IS_LOGGED_INFO("(true == (stop = " << stop << "))...");
        if (true == (stop)) {
            LOGGER_IS_LOGGED_INFO("...(true == (stop = " << stop << "))");
            LOGGER_IS_LOGGED_INFO("set_accept_done(stop = " << stop << ")...");
            set_accept_done(stop);
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (true == (stop = " << stop << "))");
        }
        return stop;
    }
    /// ...accept_restart
    virtual bool& set_accept_restart(const bool& to) {
        bool& accept_restart = this->accept_restart();
        accept_restart = to;
        return accept_restart;
    }
    virtual const bool& get_accept_restart() const {
        return this->accept_restart();
    }
    virtual bool& accept_restart() const {
        return (bool&)accept_restart_;
    }
    virtual bool& restart_set(const bool& to) {
        bool& restart = this->restart();
        LOGGER_IS_LOGGED_INFO("(true == (restart = " << restart << "))...");
        if (true == (restart)) {
            LOGGER_IS_LOGGED_INFO("...(true == (restart = " << restart << "))");
            LOGGER_IS_LOGGED_INFO("set_accept_done(restart = " << restart << ")...");
            set_accept_restart(restart);
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (true == (restart = " << restart << "))");
        }
        return restart;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...connect_host / ...connect_port
    virtual string_t& set_connect_host(const string_t& to) {
        const char_t* chars = to.has_chars();
        return set_connect_host(chars);
    }
    virtual string_t& set_connect_host(const char_t* to) {
        string_t& connect_host = this->connect_host();
        if ((to)) connect_host.assign(to);
        else connect_host.clear();
        return connect_host;
    }
    virtual const string_t& get_connect_host() const {
        return this->connect_host();
    }
    virtual string_t& connect_host() const {
        return (string_t&)connect_host_;
    }
    virtual short& set_connect_port(const short& to) {
        short& connect_port = this->connect_port();
        connect_port = to;
        return connect_port;
    }
    virtual const short& get_connect_port() const {
        return this->connect_port();
    }
    virtual short& connect_port() const {
        return (short&)connect_port_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...relay_host / ...relay_port
    virtual string_t& set_relay_host(const string_t& to) {
        const char_t* chars = to.has_chars();
        return set_relay_host(chars);
    }
    virtual string_t& set_relay_host(const char_t* to) {
        string_t& relay_host = this->relay_host();
        if ((to)) relay_host.assign(to);
        else relay_host.clear();
        return relay_host;
    }
    virtual const string_t& get_relay_host() const {
        return this->relay_host();
    }
    virtual string_t& relay_host() const {
        return (string_t&)relay_host_;
    }
    virtual short& set_relay_port(const short& to) {
        short& relay_port = this->relay_port();
        relay_port = to;
        return relay_port;
    }
    virtual const short& get_relay_port() const {
        return this->relay_port();
    }
    virtual short& relay_port() const {
        return (short&)relay_port_;
    }
    /// ...
    /// ..host / ..port
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...ep
    xos::network::sockets::endpoint& (derives::*accept_ep_)() const;
    virtual xos::network::sockets::endpoint& accept_ep() const {
        if ((this->accept_ep_)) {
            return (this->*accept_ep_)();
        }
        return this->default_accept_ep();
    }
    virtual xos::network::sockets::endpoint& default_accept_ep() const {
        return this->accept_ip_v4_ep();
    }
    virtual xos::network::sockets::endpoint& accept_ip_v4_ep() const {
        return this->ip_v4_ep();
    }
#if !defined(WINSOCK_1)
    virtual xos::network::sockets::endpoint& accept_ip_v6_ep() const {
        return this->ip_v6_ep();
    }
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)
    //////////////////////////////////////////////////////////////////////////
    /// ...tp
    xos::network::sockets::transport& (derives::*accept_tp_)() const;
    virtual xos::network::sockets::transport& accept_tp() const {
        if ((this->accept_tp_)) {
            return (this->*accept_tp_)();
        }
        return this->default_accept_tp();
    }
    virtual xos::network::sockets::transport& default_accept_tp() const {
        return this->accept_ip_v4_tcp_tp();
    }
    virtual xos::network::sockets::transport& accept_ip_v4_tcp_tp() const {
        return this->ip_v4_tcp_tp();
    }
#if !defined(WINSOCK_1)
    virtual xos::network::sockets::transport& accept_ip_v6_tcp_tp() const {
        return this->ip_v6_tcp_tp();
    }
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...ep
    xos::network::sockets::endpoint& (derives::*connect_ep_)() const;
    virtual xos::network::sockets::endpoint& connect_ep() const {
        if ((this->connect_ep_)) {
            return (this->*connect_ep_)();
        }
        return this->default_connect_ep();
    }
    virtual xos::network::sockets::endpoint& default_connect_ep() const {
        return this->connect_ip_v4_ep();
    }
    virtual xos::network::sockets::endpoint& connect_ip_v4_ep() const {
        return this->ip_v4_ep();
    }
#if !defined(WINSOCK_1)
    virtual xos::network::sockets::endpoint& connect_ip_v6_ep() const {
        return this->ip_v6_ep();
    }
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)
    //////////////////////////////////////////////////////////////////////////
    /// ...tp
    xos::network::sockets::transport& (derives::*connect_tp_)() const;
    virtual xos::network::sockets::transport& connect_tp() const {
        if ((this->connect_tp_)) {
            return (this->*connect_tp_)();
        }
        return this->default_connect_tp();
    }
    virtual xos::network::sockets::transport& default_connect_tp() const {
        return this->connect_ip_v4_tcp_tp();
    }
    virtual xos::network::sockets::transport& connect_ip_v4_tcp_tp() const {
        return this->ip_v4_tcp_tp();
    }
#if !defined(WINSOCK_1)
    virtual xos::network::sockets::transport& connect_ip_v6_tcp_tp() const {
        return this->ip_v6_tcp_tp();
    }
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...iface / ...addr / ...ep/ ...tp
    /// ...
    /// ...os_iface
    virtual xos::network::sockets::os::interface& accept_os_iface() const {
        return (xos::network::sockets::os::interface&)accept_os_iface_;
    }
    virtual xos::network::sockets::os::interface& connect_os_iface() const {
        return (xos::network::sockets::os::interface&)connect_os_iface_;
    }
    virtual xos::network::sockets::os::interface& relay_os_iface() const {
        return (xos::network::sockets::os::interface&)relay_os_iface_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...iface
    virtual xos::network::sockets::interface& accept_iface() const {
        return (xos::network::sockets::interface&)accept_os_iface();
    }
    virtual xos::network::sockets::interface& connect_iface() const {
        return (xos::network::sockets::interface&)connect_os_iface();
    }
    virtual xos::network::sockets::interface& relay_iface() const {
        return (xos::network::sockets::interface&)relay_os_iface();
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...addr /  ...addrlen
    virtual xos::network::sockets::sockaddr_t& accept_addr() const {
        return (xos::network::sockets::sockaddr_t&)accept_addr_;
    }
    virtual xos::network::sockets::socklen_t& accept_addrlen() const {
        return (xos::network::sockets::socklen_t&)accept_addrlen_;
    }
    virtual xos::network::sockets::sockaddr_t& connect_addr() const {
        return (xos::network::sockets::sockaddr_t&)connect_addr_;
    }
    virtual xos::network::sockets::socklen_t& connect_addrlen() const {
        return (xos::network::sockets::socklen_t&)connect_addrlen_;
    }
    virtual xos::network::sockets::sockaddr_t& relay_addr() const {
        return (xos::network::sockets::sockaddr_t&)relay_addr_;
    }
    virtual xos::network::sockets::socklen_t& relay_addrlen() const {
        return (xos::network::sockets::socklen_t&)relay_addrlen_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...ep
    xos::network::sockets::endpoint& (derives::*ep_)() const;
    virtual xos::network::sockets::endpoint& ep() const {
        if ((this->ep_)) {
            return (this->*ep_)();
        }
        return this->default_ep();
    }
    virtual xos::network::sockets::endpoint& default_ep() const {
        return this->ip_v4_ep();
    }
    virtual xos::network::sockets::endpoint& ip_v4_ep() const {
        return (xos::network::sockets::endpoint&)ip_v4_ep_;
    }
#if !defined(WINSOCK_1)
    virtual xos::network::sockets::endpoint& ip_v6_ep() const {
        return (xos::network::sockets::endpoint&)ip_v6_ep_;
    }
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)
    //////////////////////////////////////////////////////////////////////////
    /// ...tp
    xos::network::sockets::transport& (derives::*tp_)() const;
    virtual xos::network::sockets::transport& tp() const {
        if ((this->tp_)) {
            return (this->*tp_)();
        }
        return this->default_tp();
    }
    virtual xos::network::sockets::transport& default_tp() const {
        return this->ip_v4_tcp_tp();
    }
    virtual xos::network::sockets::transport& ip_v4_tcp_tp() const {
        return (xos::network::sockets::transport&)ip_v4_tcp_tp_;
    }
    virtual xos::network::sockets::transport& ip_v4_udp_tp() const {
        return (xos::network::sockets::transport&)ip_v4_udp_tp_;
    }
#if !defined(WINSOCK_1)
    virtual xos::network::sockets::transport& ip_v6_tcp_tp() const {
        return (xos::network::sockets::transport&)ip_v6_tcp_tp_;
    }
    virtual xos::network::sockets::transport& ip_v6_udp_tp() const {
        return (xos::network::sockets::transport&)ip_v6_udp_tp_;
    }
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)
    /// ...
    /// ...iface / ...addr / ...ep/ ...tp
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
protected:
    bool accept_one_, accept_done_, accept_restart_;
    string_t accept_host_, connect_host_, relay_host_;
    short accept_port_, connect_port_, relay_port_;

    xos::network::sockets::os::interface accept_os_iface_, connect_os_iface_, relay_os_iface_;
    xos::network::sockets::interface accept_iface_, connect_iface_, relay_iface_;

    xos::network::sockets::sockaddr_t accept_addr_, connect_addr_, relay_addr_;
    xos::network::sockets::socklen_t accept_addrlen_, connect_addrlen_, relay_addrlen_;

    xos::network::sockets::ip::v4::endpoint ip_v4_ep_;
    xos::network::sockets::ip::v4::tcp::transport ip_v4_tcp_tp_;
    xos::network::sockets::ip::v4::udp::transport ip_v4_udp_tp_;

#if !defined(WINSOCK_1)
    xos::network::sockets::ip::v6::endpoint ip_v6_ep_;
    xos::network::sockets::ip::v6::tcp::transport ip_v6_tcp_tp_;
    xos::network::sockets::ip::v6::udp::transport ip_v6_udp_tp_;
#else /// !defined(WINSOCK_1)
#endif /// !defined(WINSOCK_1)
}; /// class maint 
typedef maint<> main;

} /// namespace base 
} /// namespace sockets 
} /// namespace network 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_NETWORK_SOCKETS_BASE_MAIN_HPP

