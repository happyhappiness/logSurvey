    request_parse_status = Http::scOkay;
    return 1;
}

bool
Http::One::RequestParser::parse()
{
    // stage 1: locate the request-line
    if (parsingStage_ == HTTP_PARSE_NEW) {
        skipGarbageLines();

        // if we hit something before EOS treat it as a message
        if (!buf.isEmpty())
            parsingStage_ = HTTP_PARSE_FIRST;
        else
            return false;
    }

    // stage 2: parse the request-line
    if (parsingStage_ == HTTP_PARSE_FIRST) {
        PROF_start(HttpParserParseReqLine);
        const int retcode = parseRequestFirstLine();
        debugs(74, 5, "request-line: retval " << retcode << ": from " << req.start << "->" << req.end <<
               " line={" << buf.length() << ", data='" << buf << "'}");
        debugs(74, 5, "request-line: method " << req.m_start << "->" << req.m_end << " (" << method_ << ")");
        debugs(74, 5, "request-line: url " << req.u_start << "->" << req.u_end << " (" << uri_ << ")");
        debugs(74, 5, "request-line: proto " << req.v_start << "->" << req.v_end << " (" << msgProtocol_ << ")");
        debugs(74, 5, "Parser: bytes processed=" << parsedCount_);
        PROF_stop(HttpParserParseReqLine);

        // syntax errors already
        if (retcode < 0) {
            parsingStage_ = HTTP_PARSE_DONE;
            return false;
        }

        // first-line (or a look-alike) found successfully.
        if (retcode > 0) {
            buf.consume(firstLineSize());// first line bytes including CRLF terminator are now done.
            parsedCount_ += firstLineSize();
            parsingStage_ = HTTP_PARSE_MIME;
        }
    }

    // stage 3: locate the mime header block
    if (parsingStage_ == HTTP_PARSE_MIME) {
        // HTTP/1.x request-line is valid and parsing completed.
        if (msgProtocol_.major == 1) {
            /* NOTE: HTTP/0.9 requests do not have a mime header block.
             *       So the rest of the code will need to deal with '0'-byte headers
             *       (ie, none, so don't try parsing em)
             */
            int64_t mimeHeaderBytes = 0;
            if ((mimeHeaderBytes = headersEnd(buf.c_str(), buf.length())) == 0) {
                if (buf.length()+firstLineSize() >= Config.maxRequestHeaderSize) {
                    debugs(33, 5, "Too large request");
                    request_parse_status = Http::scHeaderTooLarge;
                    parsingStage_ = HTTP_PARSE_DONE;
                } else
                    debugs(33, 5, "Incomplete request, waiting for end of headers");
                return false;
            }
            mimeHeaderBlock_ = buf.substr(req.end+1, mimeHeaderBytes);
            buf.consume(mimeHeaderBytes); // done with these bytes now.
            parsedCount_ += mimeHeaderBytes;

        } else
            debugs(33, 3, "Missing HTTP/1.x identifier");

        // NP: we do not do any further stages here yet so go straight to DONE
        parsingStage_ = HTTP_PARSE_DONE;

