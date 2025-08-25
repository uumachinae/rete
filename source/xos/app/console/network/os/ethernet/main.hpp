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
#ifndef XOS_APP_CONSOLE_NETWORK_OS_ETHERNET_MAIN_HPP
#define XOS_APP_CONSOLE_NETWORK_OS_ETHERNET_MAIN_HPP

#include "xos/app/console/network/os/ethernet/main_opt.hpp"
#include "xos/network/ethernet/os/address.hpp"

namespace xos {
namespace app {
namespace console {
namespace network {
namespace os {
namespace ethernet {

/// class maint
template 
<class TEthernetOsAddress = xos::network::ethernet::os::address,
 class TExtends = xos::app::console::network::os::ethernet::main_optt<>,  class TImplements = typename TExtends::implements>

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
    typedef TEthernetOsAddress ethernet_os_address_t;

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
    /// ...output_ethernet_interface_addressed_name_run
    virtual int before_output_ethernet_interface_addressed_name_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const ethernet_actual_address_t& interface_address = this->interface_address();
        ethernet_address_t &ethernet = this->ethernet_address();
        const string_t& address_string = this->interface_address_string();
        const ethernet_actual_address_t *address = 0;
        unsigned index = 0, index_min = 0, index_max = 8;
        const char_t* chars = 0; size_t length = 0;
        string_t name;
        
        for (index = index_min; index_max >= index; ++index) {
            LOGGER_IS_LOGGED_INFO("((address = ethernet.set_to_adapter(" << index << ")))...");
            if ((address = ethernet.set_to_adapter(index))) {
                const ethernet_actual_address_t& ethernet_address = *address;

                LOGGER_IS_LOGGED_INFO("...((address = ethernet.set_to_adapter(" << index << ")))");
                LOGGER_IS_LOGGED_INFO("((ethernet_address != interface_address))...");
                if ((ethernet_address != interface_address)) {
                    LOGGER_IS_LOGGED_INFO("...((ethernet_address != interface_address))");
                    LOGGER_IS_LOGGED_INFO("ethernet.actual_string().has_chars(length)...");
                    if ((chars = ethernet.actual_string().has_chars(length))) {
                        LOGGER_IS_LOGGED_INFO("...\"" << chars << "\" = ethernet.actual_string().has_chars("<< length <<")");
                        name.assign(chars, length);
                        LOGGER_IS_LOGGED_INFO("(!(address_string.compare(\"" << name << "\")))...");
                        if (!(address_string.compare(name))) {
                            LOGGER_IS_LOGGED_INFO("...(!(address_string.compare(\"" << name << "\")))");
                            name.assign(ethernet.adapter_name());
                            LOGGER_IS_LOGGED_INFO("this->set_interface_name(\"" << name << "\")...");
                            this->set_interface_name(name);
                            LOGGER_IS_LOGGED_INFO("...this->set_interface_name(\"" << name << "\")");
                            break;
                        } else {
                            LOGGER_IS_LOGGED_INFO("...failed on (!(address_string.compare(\"" << name << "\")))");
                        }
                    } else {
                        LOGGER_IS_LOGGED_INFO("...unexpected !(chars = ethernet.actual_string().has_chars(length))");
                    }
                } else {
                    LOGGER_IS_LOGGED_INFO("...((ethernet_address == interface_address))");
                    name.assign(ethernet.adapter_name());
                    LOGGER_IS_LOGGED_INFO("this->set_interface_name(\"" << name << "\")...");
                    this->set_interface_name(name);
                    LOGGER_IS_LOGGED_INFO("...this->set_interface_name(\"" << name << "\")");
                    break;
                }
            } else {
                LOGGER_IS_LOGGED_INFO("...failed on ((address = ethernet.set_to_adapter(" << index << ")))");
                break;
            }
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
    /// ...output_get_ethernet_address_name_run
    virtual int before_output_get_ethernet_address_name_run(int argc, char_t** argv, char_t** env) {
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

    //////////////////////////////////////////////////////////////////////////
protected:
    ethernet_os_address_t ethernet_os_address_;
}; /// class maint 
typedef maint<> main;

} /// namespace ethernet 
} /// namespace os 
} /// namespace network 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_NETWORK_OS_ETHERNET_MAIN_HPP

