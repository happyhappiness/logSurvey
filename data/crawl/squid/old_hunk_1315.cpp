        return;

    if (io.flag != Comm::OK) {
        debugs(33, 3, HERE << "FTP reply data writing failed: " <<
               xstrerr(io.xerrno));
        closeDataConnection();
        writeCustomReply(426, "Data connection error; transfer aborted");
