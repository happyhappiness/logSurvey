 	if (opt->show_log_size)
 		printf("log size %i\n", (int)msgbuf.len);
 
-	if (msgbuf.len)
-		printf("%s%s%s", msgbuf.buf, extra, sep);
+	if (msgbuf.len) {
+		fwrite(msgbuf.buf, sizeof(char), msgbuf.len, stdout);
+		printf("%s%s", extra, sep);
+	}
 	strbuf_release(&msgbuf);
 }
 
