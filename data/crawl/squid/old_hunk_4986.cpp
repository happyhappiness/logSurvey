    char *cenc = mimeGetContentEncoding(name);

    if (cenc)
        memBufPrintf(mb, "Content-Encoding: %s\r\n", cenc);

    memBufPrintf(mb, "Content-Type: %s\r\n",
                 ctype ? ctype : def_ctype);
}


