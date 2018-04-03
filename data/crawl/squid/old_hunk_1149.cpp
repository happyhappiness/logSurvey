        return;
    }

    HttpReply *filteredReply = reply->clone();
    HttpHeader &filteredHeader = filteredReply->header;

    // Remove all unsupported commands from the response wrapper.
    int deletedCount = 0;
    HttpHeaderPos pos = HttpHeaderInitPos;
    bool hasEPRT = false;
    bool hasEPSV = false;
    int prependSpaces = 1;
    while (const HttpHeaderEntry *e = filteredHeader.getEntry(&pos)) {
        if (e->id == HDR_FTP_PRE) {
            // assume RFC 2389 FEAT response format, quoted by Squid:
            // <"> SP NAME [SP PARAMS] <">
            // but accommodate MS servers sending four SPs before NAME

            // command name ends with (SP parameter) or quote
            static const CharacterSet AfterFeatNameChars("AfterFeatName", " \"");
            static const CharacterSet FeatNameChars = AfterFeatNameChars.complement("FeatName");

            Parser::Tokenizer tok(SBuf(e->value.termedBuf()));
            if (!tok.skip('"') && !tok.skip(' '))
                continue;

            // optional spaces; remember their number to accomodate MS servers
            prependSpaces = 1 + tok.skipAll(CharacterSet::SP);

            SBuf cmd;
            if (!tok.prefix(cmd, FeatNameChars))
                continue;
            cmd.toUpper();

            if (!Ftp::SupportedCommand(cmd))
                filteredHeader.delAt(pos, deletedCount);

            if (cmd == cmdEprt())
                hasEPRT = true;
            else if (cmd == cmdEpsv())
                hasEPSV = true;
        }
    }

    char buf[256];
    int insertedCount = 0;
    if (!hasEPRT) {
        snprintf(buf, sizeof(buf), "\"%*s\"", prependSpaces + 4, "EPRT");
        filteredHeader.putStr(HDR_FTP_PRE, buf);
        ++insertedCount;
    }
    if (!hasEPSV) {
        snprintf(buf, sizeof(buf), "\"%*s\"", prependSpaces + 4, "EPSV");
        filteredHeader.putStr(HDR_FTP_PRE, buf);
        ++insertedCount;
    }

    if (deletedCount || insertedCount) {
        filteredHeader.refreshMask();
        debugs(33, 5, "deleted " << deletedCount << " inserted " << insertedCount);
    }

    writeForwardedReply(filteredReply);
}

void