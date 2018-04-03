    else
        strListAdd(&strFwd, "unknown", ',');

    hdr_out->putStr(HDR_X_FORWARDED_FOR, strFwd.buf());

    strFwd.clean();

    /* append Host if not there already */
    if (!hdr_out->has(HDR_HOST)) {
