
    outputBuffer.append(" [", 2);

    outputBuffer.Printf("%" PRIu64 "<=%" PRIu64, theGetSize, thePutSize);
    if (theBodySize >= 0)
        outputBuffer.Printf("<=%" PRId64, theBodySize);
    else
        outputBuffer.append("<=?", 3);

