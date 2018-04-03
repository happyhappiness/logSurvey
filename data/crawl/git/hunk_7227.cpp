 
 	if (msgbuf.len) {
 		fwrite(msgbuf.buf, sizeof(char), msgbuf.len, stdout);
-		printf("%s%s", extra, sep);
+		if (opt->use_terminator)
+			putchar('\n');
 	}
 	strbuf_release(&msgbuf);
 }
