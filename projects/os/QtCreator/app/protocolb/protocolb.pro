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
#   File: protocolb.pro
#
# Author: $author$
#   Date: 8/19/2025
#
# os specific QtCreator project .pro file for framework rete executable protocolb
########################################################################
# Depends: rostra;nadir;fila;crono;stara
#
# Debug: rete/build/os/QtCreator/Debug/bin/protocolb
# Release: rete/build/os/QtCreator/Release/bin/protocolb
# Profile: rete/build/os/QtCreator/Profile/bin/protocolb
#
include(../../../../../build/QtCreator/rete.pri)
include(../../../../QtCreator/rete.pri)
include(../../rete.pri)
include(../../../../QtCreator/app/protocolb/protocolb.pri)

TARGET = $${protocolb_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${protocolb_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${protocolb_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${protocolb_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${protocolb_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${protocolb_HEADERS} \
$${protocolb_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${protocolb_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${protocolb_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${protocolb_LIBS} \
$${FRAMEWORKS} \

########################################################################
