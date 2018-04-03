 	 * the objects age, so a Age: 0 header does not add any useful
 	 * information to the reply in any case.
 	 */
-	if (http->entry->timestamp < squid_curtime)
-	    httpHeaderPutInt(hdr, HDR_AGE,
-		squid_curtime - http->entry->timestamp);
+	if (http->entry->timestamp > -1)
+	    if (http->entry->timestamp < squid_curtime)
+		httpHeaderPutInt(hdr, HDR_AGE,
+		    squid_curtime - http->entry->timestamp);
     }
     /* Append X-Cache */
     httpHeaderPutStrf(hdr, HDR_X_CACHE, "%s from %s",
