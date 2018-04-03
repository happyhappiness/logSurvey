    debugs(93, 5, HERE << "have " << readBuf.contentSize() << " body bytes after " <<
           "parse; parsed all: " << parsed);

    if (parsed) {
        stopParsing();
        stopSending(true); // the parser succeeds only if all parsed data fits
