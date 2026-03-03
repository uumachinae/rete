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
#   File: protocolp.pro
#
# Author: $author$
#   Date: 8/19/2025
#
# os specific QtCreator project .pro file for framework rete executable protocolp
########################################################################
# Depends: rostra;nadir;fila;crono;stara
#
# Debug: rete/build/os/QtCreator/Debug/bin/protocolp
# Release: rete/build/os/QtCreator/Release/bin/protocolp
# Profile: rete/build/os/QtCreator/Profile/bin/protocolp
#
include(../../../../../build/QtCreator/rete.pri)
include(../../../../QtCreator/rete.pri)
include(../../rete.pri)
include(../../../../QtCreator/app/protocolp/protocolp.pri)

TARGET = $${protocolp_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${protocolp_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${protocolp_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${protocolp_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${protocolp_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${protocolp_HEADERS} \
$${protocolp_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${protocolp_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${protocolp_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${protocolp_LIBS} \
$${FRAMEWORKS} \

########################################################################
