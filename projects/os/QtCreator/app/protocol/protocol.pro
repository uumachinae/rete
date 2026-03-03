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
#   File: protocol.pro
#
# Author: $author$
#   Date: 8/19/2025
#
# os specific QtCreator project .pro file for framework rete executable protocol
########################################################################
# Depends: rostra;nadir;fila;crono;stara
#
# Debug: rete/build/os/QtCreator/Debug/bin/protocol
# Release: rete/build/os/QtCreator/Release/bin/protocol
# Profile: rete/build/os/QtCreator/Profile/bin/protocol
#
include(../../../../../build/QtCreator/rete.pri)
include(../../../../QtCreator/rete.pri)
include(../../rete.pri)
include(../../../../QtCreator/app/protocol/protocol.pri)

TARGET = $${protocol_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${protocol_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${protocol_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${protocol_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${protocol_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${protocol_HEADERS} \
$${protocol_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${protocol_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${protocol_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${protocol_LIBS} \
$${FRAMEWORKS} \

########################################################################
