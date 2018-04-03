
    if (shouldPreview(urlPath)) {
        buf.Printf("Preview: %d\r\n", (int)preview.ad());
        virginSendClaim.protectUpTo(preview.ad());
    }

    if (shouldAllow204()) {
        buf.Printf("Allow: 204\r\n");
        // be robust: do not rely on the expected body size
        virginSendClaim.protectAll();
    }

    if (TheICAPConfig.send_client_ip && request)
