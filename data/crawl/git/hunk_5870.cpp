 	}
 
 	if (fwrite(sb.buf, 1, sb.len, fp) < sb.len)
-		die("could not write commit template: %s", strerror(errno));
+		die_errno("could not write commit template");
 
 	strbuf_release(&sb);
 
