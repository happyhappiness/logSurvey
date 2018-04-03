
    if (io.flag != Comm::OK) {
        debugs(33, 3, "FTP reply data writing failed: " << xstrerr(io.xerrno));
        userDataCompletionCheckpoint(426);
        return;
    }

