    if (!tempstr[0])
        return;

    String strVary (httpHeaderGetList (&rep->header, HDR_VARY));

    if (!strVary.size() || strVary.buf()[0] != '*') {
        httpHeaderPutStr (&rep->header, HDR_VARY, tempstr);
    }
}
