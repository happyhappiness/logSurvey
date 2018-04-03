    debugs(16, 5, HERE);
    Must(fd >= 0);
    Must(aggrAction != NULL);

    std::auto_ptr<HttpReply> reply(new HttpReply);
    reply->setHeaders(strands.empty() ? HTTP_BAD_REQUEST : HTTP_OK, NULL, "text/plain", -1, squid_curtime, squid_curtime);
    reply->header.putStr(HDR_CONNECTION, "close"); // until we chunk response
    std::auto_ptr<MemBuf> replyBuf(reply->pack());
    writer = asyncCall(16, 5, "Mgr::Inquirer::noteWroteHeader",
                       CommCbMemFunT<Inquirer, CommIoCbParams>(this, &Inquirer::noteWroteHeader));
    Comm::Write(fd, replyBuf.get(), writer);