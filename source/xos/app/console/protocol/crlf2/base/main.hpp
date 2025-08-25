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
///   Date: 3/1/2025
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_PROTOCOL_CRLF2_BASE_MAIN_HPP
#define XOS_APP_CONSOLE_PROTOCOL_CRLF2_BASE_MAIN_HPP

#include "xos/app/console/protocol/crlf2/base/main_opt.hpp"

namespace xos {
namespace app {
namespace console {
namespace protocol {
namespace crlf2 {
namespace base {

/// class maint
template 
<class TExtends = xos::app::console::protocol::crlf2::base::main_optt<>,  class TImplements = typename TExtends::implements>

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
    /// ...read_text_literal
    virtual int default_read_text_literal(literal_string_t& literal, reader_t& reader, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("(!(err = this->all_crlf2_read_text_literal(literal, reader, argc, argv, env)))...");
        if (!(err = this->all_crlf2_read_text_literal(literal, reader, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...(!(" << err << " = this->all_crlf2_read_text_literal(\"" << literal << "\", reader, argc, argv, env)))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on(!(" << err << " = this->all_crlf2_read_text_literal(literal, reader, argc, argv, env)))");
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    /// ...prepare_read_text_literal...
    virtual int prepare_read_text_literal_endof(literal_string_t& literal, int argc, char_t** argv, char_t** env) {
        int err = 0;
        LOGGER_IS_LOGGED_INFO("!(err = this->prepare_read_text_literal_crlf2(\"" << literal << "\", argc, argv, env))...");
        if (!(err = this->prepare_read_text_literal_crlf2(literal, argc, argv, env))) {
            LOGGER_IS_LOGGED_INFO("...!(" << err << " = this->prepare_read_text_literal_crlf2(\"" << literal << "\", argc, argv, env))");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed !(" << err << " = this->prepare_read_text_literal_crlf2(\"" << literal << "\", argc, argv, env))");
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...output_message_run
    virtual int default_output_message_run(string_t& msg, int argc, char_t** argv, char_t** env) {
        int err = 0;
        const string_t& crlf2_endof_message = this->crlf2_endof_message();
        LOGGER_IS_LOGGED_INFO("this->out(\"" << msg << "\")...");
        this->out(msg);
        LOGGER_IS_LOGGED_INFO("this->out(\"" << crlf2_endof_message << "\")...");
        this->out(crlf2_endof_message);
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
protected:
}; /// class maint 
typedef maint<> main;

} /// namespace base 
} /// namespace crlf2 
} /// namespace protocol 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_PROTOCOL_CRLF2_BASE_MAIN_HPP

