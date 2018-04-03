errorBuildReply(ErrorState * err)
{
    HttpReply *rep = httpReplyCreate();
    const char *name = errorPageName(err->page_id);
    http_version_t version;
    /* no LMT for error pages; error pages expire immediately */
    httpBuildVersion(&version, 1, 0);
    if (strchr(name, ':')) {
	/* Redirection */
	char *quoted_url = rfc1738_escape_part(errorConvert('u', err));
	httpReplySetHeaders(rep, version, HTTP_MOVED_TEMPORARILY, NULL, "text/html", 0, 0, squid_curtime);
	httpHeaderPutStrf(&rep->header, HDR_LOCATION, name, quoted_url);
	httpHeaderPutStrf(&rep->header, HDR_X_SQUID_ERROR, "%d %s\n", err->http_status, "Access Denied");
    } else {
	MemBuf content = errorBuildContent(err);
	httpReplySetHeaders(rep, version, err->http_status, NULL, "text/html", content.size, 0, squid_curtime);
	/*
	 * include some information for downstream caches. Implicit
	 * replaceable content. This isn't quite sufficient. xerrno is not
	 * necessarily meaningful to another system, so we really should
	 * expand it. Additionally, we should identify ourselves. Someone
	 * might want to know. Someone _will_ want to know OTOH, the first
	 * X-CACHE-MISS entry should tell us who.
	 */
	httpHeaderPutStrf(&rep->header, HDR_X_SQUID_ERROR, "%s %d",
	    name, err->xerrno);
	httpBodySet(&rep->body, &content);
	/* do not memBufClean() the content, it was absorbed by httpBody */
    }
    return rep;
}
