    MemBuf mb;
    mb.init();
    mb.vPrintf(fmt, vargs);
    httpHeaderPutStr(hdr, id, mb.buf);
    mb.clean();
}

