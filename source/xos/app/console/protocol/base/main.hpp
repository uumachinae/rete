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
///   Date: 12/13/2024, 3/1/2025
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_HPP
#define XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_HPP

#include "xos/app/console/protocol/base/main_opt.hpp"

namespace xos {
namespace app {
namespace console {
namespace protocol {
namespace base {

/// class maint
template 
<class TExtends = xos::app::console::protocol::base::main_optt<>,  class TImplements = typename TExtends::implements>

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
    typedef reader_string_t literal_string_t;

    /// constructor / destructor
    maint()
    : run_(0), 
      
      text_literal_sized_size_(4), text_literal_size_(0),
      
      restart_(false), stop_(false),
      
      hello_request_("hello"),
      hello_response_(hello_request_),

      restart_request_("restart"),
      restart_response_(restart_request_),

      start_request_("start"),
      start_response_(start_response_),

      stop_request_("stop"),
      stop_response_(stop_request_),

      unknown_request_("unknown"),
      unknown_response_(unknown_request_),

      request_(hello_request_),
      response_(hello_response_) {
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
    /// ...process_request_run
    virtual int default_process_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const string_t& request = this->request();
        string_t& response = this->response();
        LOGGER_IS_LOGGED_INFO("(!(err = this->all_prepare_response_to_request_run(\"" << response << "\", \"" << request << "\", argc, argv, env)))...");
        if (!(err = this->all_prepare_response_to_request_run(response, request, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = this->all_prepare_response_to_request_run(\"" << response << "\", \"" << request << "\", argc, argv, env)))");
            LOGGER_IS_LOGGED_INFO("(!(err = this->all_output_response_run(\"" << response << "\", argc, argv, env)))...");
            if (!(err = this->all_output_response_run(response, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = this->all_output_response_run(\"" << response << "\", argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = this->all_output_response_run(\"" << response << "\", argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = this->all_prepare_response_to_request_run(\"" << response << "\", \"" << request << "\", argc, argv, env)))");
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual int default_prepare_response_to_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        int unequal = 0;
        const string_t& hello_request = this->hello_request();
        LOGGER_IS_LOGGED_INFO("(!(unequal = request.compare(hello_request = \"" << hello_request << "\")))...");
        if (!(unequal = request.compare(hello_request))) {
            LOGGER_IS_LOGGED_INFO("(!(err = this->all_prepare_response_to_hello_request_run(\"" << response << "\", \"" << request << "\", argc, argv, env)))...");
            if (!(err = this->all_prepare_response_to_hello_request_run(response, request, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = this->all_prepare_response_to_hello_request_run(\"" << response << "\", \"" << request << "\", argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = this->all_prepare_response_to_hello_request_run(\"" << response << "\", \"" << request << "\", argc, argv, env)))");
            }
        } else {
            const string_t& restart_request = this->restart_request();
            LOGGER_IS_LOGGED_INFO("... failed on(!(" << unequal << " = request.compare(hello_request = \"" << hello_request << "\")))");
            LOGGER_IS_LOGGED_INFO("(!(unequal = request.compare(restart_request = \"" << restart_request << "\")))...");
            if (!(unequal = request.compare(restart_request))) {
                LOGGER_IS_LOGGED_INFO("(!(err = this->all_prepare_response_to_restart_request_run(\"" << response << "\", \"" << request << "\", argc, argv, env)))...");
                if (!(err = this->all_prepare_response_to_restart_request_run(response, request, argc, argv, env))) {
                    LOGGER_IS_LOGGED_INFO("...(!(" << err << " = this->all_prepare_response_to_restart_request_run(\"" << response << "\", \"" << request << "\", argc, argv, env)))");
                } else {
                    LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = this->all_prepare_response_to_restart_request_run(\"" << response << "\", \"" << request << "\", argc, argv, env)))");
                }
            } else {
                const string_t& start_request = this->start_request();
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << unequal << " = request.compare(restart_request = \"" << restart_request << "\")))");
                LOGGER_IS_LOGGED_INFO("(!(unequal = request.compare(start_request = \"" << start_request << "\")))...");
                if (!(unequal = request.compare(start_request))) {
                    LOGGER_IS_LOGGED_INFO("(!(err = this->all_prepare_response_to_start_request_run(\"" << response << "\", \"" << request << "\", argc, argv, env)))...");
                    if (!(err = this->all_prepare_response_to_start_request_run(response, request, argc, argv, env))) {
                        LOGGER_IS_LOGGED_INFO("...(!(" << err << " = this->all_prepare_response_to_start_request_run(\"" << response << "\", \"" << request << "\", argc, argv, env)))");
                    } else {
                        LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = this->all_prepare_response_to_start_request_run(\"" << response << "\", \"" << request << "\", argc, argv, env)))");
                    }
                } else {
                    const string_t& stop_request = this->stop_request();
                    LOGGER_IS_LOGGED_INFO("...failed on (!(" << unequal << " = request.compare(start_request = \"" << start_request << "\")))");
                    LOGGER_IS_LOGGED_INFO("(!(unequal = request.compare(stop_request = \"" << stop_request << "\")))...");
                    if (!(unequal = request.compare(stop_request))) {
                        LOGGER_IS_LOGGED_INFO("(!(err = this->all_prepare_response_to_stop_request_run(\"" << response << "\", \"" << request << "\", argc, argv, env)))...");
                        if (!(err = this->all_prepare_response_to_stop_request_run(response, request, argc, argv, env))) {
                            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = this->all_prepare_response_to_stop_request_run(\"" << response << "\", \"" << request << "\", argc, argv, env)))");
                        } else {
                            LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = this->all_prepare_response_to_stop_request_run(\"" << response << "\", \"" << request << "\", argc, argv, env)))");
                        }
                    } else {
                        LOGGER_IS_LOGGED_INFO("...failed on(!(" << unequal << " = request.compare(stop_request = \"" << stop_request << "\")))");
                        LOGGER_IS_LOGGED_INFO("(!(err = this->all_prepare_response_to_unknown_request_run(\"" << response << "\", \"" << request << "\", argc, argv, env)))...");
                        if (!(err = this->all_prepare_response_to_unknown_request_run(response, request, argc, argv, env))) {
                            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = this->all_prepare_response_to_unknown_request_run(\"" << response << "\", \"" << request << "\", argc, argv, env)))");
                        } else {
                            LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = this->all_prepare_response_to_unknown_request_run(\"" << response << "\", \"" << request << "\", argc, argv, env)))");
                        }
                    }
                }
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...prepare_response_to_hello_request_run
    virtual int default_prepare_response_to_hello_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        const string_t& hello_response = this->hello_response();
        LOGGER_IS_LOGGED_INFO("response.assign(hello_response = \"" << hello_response << "\")...");
        response.assign(hello_response);
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...prepare_response_to_restart_request_run
    virtual int default_prepare_response_to_restart_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        const string_t& restart_response = this->restart_response();
        LOGGER_IS_LOGGED_INFO("response.assign(restart_response = \"" << restart_response << "\")...");
        response.assign(restart_response);
        return err;
    }
    virtual int after_prepare_response_to_restart_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        bool restart = false;
        LOGGER_IS_LOGGED_INFO("(true == (restart = set_restart(true)))...");
        if (true == (restart = set_restart(true))) {
            LOGGER_IS_LOGGED_INFO("...(true == (" << restart << " = set_restart(true)))");
            LOGGER_IS_LOGGED_INFO("(true == (restart = restart_set(" << restart << ")))...");
            if (true == (restart = restart_set(restart))) {
                LOGGER_IS_LOGGED_INFO("...(true == (" << restart << " = restart_set(" << restart << ")))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (true == (" << restart << " = restart_set(" << restart << ")))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (true == (" << restart << " = set_restart(true)))");
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...prepare_response_to_start_request_run
    virtual int default_prepare_response_to_start_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        const string_t& start_response = this->start_response();
        LOGGER_IS_LOGGED_INFO("response.assign(start_response = \"" << start_response << "\")...");
        response.assign(start_response);
        return err;
    }
    virtual int after_prepare_response_to_start_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        bool restart = false;
        LOGGER_IS_LOGGED_INFO("(true == (restart = set_restart(true)))...");
        if (true == (restart = set_restart(true))) {
            LOGGER_IS_LOGGED_INFO("...(true == (" << restart << " = set_restart(true)))");
            LOGGER_IS_LOGGED_INFO("(true == (restart = restart_set(" << restart << ")))...");
            if (true == (restart = restart_set(restart))) {
                LOGGER_IS_LOGGED_INFO("...(true == (" << restart << " = restart_set(" << restart << ")))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (true == (" << restart << " = restart_set(" << restart << ")))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (true == (" << restart << " = set_restart(true)))");
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...prepare_response_to_stop_request_run
    virtual int default_prepare_response_to_stop_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        const string_t& stop_response = this->stop_response();
        LOGGER_IS_LOGGED_INFO("response.assign(stop_response = \"" << stop_response << "\")...");
        response.assign(stop_response);
        return err;
    }
    virtual int after_prepare_response_to_stop_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        bool stop = false;
        LOGGER_IS_LOGGED_INFO("(true == (stop = set_stop(true)))...");
        if (true == (stop = set_stop(true))) {
            LOGGER_IS_LOGGED_INFO("...(true == (" << stop << " = set_stop(true)))");
            LOGGER_IS_LOGGED_INFO("(true == (stop = stop_set(" << stop << ")))...");
            if (true == (stop = stop_set(stop))) {
                LOGGER_IS_LOGGED_INFO("...(true == (" << stop << " = stop_set(" << stop << ")))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (true == (" << stop << " = stop_set(" << stop << ")))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (true == (" << stop << " = set_stop(true)))");
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...prepare_response_to_unknown_request_run
    virtual int default_prepare_response_to_unknown_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        const string_t& unknown_request = this->unknown_request();
        LOGGER_IS_LOGGED_INFO("response.assign(unknown_request = \"" << unknown_request << "\")...");
        response.assign(unknown_request);
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...process_response_run
    virtual int default_process_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        string_t& response = this->response();
        LOGGER_IS_LOGGED_INFO("(!(err = this->all_process_response_run(\"" << response << "\", argc, argv, env)))...");
        if (!(err = this->all_process_response_run(response, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = this->all_process_response_run(\"" << response << "\", argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = this->all_process_response_run(\"" << response << "\", argc, argv, env)))");
        }
        return err;
    }
    virtual int default_process_response_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        string_t& response_to_process = this->response_to_process();
        LOGGER_IS_LOGGED_INFO("response_to_process.assign(\"" << response << "\")...");
        response_to_process.assign(response);
        LOGGER_IS_LOGGED_INFO("(!(err = this->all_process_unknown_response_run(\"" << response << "\", argc, argv, env)))...");
        if (!(err = this->all_process_unknown_response_run(response, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = this->all_process_unknown_response_run(\"" << response << "\", argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = this->all_process_unknown_response_run(\"" << response << "\", argc, argv, env)))");
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...prepare_to_process_unknown_response_run
    virtual int default_prepare_to_process_unknown_response_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        const string_t& unknown_response = this->unknown_response();
        const string_t& hello_response = this->hello_response();
        int unequal = 0;
        LOGGER_IS_LOGGED_INFO("(!(unequal = response.compare(hello_response)))...");
        if (!(unequal = response.compare(hello_response))) {
            return err;
        } else {
            const string_t& restart_response = this->restart_response();
            LOGGER_IS_LOGGED_INFO("(!(unequal = response.compare(restart_response)))...");
            if (!(unequal = response.compare(restart_response))) {
                return err;
            } else {
                const string_t& start_response = this->start_response();
                LOGGER_IS_LOGGED_INFO("(!(unequal = response.compare(start_response)))...");
                if (!(unequal = response.compare(start_response))) {
                    return err;
                } else {
                    const string_t& stop_response = this->stop_response();
                    LOGGER_IS_LOGGED_INFO("(!(unequal = response.compare(stop_response)))...");
                    if (!(unequal = response.compare(stop_response))) {
                        return err;
                    } else {
                    }
                }
            }
        }
        LOGGER_IS_LOGGED_INFO("response.assign(unknown_response = \"" << unknown_response << "\")...");
        response.assign(unknown_response);
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...output_request_run
    virtual int default_output_request_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        string_t& request = this->request();
        LOGGER_IS_LOGGED_INFO("!(err = all_output_request_run(\"" << request << "\", argc, argv, env))...");
        if (!(err = this->all_output_request_run(request, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_output_request_run(\"" << request << "\", argc, argv, env))");
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...output_response_run
    virtual int default_output_response_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        string_t& response = this->response();
        LOGGER_IS_LOGGED_INFO("(err = all_output_response_run(\"" << response << "\", argc, argv, env))...");
        if (!(err = this->all_output_response_run(response, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_output_response_run(\"" << response << "\", argc, argv, env))");
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...output_response_run
    using extends::default_output_response_run;
    virtual int output_response_to_output_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        string_t& response_to_output = this->response_to_output();
        LOGGER_IS_LOGGED_INFO("!(err = this->default_output_response_run(\"" << response_to_output << "\", argc, argv, env))...");
        if (!(err = this->default_output_response_run(response_to_output, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = this->default_output_response_run(\"" << response_to_output << "\", argc, argv, env))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = this->default_output_response_run(\"" << response_to_output << "\", argc, argv, env))");
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...on...request_option...
    virtual int input_on_get_request_option
    (const char_t* optarg, int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        string_t& request = this->request();
        if (!(err = this->all_input_message_run(request, argc, argv, env))) {
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...on...response_option...
    virtual int input_on_get_response_option
    (const char_t* optarg, int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        string_t& response = this->response();
        if (!(err = this->all_input_message_run(response, argc, argv, env))) {
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...on...request_option...
    virtual int default_on_set_request_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            string_t& request = this->request();
            LOGGER_IS_LOGGED_INFO("request.assign(\"" << optarg << "\")...");
            request.assign(optarg);
            LOGGER_IS_LOGGED_INFO("...request.assign(\"" << optarg << "\")");
        } else {
        }
        return err;
    }
    virtual int file_on_set_request_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            string_t& request = this->request();
            LOGGER_IS_LOGGED_INFO("(!(err = file_on_set_message_option(request, \"" << optarg << "\", optind, argc, argv, env)))...");
            if (!(err = file_on_set_message_option(request, optarg, optind, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = file_on_set_message_option(\"" << request << "\", \"" << optarg << "\", optind, argc, argv, env)))");
                LOGGER_IS_LOGGED_INFO("(!(err = on_file_on_set_request_option(\"" << optarg << "\", optind, argc, argv, env)))...");
                if (!(err = on_file_on_set_request_option(optarg, optind, argc, argv, env))) {
                    LOGGER_IS_LOGGED_INFO("...(!(" << err << " = on_file_on_set_request_option(\"" << optarg << "\", optind, argc, argv, env)))");
                } else {
                    LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = on_file_on_set_request_option(\"" << optarg << "\", optind, argc, argv, env)))");
                }
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = file_on_set_message_option(request, \"" << optarg << "\", optind, argc, argv, env)))");
            }
        } else {
        }
        return err;
    }
    virtual int on_file_on_set_request_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...on...response_option...
    virtual int default_on_set_response_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            string_t& response = this->response();
            LOGGER_IS_LOGGED_INFO("response.assign(\"" << optarg << "\")...");
            response.assign(optarg);
            LOGGER_IS_LOGGED_INFO("...response.assign(\"" << optarg << "\")");
        } else {
        }
        return err;
    }
    virtual int file_on_set_response_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            string_t& response = this->response();
            LOGGER_IS_LOGGED_INFO("(!(err = file_on_set_message_option(response, \"" << optarg << "\", optind, argc, argv, env)))...");
            if (!(err = file_on_set_message_option(response, optarg, optind, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = file_on_set_message_option(\"" << response << "\", \"" << optarg << "\", optind, argc, argv, env)))");
                LOGGER_IS_LOGGED_INFO("(!(err = on_file_on_set_response_option(\"" << optarg << "\", optind, argc, argv, env)))...");
                if (!(err = on_file_on_set_response_option(optarg, optind, argc, argv, env))) {
                    LOGGER_IS_LOGGED_INFO("...(!(" << err << " = on_file_on_set_response_option(\"" << optarg << "\", optind, argc, argv, env)))");
                } else {
                    LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = on_file_on_set_response_option(\"" << optarg << "\", optind, argc, argv, env)))");
                }
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = file_on_set_message_option(response, \"" << optarg << "\", optind, argc, argv, env)))");
            }
        } else {
        }
        return err;
    }
    virtual int on_file_on_set_response_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    virtual int file_on_set_message_option
    (string_t& message, const char_t* optarg, int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            xos::io::crt::file::readert<xos::io::readert<xos::io::seekert<xos::io::sequencet<char> > > > file;

            LOGGER_IS_LOGGED_INFO("file.open(\""<< optarg <<"\")...");
            if ((file.open(optarg))) {
                literal_string_t& literal_string_read = this->literal_string_read();
                LOGGER_IS_LOGGED_INFO("...file.open(\""<< optarg <<"\")");
                LOGGER_IS_LOGGED_INFO("!(err = all_file_read_text_literal(literal_string_read, file, argc, argv, env))...");
                if (!(err = all_file_read_text_literal(literal_string_read, file, argc, argv, env))) {
                    LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_file_read_text_literal(literal_string_read, file, argc, argv, env))");
                    LOGGER_IS_LOGGED_INFO("literal.assign(literal_string_read)...");
                    message.assign(literal_string_read);
                } else {
                    LOGGER_IS_LOGGED_INFO("...failed !(" << err << " = all_file_read_text_literal(message_assign, file, argc, argv, env))");
                }
                LOGGER_IS_LOGGED_INFO("file.close(\""<< optarg <<"\")...");
                file.close();
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on file.open(\""<< optarg <<"\")");
            }
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...text_input_message_run
    virtual int text_input_message_run(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        in_reader_t reader(*this);
        literal_string_t& literal_string_read = this->literal_string_read();
        
        LOGGER_IS_LOGGED_INFO("!(err = all_read_text_literal(literal_string_read, reader, argc, argv, env))...");
        if (!(err = all_read_text_literal(literal_string_read, reader, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_read_text_literal(literal_string_read, reader, argc, argv, env))");
            LOGGER_IS_LOGGED_INFO("literal.assign(literal_string_read)...");
            message.assign(literal_string_read);
        } else {
            LOGGER_IS_LOGGED_INFO("...failed !(" << err << " = all_read_text_literal(message_assign, reader, argc, argv, env))");
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// on...input_input_option...
    virtual int on_input_input_option_on_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("this->set_input_on_get_request_option(argc, argv, env)...");
        if (!(err = this->set_input_on_get_request_option(argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("this->input_on_get_request_option_set(argc, argv, env)...");
            if (!(err = this->input_on_get_request_option_set(argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("this->set_input_on_get_response_option(argc, argv, env)...");
                if (!(err = this->set_input_on_get_response_option(argc, argv, env))) {
                    LOGGER_IS_LOGGED_INFO("this->input_on_get_response_option_set(argc, argv, env)...");
                    if (!(err = this->input_on_get_response_option_set(argc, argv, env))) {
                    } else {
                    }
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_input_input_option_off_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("this->unset_input_on_get_request_option(argc, argv, env)...");
        if (!(err = this->unset_input_on_get_request_option(argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("this->input_on_get_request_option_unset(argc, argv, env)...");
            if (!(err = this->input_on_get_request_option_unset(argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("this->unset_input_on_get_response_option(argc, argv, env)...");
                if (!(err = this->unset_input_on_get_response_option(argc, argv, env))) {
                    LOGGER_IS_LOGGED_INFO("this->input_on_get_response_option_unset(argc, argv, env)...");
                    if (!(err = this->input_on_get_response_option_unset(argc, argv, env))) {
                    } else {
                    }
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...file_input_option...
    virtual int on_file_input_option_on_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("this->set_file_on_set_request_option(argc, argv, env)...");
        if (!(err = this->set_file_on_set_request_option(argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("this->file_on_set_request_option_set(argc, argv, env)...");
            if (!(err = this->file_on_set_request_option_set(argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("this->set_file_on_set_response_option(argc, argv, env)...");
                if (!(err = this->set_file_on_set_response_option(argc, argv, env))) {
                    LOGGER_IS_LOGGED_INFO("this->file_on_set_response_option_set(argc, argv, env)...");
                    if (!(err = this->file_on_set_response_option_set(argc, argv, env))) {
                    } else {
                    }
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_file_input_option_off_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("this->unset_file_on_set_request_option(argc, argv, env)...");
        if (!(err = this->unset_file_on_set_request_option(argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("this->file_on_set_request_option_unset(argc, argv, env)...");
            if (!(err = this->file_on_set_request_option_unset(argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("this->unset_file_on_set_response_option(argc, argv, env)...");
                if (!(err = this->unset_file_on_set_response_option(argc, argv, env))) {
                    LOGGER_IS_LOGGED_INFO("this->file_on_set_response_option_unset(argc, argv, env)...");
                    if (!(err = this->file_on_set_response_option_unset(argc, argv, env))) {
                    } else {
                    }
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...string_input_option...
    virtual int on_string_input_option_on_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = this->on_file_input_option_off_set(optarg, optind, argc, argv, env)))...");
        if (!(err = this->on_file_input_option_off_set(optarg, optind, argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int on_string_input_option_off_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = this->on_file_input_option_on_set(optarg, optind, argc, argv, env)))...");
        if (!(err = this->on_file_input_option_on_set(optarg, optind, argc, argv, env))) {
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...read_text_literal
    int (derives::*read_text_literal_)(literal_string_t& literal, reader_t& reader, int argc, char_t** argv, char_t** env);
    virtual int read_text_literal(literal_string_t& literal, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (read_text_literal_) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*read_text_literal_)(literal, reader, argc, argv, env)))...");
            if (!(err = (this->*read_text_literal_)(literal, reader, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*read_text_literal_)(\"" << literal << "\", reader, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*read_text_literal_)(literal, reader, argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_read_text_literal(literal, reader, argc, argv, env)))...");
            if (!(err = default_read_text_literal(literal, reader, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_read_text_literal(\"" << literal << "\", reader, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_read_text_literal(literal, reader, argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int default_read_text_literal(literal_string_t& literal, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = all_lf_read_text_literal(literal, reader, argc, argv, env)))...");
        if (!(err = all_lf_read_text_literal(literal, reader, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = all_lf_read_text_literal(\"" << literal << "\", reader, argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = all_lf_read_text_literal(literal, reader, argc, argv, env)))");
        }
        return err;
    }
    virtual int before_read_text_literal(literal_string_t& literal, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_read_text_literal(literal_string_t& literal, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_read_text_literal(literal_string_t& literal, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_read_text_literal(literal, reader, argc, argv, env))) {
            int err2 = 0;
            err = read_text_literal(literal, reader, argc, argv, env);
            if ((err2 = after_read_text_literal(literal, reader, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...file_read_text_literal
    int (derives::*file_read_text_literal_)(literal_string_t& literal, reader_t& reader, int argc, char_t** argv, char_t** env);
    virtual int file_read_text_literal(literal_string_t& literal, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (file_read_text_literal_) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*file_read_text_literal_)(literal, reader, argc, argv, env)))...");
            if (!(err = (this->*file_read_text_literal_)(literal, reader, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*file_read_text_literal_)(\"" << literal << "\", reader, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*file_read_text_literal_)(literal, reader, argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_file_read_text_literal(literal, reader, argc, argv, env)))...");
            if (!(err = default_file_read_text_literal(literal, reader, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_file_read_text_literal(\"" << literal << "\", reader, argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_file_read_text_literal(literal, reader, argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int default_file_read_text_literal(literal_string_t& literal, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = all_endof_read_text_literal(literal, reader, argc, argv, env)))...");
        if (!(err = all_endof_read_text_literal(literal, reader, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = all_endof_read_text_literal(\"" << literal << "\", reader, argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = all_endof_read_text_literal(literal, reader, argc, argv, env)))");
        }
        return err;
    }
    virtual int before_file_read_text_literal(literal_string_t& literal, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_file_read_text_literal(literal_string_t& literal, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_file_read_text_literal(literal_string_t& literal, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_file_read_text_literal(literal, reader, argc, argv, env))) {
            int err2 = 0;
            err = file_read_text_literal(literal, reader, argc, argv, env);
            if ((err2 = after_file_read_text_literal(literal, reader, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...endof_read_text_literal
    virtual int endof_read_text_literal(literal_string_t& literal, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("literal.clear()...");
        literal.clear();
        LOGGER_IS_LOGGED_INFO("!(err = unset_prepare_read_text_literal(argc, argv, env))...");
        if (!(err = unset_prepare_read_text_literal(argc, argv, env))) {
             char_t c = 0;
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = unset_prepare_read_text_literal(argc, argv, env))");

            LOGGER_IS_LOGGED_INFO("!(err = read_text_literal_endof(literal, c, reader, argc, argv, env))...");
            if (!(err = read_text_literal_endof(literal, c, reader, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...!(" << err << " = read_text_literal_endof(\"" << literal << "\", c, reader, argc, argv, env))");

                LOGGER_IS_LOGGED_INFO("!(err = prepare_read_text_literal_endof(\"" << literal << "\", argc, argv, env))...");
                if (!(err = prepare_read_text_literal_endof(literal, argc, argv, env))) {
                    LOGGER_IS_LOGGED_INFO("...!(" << err << " = prepare_read_text_literal_endof(\"" << literal << "\", argc, argv, env))");
                } else {
                    LOGGER_IS_LOGGED_INFO("...failed !(" << err << " = prepare_read_text_literal_endof(\"" << literal << "\", argc, argv, env))");
                }
            } else {
                LOGGER_IS_LOGGED_INFO("...failed !(" << err << " = read_text_literal_endof(literal, c, reader, argc, argv, env))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed !(" << err << " = unset_prepare_read_text_literal(argc, argv, env))");
        }
        return err;
    }
    virtual int before_endof_read_text_literal(literal_string_t& literal, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_endof_read_text_literal(literal_string_t& literal, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_endof_read_text_literal(literal_string_t& literal, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_endof_read_text_literal(literal, reader, argc, argv, env))) {
            int err2 = 0;
            err = endof_read_text_literal(literal, reader, argc, argv, env);
            if ((err2 = after_endof_read_text_literal(literal, reader, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...lf_read_text_literal
    virtual int lf_read_text_literal(literal_string_t& literal, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("literal.clear()...");
        literal.clear();
        LOGGER_IS_LOGGED_INFO("!(err = unset_prepare_read_text_literal(argc, argv, env))...");
        if (!(err = unset_prepare_read_text_literal(argc, argv, env))) {
             char_t c = 0;
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = unset_prepare_read_text_literal(argc, argv, env))");

            LOGGER_IS_LOGGED_INFO("!(err = read_text_literal_lf(literal, c, reader, argc, argv, env))...");
            if (!(err = read_text_literal_lf(literal, c, reader, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...!(" << err << " = read_text_literal_lf(\"" << literal << "\", c, reader, argc, argv, env))");
    
                LOGGER_IS_LOGGED_INFO("!(err = prepare_read_text_literal(\"" << literal << "\", argc, argv, env))...");
                if (!(err = prepare_read_text_literal(literal, argc, argv, env))) {
                    LOGGER_IS_LOGGED_INFO("...!(" << err << " = prepare_read_text_literal(\"" << literal << "\", argc, argv, env))");
                } else {
                    LOGGER_IS_LOGGED_INFO("...failed !(" << err << " = prepare_read_text_literal(\"" << literal << "\", argc, argv, env))");
                }
            } else {
                LOGGER_IS_LOGGED_INFO("...failed !(" << err << " = read_text_literal_lf(literal, c, reader, argc, argv, env))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed !(" << err << " = unset_prepare_read_text_literal(argc, argv, env))");
        }
        return err;
    }
    virtual int before_lf_read_text_literal(literal_string_t& literal, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_lf_read_text_literal(literal_string_t& literal, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_lf_read_text_literal(literal_string_t& literal, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_lf_read_text_literal(literal, reader, argc, argv, env))) {
            int err2 = 0;
            err = lf_read_text_literal(literal, reader, argc, argv, env);
            if ((err2 = after_lf_read_text_literal(literal, reader, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...cr_read_text_literal
    virtual int cr_read_text_literal(literal_string_t& literal, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("literal.clear()...");
        literal.clear();
        LOGGER_IS_LOGGED_INFO("!(err = unset_prepare_read_text_literal(argc, argv, env))...");
        if (!(err = unset_prepare_read_text_literal(argc, argv, env))) {
             char_t c = 0;
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = unset_prepare_read_text_literal(argc, argv, env))");

            LOGGER_IS_LOGGED_INFO("!(err = read_text_literal_cr(literal, c, reader, argc, argv, env))...");
            if (!(err = read_text_literal_cr(literal, c, reader, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...!(" << err << " = read_text_literal_cr(\"" << literal << "\", c, reader, argc, argv, env))");
    
                LOGGER_IS_LOGGED_INFO("!(err = prepare_read_text_literal(\"" << literal << "\", argc, argv, env))...");
                if (!(err = prepare_read_text_literal(literal, argc, argv, env))) {
                    LOGGER_IS_LOGGED_INFO("...!(" << err << " = prepare_read_text_literal(\"" << literal << "\", argc, argv, env))");
                } else {
                    LOGGER_IS_LOGGED_INFO("...failed !(" << err << " = prepare_read_text_literal(\"" << literal << "\", argc, argv, env))");
                }
            } else {
                LOGGER_IS_LOGGED_INFO("...failed !(" << err << " = read_text_literal_cr(literal, c, reader, argc, argv, env))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed !(" << err << " = unset_prepare_read_text_literal(argc, argv, env))");
        }
        return err;
    }
    virtual int before_cr_read_text_literal(literal_string_t& literal, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_cr_read_text_literal(literal_string_t& literal, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_cr_read_text_literal(literal_string_t& literal, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_cr_read_text_literal(literal, reader, argc, argv, env))) {
            int err2 = 0;
            err = cr_read_text_literal(literal, reader, argc, argv, env);
            if ((err2 = after_cr_read_text_literal(literal, reader, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...crlf_read_text_literal
    virtual int crlf_read_text_literal(literal_string_t& literal, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("literal.clear()...");
        literal.clear();
        LOGGER_IS_LOGGED_INFO("!(err = unset_prepare_read_text_literal(argc, argv, env))...");
        if (!(err = unset_prepare_read_text_literal(argc, argv, env))) {
             char_t c = 0;
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = unset_prepare_read_text_literal(argc, argv, env))");

            LOGGER_IS_LOGGED_INFO("!(err = read_text_literal_crlf(literal, c, reader, argc, argv, env))...");
            if (!(err = read_text_literal_crlf(literal, c, reader, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...!(" << err << " = read_text_literal_crlf(\"" << literal << "\", c, reader, argc, argv, env))");
    
                LOGGER_IS_LOGGED_INFO("!(err = prepare_read_text_literal(\"" << literal << "\", argc, argv, env))...");
                if (!(err = prepare_read_text_literal(literal, argc, argv, env))) {
                    LOGGER_IS_LOGGED_INFO("...!(" << err << " = prepare_read_text_literal(\"" << literal << "\", argc, argv, env))");
                } else {
                    LOGGER_IS_LOGGED_INFO("...failed !(" << err << " = prepare_read_text_literal(\"" << literal << "\", argc, argv, env))");
                }
            } else {
                LOGGER_IS_LOGGED_INFO("...failed !(" << err << " = read_text_literal_crlf(literal, c, reader, argc, argv, env))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed !(" << err << " = unset_prepare_read_text_literal(argc, argv, env))");
        }
        return err;
    }
    virtual int before_crlf_read_text_literal(literal_string_t& literal, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_crlf_read_text_literal(literal_string_t& literal, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_crlf_read_text_literal(literal_string_t& literal, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_crlf_read_text_literal(literal, reader, argc, argv, env))) {
            int err2 = 0;
            err = crlf_read_text_literal(literal, reader, argc, argv, env);
            if ((err2 = after_crlf_read_text_literal(literal, reader, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...crlf2_read_text_literal
    virtual int crlf2_read_text_literal(literal_string_t& literal, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("literal.clear()...");
        literal.clear();
        LOGGER_IS_LOGGED_INFO("!(err = unset_prepare_read_text_literal(argc, argv, env))...");
        if (!(err = unset_prepare_read_text_literal(argc, argv, env))) {
             char_t c = 0;
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = unset_prepare_read_text_literal(argc, argv, env))");

            LOGGER_IS_LOGGED_INFO("!(err = read_text_literal_crlf2(literal, c, reader, argc, argv, env))...");
            if (!(err = read_text_literal_crlf2(literal, c, reader, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...!(" << err << " = read_text_literal_crlf2(\"" << literal << "\", c, reader, argc, argv, env))");
    
                LOGGER_IS_LOGGED_INFO("!(err = prepare_read_text_literal(\"" << literal << "\", argc, argv, env))...");
                if (!(err = prepare_read_text_literal(literal, argc, argv, env))) {
                    LOGGER_IS_LOGGED_INFO("...!(" << err << " = prepare_read_text_literal(\"" << literal << "\", argc, argv, env))");
                } else {
                    LOGGER_IS_LOGGED_INFO("...failed !(" << err << " = prepare_read_text_literal(\"" << literal << "\", argc, argv, env))");
                }
            } else {
                LOGGER_IS_LOGGED_INFO("...failed !(" << err << " = read_text_literal_crlf2(literal, c, reader, argc, argv, env))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed !(" << err << " = unset_prepare_read_text_literal(argc, argv, env))");
        }
        return err;
    }
    virtual int before_crlf2_read_text_literal(literal_string_t& literal, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_crlf2_read_text_literal(literal_string_t& literal, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_crlf2_read_text_literal(literal_string_t& literal, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_crlf2_read_text_literal(literal, reader, argc, argv, env))) {
            int err2 = 0;
            err = crlf2_read_text_literal(literal, reader, argc, argv, env);
            if ((err2 = after_crlf2_read_text_literal(literal, reader, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...sized_read_text_literal
    virtual int sized_read_text_literal(literal_string_t& literal, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        const size_t& sized_size = this->text_literal_sized_size();
        LOGGER_IS_LOGGED_INFO("(!(err = sized_size_read_text_literal(literal, reader, " << sized_size << ", argc, argv, env)))...");
        if (!(err = all_sized_size_read_text_literal(literal, reader, sized_size, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = sized_size_read_text_literal(\"" << literal << "\", reader, " << sized_size << ", argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = sized_size_read_text_literal(literal, reader, " << sized_size << ", argc, argv, env)))");
        }
        return err;
    }
    virtual int before_sized_read_text_literal(literal_string_t& literal, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_sized_read_text_literal(literal_string_t& literal, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_sized_read_text_literal(literal_string_t& literal, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_sized_read_text_literal(literal, reader, argc, argv, env))) {
            int err2 = 0;
            err = sized_read_text_literal(literal, reader, argc, argv, env);
            if ((err2 = after_sized_read_text_literal(literal, reader, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...sized_size_read_text_literal
    virtual int sized_size_read_text_literal(literal_string_t& literal, reader_t& reader, const size_t& sized, int argc, char_t** argv, char_t** env) {
        int err = 0;
        char_t c = 0;
        size_t size = 0;
        ssize_t amount = 0;
        LOGGER_IS_LOGGED_INFO("literal.clear()...");
        literal.clear();
        LOGGER_IS_LOGGED_INFO("for (size_t remain = " << sized << "; remain; --remain) {...");
        for (size_t remain = sized; remain; --remain) {
            LOGGER_IS_LOGGED_INFO("(0 < (amount = reader.read(&c, 1)))...");
            if  (0 < (amount = reader.read(&c, 1))) {
                LOGGER_IS_LOGGED_INFO("...(0 < (" << amount << " = reader.read(&c, 1)))");
                LOGGER_IS_LOGGED_INFO("literal.append(&c, 1)...");
                literal.append(&c, 1);
                LOGGER_IS_LOGGED_INFO("size = ((" << size << " << 8) | " << ((uint8_t)c) << ")...");
                size = ((size << 8) | ((uint8_t)c));
            } else {
                LOGGER_IS_LOGGED_ERROR("...failed on (0 < (" << amount << " = reader.read(&c, 1)))");
                return err = 1;
            }
        } /// for (size_t remain = sized; remain; --remain)
        LOGGER_IS_LOGGED_INFO("...} for (size_t remain = " << sized << "; remain; --remain) {");
        LOGGER_IS_LOGGED_INFO("(!(err = all_size_read_text_literal(literal, reader, size, argc, argv, env)))...");
        if (!(err = all_size_read_text_literal(literal, reader, size, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(err = all_size_read_text_literal(\"" << literal << "\", reader, size, argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(err = all_size_read_text_literal(literal, reader, size, argc, argv, env)))");
        }
        return err;
    }
    virtual int before_sized_size_read_text_literal(literal_string_t& literal, reader_t& reader, const size_t& sized, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_sized_size_read_text_literal(literal_string_t& literal, reader_t& reader, const size_t& sized, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_sized_size_read_text_literal(literal_string_t& literal, reader_t& reader, const size_t& sized, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_sized_size_read_text_literal(literal, reader, sized, argc, argv, env))) {
            int err2 = 0;
            err = sized_size_read_text_literal(literal, reader, sized, argc, argv, env);
            if ((err2 = after_sized_size_read_text_literal(literal, reader, sized, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...size_read_text_literal...
    virtual int size_read_text_literal(literal_string_t& literal, reader_t& reader, const size_t& size, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("!(err = unset_prepare_read_text_literal(argc, argv, env))...");
        if (!(err = unset_prepare_read_text_literal(argc, argv, env))) {
             char_t c = 0;
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = unset_prepare_read_text_literal(argc, argv, env))");

            LOGGER_IS_LOGGED_INFO("!(err = read_text_literal_size(literal, c, reader, " << size << ", argc, argv, env))...");
            if (!(err = read_text_literal_size(literal, c, reader, size, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...!(" << err << " = read_text_literal_size(\"" << literal << "\", c, reader, " << size << ", argc, argv, env))");
    
                LOGGER_IS_LOGGED_INFO("!(err = prepare_read_text_literal_size(\"" << literal << "\", " << size << ", argc, argv, env))...");
                if (!(err = prepare_read_text_literal_size(literal, size, argc, argv, env))) {
                    LOGGER_IS_LOGGED_INFO("...!(" << err << " = prepare_read_text_literal_size(\"" << literal << "\", " << size << ", argc, argv, env))");
                } else {
                    LOGGER_IS_LOGGED_INFO("...failed !(" << err << " = prepare_read_text__size(\"" << literal << "\", " << size << ", argc, argv, env))");
                }
            } else {
                LOGGER_IS_LOGGED_INFO("...failed !(" << err << " = read_text_literal_size(literal, c, reader, " << size << ", argc, argv, env))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed !(" << err << " = unset_prepare_read_text_literal(argc, argv, env))");
        }
        return err;
    }
    virtual int before_size_read_text_literal(literal_string_t& literal, reader_t& reader, const size_t& size, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_size_read_text_literal(literal_string_t& literal, reader_t& reader, const size_t& size, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_size_read_text_literal(literal_string_t& literal, reader_t& reader, const size_t& size, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_size_read_text_literal(literal, reader, size, argc, argv, env))) {
            int err2 = 0;
            err = size_read_text_literal(literal, reader, size, argc, argv, env);
            if ((err2 = after_size_read_text_literal(literal, reader, size, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...prepare_read_text_literal
    int (derives::*prepare_read_text_literal_)(literal_string_t& r, int argc, char_t** argv, char_t** env);
    virtual int prepare_read_text_literal(literal_string_t& r, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (prepare_read_text_literal_) {
            LOGGER_IS_LOGGED_INFO("(!(err = (this->*prepare_read_text_literal_)(\"" << r << "\", argc, argv, env)))...");
            if (!(err = (this->*prepare_read_text_literal_)(r, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = (this->*prepare_read_text_literal_)(\"" << r << "\", argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << " = (this->*prepare_read_text_literal_)(\"" << r << "\", argc, argv, env)))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("(!(err = default_prepare_read_text_literal(\"" << r << "\", argc, argv, env)))...");
            if (!(err = default_prepare_read_text_literal(r, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...(!(" << err << " = default_prepare_read_text_literal(\"" << r << "\", argc, argv, env)))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = default_prepare_read_text_literal(\"" << r << "\", argc, argv, env)))");
            }
        }
        return err;
    }
    virtual int default_prepare_read_text_literal(literal_string_t& r, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_prepare_read_text_literal(literal_string_t& r, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_read_text_literal(literal_string_t& r, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_read_text_literal(literal_string_t& r, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_read_text_literal(r, argc, argv, env))) {
            int err2 = 0;
            err = prepare_read_text_literal(r, argc, argv, env);
            if ((err2 = after_prepare_read_text_literal(r, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int unset_prepare_read_text_literal(int argc, char_t** argv, char_t** env) {
        int err = 0;
        prepare_read_text_literal_ = 0;
        return err;
    }
    virtual int prepare_read_text_literal_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int set_prepare_read_text_literal_endof(int argc, char_t** argv, char_t** env) {
        int err = 0;
        prepare_read_text_literal_ = &derives::prepare_read_text_literal_endof;
        return err;
    }
    virtual int prepare_read_text_literal_endof_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_prepare_read_text_literal_endof(int argc, char_t** argv, char_t** env) {
        int err = 0;
        prepare_read_text_literal_ = 0;
        return err;
    }
    virtual int prepare_read_text_literal_endof_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int set_prepare_read_text_literal_cr(int argc, char_t** argv, char_t** env) {
        int err = 0;
        prepare_read_text_literal_ = &derives::prepare_read_text_literal_cr;
        return err;
    }
    virtual int prepare_read_text_literal_cr_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_prepare_read_text_literal_cr(int argc, char_t** argv, char_t** env) {
        int err = 0;
        prepare_read_text_literal_ = 0;
        return err;
    }
    virtual int prepare_read_text_literal_cr_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int set_prepare_read_text_literal_lf(int argc, char_t** argv, char_t** env) {
        int err = 0;
        prepare_read_text_literal_ = &derives::prepare_read_text_literal_lf;
        return err;
    }
    virtual int prepare_read_text_literal_lf_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_prepare_read_text_literal_lf(int argc, char_t** argv, char_t** env) {
        int err = 0;
        prepare_read_text_literal_ = 0;
        return err;
    }
    virtual int prepare_read_text_literal_lf_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int set_prepare_read_text_literal_crlf(int argc, char_t** argv, char_t** env) {
        int err = 0;
        prepare_read_text_literal_ = &derives::prepare_read_text_literal_crlf;
        return err;
    }
    virtual int prepare_read_text_literal_crlf_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_prepare_read_text_literal_crlf(int argc, char_t** argv, char_t** env) {
        int err = 0;
        prepare_read_text_literal_ = 0;
        return err;
    }
    virtual int prepare_read_text_literal_crlf_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int set_prepare_read_text_literal_crlf2(int argc, char_t** argv, char_t** env) {
        int err = 0;
        prepare_read_text_literal_ = &derives::prepare_read_text_literal_crlf2;
        return err;
    }
    virtual int prepare_read_text_literal_crlf2_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_prepare_read_text_literal_crlf2(int argc, char_t** argv, char_t** env) {
        int err = 0;
        prepare_read_text_literal_ = 0;
        return err;
    }
    virtual int prepare_read_text_literal_crlf2_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////
    /// ...prepare_read_text_literal...
    /// ...
    /// ...endof
    virtual int prepare_read_text_literal_endof(literal_string_t& literal, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("!(err = prepare_read_text_literal_lf(\"" << literal << "\", argc, argv, env))...");
        if (!(err = prepare_read_text_literal_lf(literal, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = prepare_read_text_literal_lf(\"" << literal << "\", argc, argv, env))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed !(" << err << " = prepare_read_text_literal_lf(\"" << literal << "\", argc, argv, env))");
        }
        return err;
    }
    /// ...<cr>
    virtual int prepare_read_text_literal_cr(literal_string_t& r, int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;
        
        if ((chars = r.has_chars(length))) {
            enum { ch, cr } s = ch;
            size_t count = 0;
            string_t r_assign;

            for (count = length; count > 0; --count, ++chars) {
                char_t c = *chars;

                switch(c) {
                case '\r':
                    LOGGER_IS_LOGGED_INFO("...case '\\r':");
                    switch (s) {
                    case ch:
                        s = cr;
                        LOGGER_IS_LOGGED_INFO("r.assign(\"" << r_assign << "\")...");
                        r.assign(r_assign);
                        return err;
                    default:
                        LOGGER_IS_LOGGED_ERROR("...unexpected s = " << int_to_string(s));
                        return err = 1;
                    } /// switch (s)
                    break;
                case '\n':
                    LOGGER_IS_LOGGED_INFO("...case '\\n':");
                    r_assign.append(&c, 1);
                    break;
                default:
                    LOGGER_IS_LOGGED_INFO("...default:");
                    r_assign.append(&c, 1);
                    break;
                } /// switch(c) 
            } /// for (count = length; count > 0; --count, ++chars)
        }
        return err;
    }
    /// ...<lf>
    virtual int prepare_read_text_literal_lf(literal_string_t& r, int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;
        
        if ((chars = r.has_chars(length))) {
            enum { ch, lf } s = ch;
            size_t count = 0;
            string_t r_assign;

            for (count = length; count > 0; --count, ++chars) {
                char_t c = *chars;

                switch(c) {
                case '\r':
                    LOGGER_IS_LOGGED_INFO("...case '\\r':");
                    r_assign.append(&c, 1);
                    break;
                case '\n':
                    LOGGER_IS_LOGGED_INFO("...case '\\n':");
                    switch (s) {
                    case ch:
                        s = lf;
                        LOGGER_IS_LOGGED_INFO("r.assign(\"" << r_assign << "\")...");
                        r.assign(r_assign);
                        return err;
                    default:
                        LOGGER_IS_LOGGED_ERROR("...unexpected s = " << int_to_string(s));
                        return err = 1;
                    } /// switch (s)
                    break;
                default:
                    LOGGER_IS_LOGGED_INFO("...default:");
                    r_assign.append(&c, 1);
                    break;
                } /// switch(c) 
            } /// for (count = length; count > 0; --count, ++chars)
        }
        return err;
    }
    /// ...<cr><lf>
    virtual int prepare_read_text_literal_crlf(literal_string_t& r, int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;
        
        if ((chars = r.has_chars(length))) {
            enum { ch, cr } s = ch;
            size_t count = 0;
            string_t r_append, r_assign;
            
            for (count = length; count > 0; --count, ++chars) {
                char_t c = *chars;
                r_append.append(&c, 1);
                switch(c) {
                case '\r':
                    LOGGER_IS_LOGGED_INFO("...case '\\r':");
                    switch (s) {
                    case ch:
                        s = cr;
                        break;
                    case cr:
                        s = cr;
                        r_assign.append(r_append);
                        r_append.clear();
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
                        r_assign.append(r_append);
                        r_append.clear();
                        break;
                    case cr:
                        r.assign(r_assign);
                        return err;
                    default:
                        LOGGER_IS_LOGGED_ERROR("...unexpected s = " << int_to_string(s));
                        return err = 1;
                    }
                    break;
                default:
                    LOGGER_IS_LOGGED_INFO("...default:");
                    s = ch;
                    r_assign.append(r_append);
                    r_append.clear();
                    break;
                }
            }
        } else {
        }
        return err;
    }
    /// ...<cr><lf><cr><lf>
    virtual int prepare_read_text_literal_crlf2(literal_string_t& r, int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const char_t* chars = 0;
        
        if ((chars = r.has_chars(length))) {
            enum { ch, cr, crlf, crlfcr } s = ch;
            size_t count = 0;
            string_t r_append, r_assign;
            
            for (count = length; count > 0; --count, ++chars) {
                char_t c = *chars;
                r_append.append(&c, 1);
                switch(c) {
                case '\r':
                    LOGGER_IS_LOGGED_INFO("...case '\\r':");
                    switch (s) {
                    case ch:
                        s = cr;
                        break;
                    case cr:
                        s = cr;
                        r_assign.append(r_append);
                        r_append.clear();
                        break;
                    case crlf:
                        s = crlfcr;
                        break;
                    case crlfcr:
                        s = cr;
                        r_assign.append(r_append);
                        r_append.clear();
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
                        r_assign.append(r_append);
                        r_append.clear();
                        break;
                    case crlf:
                        s = ch;
                        r_assign.append(r_append);
                        r_append.clear();
                        break;
                    case cr:
                        s = crlf;
                        break;
                    case crlfcr:
                        r.assign(r_assign);
                        return err;
                    default:
                        LOGGER_IS_LOGGED_ERROR("...unexpected s = " << int_to_string(s));
                        return err = 1;
                    }
                    break;
                default:
                    LOGGER_IS_LOGGED_INFO("...default:");
                    s = ch;
                    r_assign.append(r_append);
                    r_append.clear();
                    break;
                }
            }
        } else {
        }
        return err;
    }
    /// ...[size]
    virtual int prepare_read_text_literal_size(literal_string_t& r, const size_t& size, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    /// ...
    /// ...prepare_read_text_literal...
    ///////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////
    /// ...read...
    /// ...
    /// ...<endof>
    virtual int read_text_literal_endof(literal_string_t& r, char_t& c, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        ssize_t amount = 0;
        while (0 < (amount = reader.read(&c, 1))) {
            r.append(&c, 1);
            switch (c) {
            case '\r':
                LOGGER_IS_LOGGED_INFO("...case '\\r':");
                break;
            case '\n':
                LOGGER_IS_LOGGED_INFO("...case '\\n':");
                break;
            default:
                LOGGER_IS_LOGGED_INFO("...default:");
                break;
            } /// switch (c)
        } /// while (0 < (amount = reader.read(&c, 1)))
        return err;
    }
    /// ...<cr>
    virtual int on_read_text_literal_cr(literal_string_t& r, char_t& c, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("!(err = set_prepare_read_text_literal_cr(argc, argv, env))...");
        if (!(err = set_prepare_read_text_literal_cr(argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = set_prepare_read_text_literal_cr(argc, argv, env))");

            LOGGER_IS_LOGGED_INFO("!(err = prepare_read_text_literal_cr_set(argc, argv, env))...");
            if (!(err = prepare_read_text_literal_cr_set(argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...!(" << err << " = prepare_read_text_literal_cr_set(argc, argv, env))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed !(" << err << " = prepare_read_text_literal_cr_set(argc, argv, env))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed !(" << err << " = set_prepare_read_text_literal_cr(argc, argv, env))");
        }
        return err;
    }
    virtual int read_text_literal_cr(literal_string_t& r, char_t& c, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        ssize_t amount = 0;
        enum { ch, cr } s = ch;

        while (0 < (amount = reader.read(&c, 1))) {
            r.append(&c, 1);
            switch (c) {
            case '\r':
                LOGGER_IS_LOGGED_INFO("...case '\\r':");
                switch (s) {
                case ch:
                    s = cr;
                    LOGGER_IS_LOGGED_INFO("err = on_read_text_literal_cr(r, c, reader, argc, argv, env)...");
                    err = on_read_text_literal_cr(r, c, reader, argc, argv, env);
                    return err;
                default:
                    LOGGER_IS_LOGGED_ERROR("...unexpected s = " << int_to_string(s));
                    return err = 1;
                } /// switch (s)
                break;
            case '\n':
                LOGGER_IS_LOGGED_INFO("...case '\\n':");
                break;
            default:
                LOGGER_IS_LOGGED_INFO("...default:");
                break;
            } /// switch (c)
        } /// while (0 < (amount = reader.read(&c, 1)))
        return err;
    }
    /// ...<lf>
    virtual int on_read_text_literal_lf(literal_string_t& r, char_t& c, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("!(err = set_prepare_read_text_literal_lf(argc, argv, env))...");
        if (!(err = set_prepare_read_text_literal_lf(argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = set_prepare_read_text_literal_lf(argc, argv, env))");

            LOGGER_IS_LOGGED_INFO("!(err = prepare_read_text_literal_lf_set(argc, argv, env))...");
            if (!(err = prepare_read_text_literal_lf_set(argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...!(" << err << " = prepare_read_text_literal_lf_set(argc, argv, env))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed !(" << err << " = prepare_read_text_literal_lf_set(argc, argv, env))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed !(" << err << " = set_prepare_read_text_literal_lf(argc, argv, env))");
        }
        return err;
    }
    virtual int read_text_literal_lf(literal_string_t& r, char_t& c, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        ssize_t amount = 0;
        enum { ch, lf } s = ch;

        while (0 < (amount = reader.read(&c, 1))) {
            r.append(&c, 1);
            switch (c) {
            case '\r':
                LOGGER_IS_LOGGED_INFO("...case '\\r':");
                break;
            case '\n':
                LOGGER_IS_LOGGED_INFO("...case '\\n':");
                switch (s) {
                case ch:
                    s = lf;
                    LOGGER_IS_LOGGED_INFO("err = on_read_text_literal_lf(r, c, reader, argc, argv, env)...");
                    err = on_read_text_literal_lf(r, c, reader, argc, argv, env);
                    return err;
                default:
                    LOGGER_IS_LOGGED_ERROR("...unexpected s = " << int_to_string(s));
                    return err = 1;
                } /// switch (s)
                break;
            default:
                LOGGER_IS_LOGGED_INFO("...default:");
                break;
            } /// switch (c)
        } /// while (0 < (amount = reader.read(&c, 1)))
        return err;
    }
    /// ...<cr><lf>
    virtual int on_read_text_literal_crlf(literal_string_t& r, char_t& c, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("!(err = set_prepare_read_text_literal_crlf(argc, argv, env))...");
        if (!(err = set_prepare_read_text_literal_crlf(argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = set_prepare_read_text_literal_crlf(argc, argv, env))");

            LOGGER_IS_LOGGED_INFO("!(err = prepare_read_text_literal_crlf_set(argc, argv, env))...");
            if (!(err = prepare_read_text_literal_crlf_set(argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...!(" << err << " = prepare_read_text_literal_crlf_set(argc, argv, env))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed !(" << err << " = prepare_read_text_literal_crlf_set(argc, argv, env))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed !(" << err << " = set_prepare_read_text_literal_crlf(argc, argv, env))");
        }
        return err;
    }
    virtual int read_text_literal_crlf(literal_string_t& r, char_t& c, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        ssize_t amount = 0;
        enum { ch, cr } s = ch;

        while (0 < (amount = reader.read(&c, 1))) {
            r.append(&c, 1);
            switch (c) {
            case '\r':
                LOGGER_IS_LOGGED_INFO("...case '\\r':");
                switch (s) {
                case ch:
                    s = cr;
                    break;
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
                    LOGGER_IS_LOGGED_INFO("err = on_read_text_literal_crlf(r, c, reader, argc, argv, env)...");
                    err = on_read_text_literal_crlf(r, c, reader, argc, argv, env);
                    return err;
                default:
                    LOGGER_IS_LOGGED_ERROR("...unexpected s = " << int_to_string(s));
                    return err = 1;
                }
                break;
            default:
                LOGGER_IS_LOGGED_INFO("...default:");
                s = ch;
                break;
            }
        }
        return err;
    }
    /// ...<cr><lf><cr><lf>
    virtual int on_read_text_literal_crlf2(literal_string_t& r, char_t& c, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("!(err = set_prepare_read_text_literal_crlf2(argc, argv, env))...");
        if (!(err = set_prepare_read_text_literal_crlf2(argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = set_prepare_read_text_literal_crlf2(argc, argv, env))");

            LOGGER_IS_LOGGED_INFO("!(err = prepare_read_text_literal_crlf2_set(argc, argv, env))...");
            if (!(err = prepare_read_text_literal_crlf2_set(argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...!(" << err << " = prepare_read_text_literal_crlf2_set(argc, argv, env))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed !(" << err << " = prepare_read_text_literal_crlf2_set(argc, argv, env))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed !(" << err << " = set_prepare_read_text_literal_crlf2(argc, argv, env))");
        }
        return err;
    }
    virtual int read_text_literal_crlf2(literal_string_t& r, char_t& c, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        ssize_t amount = 0;
        enum { ch, cr, crlf, crlfcr } s = ch;

        while (0 < (amount = reader.read(&c, 1))) {
            r.append(&c, 1);
            switch (c) {
            case '\r':
                LOGGER_IS_LOGGED_INFO("...case '\\r':");
                switch (s) {
                case ch:
                    s = cr;
                    break;
                case cr:
                    s = cr;
                    break;
                case crlf:
                    s = crlfcr;
                    break;
                case crlfcr:
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
                case crlf:
                    s = ch;
                    break;
                case cr:
                    s = crlf;
                    break;
                case crlfcr:
                    LOGGER_IS_LOGGED_INFO("err = on_read_text_literal_crlf2(r, c, reader, argc, argv, env)...");
                    err = on_read_text_literal_crlf2(r, c, reader, argc, argv, env);
                    return err;
                default:
                    LOGGER_IS_LOGGED_ERROR("...unexpected s = " << int_to_string(s));
                    return err = 1;
                }
                break;
            default:
                LOGGER_IS_LOGGED_INFO("...default:");
                s = ch;
                break;
            }
        }
        return err;
    }
    /// ...[size]
    virtual int on_read_text_literal_size(literal_string_t& r, char_t& c, reader_t& reader, const size_t& size, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("set_text_literal_size(" << size << ")...");
        set_text_literal_size(size);
        return err;
    }
    virtual int read_text_literal_size(literal_string_t& r, char_t& c, reader_t& reader, const size_t& size, int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t size_of = 0;
        ssize_t amount = 0;
        for (size_of = size; size_of; --size_of) {
            if (0 < (amount = reader.read(&c, 1))) {
                r.append(&c, 1);
            } else {
                LOGGER_IS_LOGGED_ERROR("...failed on (0 < (" << amount << " = reader.read(&c, 1)))");
                return err = 1;
            }
        } /// for (; size; --size)
        LOGGER_IS_LOGGED_INFO("err = on_read_text_literal_size(r, c, reader, " << size << ", argc, argv, env)...");
        if (!(err = on_read_text_literal_size(r, c, reader, size, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(err = on_read_text_literal_size(r, c, reader, " << size << ", argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(err = on_read_text_literal_size(r, c, reader, " << size << ", argc, argv, env)))");
        }
        return err;
    }
    /// ...
    /// ...read...
    ///////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...literal_string...
    virtual literal_string_t& literal_string_input() const {
        return (literal_string_t&)literal_string_input_;
    }
    virtual literal_string_t& literal_string_read() const {
        return (literal_string_t&)literal_string_read_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...hello_request
    virtual string_t& set_hello_request(const string_t& to) {
        string_t& hello_request = this->hello_request();
        hello_request.assign(to);
        return hello_request;
    }
    virtual string_t& set_hello_request(const char_t* to) {
        string_t& hello_request = this->hello_request();
        hello_request.assign(to);
        return hello_request;
    }
    virtual string_t& set_hello_request(const char_t* to, size_t length) {
        string_t& hello_request = this->hello_request();
        hello_request.assign(to, length);
        return hello_request;
    }
    virtual string_t& hello_request() const {
        return (string_t&)hello_request_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...hello_response
    virtual string_t& set_hello_response(const string_t& to) {
        string_t& hello_response = this->hello_response();
        hello_response.assign(to);
        return hello_response;
    }
    virtual string_t& set_hello_response(const char_t* to, size_t length) {
        string_t& hello_response = this->hello_response();
        hello_response.assign(to, length);
        return hello_response;
    }
    virtual string_t& set_hello_response(const char_t* to) {
        string_t& hello_response = this->hello_response();
        hello_response.assign(to);
        return hello_response;
    }
    virtual string_t& hello_response() const {
        return (string_t&)hello_response_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...restart_request
    virtual string_t& set_to_restart_request() {
        const string_t& restart_request = this->restart_request();
        string_t& request = this->request();
        request.assign(restart_request);
        return request;
    }
    virtual string_t& set_restart_request(const string_t& to) {
        string_t& restart_request = this->restart_request();
        restart_request.assign(to);
        return restart_request;
    }
    virtual string_t& set_restart_request(const char_t* to) {
        string_t& restart_request = this->restart_request();
        restart_request.assign(to);
        return restart_request;
    }
    virtual string_t& set_restart_request(const char_t* to, size_t length) {
        string_t& restart_request = this->restart_request();
        restart_request.assign(to, length);
        return restart_request;
    }
    virtual string_t& restart_request() const {
        return (string_t&)restart_request_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...restart_response
    virtual string_t& set_restart_response(const string_t& to) {
        string_t& restart_response = this->restart_response();
        restart_response.assign(to);
        return restart_response;
    }
    virtual string_t& set_restart_response(const char_t* to, size_t length) {
        string_t& restart_response = this->restart_response();
        restart_response.assign(to, length);
        return restart_response;
    }
    virtual string_t& set_restart_response(const char_t* to) {
        string_t& restart_response = this->restart_response();
        restart_response.assign(to);
        return restart_response;
    }
    virtual string_t& restart_response() const {
        return (string_t&)restart_response_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...start_request
    virtual string_t& set_to_start_request() {
        const string_t& start_request = this->start_request();
        string_t& request = this->request();
        request.assign(start_request);
        return request;
    }
    virtual string_t& set_start_request(const string_t& to) {
        string_t& start_request = this->start_request();
        start_request.assign(to);
        return start_request;
    }
    virtual string_t& set_start_request(const char_t* to) {
        string_t& start_request = this->start_request();
        start_request.assign(to);
        return start_request;
    }
    virtual string_t& set_start_request(const char_t* to, size_t length) {
        string_t& start_request = this->start_request();
        start_request.assign(to, length);
        return start_request;
    }
    virtual string_t& start_request() const {
        return (string_t&)start_request_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...start_response
    virtual string_t& set_start_response(const string_t& to) {
        string_t& start_response = this->start_response();
        start_response.assign(to);
        return start_response;
    }
    virtual string_t& set_start_response(const char_t* to, size_t length) {
        string_t& start_response = this->start_response();
        start_response.assign(to, length);
        return start_response;
    }
    virtual string_t& set_start_response(const char_t* to) {
        string_t& start_response = this->start_response();
        start_response.assign(to);
        return start_response;
    }
    virtual string_t& start_response() const {
        return (string_t&)start_response_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...stop_request
    virtual string_t& set_to_stop_request() {
        const string_t& stop_request = this->stop_request();
        string_t& request = this->request();
        request.assign(stop_request);
        return request;
    }
    virtual string_t& set_stop_request(const string_t& to) {
        string_t& stop_request = this->stop_request();
        stop_request.assign(to);
        return stop_request;
    }
    virtual string_t& set_stop_request(const char_t* to) {
        string_t& stop_request = this->stop_request();
        stop_request.assign(to);
        return stop_request;
    }
    virtual string_t& set_stop_request(const char_t* to, size_t length) {
        string_t& stop_request = this->stop_request();
        stop_request.assign(to, length);
        return stop_request;
    }
    virtual string_t& stop_request() const {
        return (string_t&)stop_request_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...stop_response
    virtual string_t& set_stop_response(const string_t& to) {
        string_t& stop_response = this->stop_response();
        stop_response.assign(to);
        return stop_response;
    }
    virtual string_t& set_stop_response(const char_t* to, size_t length) {
        string_t& stop_response = this->stop_response();
        stop_response.assign(to, length);
        return stop_response;
    }
    virtual string_t& set_stop_response(const char_t* to) {
        string_t& stop_response = this->stop_response();
        stop_response.assign(to);
        return stop_response;
    }
    virtual string_t& stop_response() const {
        return (string_t&)stop_response_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...unknown_request
    virtual string_t& set_unknown_request(const string_t& to) {
        string_t& unknown_request = this->unknown_request();
        unknown_request.assign(to);
        return unknown_request;
    }
    virtual string_t& set_unknown_request(const char_t* to) {
        string_t& unknown_request = this->unknown_request();
        unknown_request.assign(to);
        return unknown_request;
    }
    virtual string_t& set_unknown_request(const char_t* to, size_t length) {
        string_t& unknown_request = this->unknown_request();
        unknown_request.assign(to, length);
        return unknown_request;
    }
    virtual string_t& unknown_request() const {
        return (string_t&)unknown_request_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...unknown_response
    virtual string_t& set_unknown_response(const string_t& to) {
        string_t& unknown_response = this->unknown_response();
        unknown_response.assign(to);
        return unknown_response;
    }
    virtual string_t& set_unknown_response(const char_t* to, size_t length) {
        string_t& unknown_response = this->unknown_response();
        unknown_response.assign(to, length);
        return unknown_response;
    }
    virtual string_t& set_unknown_response(const char_t* to) {
        string_t& unknown_response = this->unknown_response();
        unknown_response.assign(to);
        return unknown_response;
    }
    virtual string_t& unknown_response() const {
        return (string_t&)unknown_response_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...request
    virtual string_t& set_request(const string_t& to) {
        string_t& request = this->request();
        request.assign(to);
        return request;
    }
    virtual string_t& set_request(const char_t* to) {
        string_t& request = this->request();
        request.assign(to);
        return request;
    }
    virtual string_t& set_request(const char_t* to, size_t length) {
        string_t& request = this->request();
        request.assign(to, length);
        return request;
    }
    virtual string_t& request() const {
        return (string_t&)request_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...response
    virtual string_t& set_response(const string_t& to) {
        string_t& response = this->response();
        response.assign(to);
        return response;
    }
    virtual string_t& set_response(const char_t* to, size_t length) {
        string_t& response = this->response();
        response.assign(to, length);
        return response;
    }
    virtual string_t& set_response(const char_t* to) {
        string_t& response = this->response();
        response.assign(to);
        return response;
    }
    virtual string_t& response() const {
        return (string_t&)response_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...response_to_output
    virtual string_t& set_response_to_output(const string_t& to) {
        string_t& response = this->response_to_output();
        response.assign(to);
        return response;
    }
    virtual string_t& set_response_to_output(const char_t* to, size_t length) {
        string_t& response = this->response_to_output();
        response.assign(to, length);
        return response;
    }
    virtual string_t& set_response_to_output(const char_t* to) {
        string_t& response = this->response_to_output();
        response.assign(to);
        return response;
    }
    virtual string_t& response_to_output() const {
        return (string_t&)response_to_output_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...response_to_process
    virtual string_t& set_response_to_process(const string_t& to) {
        string_t& response = this->response_to_process();
        response.assign(to);
        return response;
    }
    virtual string_t& set_response_to_process(const char_t* to, size_t length) {
        string_t& response = this->response_to_process();
        response.assign(to, length);
        return response;
    }
    virtual string_t& set_response_to_process(const char_t* to) {
        string_t& response = this->response_to_process();
        response.assign(to);
        return response;
    }
    virtual string_t& response_to_process() const {
        return (string_t&)response_to_process_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...restart
    virtual bool& set_restart(const bool& to) {
        bool& restart = this->restart();
        restart = to;
        return restart;
    }
    virtual bool& restart_set(const bool& to) {
        bool& restart = this->restart();
        return restart;
    }
    virtual const bool& get_restart() const {
        return this->restart();
    }
    virtual bool& restart() const {
        bool& restart = (bool&)restart_;
        return restart;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...stop
    virtual bool& set_stop(const bool& to) {
        bool& stop = this->stop();
        stop = to;
        return stop;
    }
    virtual bool& stop_set(const bool& to) {
        bool& stop = this->stop();
        return stop;
    }
    virtual const bool& get_stop() const {
        return this->stop();
    }
    virtual bool& stop() const {
        bool& stop = (bool&)stop_;
        return stop;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    virtual const string_t& endof_request() const {
        const string_t& endof_request = this->endof_message();
        return endof_request;
    }
    virtual const string_t& endof_response() const {
        const string_t& endof_response = this->endof_message();
        return endof_response;
    }
    virtual const string_t& endof_message() const {
        const string_t& endof_message = this->crlf2_endof_message();
        return endof_message;
    }
    virtual const string_t& crlf2_endof_message() const {
        const string_t& endof_message = this->crlf2();
        return endof_message;
    }
    virtual const string_t& crlf_endof_message() const {
        const string_t& endof_message = this->crlf();
        return endof_message;
    }
    virtual const string_t& cr_endof_message() const {
        const string_t& endof_message = this->cr();
        return endof_message;
    }
    virtual const string_t& lf_endof_message() const {
        const string_t& endof_message = this->lf();
        return endof_message;
    }
    virtual const string_t& no_endof_message() const {
        const string_t& endof_message = this->null_lf();
        return endof_message;
    }
    //////////////////////////////////////////////////////////////////////////
    
    //////////////////////////////////////////////////////////////////////////
    virtual size_t& set_text_literal_sized_size(const size_t& to) {
        size_t& text_literal_sized_size = this->text_literal_sized_size();
        text_literal_sized_size = to;
        return text_literal_sized_size;
    }
    virtual size_t& text_literal_sized_size() const {
        return (size_t&)text_literal_sized_size_;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual size_t& set_text_literal_size(const size_t& to) {
        size_t& text_literal_size = this->text_literal_size();
        text_literal_size = to;
        return text_literal_size;
    }
    virtual size_t& text_literal_size() const {
        return (size_t&)text_literal_size_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
protected:
    size_t text_literal_sized_size_, text_literal_size_;
    bool restart_, stop_;
    string_t hello_request_, hello_response_, 
             restart_request_, restart_response_, 
             start_request_, start_response_, 
             stop_request_, stop_response_, 
             unknown_request_, unknown_response_, 
             request_, response_, response_to_output_, response_to_process_;
    literal_string_t literal_string_input_, literal_string_read_;
}; /// class maint 
typedef maint<> main;

} /// namespace base 
} /// namespace protocol 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_PROTOCOL_BASE_MAIN_HPP

