            hdr_out->putStr(HDR_FRONT_END_HTTPS, "On");
    }

    /* Now mangle the headers. */
    if (Config2.onoff.mangle_request_headers)
        httpHdrMangleList(hdr_out, request, ROR_REQUEST);
