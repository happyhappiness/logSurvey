 			sign = '-';
 
 		if (verbose) {
-			char *buf = NULL;
-			unsigned long buflen = 0;
-			pretty_print_commit(CMIT_FMT_ONELINE, commit, ~0,
-			                    &buf, &buflen, 0, NULL, NULL, 0);
+			struct strbuf buf;
+			strbuf_init(&buf, 0);
+			pretty_print_commit(CMIT_FMT_ONELINE, commit,
+			                    &buf, 0, NULL, NULL, 0);
 			printf("%c %s %s\n", sign,
-			       sha1_to_hex(commit->object.sha1), buf);
-			free(buf);
+			       sha1_to_hex(commit->object.sha1), buf.buf);
+			strbuf_release(&buf);
 		}
 		else {
 			printf("%c %s\n", sign,
