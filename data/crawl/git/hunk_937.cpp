 
 	new_len = got->len;
 	if (!strip_suffix_mem(got->buf, &new_len, tail))
-		return 0; /* insane redirect scheme */
+		die(_("unable to update url base from redirection:\n"
+		      "  asked for: %s\n"
+		      "   redirect: %s"),
+		    asked, got->buf);
 
 	strbuf_reset(base);
 	strbuf_add(base, got->buf, new_len);
+
 	return 1;
 }
 
