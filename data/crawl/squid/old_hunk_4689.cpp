    static MemBuf buf;
    buf.reset();

    buf.append("[", 1);

    fillPendingStatus(buf);
    buf.append("/", 1);
    fillDoneStatus(buf);

    buf.append("]", 1);

    buf.terminate();

