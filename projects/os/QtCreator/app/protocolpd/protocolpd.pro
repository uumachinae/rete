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
#   File: protocolpd.pro
#
# Author: $author$
#   Date: 8/19/2025
#
# os specific QtCreator project .pro file for framework rete executable protocolpd
########################################################################
# Depends: rostra;nadir;fila;crono;stara
#
# Debug: rete/build/os/QtCreator/Debug/bin/protocolpd
# Release: rete/build/os/QtCreator/Release/bin/protocolpd
# Profile: rete/build/os/QtCreator/Profile/bin/protocolpd
#
include(../../../../../build/QtCreator/rete.pri)
include(../../../../QtCreator/rete.pri)
include(../../rete.pri)
include(../../../../QtCreator/app/protocolpd/protocolpd.pri)

TARGET = $${protocolpd_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${protocolpd_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${protocolpd_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${protocolpd_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${protocolpd_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${protocolpd_HEADERS} \
$${protocolpd_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${protocolpd_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${protocolpd_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${protocolpd_LIBS} \
$${FRAMEWORKS} \

########################################################################
