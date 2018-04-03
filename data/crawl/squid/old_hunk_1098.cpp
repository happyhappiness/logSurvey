    /* append Authorization if known in URL, not in header and going direct */
    if (!hdr_out->has(HDR_AUTHORIZATION)) {
        if (!request->flags.proxying && !request->url.userInfo().isEmpty()) {
            static char result[MAX_URL*2]; // should be big enough for a single URI segment
            if (base64_encode_str(result, sizeof(result)-1, request->url.userInfo().rawContent(), request->url.userInfo().length()) < static_cast<int>(sizeof(result)-1))
                httpHeaderPutStrf(hdr_out, HDR_AUTHORIZATION, "Basic %s", result);
        }
    }

