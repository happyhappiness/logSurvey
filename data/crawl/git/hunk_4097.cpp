 	}
 	else {
 		/* Reading from stdin */
-		contents_from = "standard input";
 		mode = 0;
 		if (strbuf_read(&buf, 0, 0) < 0)
 			die_errno("failed to read from stdin");
