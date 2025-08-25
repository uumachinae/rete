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
///   Date: 11/14/2024
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_OS_IDENTIFIER_MAIN_HPP
#define XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_OS_IDENTIFIER_MAIN_HPP

#include "xos/app/console/network/universal/unique/os/identifier/main_opt.hpp"
#include "xos/network/universal/unique/os/identifier.hpp"
#include "xos/network/ethernet/os/address.hpp"

namespace xos {
namespace app {
namespace console {
namespace network {
namespace universal {
namespace unique {
namespace os {
namespace identifier {

/// class maint
template 
<class TEthernetOsAddress = xos::network::ethernet::os::address,
 class TExtends = xos::app::console::network::universal::unique::os::identifier::main_optt<>,  class TImplements = typename TExtends::implements>

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

    typedef typename extends::ethernet_address_t ethernet_address_t;
    typedef typename extends::ethernet_address_string_t ethernet_address_string_t;
    typedef typename extends::ethernet_actual_address_t ethernet_actual_address_t;
    typedef typename extends::ethernet_actual_address_from_string_t ethernet_actual_address_from_string_t;
    typedef typename extends::ethernet_actual_address_to_string_t ethernet_actual_address_to_string_t;
    typedef TEthernetOsAddress ethernet_os_address_t;

    typedef xos::network::universal::unique::identifier universal_unique_identifier_t;
    typedef xos::network::universal::unique::os::identifier universal_unique_os_identifier_t;

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
    /// ...output_ethernet_address_uuid_run
    virtual int default_output_ethernet_address_uuid_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const ethernet_actual_address_t& ethernet_address = this->interface_address();
        const ethernet_actual_address_to_string_t ethernet_address_string(ethernet_address);
        const char_t* chars = 0; size_t length = 0;
        
        LOGGER_IS_LOGGED_INFO("((chars = ethernet_address_string.has_chars(length)))...");
        if ((chars = ethernet_address_string.has_chars(length))) {
            universal_unique_identifier_t& uuid = this->universal_unique_identifier();
            
            LOGGER_IS_LOGGED_INFO("...((\"" << chars << "\" = ethernet_address_string.has_chars(" << length << ")))");
            LOGGER_IS_LOGGED_INFO("((uuid.generate(\"" << ethernet_address_string << "\")))...");
            if ((uuid.generate(ethernet_address))) {
    
                LOGGER_IS_LOGGED_INFO("...((uuid.generate(\"" << ethernet_address_string << "\")))");
                LOGGER_IS_LOGGED_INFO("((chars = uuid.string().has_chars(length)))...");
                if ((chars = uuid.string().has_chars(length))) {
                    const bool& output_lf = this->output_lf();
    
                    LOGGER_IS_LOGGED_INFO("...((\"" << chars << "\" = uuid.string().has_chars("<< length <<")))");
                    if ((output_lf )) {
                        this->outln(chars, length);
                    } else {
                        this->out(chars, length);
                    }
                } else {
                    LOGGER_IS_LOGGED_ERROR("...failed on ((chars = uuid.string().has_chars(length)))");
                }
            } else {
                LOGGER_IS_LOGGED_ERROR("...failed on ((uuid.generate(\"" << ethernet_address_string << "\")))");
            }
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on ((chars = ethernet_address_string.has_chars(length)))");
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...output_ethernet_address_named_run
    virtual int before_output_ethernet_address_named_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const string_t& name = this->interface_name();
        ethernet_address_t &ethernet = this->ethernet_address();
        ethernet_actual_address_t *address = 0;
        
        LOGGER_IS_LOGGED_INFO("((address = ethernet.set_to_adapter(\"" << name << "\")))...");
        if ((address = ethernet.set_to_adapter(name))) {
            LOGGER_IS_LOGGED_INFO("...((address = ethernet.set_to_adapter(\"" << name << "\")))");
            LOGGER_IS_LOGGED_INFO("this->set_interface_address(*address)...");
            this->set_interface_address(*address);
            LOGGER_IS_LOGGED_INFO("...this->set_interface_address(*address)");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on ((address = ethernet.set_to_adapter(\"" << name << "\")))");
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...output_ethernet_address_numbered_run
    virtual int before_output_ethernet_address_numbered_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        unsigned index = this->interface_number();
        ethernet_address_t &ethernet = this->ethernet_address();
        ethernet_actual_address_t *address = 0;
        
        LOGGER_IS_LOGGED_INFO("((address = ethernet.set_to_adapter(" << index << ")))...");
        if ((address = ethernet.set_to_adapter(index))) {
            LOGGER_IS_LOGGED_INFO("...((address = ethernet.set_to_adapter(" << index << ")))");
            LOGGER_IS_LOGGED_INFO("this->set_interface_address(*address)...");
            this->set_interface_address(*address);
            LOGGER_IS_LOGGED_INFO("...this->set_interface_address(*address)");
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on ((address = ethernet.set_to_adapter(" << index << ")))");
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...named_before_output_ethernet_address_name_run
    virtual int named_before_output_ethernet_address_name_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        unsigned index = this->interface_number();
        ethernet_address_t &ethernet = this->ethernet_address();
        ethernet_actual_address_t *address = 0;
        
        LOGGER_IS_LOGGED_INFO("((address = ethernet.set_to_adapter(" << index << ")))...");
        if ((address = ethernet.set_to_adapter(index))) {
            const ethernet_address_string_t& adapter_name = ethernet.adapter_name();
            string_t& interface_name = this->interface_name();
            LOGGER_IS_LOGGED_INFO("...((address = ethernet.set_to_adapter(" << index << ")))");
            LOGGER_IS_LOGGED_INFO("interface_name.assign(\"" << adapter_name << "\")...");
            interface_name.assign(adapter_name);
        } else {
            LOGGER_IS_LOGGED_INFO("...failed on ((address = ethernet.set_to_adapter(" << index << ")))");
        }
        return err;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    /// ...ethernet_address
    virtual ethernet_address_t& ethernet_address() const {
        return (ethernet_address_t&)ethernet_os_address_;
    }
    //////////////////////////////////////////////////////////////////////////
    /// ...universal_unique_identifier
    virtual universal_unique_identifier_t& universal_unique_identifier() const {
        return (universal_unique_identifier_t&)universal_unique_os_identifier_;
    }
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
protected:
    ethernet_os_address_t ethernet_os_address_;
    universal_unique_os_identifier_t universal_unique_os_identifier_;
}; /// class maint 
typedef maint<> main;

} /// namespace identifier 
} /// namespace os 
} /// namespace unique 
} /// namespace universal 
} /// namespace network 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_NETWORK_UNIVERSAL_UNIQUE_OS_IDENTIFIER_MAIN_HPP

