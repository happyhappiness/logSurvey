 		strbuf_addf(buf, "%s%s", buf->len ? "\n\n" : "", arg);
 		have_message = 1;
 	} else
-		return error("switch `m' requires a value");
+		return error(_("switch `m' requires a value"));
 	return 0;
 }
 
