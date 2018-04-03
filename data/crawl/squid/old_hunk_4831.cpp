
    /* stuff the header with required entries and pack it */

    if (httpHeaderHas(&rep->header, HDR_CONTENT_TYPE))
        httpHeaderPutStr(&hdr, HDR_CONTENT_TYPE, httpHeaderGetStr(&rep->header, HDR_CONTENT_TYPE));

    httpHeaderAddContRange(&hdr, *spec, rep->content_length);

    packerToMemInit(&p, mb);

    httpHeaderPackInto(&hdr, &p);

    packerClean(&p);

