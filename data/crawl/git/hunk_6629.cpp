 			die("this should not happen, your snprintf is broken");
 	}
 
-	error(sb.buf);
+	error("%s", sb.buf);
 	strbuf_release(&sb);
 	return 1;
 }
