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
///   Date: 11/13/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_HPP
#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_HPP

#include "xos/app/console/network/universal/unique/identifier/main_opt.hpp"
#include "xos/network/ethernet/actual/address_from_string.hpp"
#include "xos/network/ethernet/actual/address_to_string.hpp"
#include "xos/network/ethernet/actual/address.hpp"
#include "xos/network/ethernet/address.hpp"

namespace xos {
namespace app {
namespace console {
namespace network {
namespace universal {
namespace unique {
namespace identifier {

/// class maint
template 
<class TExtends = xos::app::console::network::universal::unique::identifier::main_optt<>,  class TImplements = typename TExtends::implements>

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

    typedef xos::network::ethernet::address ethernet_address_t;
    typedef xos::network::ethernet::address::string_t ethernet_address_string_t;
    typedef xos::network::ethernet::actual::address ethernet_actual_address_t;
    typedef xos::network::ethernet::actual::address_from_string ethernet_actual_address_from_string_t;
    typedef xos::network::ethernet::actual::address_to_string ethernet_actual_address_to_string_t;

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
    /// ...output_ethernet_interface_addressed_run
    virtual int default_output_ethernet_interface_addressed_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = this->all_output_ethernet_address_uuid_run(argc, argv, env))) {
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...output_ethernet_address_named_run
    virtual int default_output_ethernet_address_named_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = this->all_output_ethernet_address_uuid_run(argc, argv, env))) {
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...output_ethernet_address_numbered_run
    virtual int default_output_ethernet_address_numbered_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = this->all_output_ethernet_address_uuid_run(argc, argv, env))) {
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...output_ethernet_address_run
    virtual int default_output_ethernet_address_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const bool output_lf = this->output_lf();
        const ethernet_actual_address_t& interface_address = this->interface_address();
        size_t length = 0;

        LOGGER_IS_LOGGED_INFO("(0 < (length = interface_address.size()))...");
        if (0 < (length = interface_address.size())) {
            ethernet_actual_address_to_string_t address_string(interface_address, this->is_logged());

            LOGGER_IS_LOGGED_INFO("...(0 < (length = interface_address.size()))");
            LOGGER_IS_LOGGED_INFO("(0 < (address_string.length()))...");
            if (0 < (address_string.length())) {
                LOGGER_IS_LOGGED_INFO("...(0 < (address_string.length()))");
                LOGGER_IS_LOGGED_INFO("this->out(address_string)...");
                this->out(address_string);
                if ((output_lf)) {
                    LOGGER_IS_LOGGED_INFO("this->outln()...");
                    this->outln();
                }
            } else {
                const uint8_t *byte = 0;

                LOGGER_IS_LOGGED_INFO("...failed on (0 < (address_string.length()))");
                for (byte = &interface_address.element(); 0 < length; --length, ++byte) {
                    LOGGER_IS_LOGGED_INFO("this->outX(" << (unsigned)(*byte) << ", 1)...");
                    this->outX(byte, 1);
                    if ((1 < length)) {
                        LOGGER_IS_LOGGED_INFO("this->out(\":\")...");
                        this->out(":");
                    } else {
                        if ((output_lf)) {
                            LOGGER_IS_LOGGED_INFO("this->outln()...");
                            this->outln();
                        }
                    }
                }
            }
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...output_ethernet_address_name_run
    virtual int default_output_ethernet_address_name_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const bool output_lf = this->output_lf();
        const string_t& interface_name = this->interface_name();
        this->out(interface_name);
        if ((output_lf)) {
            this->outln();
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...output_ethernet_address_number_run
    virtual int default_output_ethernet_address_number_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const bool output_lf = this->output_lf();
        const unsigned& interface_number = this->interface_number();
        this->out(unsigned_to_string(interface_number));
        if ((output_lf)) {
            this->outln();
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// on...ethernet_number_option...
    virtual int on_set_ethernet_number_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_number_option(optarg, optind, argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...ethernet_name_option...
    virtual int on_set_ethernet_name_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_name_option(optarg, optind, argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...ethernet_address_option...
    virtual int on_set_ethernet_address_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_address_option(optarg, optind, argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// on...address_option...
    virtual int on_set_address_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            const char_t* chars = 0; size_t length = 0;
            string_t arg(optarg);
            
            LOGGER_IS_LOGGED_INFO("((chars = arg.has_chars(length)))...");
            if ((chars = arg.has_chars(length))) {
                LOGGER_IS_LOGGED_INFO("...((\"" << chars << "\" = arg.has_chars(" << length << ")))");
                LOGGER_IS_LOGGED_INFO("set_interface_address_string(\"" << arg << "\")...");
                set_interface_address_string(arg);
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on ((chars = arg.has_chars(length)))");
            }
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...number_option...
    virtual int on_set_number_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            string_t arg(optarg);
            unsigned interface_number = arg.to_unsigned();
            set_interface_number(interface_number);
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...name_option...
    virtual int on_set_name_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_interface_name(optarg);
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// on...ethernet_option...
    virtual int on_set_ethernet_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;

        if ((optarg) && (optarg[0])) {
            const char_t* chars = 0;
            size_t length = 0;
            string_t arg(optarg);
            
            if ((chars = arg.has_chars(length))) {
                enum { number, name, address };
                char_t c = 0; int s = 0;
                
                for (s = number; 0 < length; --length) {
                    c = *(chars++);
                    switch(s) {

                    case name:
                        break;

                    case address:
                        if (!(('9' >= (c)) && ('0' <= (c)))) {
                            if (!(('F' >= (c)) && ('A' <= (c)))) {
                                if (!(('f' >= (c)) && ('a' <= (c)))) {
                                    if (!((':' >= (c)) && (':' <= (c)))) {
                                        s = name;
                                    } else {
                                    }
                                } else {
                                }
                            } else {
                            }
                        } else {
                        }
                        break;

                    case number:
                    default:
                        if (!(('9' >= (c)) && ('0' <= (c)))) {
                            if (!(('F' >= (c)) && ('A' <= (c)))) {
                                if (!(('f' >= (c)) && ('a' <= (c)))) {
                                    if (!((':' >= (c)) && (':' <= (c)))) {
                                        s = name;
                                    } else {
                                        s = address;
                                    }
                                } else {
                                    s = address;
                                }
                            } else {
                                s = address;
                            }
                        } else {
                        }
                        break;
                    }
                }
                switch(s) {
                case address:
                    if (!(err = this->on_set_ethernet_address_option(optarg, optind, argc, argv, env))) {
                        if (!(err = this->on_ethernet_address_option_set(optarg, optind, argc, argv, env))) {
                        } else {}
                    } else {}
                    break;
                case name:
                    if (!(err = this->on_set_ethernet_name_option(optarg, optind, argc, argv, env))) {
                        if (!(err = this->on_ethernet_name_option_set(optarg, optind, argc, argv, env))) {
                        } else {}
                    } else {}
                    break;
                case number:
                default:
                    if (!(err = this->on_set_ethernet_number_option(optarg, optind, argc, argv, env))) {
                        if (!(err = this->on_ethernet_number_option_set(optarg, optind, argc, argv, env))) {
                        } else {}
                    } else {}
                    break;
                }
            } else {
            }
        } else {
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...ethernet_address
    virtual ethernet_address_t& ethernet_address() const {
        return (ethernet_address_t&)ethernet_address_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...interface_address
    virtual ethernet_actual_address_t& set_interface_address(const ethernet_actual_address_t& to) {
        ethernet_actual_address_t& interface_address = this->interface_address();
        interface_address.assign(to);
        return interface_address;
    }
    virtual ethernet_actual_address_t& clear_interface_address() {
        ethernet_actual_address_t& interface_address = this->interface_address();
        interface_address.clear();
        return interface_address;
    }
    virtual ethernet_actual_address_t& interface_address() const {
        return (ethernet_actual_address_t&)interface_address_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...interface_address_string
    virtual string_t& set_interface_address_string(const string_t& to) {
        string_t& interface_address_string = this->interface_address_string();
        interface_address_string.assign(to);
        if ((0 < (interface_address_string.length()))) {
            ethernet_actual_address_t& interface_address = this->interface_address();
            ethernet_actual_address_from_string_t  actual_address(interface_address_string, this->is_logged());
            interface_address.assign(actual_address);
        } else {
        }
        return interface_address_string;
    }
    virtual string_t& clear_interface_address_string() {
        string_t& interface_address_string = this->interface_address_string();
        interface_address_string.clear();
        return interface_address_string;
    }
    virtual string_t& interface_address_string() const {
        return (string_t&)interface_address_string_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...interface_name
    virtual string_t& set_interface_name(const string_t& to) {
        string_t& interface_name = this->interface_name();
        interface_name.assign(to);
        return interface_name;
    }
    virtual string_t& clear_interface_name() {
        string_t& interface_name = this->interface_name();
        interface_name.clear();
        return interface_name;
    }
    virtual string_t& interface_name() const {
        return (string_t&)interface_name_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...interface_number
    virtual unsigned& set_interface_number(const unsigned& to) {
        unsigned& interface_number = this->interface_number();
        interface_number = to;
        return interface_number;
    }
    virtual unsigned& clear_interface_number() {
        unsigned& interface_number = this->interface_number();
        interface_number = 0;
        return interface_number;
    }
    virtual unsigned& interface_number() const {
        return (unsigned&)interface_number_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
protected:
    unsigned interface_number_;
    string_t interface_name_, interface_address_string_;
    ethernet_actual_address_t interface_address_;
    ethernet_address_t ethernet_address_;
}; /// class maint 
typedef maint<> main;

} /// namespace identifier 
} /// namespace unique 
} /// namespace universal 
} /// namespace network 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_HPP

