 	char *quoted_url = rfc1738_escape_part(errorConvert('u', err));
 	httpReplySetHeaders(rep, version, HTTP_MOVED_TEMPORARILY, NULL, "text/html", 0, 0, squid_curtime);
 	httpHeaderPutStrf(&rep->header, HDR_LOCATION, name, quoted_url);
-	httpHeaderPutStrf(&rep->header, HDR_X_SQUID_ERROR, "%d %s\n", err->http_status, "Access Denied");
+	httpHeaderPutStrf(&rep->header, HDR_X_SQUID_ERROR, "%d %s\n", err->httpStatus, "Access Denied");
     } else {
 	MemBuf content = errorBuildContent(err);
-	httpReplySetHeaders(rep, version, err->http_status, NULL, "text/html", content.size, 0, squid_curtime);
+	httpReplySetHeaders(rep, version, err->httpStatus, NULL, "text/html", content.size, 0, squid_curtime);
 	/*
 	 * include some information for downstream caches. Implicit
 	 * replaceable content. This isn't quite sufficient. xerrno is not
