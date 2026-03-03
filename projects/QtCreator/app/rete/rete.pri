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
#   File: rete.pri
#
# Author: $author$
#   Date: 8/19/2025
#
# generic QtCreator project .pri file for framework rete executable rete
########################################################################

########################################################################
# rete

# rete_exe TARGET
#
rete_exe_TARGET = rete

# rete_exe INCLUDEPATH
#
rete_exe_INCLUDEPATH += \
$${rete_INCLUDEPATH} \

# rete_exe DEFINES
#
rete_exe_DEFINES += \
$${rete_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# rete_exe OBJECTIVE_HEADERS
#
#rete_exe_OBJECTIVE_HEADERS += \
#$${RETE_SRC}/xos/app/console/rete/main.hh \

# rete_exe OBJECTIVE_SOURCES
#
#rete_exe_OBJECTIVE_SOURCES += \
#$${RETE_SRC}/xos/app/console/rete/main.mm \

########################################################################
# rete_exe HEADERS
#
rete_exe_HEADERS += \
$${RETE_SRC}/xos/app/console/rete/main_opt.hpp \
$${RETE_SRC}/xos/app/console/rete/main.hpp \

# rete_exe SOURCES
#
rete_exe_SOURCES += \
$${RETE_SRC}/xos/app/console/rete/main_opt.cpp \
$${RETE_SRC}/xos/app/console/rete/main.cpp \

########################################################################
# rete_exe FRAMEWORKS
#
rete_exe_FRAMEWORKS += \
$${rete_FRAMEWORKS} \

# rete_exe LIBS
#
rete_exe_LIBS += \
$${rete_LIBS} \

########################################################################
# NO Qt
QT -= gui core
