#
# Project:  Feographia
# Purpose:  Mobile application to work with the biblical text
# Author:   NikitaFeodonit, nfeodonit@yandex.com
# ****************************************************************************
# Copyright (C) 2015-2016 NikitaFeodonit
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += \
    $$PWD

HEADERS += \

SOURCES += \
    $$PWD/fcore/platform/android/FcoreAndroid.cpp \

OTHER_FILES += \
    $$PWD/Android.mk \
    $$PWD/../android-nkd/jni/Application.mk \
#    $$PWD/../.clang-format \  # see archive folder

# from Crystax NDK
INCLUDEPATH += \
    $(ANDROID_NDK_ROOT)/sources/boost/1.58.0/include \

include(fcore.pri)
