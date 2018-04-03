     */
    httpHeaderPutStrf(&rep->header, HDR_X_SQUID_ERROR, "%s %d",
	err_type_str[err->page_id], err->xerrno);
    httpBodySet(&rep->body, &content);
    /* do not memBufClean() the content, it was absorbed by httpBody */
    return rep;
}

