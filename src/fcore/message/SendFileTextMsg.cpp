/*
 * Project:  Feographia
 * Purpose:  Mobile application to work with the biblical text
 * Authors:  NikitaFeodonit, nfeodonit@yandex.com
 * ****************************************************************************
 * Copyright (C) 2015 NikitaFeodonit
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <fstream>

#include "fcore/message/SendFileTextMsg.hpp"


boost::shared_ptr<char[]> getFileText(std::string filePath)
{
    auto file = boost::make_shared<std::ifstream>(filePath, std::ios::in | std::ios::binary | std::ios::ate);

    if (file->is_open()) {
        std::streampos fileSize = file->tellg();
        size_t bufferSize = fileSize;

        auto buffer = boost::make_shared<char[]>(++bufferSize);

        file->seekg(0, std::ios::beg);
        file->read(buffer.get(), fileSize);
        buffer[fileSize] = 0; // terminate C-string by 0

        return buffer;
    }

    else {
        std::string errInfo = "Unable to open file, file path: " + filePath;
        // TODO: boost logger
        std::cout << errorMsg << filePath << std::endl;
        throw FcoreErrEx() << FcoreErrInfo(errInfo);
    }
}


boost::shared_ptr<capnp::AnyPointer::Builder> SendFileTextMsg::dataWorker(
        boost::shared_ptr<capnp::AnyPointer::Reader> dataPtrQ,
        boost::shared_ptr<FcMsg::Message::Builder> msgPtrR)
{
    // get the query data
    FcMsg::GetFileTextQ::Reader dataQ = dataPtrQ->getAs<FcMsg::GetFileTextQ>();
    std::string path = dataQ.getFilePath().cStr();
    // TODO: boost logger
    std::cout << "filePath: " << path << std::endl;

    // make the reply data
    // read file
    // TODO: boost logger
    std::cout << "file reading" << std::endl;
    auto fileText = getFileText(path);

    // set the reply data
    if (nullptr != fileText) {
        capnp::AnyPointer::Builder dataPtrR = msgPtrR->initDataPointer();
        FcMsg::GetFileTextR::Builder dataR = dataPtrR.initAs<FcMsg::GetFileTextR>();
        dataR.setFileText(fileText.get());
    } else {
        throw FcoreErrEx() << FcoreErrInfo("getFileText() error, nullptr == fileText");
    }
}