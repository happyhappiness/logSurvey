            hdr_out->putStr(HDR_FRONT_END_HTTPS, "On");
    }

    if (orig_request->header.chunked() && orig_request->content_length <= 0) {
        /* Preserve original chunked encoding unless we learned the length.
         * Do not just copy the original value so that if the client-side
         * starts decode other encodings, this code may remain valid.
         */
        hdr_out->putStr(HDR_TRANSFER_ENCODING, "chunked");
    }

    /* Now mangle the headers. */
    if (Config2.onoff.mangle_request_headers)
        httpHdrMangleList(hdr_out, request, ROR_REQUEST);
