{
    MemBuf mb;
    mb.init();
    mb.vappendf(fmt, vargs);
    hdr->putStr(id, mb.buf);
    mb.clean();
}
