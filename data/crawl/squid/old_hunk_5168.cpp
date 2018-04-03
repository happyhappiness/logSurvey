    debugs(19, 6, "mem_hdr::write: " << writeBuffer.range() << " object end " << endOffset());

    if (unionNotEmpty(writeBuffer)) {
        fatal("Attempt to overwrite already in-memory data\n");
        PROF_stop(mem_hdr_write);
        return false;
    }