 		return;
 	out = reencode_string(line->buf, metainfo_charset, charset);
 	if (!out)
-		die("cannot convert from %s to %s\n",
+		die("cannot convert from %s to %s",
 		    charset, metainfo_charset);
 	strbuf_attach(line, out, strlen(out), strlen(out));
 }
