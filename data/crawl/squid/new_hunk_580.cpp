    setbuf(FDNIN, NULL);
    setbuf(FDNOUT, NULL);

    int result = processingLoop(FDKIN, FDKOUT, FDNIN, FDNOUT);
    closeFds(FDKIN, FDKOUT, FDNIN, FDNOUT);
    return result;
}
