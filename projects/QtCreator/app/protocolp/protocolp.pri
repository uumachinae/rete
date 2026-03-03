########################################################################
# Copyright (c) 1988-2025 $organization$
#
# This software is provided by the author and contributors ``as is''
# and any express or implied warranties, including, but not limited to,
# the implied warranties of merchantability and fitness for a particular
# purpose are disclaimed. In no event shall the author or contributors
# be liable for any direct, indirect, incidental, special, exemplary,
# or consequential damages (including, but not limited to, procurement
# of substitute goods or services; loss of use, data, or profits; or
# business interruption) however caused and on any theory of liability,
# whether in contract, strict liability, or tort (including negligence
# or otherwise) arising in any way out of the use of this software,
# even if advised of the possibility of such damage.
#
#   File: protocolp.pri
#
# Author: $author$
#   Date: 8/19/2025
#
# generic QtCreator project .pri file for framework rete executable protocolp
########################################################################

########################################################################
# protocolp

# protocolp TARGET
#
protocolp_TARGET = protocolp

# protocolp INCLUDEPATH
#
protocolp_INCLUDEPATH += \
$${rete_INCLUDEPATH} \

# protocolp DEFINES
#
protocolp_DEFINES += \
$${rete_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# protocolp OBJECTIVE_HEADERS
#
#protocolp_OBJECTIVE_HEADERS += \
#$${RETE_SRC}/xos/app/console/protocol/main.hh \

# protocolp OBJECTIVE_SOURCES
#
#protocolp_OBJECTIVE_SOURCES += \
#$${RETE_SRC}/xos/app/console/protocol/main.mm \

########################################################################
# protocolp HEADERS
#
protocolp_HEADERS += \
$${NADIR_SRC}/xos/base/acquired.hpp \
$${NADIR_SRC}/xos/base/argv.hpp \
$${NADIR_SRC}/xos/base/array.hpp \
$${NADIR_SRC}/xos/base/arrays.hpp \
$${NADIR_SRC}/xos/base/attached.hpp \
$${NADIR_SRC}/xos/base/base.hpp \
$${NADIR_SRC}/xos/base/chars.hpp \
$${NADIR_SRC}/xos/base/created.hpp \
$${NADIR_SRC}/xos/base/error.hpp \
$${NADIR_SRC}/xos/base/exception.hpp \
$${NADIR_SRC}/xos/base/extended/creator.hpp \
$${NADIR_SRC}/xos/base/finalized.hpp \
$${NADIR_SRC}/xos/base/forked.hpp \
$${NADIR_SRC}/xos/base/initialized.hpp \
$${NADIR_SRC}/xos/base/joined.hpp \
$${NADIR_SRC}/xos/base/location.hpp \
$${NADIR_SRC}/xos/base/locked.hpp \
$${NADIR_SRC}/xos/base/logged.hpp \
$${NADIR_SRC}/xos/base/opened.hpp \
$${NADIR_SRC}/xos/base/pointed.hpp \
$${NADIR_SRC}/xos/base/ran.hpp \
$${NADIR_SRC}/xos/base/resumed.hpp \
$${NADIR_SRC}/xos/base/signaled.hpp \
$${NADIR_SRC}/xos/base/string.hpp \
$${NADIR_SRC}/xos/base/suspended.hpp \
$${NADIR_SRC}/xos/base/time.hpp \
$${NADIR_SRC}/xos/base/to_string.hpp \
$${NADIR_SRC}/xos/base/waited.hpp \
$${NADIR_SRC}/xos/base/wrapped.hpp \
\
$${NADIR_SRC}/xos/io/array/reader.hpp \
$${NADIR_SRC}/xos/io/base64/output_to.hpp \
$${NADIR_SRC}/xos/io/base64/read_to_output.hpp \
$${NADIR_SRC}/xos/io/base64/reader_to.hpp \
$${NADIR_SRC}/xos/io/base64/reader_to_events.hpp \
$${NADIR_SRC}/xos/io/base64/to_array.hpp \
$${NADIR_SRC}/xos/io/base64/write_to_output.hpp \
$${NADIR_SRC}/xos/io/base64/writer_to.hpp \
$${NADIR_SRC}/xos/io/base64/writer_to_events.hpp \
$${NADIR_SRC}/xos/io/console/output.hpp \
$${NADIR_SRC}/xos/io/crt/file/attached.hpp \
$${NADIR_SRC}/xos/io/crt/file/opened.hpp \
$${NADIR_SRC}/xos/io/crt/file/output.hpp \
$${NADIR_SRC}/xos/io/crt/file/reader.hpp \
$${NADIR_SRC}/xos/io/crt/file/stream.hpp \
$${NADIR_SRC}/xos/io/crt/file/writer.hpp \
$${NADIR_SRC}/xos/io/delegated/reader.hpp \
$${NADIR_SRC}/xos/io/delegated/reader_events.hpp \
$${NADIR_SRC}/xos/io/delegated/writer.hpp \
$${NADIR_SRC}/xos/io/delegated/writer_events.hpp \
$${NADIR_SRC}/xos/io/file/reader.hpp \
$${NADIR_SRC}/xos/io/file/writer.hpp \
$${NADIR_SRC}/xos/io/hex/output_to.hpp \
$${NADIR_SRC}/xos/io/hex/read_to_array.hpp \
$${NADIR_SRC}/xos/io/hex/read_to_arrays.hpp \
$${NADIR_SRC}/xos/io/hex/read_to_output.hpp \
$${NADIR_SRC}/xos/io/hex/read_to_string.hpp \
$${NADIR_SRC}/xos/io/hex/reader.hpp \
$${NADIR_SRC}/xos/io/hex/reader_to.hpp \
$${NADIR_SRC}/xos/io/hex/reader_to_events.hpp \
$${NADIR_SRC}/xos/io/hex/write_to_output.hpp \
$${NADIR_SRC}/xos/io/hex/writer_to.hpp \
$${NADIR_SRC}/xos/io/hex/writer_to_events.hpp \
$${NADIR_SRC}/xos/io/output.hpp \
$${NADIR_SRC}/xos/io/reader.hpp \
$${NADIR_SRC}/xos/io/seeker.hpp \
$${NADIR_SRC}/xos/io/sequence.hpp \
$${NADIR_SRC}/xos/io/stream.hpp \
$${NADIR_SRC}/xos/io/string/output.hpp \
$${NADIR_SRC}/xos/io/string/reader.hpp \
$${NADIR_SRC}/xos/io/string/writer.hpp \
$${NADIR_SRC}/xos/io/told.hpp \
$${NADIR_SRC}/xos/io/writer.hpp \
\
$${NADIR_SRC}/xos/console/error.hpp \
$${NADIR_SRC}/xos/console/getopt/main.hpp \
$${NADIR_SRC}/xos/console/getopt/main_opt.hpp \
$${NADIR_SRC}/xos/console/input.hpp \
$${NADIR_SRC}/xos/console/io.hpp \
$${NADIR_SRC}/xos/console/main.hpp \
$${NADIR_SRC}/xos/console/main_main.hpp \
$${NADIR_SRC}/xos/console/main_opt.hpp \
$${NADIR_SRC}/xos/console/out.hpp \
$${NADIR_SRC}/xos/console/output.hpp \
$${NADIR_SRC}/xos/console/sequence.hpp \
\
$${RETE_SRC}/xos/app/console/protocol/base/main_opt.hpp \
$${RETE_SRC}/xos/app/console/protocol/base/main.hpp \
$${RETE_SRC}/xos/app/console/protocol/client/main_opt.hpp \
$${RETE_SRC}/xos/app/console/protocol/client/main.hpp \
$${RETE_SRC}/xos/app/console/protocol/server/main.hpp \
$${RETE_SRC}/xos/app/console/protocol/server/main_opt.hpp \
\
$${RETE_SRC}/xos/app/console/protocol/cr/base/main.hpp \
$${RETE_SRC}/xos/app/console/protocol/cr/base/main_opt.hpp \
$${RETE_SRC}/xos/app/console/protocol/cr/client/main.hpp \
$${RETE_SRC}/xos/app/console/protocol/cr/client/main_opt.hpp \
$${RETE_SRC}/xos/app/console/protocol/cr/server/main.hpp \
$${RETE_SRC}/xos/app/console/protocol/cr/server/main_opt.hpp \
\
$${RETE_SRC}/xos/app/console/protocol/lf/base/main.hpp \
$${RETE_SRC}/xos/app/console/protocol/lf/base/main_opt.hpp \
$${RETE_SRC}/xos/app/console/protocol/lf/client/main.hpp \
$${RETE_SRC}/xos/app/console/protocol/lf/client/main_opt.hpp \
$${RETE_SRC}/xos/app/console/protocol/lf/server/main.hpp \
$${RETE_SRC}/xos/app/console/protocol/lf/server/main_opt.hpp \
\
$${RETE_SRC}/xos/app/console/protocol/crlf/base/main.hpp \
$${RETE_SRC}/xos/app/console/protocol/crlf/base/main_opt.hpp \
$${RETE_SRC}/xos/app/console/protocol/crlf/client/main.hpp \
$${RETE_SRC}/xos/app/console/protocol/crlf/client/main_opt.hpp \
$${RETE_SRC}/xos/app/console/protocol/crlf/server/main.hpp \
$${RETE_SRC}/xos/app/console/protocol/crlf/server/main_opt.hpp \
\
$${RETE_SRC}/xos/app/console/protocol/crlf2/base/main.hpp \
$${RETE_SRC}/xos/app/console/protocol/crlf2/base/main_opt.hpp \
$${RETE_SRC}/xos/app/console/protocol/crlf2/client/main.hpp \
$${RETE_SRC}/xos/app/console/protocol/crlf2/client/main_opt.hpp \
$${RETE_SRC}/xos/app/console/protocol/crlf2/server/main.hpp \
$${RETE_SRC}/xos/app/console/protocol/crlf2/server/main_opt.hpp \

# protocolp SOURCES
#
protocolp_SOURCES += \
$${RETE_SRC}/xos/app/console/protocol/client/main_opt.cpp \
$${RETE_SRC}/xos/app/console/protocol/client/main.cpp \

########################################################################
# protocolp FRAMEWORKS
#
protocolp_FRAMEWORKS += \
$${rete_FRAMEWORKS} \

# protocolp LIBS
#
protocolp_LIBS += \
$${rete_LIBS} \

########################################################################
# NO Qt
QT -= gui core
