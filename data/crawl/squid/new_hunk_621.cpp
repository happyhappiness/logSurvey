    } else {
        std::unique_ptr<HttpReply> reply(new HttpReply);
        reply->setHeaders(Http::scOkay, NULL, "text/plain", -1, squid_curtime, squid_curtime);
        reply->header.putStr(Http::HdrType::CONNECTION, "close"); // until we chunk response
        replyBuf.reset(reply->pack());
    }
    writer = asyncCall(16, 5, "Mgr::Inquirer::noteWroteHeader",
