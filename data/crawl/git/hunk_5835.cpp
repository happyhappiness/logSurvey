 		else {
 			if (!strcmp(msgfile, "-")) {
 				if (strbuf_read(&buf, 0, 1024) < 0)
-					die("cannot read %s", msgfile);
+					die_errno("cannot read '%s'", msgfile);
 			} else {
 				if (strbuf_read_file(&buf, msgfile, 1024) < 0)
 					die_errno("could not open or read '%s'",
