    Must(io.flag == COMM_OK);
    Must(io.size >= 0);

    al.icap.bytesRead+=io.size;

    updateTimeout();
