
    httpHeaderAddContRange(&hdr, *spec, rep->content_length);

    hdr.packInto(mb);
    hdr.clean();

    /* append <crlf> (we packed a header, not a reply) */
    mb->append("\r\n", 2);
}

/**
