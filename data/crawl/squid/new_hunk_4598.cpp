        hdr->putStr(HDR_CONTENT_TYPE, ctype);
        content_type = ctype;
    } else
        content_type.clear();

    if (clen >= 0)
        hdr->putInt(HDR_CONTENT_LENGTH, clen);
