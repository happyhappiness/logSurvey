
/*
 * $Id: ICAPAnchor.h,v 1.1 2005/11/21 23:32:59 wessels Exp $
 *
 *
 * SQUID Web Proxy Cache          http://www.squid-cache.org/
 * ----------------------------------------------------------
 *
 *  Squid is the result of efforts by numerous individuals from
 *  the Internet community; see the CONTRIBUTORS file for full
 *  details.   Many organizations have provided support for Squid's
 *  development; see the SPONSORS file for full details.  Squid is
 *  Copyrighted (C) 2001 by the Regents of the University of
 *  California; see the COPYRIGHT file for full details.  Squid
 *  incorporates software developed and/or copyrighted by other
 *  sinks; see the CREDITS file for full details.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111, USA.
 *
 */

#ifndef SQUID_ICAPANCHOR_H
#define SQUID_ICAPANCHOR_H

#include "MsgPipe.h"
#include "MsgPipeSource.h"
#include "MsgPipeSink.h"
#include "ICAPServiceRep.h"

/* The ICAP Anchor implements message pipe sink and source interfaces.  It
 * helps HttpStateData to marshall the incoming/virgin HTTP message (being
 * recieved from the HTTP server) to Squid's ICAP client module, using the
 * MsgPipe interface. The same interface is used to get the adapted HTTP
 * message back from the ICAP client. HttpStateData is the "owner" of the
 * ICAPAnchor.
 */

class HttpRequest;

class HttpReply;

class ICAPAnchor: public MsgPipeSource, public MsgPipeSink
{

public:
    ICAPAnchor(ICAPServiceRep::Pointer);
    virtual ~ICAPAnchor();

    // synchronous calls called by HttpStateData
    void startRespMod(HttpStateData *anHttpState, HttpRequest *request, HttpReply *reply);
    void sendMoreData(StoreIOBuffer buf);
    void doneSending();
    void ownerAbort();
    int potentialSpaceSize();	/* how much data can we accept? */

    // pipe source methods; called by ICAP while receiving the virgin message
    virtual void noteSinkNeed(MsgPipe *p);
    virtual void noteSinkAbort(MsgPipe *p);

    // pipe sink methods; called by ICAP while sending the adapted message
    virtual void noteSourceStart(MsgPipe *p);
    virtual void noteSourceProgress(MsgPipe *p);
    virtual void noteSourceFinish(MsgPipe *p);
    virtual void noteSourceAbort(MsgPipe *p);

public:
    ICAPServiceRep::Pointer service;
    HttpStateData *httpState;
    MsgPipe::Pointer virgin;
    MsgPipe::Pointer adapted;

private:
    typedef enum { notifyNone, notifyOwner, notifyIcap } Notify;
    void stop(Notify notify);
    void freeVirgin();
    void freeAdapted();
    CBDATA_CLASS2(ICAPAnchor);
};

#endif /* SQUID_ICAPANCHOR_H */
