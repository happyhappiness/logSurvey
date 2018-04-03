    Must(io.flag == COMM_OK);
    Must(io.size >= 0);

    if (!io.size) {
        commEof = true;
        reuseConnection = false;

        // detect a pconn race condition: eof on the first pconn read
        if (!al.icap.bytesRead && retriable()) {
            setOutcome(xoRace);
            mustStop("pconn race");
            return;
        }
    } else {

    al.icap.bytesRead+=io.size;

    updateTimeout();
