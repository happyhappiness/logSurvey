    request_parse_status = Http::scOkay;
    return 1;
}
#include <cstdio>
bool
Http::One::RequestParser::parse()
{
    // stage 1: locate the request-line
    if (parsingStage_ == HTTP_PARSE_NEW) {
fprintf(stderr, "parse GARBAGE: '%s'\n", buf);
        skipGarbageLines();
fprintf(stderr, "parse GBG A(%d) < B(%u)\n", bufsiz, parseOffset_);

        // if we hit something before EOS treat it as a message
        if ((size_t)bufsiz > parseOffset_)
            parsingStage_ = HTTP_PARSE_FIRST;
        else
            return false;
    }

    // stage 2: parse the request-line
    if (parsingStage_ == HTTP_PARSE_FIRST) {
fprintf(stderr, "parse FIRST: '%s'\n", buf);
        PROF_start(HttpParserParseReqLine);
        const int retcode = parseRequestFirstLine();
        debugs(74, 5, "request-line: retval " << retcode << ": from " << req.start << "->" << req.end << " " << Raw("line", &buf[req.start], req.end-req.start));
        debugs(74, 5, "request-line: method " << req.m_start << "->" << req.m_end << " (" << method_ << ")");
        debugs(74, 5, "request-line: url " << req.u_start << "->" << req.u_end << " (" << uri_ << ")");
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
             *       So the rest of the code will need to deal with '0'-byte headers
             *       (ie, none, so don't try parsing em)
             */
            int64_t mimeHeaderBytes = 0;
            if ((mimeHeaderBytes = headersEnd(buf+parseOffset_, bufsiz-parseOffset_)) == 0) {
                if (bufsiz-parseOffset_ >= Config.maxRequestHeaderSize) {
                    debugs(33, 5, "Too large request");
                    request_parse_status = Http::scHeaderTooLarge;
                    parsingStage_ = HTTP_PARSE_DONE;
fprintf(stderr, "parse DONE: HTTP/1.x\n");
                } else {
                    debugs(33, 5, "Incomplete request, waiting for end of headers");
fprintf(stderr, "parse MIME incomplete\n");
}                return false;
            }
            mimeHeaderBlock_.assign(&buf[req.end+1], mimeHeaderBytes);
            parseOffset_ += mimeHeaderBytes; // done with these bytes now.

        } else {
            debugs(33, 3, "Missing HTTP/1.x identifier");
fprintf(stderr, "parse MIME: HTTP/0.9\n");
}
        // NP: we do not do any further stages here yet so go straight to DONE
        parsingStage_ = HTTP_PARSE_DONE;

