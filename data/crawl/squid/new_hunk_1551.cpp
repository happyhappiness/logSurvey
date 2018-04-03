        debugs(74, 5, "request-line: proto " << req.v_start << "->" << req.v_end << " (" << msgProtocol_ << ")");
        debugs(74, 5, "Parser: parse-offset=" << parseOffset_);
        PROF_stop(HttpParserParseReqLine);

        // syntax errors already
        if (retcode < 0) {
            parsingStage_ = HTTP_PARSE_DONE;
fprintf(stderr, "parse FIRST DONE (error)\n");
            return false;
        }

        // first-line (or a look-alike) found successfully.
        if (retcode > 0) {
            parseOffset_ += firstLineSize(); // first line bytes including CRLF terminator are now done.
            parsingStage_ = HTTP_PARSE_MIME;
fprintf(stderr, "parse FIRST (next: MIME)\n");
        }
else fprintf(stderr, "parse FIRST: ret=%d\n",retcode);
    }

    // stage 3: locate the mime header block
    if (parsingStage_ == HTTP_PARSE_MIME) {
fprintf(stderr, "parse MIME: '%s'\n", buf);
        // HTTP/1.x request-line is valid and parsing completed.
        if (msgProtocol_.major == 1) {
            /* NOTE: HTTP/0.9 requests do not have a mime header block.
