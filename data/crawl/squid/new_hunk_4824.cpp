    if (!tempstr[0])
        return;

    String strVary (rep->header.getList (HDR_VARY));

    if (!strVary.size() || strVary.buf()[0] != '*') {
        rep->header.putStr (HDR_VARY, tempstr);
    }
}
