 		die("malformed index info %s", buf.buf);
 	}
 	strbuf_release(&buf);
+	strbuf_release(&uq);
 }
 
 static const char update_index_usage[] =
