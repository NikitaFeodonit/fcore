/*
 * Project:  Feographia
 * Purpose:  Mobile application to work with the biblical text
 * Author:   NikitaFeodonit, nfeodonit@yandex.com
 * ****************************************************************************
 * Copyright (C) 2015-2016 NikitaFeodonit
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

#ifndef FCORE_SENDFILETEXTMSG_H
#define FCORE_SENDFILETEXTMSG_H

#include "fcore/message/FcoreMsg.h"


namespace fcore
{
  class SendFileTextMsg
    : public FcoreMsg
  {
  public:
    explicit SendFileTextMsg(boost::shared_ptr <FcMsg::Message::Reader> msgPtrQ)
      : FcoreMsg(msgPtrQ)
    {}

  protected:
    void dataWorker(
        boost::shared_ptr <capnp::AnyPointer::Reader> dataPtrQ,
        boost::shared_ptr <FcMsg::Message::Builder>   msgPtrR);
  };
}  // namespace fcore

#endif  // FCORE_SENDFILETEXTMSG_H
