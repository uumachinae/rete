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
#   File: librete.pri
#
# Author: $author$
#   Date: 8/19/2025
#
# generic QtCreator project .pri file for framework rete static library librete
########################################################################

########################################################################
# librete
XOS_LIB_RETE_VERSION_BUILD_DATE = 8/19/2025 #$$system(~/bin/utility/tdate)

# librete TARGET
#
librete_TARGET = rete
librete_TEMPLATE = lib
librete_CONFIG += staticlib

# librete INCLUDEPATH
#
librete_INCLUDEPATH += \
$${rete_INCLUDEPATH} \

# librete DEFINES
#
librete_DEFINES += \
$${rete_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_LIB_RETE_VERSION_BUILD_DATE=$${XOS_LIB_RETE_VERSION_BUILD_DATE} \

########################################################################
# librete OBJECTIVE_HEADERS
#
#librete_OBJECTIVE_HEADERS += \
#$${RETE_SRC}/xos/lib/rete/version.hh \

# librete OBJECTIVE_SOURCES
#
#librete_OBJECTIVE_SOURCES += \
#$${RETE_SRC}/xos/lib/rete/version.mm \

########################################################################
# librete HEADERS
#
librete_HEADERS += \
$${NADIR_SRC}/xos/app/console/framework/version/main.hpp \
$${NADIR_SRC}/xos/app/console/framework/version/main_opt.hpp \
$${NADIR_SRC}/xos/app/console/input/base/main.hpp \
$${NADIR_SRC}/xos/app/console/input/base/main_opt.hpp \
$${NADIR_SRC}/xos/app/console/main.hpp \
$${NADIR_SRC}/xos/app/console/main_opt.hpp \
$${NADIR_SRC}/xos/app/console/nadir/main.hpp \
$${NADIR_SRC}/xos/app/console/nadir/main_opt.hpp \
$${NADIR_SRC}/xos/app/console/nadir/version/main.hpp \
$${NADIR_SRC}/xos/app/console/nadir/version/main_opt.hpp \
$${NADIR_SRC}/xos/app/console/output/base/main.hpp \
$${NADIR_SRC}/xos/app/console/output/base/main_opt.hpp \
$${NADIR_SRC}/xos/app/console/version/main.hpp \
$${NADIR_SRC}/xos/app/console/version/main_opt.hpp \
\
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
$${NADIR_SRC}/xos/lib/nadir/version.hpp \
$${NADIR_SRC}/xos/lib/version.hpp \
$${NADIR_SRC}/xos/platform/platform.hpp \
$${NADIR_SRC}/xos/platform/platform_unix.hpp \
$${NADIR_SRC}/xos/platform/platform_windows.hpp \
\
$${RETE_SRC}/xos/app/console/protocol/crlf2/client/main_opt.hpp \
$${RETE_SRC}/xos/app/console/protocol/crlf2/server/main.hpp \
$${RETE_SRC}/xos/app/console/protocol/crlf2/server/main_opt.hpp \
$${RETE_SRC}/xos/app/console/protocol/kasa/base/main.hpp \
$${RETE_SRC}/xos/app/console/protocol/kasa/base/main_opt.hpp \
$${RETE_SRC}/xos/app/console/protocol/kasa/client/main.hpp \
$${RETE_SRC}/xos/app/console/protocol/kasa/client/main_opt.hpp \
$${RETE_SRC}/xos/app/console/protocol/kasa/server/main.hpp \
$${RETE_SRC}/xos/app/console/protocol/kasa/server/main_opt.hpp \
$${RETE_SRC}/xos/app/console/protocol/lf/base/main.hpp \
$${RETE_SRC}/xos/app/console/protocol/lf/base/main_opt.hpp \
$${RETE_SRC}/xos/app/console/protocol/lf/client/main.hpp \
$${RETE_SRC}/xos/app/console/protocol/lf/client/main_opt.hpp \
$${RETE_SRC}/xos/app/console/protocol/lf/server/main.hpp \
$${RETE_SRC}/xos/app/console/protocol/lf/server/main_opt.hpp \
$${RETE_SRC}/xos/app/console/protocol/server/main.hpp \
$${RETE_SRC}/xos/app/console/protocol/server/main_opt.hpp \
$${RETE_SRC}/xos/app/console/protocol/sized/base/main.hpp \
$${RETE_SRC}/xos/app/console/protocol/sized/base/main_opt.hpp \
$${RETE_SRC}/xos/app/console/protocol/sized/client/main.hpp \
$${RETE_SRC}/xos/app/console/protocol/sized/client/main_opt.hpp \
$${RETE_SRC}/xos/app/console/protocol/sized/server/main.hpp \
$${RETE_SRC}/xos/app/console/protocol/sized/server/main_opt.hpp \
\
$${RETE_SRC}/xos/app/console/rete/main.hpp \
$${RETE_SRC}/xos/app/console/rete/main_opt.hpp \
$${RETE_SRC}/xos/app/console/rete/version/main.hpp \
$${RETE_SRC}/xos/app/console/rete/version/main_opt.hpp \
\
$${RETE_SRC}/xos/lib/rete/version.hpp \

# librete SOURCES
#
librete_SOURCES += \
$${RETE_SRC}/xos/lib/rete/version.cpp \

########################################################################
