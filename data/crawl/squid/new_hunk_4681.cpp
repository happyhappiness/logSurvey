
    if (shouldPreview(urlPath)) {
        buf.Printf("Preview: %d\r\n", (int)preview.ad());
        if (virginBody.expected()) // there is a body to preview
            virginBodySending.plan();
        else
            finishNullOrEmptyBodyPreview(httpBuf);
    }

    if (shouldAllow204()) {
        debugs(93,5, HERE << "will allow 204s outside of preview");
        state.allowedPostview204 = true;
        buf.Printf("Allow: 204\r\n");
        if (virginBody.expected()) // there is a body to echo
            virginBodySending.plan();
    }

    if (TheICAPConfig.send_client_ip && request)
