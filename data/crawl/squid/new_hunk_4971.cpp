    httpHeaderClean(&hdr);

    /* append <crlf> (we packed a header, not a reply) */
    mb->Printf("\r\n");
}

/*
