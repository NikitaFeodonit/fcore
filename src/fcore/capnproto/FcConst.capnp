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

@0xe4ee0ce1e6c6a481;

using Cxx = import "/capnp/c++.capnp";
$Cxx.namespace("FcConst");

using Java = import "/capnp/java.capnp";
$Java.package("ru.feographia.capnproto");
$Java.outerClassname("FcConst");


const unknownId :UInt8 = 0;

const msgTypeUnknown :Int32 = 0;
const msgTypeGetFragmentText :Int32 = 1;
const msgTypeError :Int32 = 1000;

# for test
const msgTypeCreateTestModule :Int32 = 997;
const msgTypeGetFileText :Int32 = 998;
const msgTypeGetTestText :Int32 = 999;
