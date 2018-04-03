 		else if (hunk == RR_SIDE_2)
 			strbuf_addstr(&two, buf);
 		else if (out)
-			fputs(buf, out);
+			ferr_puts(buf, out, &wrerror);
 		continue;
 	bad:
 		hunk = 99; /* force error exit */
