        writeComplete(fd(), NULL, 0, COMM_OK);
}

/** put terminating boundary for multiparts */
static void
clientPackTermBound(String boundary, MemBuf * mb)
