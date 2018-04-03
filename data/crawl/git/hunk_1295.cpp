 			strbuf_addch(&buf, '\n');
 		}
 
+		if (mboxrd && is_gtfrom(&buf))
+			strbuf_remove(&buf, 0, 1);
+
 		if (fwrite(buf.buf, 1, buf.len, output) != buf.len)
 			die_errno("cannot write output");
 
