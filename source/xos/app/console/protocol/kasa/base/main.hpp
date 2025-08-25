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
///   Date: 6/11/2025
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_PROTOCOL_KASA_BASE_MAIN_HPP
#define XOS_APP_CONSOLE_PROTOCOL_KASA_BASE_MAIN_HPP

#include "xos/app/console/protocol/kasa/base/main_opt.hpp"

namespace xos {
namespace app {
namespace console {
namespace protocol {
namespace kasa {
namespace base {

/// class maint
template 
<class TExtends = xos::app::console::protocol::kasa::base::main_optt<>,  class TImplements = typename TExtends::implements>

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
      
      power_on_request_("{\"system\":{\"set_relay_state\":{\"state\":1}}}"), 
      power_off_request_("{\"system\":{\"set_relay_state\":{\"state\":0}}}"),
      power_request_("{\"system\":{\"get_sysinfo\":null}}"),

      power_on_response_("{\"system\":{\"relay_state\":{\"state\":1}}}"), 
      power_off_response_("{\"system\":{\"relay_state\":{\"state\":0}}}"),
      power_response_("{\"system\":{\"sysinfo\":null}}") {
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
    /// ...prepare_response_to_unknown_request_run
    virtual int prepare_response_to_unknown_request_run(string_t& response, const string_t& request, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = extends::prepare_response_to_unknown_request_run(response, request, argc, argv, env)))...");
        if (!(err = extends::prepare_response_to_unknown_request_run(response, request, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << "  = extends::prepare_response_to_unknown_request_run(response, request, argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on (!(" << err << "  = extends::prepare_response_to_unknown_request_run(response, request, argc, argv, env)))");
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...prepare_message_to_output_run
    virtual int default_prepare_message_to_output_run(string_t& msg, int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* chars = 0;
        size_t length = 0;        
        string_t& encrypted = this->encrypt_text(msg);
        LOGGER_IS_LOGGED_INFO("((chars = encrypted.has_chars(length)))...");
        if ((chars = encrypted.has_chars(length))) {
            LOGGER_IS_LOGGED_INFO("...((chars = encrypted.has_chars(" << length << ")))");
            LOGGER_IS_LOGGED_INFO("msg.assign(chars, " << length << ")...");
            msg.assign(chars, length);
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on ((chars = encrypted.has_chars(" << length << ")))");
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...[size]
    virtual int prepare_read_text_literal_size(literal_string_t& literal, const size_t& size, int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* chars = 0;
        size_t length = 0;
        string_t& decrypted = decrypt_text(literal);
        LOGGER_IS_LOGGED_INFO("((chars = decrypted.has_chars(length)))...");
        if ((chars = decrypted.has_chars(length))) {
            LOGGER_IS_LOGGED_INFO("...((\"" << chars << "\" = decrypted.has_chars(" << length << ")))");
            LOGGER_IS_LOGGED_INFO("literal.assign(\"" << chars << "\", " << length << ")...");
            literal.assign(chars, length);
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on ((chars = decrypted.has_chars(" << length << ")))");
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...decrypt_text
    virtual string_t& decrypt_text(const string_t& cipher) {
        string_t& decrypted = this->plain_text();
        const char_t* chars = 0;
        size_t length = 0;

        decrypted.clear();
        LOGGER_IS_LOGGED_INFO("((chars = cipher.has_chars(length)) && (4 < " << length << "))...");
        if ((chars = cipher.has_chars(length)) && (4 < length)) {
            char_t a = 0, i = 0, k = 0;
            LOGGER_IS_LOGGED_INFO("...((chars = cipher.has_chars(" << length << ")) && (4 < " << length << "))");
            LOGGER_IS_LOGGED_INFO("(k = 171, chars += 4, length -= 4; " << length << "; --length, ++chars) {...");
            for (k = 171, chars += 4, length -= 4; length; --length, ++chars) {
                i = *chars;
                a = k ^ i;
                k = i;
                decrypted.append(&a, 1);
            }
            LOGGER_IS_LOGGED_INFO("...} (k = 171, chars += 4, length -= 4; length; --length, ++chars)");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on ((chars = cipher.has_chars(" << length << ")) && (4 < " << length << "))");
        }
        return decrypted;
    }
    /// ...encrypt_text
    virtual string_t& encrypt_text(const string_t& plain) {
        string_t& encrypted = this->cipher_text();
        const char_t* chars = 0;
        size_t length = 0;

        encrypted.clear();
        LOGGER_IS_LOGGED_INFO("((chars = plain.has_chars(length)))...");
        if ((chars = plain.has_chars(length))) {
            char_t a = 0, i = 0, k = 0;
            size_t lsb = length, msb = 0, remain = 0;
            LOGGER_IS_LOGGED_INFO("...((\"" << chars << "\" = plain.has_chars(" << length << ")))");
            LOGGER_IS_LOGGED_INFO("for (remain = 4; remain; --remain) {...");
            for (remain = 4; remain; --remain) {
                msb = (msb << 8) | (lsb & 255);
                lsb = (lsb >> 8);
            }
            LOGGER_IS_LOGGED_INFO("...} for (remain = 4; remain; --remain)");
            LOGGER_IS_LOGGED_INFO("for (remain = 4; remain; --remain) {...");
            for (remain = 4; remain; --remain) {
                i = (char_t)(msb & 255);
                msb = (msb >> 8);
                encrypted.append(&i, 1);
            }
            LOGGER_IS_LOGGED_INFO("...} for (remain = 4; remain; --remain)");
            LOGGER_IS_LOGGED_INFO("for (k = 171; " << length << "; --length, ++chars) {...");
            for (k = 171; length; --length, ++chars) {
                i = *chars;
                a = k ^ i;
                k = a;
                encrypted.append(&a, 1);
            }
            LOGGER_IS_LOGGED_INFO("...} for (k = 171; length; --length, ++chars)");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on ((chars = plain.has_chars(" << length << ")))");
        }
        return encrypted;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...power...request
    virtual string_t& power_on_request() const {
        return (string_t&)power_on_request_;
    }
    virtual string_t& power_off_request() const {
        return (string_t&)power_off_request_;
    }
    virtual string_t& power_request() const {
        return (string_t&)power_request_;
    }
    /// ...power...response
    virtual string_t& power_on_response() const {
        return (string_t&)power_on_response_;
    }
    virtual string_t& power_off_response() const {
        return (string_t&)power_off_response_;
    }
    virtual string_t& power_response() const {
        return (string_t&)power_response_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...text
    virtual string_t& cipher_text() const {
        return (string_t&)cipher_text_;
    }
    virtual string_t& plain_text() const {
        return (string_t&)plain_text_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
protected:
    string_t power_on_request_, power_off_request_, power_request_;
    string_t power_on_response_, power_off_response_, power_response_;    
    string_t cipher_text_, plain_text_;
}; /// class maint 
typedef maint<> main;

} /// namespace base 
} /// namespace kasa 
} /// namespace protocol 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_PROTOCOL_KASA_BASE_MAIN_HPP
