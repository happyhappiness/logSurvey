HttpReply *
errorBuildReply(ErrorState * err)
{
    char err_hdr[CVT_BUF_SZ];
    HttpReply *rep = httpReplyCreate();
    MemBuf content = errorBuildContent(err);
    /* no LMT for error pages; error pages expire immediately */
    httpReplySetHeaders(rep, 1.0, err->http_status, NULL, "text/html", content.size, 0, squid_curtime);
    /*
     * include some information for downstream caches. Implicit
     * replaceable content This isn't quite sufficient. xerrno is not
     * necessarily meaningful to another system, so we really should
     * expand it. Additionally, we should identify ourselves. Someone
     * might want to know. Someone _will_ want to know OTOH, the first
     * X-CACHE-MISS entry should tell us who.
     */
    snprintf(err_hdr, CVT_BUF_SZ, "%s %d",
	err_type_str[err->page_id], err->xerrno);
    httpHeaderPutStr(&rep->header, HDR_X_SQUID_ERROR, err_hdr);
    httpBodySet(&rep->body, content.buf, content.size + 1, NULL);
    memBufClean(&content);
    return rep;