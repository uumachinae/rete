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
///   Date: 11/13/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_OPT_HPP

#include "xos/app/console/output/base/main.hpp"

#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_ETHERNET_OPT "ethernet"
#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_ETHERNET_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_ETHERNET_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_ETHERNET_OPTARG "[{ 0..n | string | xx:xx:xx:xx:xx:xx }]"
#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_ETHERNET_OPTUSE "ethernet interface [number] | name | address"
#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_ETHERNET_OPTVAL_S "e::"
#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_ETHERNET_OPTVAL_C 'e'
#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_ETHERNET_OPTION \
   {XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_ETHERNET_OPT, \
    XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_ETHERNET_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_ETHERNET_OPTARG_RESULT, \
    XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_ETHERNET_OPTVAL_C}, \

#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_ADDRESS_OPT "address"
#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_ADDRESS_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_ADDRESS_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_ADDRESS_OPTARG "[xx:xx:xx:xx:xx:xx]"
#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_ADDRESS_OPTUSE "ethernet interface address"
#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_ADDRESS_OPTVAL_S "a::"
#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_ADDRESS_OPTVAL_C 'a'
#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_ADDRESS_OPTION \
   {XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_ADDRESS_OPT, \
    XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_ADDRESS_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_ADDRESS_OPTARG_RESULT, \
    XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_ADDRESS_OPTVAL_C}, \

#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NUMBER_OPT "number"
#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NUMBER_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NUMBER_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NUMBER_OPTARG "[0..n]"
#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NUMBER_OPTUSE "ethernet interface number"
#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NUMBER_OPTVAL_S "n::"
#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NUMBER_OPTVAL_C 'n'
#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NUMBER_OPTION \
   {XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NUMBER_OPT, \
    XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NUMBER_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NUMBER_OPTARG_RESULT, \
    XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NUMBER_OPTVAL_C}, \

#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NAME_OPT "name"
#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NAME_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NAME_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NAME_OPTARG "[string]"
#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NAME_OPTUSE "ethernet interface name"
#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NAME_OPTVAL_S "m::"
#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NAME_OPTVAL_C 'm'
#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NAME_OPTION \
   {XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NAME_OPT, \
    XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NAME_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NAME_OPTARG_RESULT, \
    XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NAME_OPTVAL_C}, \

#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NOLINE_OUTPUT_OPT "noline"
#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NOLINE_OUTPUT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NOLINE_OUTPUT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NOLINE_OUTPUT_OPTARG XOS_APP_CONSOLE_MAIN_OPTARG_ONOFF_OPTIONAL
#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NOLINE_OUTPUT_OPTUSE "no line feed on output"
#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NOLINE_OUTPUT_OPTVAL_S "o::"
#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NOLINE_OUTPUT_OPTVAL_C 'o'
#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NOLINE_OUTPUT_OPTION \
   {XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NOLINE_OUTPUT_OPT, \
    XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NOLINE_OUTPUT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NOLINE_OUTPUT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NOLINE_OUTPUT_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_ETHERNET_OPTVAL_S \
   XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_ADDRESS_OPTVAL_S \
   XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NUMBER_OPTVAL_S \
   XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NAME_OPTVAL_S \
   XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NOLINE_OUTPUT_OPTVAL_S \

#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_ETHERNET_OPTION \
   XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_ADDRESS_OPTION \
   XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NUMBER_OPTION \
   XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NAME_OPTION \
   XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NOLINE_OUTPUT_OPTION \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_OUTPUT_BASE_MAIN_VERBOSE_OPTIONS_CHARS \

#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_OUTPUT_BASE_MAIN_VERBOSE_OPTIONS_OPTIONS \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_ARGS 0
#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_ARGV 0,

namespace xos {
namespace app {
namespace console {
namespace network {
namespace universal {
namespace unique {
namespace identifier {

/// class main_optt
template 
<class TExtends = xos::app::console::output::base::maint<>,  class TImplements = typename TExtends::implements>

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
            if (!(err = all_output_ethernet_address_numbered_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }

    //////////////////////////////////////////////////////////////////////////
    /// ...output_ethernet_address_uuid_run
    int (derives::*output_ethernet_address_uuid_run_)(int argc, char_t** argv, char_t** env);
    virtual int output_ethernet_address_uuid_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (output_ethernet_address_uuid_run_) {
            if (!(err = (this->*output_ethernet_address_uuid_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_output_ethernet_address_uuid_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_output_ethernet_address_uuid_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = all_output_ethernet_address_run(argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int before_output_ethernet_address_uuid_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_ethernet_address_uuid_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_ethernet_address_uuid_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_ethernet_address_uuid_run(argc, argv, env))) {
            int err2 = 0;
            err = output_ethernet_address_uuid_run(argc, argv, env);
            if ((err2 = after_output_ethernet_address_uuid_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_ethernet_address_uuid_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_output_ethernet_address_uuid_run;
        return err;
    }
    virtual int output_ethernet_address_uuid_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_output_ethernet_address_uuid_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int output_ethernet_address_uuid_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...output_ethernet_interface_addressed_run
    int (derives::*output_ethernet_interface_addressed_run_)(int argc, char_t** argv, char_t** env);
    virtual int output_ethernet_interface_addressed_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (output_ethernet_interface_addressed_run_) {
            if (!(err = (this->*output_ethernet_interface_addressed_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_output_ethernet_interface_addressed_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_output_ethernet_interface_addressed_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_output_ethernet_interface_addressed_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_ethernet_interface_addressed_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_ethernet_interface_addressed_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_ethernet_interface_addressed_run(argc, argv, env))) {
            int err2 = 0;
            err = output_ethernet_interface_addressed_run(argc, argv, env);
            if ((err2 = after_output_ethernet_interface_addressed_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_ethernet_interface_addressed_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_output_ethernet_interface_addressed_run;
        return err;
    }
    virtual int output_ethernet_interface_addressed_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_output_ethernet_interface_addressed_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int output_ethernet_interface_addressed_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...output_ethernet_address_named_run
    int (derives::*output_ethernet_address_named_run_)(int argc, char_t** argv, char_t** env);
    virtual int output_ethernet_address_named_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (output_ethernet_address_named_run_) {
            if (!(err = (this->*output_ethernet_address_named_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_output_ethernet_address_named_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_output_ethernet_address_named_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_output_ethernet_address_named_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_ethernet_address_named_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_ethernet_address_named_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_ethernet_address_named_run(argc, argv, env))) {
            int err2 = 0;
            err = output_ethernet_address_named_run(argc, argv, env);
            if ((err2 = after_output_ethernet_address_named_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_ethernet_address_named_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_output_ethernet_address_named_run;
        return err;
    }
    virtual int output_ethernet_address_named_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_output_ethernet_address_named_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int output_ethernet_address_named_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...output_ethernet_address_numbered_run
    int (derives::*output_ethernet_address_numbered_run_)(int argc, char_t** argv, char_t** env);
    virtual int output_ethernet_address_numbered_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (output_ethernet_address_numbered_run_) {
            if (!(err = (this->*output_ethernet_address_numbered_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_output_ethernet_address_numbered_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_output_ethernet_address_numbered_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_output_ethernet_address_numbered_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_ethernet_address_numbered_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_ethernet_address_numbered_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_ethernet_address_numbered_run(argc, argv, env))) {
            int err2 = 0;
            err = output_ethernet_address_numbered_run(argc, argv, env);
            if ((err2 = after_output_ethernet_address_numbered_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_ethernet_address_numbered_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_output_ethernet_address_numbered_run;
        return err;
    }
    virtual int output_ethernet_address_numbered_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_output_ethernet_address_numbered_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int output_ethernet_address_numbered_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...output_ethernet_address_run
    int (derives::*output_ethernet_address_run_)(int argc, char_t** argv, char_t** env);
    virtual int output_ethernet_address_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (output_ethernet_address_run_) {
            if (!(err = (this->*output_ethernet_address_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_output_ethernet_address_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_output_ethernet_address_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...before_output_ethernet_address_run
    int (derives::*before_output_ethernet_address_run_)(int argc, char_t** argv, char_t** env);
    virtual int before_output_ethernet_address_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (before_output_ethernet_address_run_) {
            if (!(err = (this->*before_output_ethernet_address_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_before_output_ethernet_address_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_before_output_ethernet_address_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual int set_numbered_before_output_ethernet_address_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        before_output_ethernet_address_run_ = &derives::before_output_ethernet_address_numbered_run;
        return err;
    }
    virtual int numbered_before_output_ethernet_address_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_numbered_before_output_ethernet_address_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        before_output_ethernet_address_run_ = 0;
        return err;
    }
    virtual int numbered_before_output_ethernet_address_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual int set_named_before_output_ethernet_address_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        before_output_ethernet_address_run_ = &derives::before_output_ethernet_address_named_run;
        return err;
    }
    virtual int named_before_output_ethernet_address_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_named_before_output_ethernet_address_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        before_output_ethernet_address_run_ = 0;
        return err;
    }
    virtual int named_before_output_ethernet_address_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual int after_output_ethernet_address_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_ethernet_address_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_ethernet_address_run(argc, argv, env))) {
            int err2 = 0;
            err = output_ethernet_address_run(argc, argv, env);
            if ((err2 = after_output_ethernet_address_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_ethernet_address_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_output_ethernet_address_run;
        return err;
    }
    virtual int output_ethernet_address_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_output_ethernet_address_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int output_ethernet_address_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...output_ethernet_address_name_run
    int (derives::*output_ethernet_address_name_run_)(int argc, char_t** argv, char_t** env);
    virtual int output_ethernet_address_name_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (output_ethernet_address_name_run_) {
            if (!(err = (this->*output_ethernet_address_name_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_output_ethernet_address_name_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_output_ethernet_address_name_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...before_output_ethernet_address_name_run
    int (derives::*before_output_ethernet_address_name_run_)(int argc, char_t** argv, char_t** env);
    virtual int before_output_ethernet_address_name_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (before_output_ethernet_address_name_run_) {
            if (!(err = (this->*before_output_ethernet_address_name_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_before_output_ethernet_address_name_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_before_output_ethernet_address_name_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...named_before_output_ethernet_address_name_run
    virtual int named_before_output_ethernet_address_name_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int set_named_before_output_ethernet_address_name_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        before_output_ethernet_address_name_run_ = &derives::named_before_output_ethernet_address_name_run;
        return err;
    }
    virtual int named_before_output_ethernet_address_name_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_named_before_output_ethernet_address_name_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        before_output_ethernet_address_name_run_ = 0;
        return err;
    }
    virtual int named_before_output_ethernet_address_name_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...after_output_ethernet_address_name_run
    virtual int after_output_ethernet_address_name_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_ethernet_address_name_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_ethernet_address_name_run(argc, argv, env))) {
            int err2 = 0;
            err = output_ethernet_address_name_run(argc, argv, env);
            if ((err2 = after_output_ethernet_address_name_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_ethernet_address_name_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_output_ethernet_address_name_run;
        return err;
    }
    virtual int output_ethernet_address_name_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_output_ethernet_address_name_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int output_ethernet_address_name_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...output_ethernet_address_number_run
    int (derives::*output_ethernet_address_number_run_)(int argc, char_t** argv, char_t** env);
    virtual int output_ethernet_address_number_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (output_ethernet_address_number_run_) {
            if (!(err = (this->*output_ethernet_address_number_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_output_ethernet_address_number_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_output_ethernet_address_number_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_output_ethernet_address_number_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_ethernet_address_number_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_ethernet_address_number_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_ethernet_address_number_run(argc, argv, env))) {
            int err2 = 0;
            err = output_ethernet_address_number_run(argc, argv, env);
            if ((err2 = after_output_ethernet_address_number_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_ethernet_address_number_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_output_ethernet_address_number_run;
        return err;
    }
    virtual int output_ethernet_address_number_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_output_ethernet_address_number_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int output_ethernet_address_number_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// on...ethernet...option...
    /// ...
    /// on...ethernet_number_option...
    virtual int on_set_ethernet_number_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_ethernet_number_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = set_output_ethernet_address_numbered_run(argc, argv, env))) {
                if (!(err = output_ethernet_address_numbered_run_set(argc, argv, env))) {
                } else {
                }
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
        } else {
        }
        return err;
    }
    virtual int on_ethernet_name_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = set_output_ethernet_address_named_run(argc, argv, env))) {
                if (!(err = output_ethernet_address_named_run_set(argc, argv, env))) {
                } else {
                }
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
        } else {
        }
        return err;
    }
    virtual int on_ethernet_address_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = set_output_ethernet_interface_addressed_run(argc, argv, env))) {
                if (!(err = output_ethernet_interface_addressed_run_set(argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    /// ...
    /// on...ethernet...option...
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// on...ethernet_option...
    virtual int on_get_ethernet_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_ethernet_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_output_ethernet_address_numbered_run(argc, argv, env))) {
            if (!(err = output_ethernet_address_numbered_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_ethernet_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_ethernet_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_ethernet_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_ethernet_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_ethernet_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_ethernet_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_ethernet_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* ethernet_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_ETHERNET_OPTUSE;
        optarg = XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_ETHERNET_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...address_option...
    virtual int on_get_address_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_address_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_output_ethernet_address_run(argc, argv, env))) {
            if (!(err = output_ethernet_address_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_address_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_address_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = set_output_ethernet_address_run(argc, argv, env))) {
                if (!(err = output_ethernet_address_run_set(argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_address_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_address_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_address_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_address_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_address_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* address_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_ADDRESS_OPTUSE;
        optarg = XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_ADDRESS_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...number_option...
    virtual int on_get_number_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_number_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_output_ethernet_address_number_run(argc, argv, env))) {
            if (!(err = output_ethernet_address_number_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_number_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_number_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = set_output_ethernet_address_numbered_run(argc, argv, env))) {
                if (!(err = output_ethernet_address_numbered_run_set(argc, argv, env))) {
                    if (!(err = set_numbered_before_output_ethernet_address_run(argc, argv, env))) {
                        if (!(err = numbered_before_output_ethernet_address_run_set(argc, argv, env))) {
                        } else {
                        }
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
    virtual int on_number_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_number_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_number_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_number_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_number_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* number_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NUMBER_OPTUSE;
        optarg = XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NUMBER_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    /// on...name_option...
    virtual int on_get_name_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_name_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_output_ethernet_address_name_run(argc, argv, env))) {
            if (!(err = output_ethernet_address_name_run_set(argc, argv, env))) {
                if (!(err = set_named_before_output_ethernet_address_name_run(argc, argv, env))) {
                    if (!(err = named_before_output_ethernet_address_name_run_set(argc, argv, env))) {
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
    virtual int on_set_name_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_name_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = set_output_ethernet_address_named_run(argc, argv, env))) {
                if (!(err = output_ethernet_address_named_run_set(argc, argv, env))) {
                    if (!(err = set_named_before_output_ethernet_address_run(argc, argv, env))) {
                        if (!(err = named_before_output_ethernet_address_run_set(argc, argv, env))) {
                        } else {
                        }
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
    virtual int on_name_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_name_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_name_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_name_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_name_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* name_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NAME_OPTUSE;
        optarg = XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NAME_OPTARG;
        return chars;
    }
    //////////////////////////////////////////////////////////////////////////
    virtual const char_t* noline_output_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NOLINE_OUTPUT_OPTUSE;
        optarg = XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NOLINE_OUTPUT_OPTARG;
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

        case XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_ETHERNET_OPTVAL_C:
            err = this->on_ethernet_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_ADDRESS_OPTVAL_C:
            err = this->on_address_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NUMBER_OPTVAL_C:
            err = this->on_number_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NAME_OPTVAL_C:
            err = this->on_name_option(optval, optarg, optname, optind, argc, argv, env);
            break;

        case XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NOLINE_OUTPUT_OPTVAL_C:
            err = this->on_noline_output_option(optval, optarg, optname, optind, argc, argv, env);
            break;

        default:
            err = extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    
    /// option_usage
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {

        case XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_ETHERNET_OPTVAL_C:
            chars = this->ethernet_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_ADDRESS_OPTVAL_C:
            chars = this->address_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NUMBER_OPTVAL_C:
            chars = this->number_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NAME_OPTVAL_C:
            chars = this->name_option_usage(optarg, longopt);
            break;

        case XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_NOLINE_OUTPUT_OPTVAL_C:
            chars = this->noline_output_option_usage(optarg, longopt);
            break;

        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }

    /// options
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// arguments
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
protected:
}; /// class main_optt 
typedef main_optt<> main_opt;

} /// namespace identifier 
} /// namespace unique 
} /// namespace universal 
} /// namespace network 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_IDENTIFIER_MAIN_OPT_HPP

