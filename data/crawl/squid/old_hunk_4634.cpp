
    buf.append(ICAP::crlf, 2); // terminate Encapsulated line

    if (shouldPreview(urlPath)) {
        buf.Printf("Preview: %d\r\n", (int)preview.ad());
        if (virginBody.expected()) // there is a body to preview
            virginBodySending.plan();
