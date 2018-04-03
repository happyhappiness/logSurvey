 			hunk_no++;
 			hunk = RR_CONTEXT;
 			if (out) {
-				fputs("<<<<<<<\n", out);
-				fwrite(one.buf, one.len, 1, out);
-				fputs("=======\n", out);
-				fwrite(two.buf, two.len, 1, out);
-				fputs(">>>>>>>\n", out);
+				ferr_puts("<<<<<<<\n", out, &wrerror);
+				ferr_write(one.buf, one.len, out, &wrerror);
+				ferr_puts("=======\n", out, &wrerror);
+				ferr_write(two.buf, two.len, out, &wrerror);
+				ferr_puts(">>>>>>>\n", out, &wrerror);
 			}
 			if (sha1) {
 				git_SHA1_Update(&ctx, one.buf ? one.buf : "",
