    cbdataFree(gopherState);
}


/**
 \ingroup ServerProtocolGopherInternal
 * Figure out content type from file extension
 */
static void
gopher_mime_content(MemBuf * mb, const char *name, const char *def_ctype)
{
    char *ctype = mimeGetContentType(name);
    char *cenc = mimeGetContentEncoding(name);

    if (cenc)
        mb->Printf("Content-Encoding: %s\r\n", cenc);

    mb->Printf("Content-Type: %s\r\n",
               ctype ? ctype : def_ctype);
}



/**
 \ingroup ServerProtocolGopherInternal
 * Create MIME Header for Gopher Data
 */
static void
gopherMimeCreate(GopherStateData * gopherState)
{
    MemBuf mb;

    mb.init();

    mb.Printf("HTTP/1.0 200 OK Gatewaying\r\n"
              "Server: Squid/%s\r\n"
              "Date: %s\r\n",
              version_string, mkrfc1123(squid_curtime));

    switch (gopherState->type_id) {

