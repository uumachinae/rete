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
///   Date: 10/20/2024, 5/13/2025
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_PROTOCOL_JSON_BASE_MAIN_HPP
#define XOS_APP_CONSOLE_PROTOCOL_JSON_BASE_MAIN_HPP

#include "xos/app/console/protocol/json/base/main_opt.hpp"
#include "xos/io/format/json/libjson/to_node.hpp"

namespace xos {
namespace app {
namespace console {
namespace protocol {
namespace json {
namespace base {

/// class maint
template 
<class TExtends = xos::app::console::protocol::json::base::main_optt<>,  class TImplements = typename TExtends::implements>

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
    typedef typename extends::literal_string_t literal_string_t;

    typedef xos::io::format::json::libjson::to_node to_json_node_t;
    typedef xos::io::format::json::node json_node_t;

    /// constructor / destructor
    maint()
    : run_(0), 
      
      hello_request_("{\"system\":{\"action\":\"hello\"}}"),
      hello_response_(hello_request_),
    
      restart_request_("{\"system\":{\"action\":\"restart\"}}"),
      restart_response_(restart_request_),
    
      stop_request_("{\"system\":{\"action\":\"stop\"}}"),
      stop_response_(stop_request_),
    
      unknown_request_("{\"system\":{\"request\":\"unknown\"}}"),
      unknown_response_("{\"system\":{\"response\":\"unknown\"}}"),
    
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
            err = (this->*run_)(argc, argv, env);
        } else {
            err = extends::run(argc, argv, env);
        }
        return err;
    }

    //////////////////////////////////////////////////////////////////////////
    /// ...process_json_node_run
    virtual int process_json_node_run(const json_node_t& json_node, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_process_json_node_run(const json_node_t& json_node, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_json_node_run(const json_node_t& json_node, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_json_node_run(const json_node_t& json_node, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_process_json_node_run(json_node, argc, argv, env))) {
            int err2 = 0;
            err = process_json_node_run(json_node, argc, argv, env);
            if ((err2 = after_process_json_node_run(json_node, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...process_json_node_response_run
    virtual int process_json_node_response_run
    (string_t& response, const json_node_t& json_node, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_process_json_node_response_run
    (string_t& response, const json_node_t& json_node, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_json_node_response_run
    (string_t& response, const json_node_t& json_node, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_json_node_response_run
    (string_t& response, const json_node_t& json_node, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_process_json_node_response_run(response, json_node, argc, argv, env))) {
            int err2 = 0;
            err = process_json_node_response_run(response, json_node, argc, argv, env);
            if ((err2 = after_process_json_node_response_run(response, json_node, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...prepare_to_process_unknown_response_run
    virtual int default_prepare_to_process_unknown_response_run(string_t& response, int argc, char_t** argv, char_t** env) {
        int err = 0;
        string_t& json_response = this->json_response();
        LOGGER_IS_LOGGED_INFO("json_response.assign(\"" << response << "\")...");
        json_response.assign(response);
        LOGGER_IS_LOGGED_INFO("(!(err = extends::default_prepare_to_process_unknown_response_run(response, argc, argv, env)))...");
        if (!(err = extends::default_prepare_to_process_unknown_response_run(response, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = extends::default_prepare_to_process_unknown_response_run(response, argc, argv, env)))");
            to_json_node_t to_json_node;
            json_node_t json_node;
            
            LOGGER_IS_LOGGED_INFO("to_json_node.to(json_node, \"" << json_response << "\")...");
            to_json_node.to(json_node, json_response);
            LOGGER_IS_LOGGED_INFO("...to_json_node.to(json_node, \"" << json_response << "\")");
            LOGGER_IS_LOGGED_INFO("!(err = all_process_json_node_response_run(\"" << json_response << "\", json_node, argc, argv, env))...");
            if (!(err = all_process_json_node_response_run(json_response, json_node, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_process_json_node_response_run(\"" << json_response << "\", json_node, argc, argv, env))");
                LOGGER_IS_LOGGED_INFO("(0 < (json_response.length()))...");
                if (0 < (json_response.length())) {
                    LOGGER_IS_LOGGED_INFO("...(0 < (json_response.length()))");
                    LOGGER_IS_LOGGED_INFO("response.assign(\"" << json_response << "\")...");
                    response.assign(json_response);
                } else {
                    LOGGER_IS_LOGGED_INFO("...failed on (0 < (json_response.length()))");
                }
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = all_process_json_node_response_run(\"" << json_response << "\", json_node, argc, argv, env))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = extends::default_prepare_to_process_unknown_response_run(response, argc, argv, env)))");
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...prepare_response_to_json_node_request_run
    virtual int prepare_response_to_json_node_request_run
    (string_t& response, const string_t& request, const json_node_t& json_node, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_prepare_response_to_json_node_request_run
    (string_t& response, const string_t& request, const json_node_t& json_node, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_response_to_json_node_request_run
    (string_t& response, const string_t& request, const json_node_t& json_node, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_response_to_json_node_request_run
    (string_t& response, const string_t& request, const json_node_t& json_node, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_response_to_json_node_request_run(response, request, json_node, argc, argv, env))) {
            int err2 = 0;
            err = prepare_response_to_json_node_request_run(response, request, json_node, argc, argv, env);
            if ((err2 = after_prepare_response_to_json_node_request_run(response, request, json_node, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...prepare_response_to_unknown_request_run
    virtual int default_prepare_response_to_unknown_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = extends::default_prepare_response_to_unknown_request_run(response, request, argc, argv, env)))...");
        if (!(err = extends::default_prepare_response_to_unknown_request_run(response, request, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = extends::default_prepare_response_to_unknown_request_run(response, request, argc, argv, env)))");
            to_json_node_t to_json_node;
            json_node_t json_node;
            
            LOGGER_IS_LOGGED_INFO("to_json_node.to(json_node, \"" << request << "\")...");
            to_json_node.to(json_node, request);
            LOGGER_IS_LOGGED_INFO("...to_json_node.to(json_node, \"" << request << "\")");
            LOGGER_IS_LOGGED_INFO("!(err = all_prepare_response_to_json_node_request_run(response, \"" << request << "\", json_node, argc, argv, env))...");
            if (!(err = all_prepare_response_to_json_node_request_run(response, request, json_node, argc, argv, env))) {
                LOGGER_IS_LOGGED_INFO("...!(" << err << " = all_prepare_response_to_json_node_request_run(response, \"" << request << "\", json_node, argc, argv, env))");
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on !(" << err << " = all_prepare_response_to_json_node_request_run(response, \"" << request << "\", json_node, argc, argv, env))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = extends::default_prepare_response_to_unknown_request_run(response, request, argc, argv, env)))");
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...hello_request
    virtual string_t& set_system_hello_request() {
        return set_to_hello_request();
    }
    virtual string_t& set_to_hello_request() {
        const string_t &hello_request = this->hello_request();
        string_t &request = this->request();
        request.assign(hello_request);
        return request;
    }
    virtual string_t& hello_request() const {
        return (string_t&)hello_request_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...hello_response
    virtual string_t& hello_response() const {
        return (string_t&)hello_response_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...restart_request
    virtual string_t& set_system_restart_request() {
        return set_to_restart_request();
    }
    virtual string_t& set_to_restart_request() {
        const string_t &restart_request = this->restart_request();
        string_t &request = this->request();
        request.assign(restart_request);
        return request;
    }
    virtual string_t& restart_request() const {
        return (string_t&)restart_request_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...restart_response
    virtual string_t& restart_response() const {
        return (string_t&)restart_response_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...start_request
    virtual string_t& set_system_start_request() {
        return set_to_start_request();
    }
    virtual string_t& set_to_start_request() {
        const string_t &start_request = this->start_request();
        string_t &request = this->request();
        request.assign(start_request);
        return request;
    }
    virtual string_t& start_request() const {
        return (string_t&)restart_request_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...start_response
    virtual string_t& start_response() const {
        return (string_t&)restart_response_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...stop_request
    virtual string_t& set_system_stop_request() {
        return set_to_stop_request();
    }
    virtual string_t& set_to_stop_request() {
        const string_t &stop_request = this->stop_request();
        string_t &request = this->request();
        request.assign(stop_request);
        return request;
    }
    virtual string_t& stop_request() const {
        return (string_t&)stop_request_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...stop_response
    virtual string_t& stop_response() const {
        return (string_t&)stop_response_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...unknown_request
    virtual string_t& set_system_unknown_request() {
        return set_to_unknown_request();
    }
    virtual string_t& set_to_unknown_request() {
        const string_t &unknown_request = this->unknown_request();
        string_t &request = this->request();
        request.assign(unknown_request);
        return request;
    }
    virtual string_t& unknown_request() const {
        return (string_t&)unknown_request_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...unknown_response
    virtual string_t& set_system_unknown_response() {
        return set_to_unknown_response();
    }
    virtual string_t& set_to_unknown_response() {
        const string_t &unknown_response = this->unknown_response();
        string_t &response = this->response();
        response.assign(unknown_response);
        return response;
    }
    virtual string_t& unknown_response() const {
        return (string_t&)unknown_response_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...request
    virtual string_t& request() const {
        return (string_t&)request_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...response
    virtual string_t& response() const {
        return (string_t&)response_;
    }
    virtual string_t& json_response() const {
        return (string_t&)json_response_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
protected:
    string_t hello_request_, hello_response_, 
             restart_request_, restart_response_, 
             stop_request_, stop_response_, 
             unknown_request_, unknown_response_, 
             request_, response_, json_response_;
}; /// class maint 
typedef maint<> main;

} /// namespace base 
} /// namespace json 
} /// namespace protocol 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_PROTOCOL_JSON_BASE_MAIN_HPP

