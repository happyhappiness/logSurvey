 
 	strbuf_reset(&buffer);
 	if (strbuf_read(&buffer, pass.out, 20) < 0)
-		die("failed to read password from %s\n", askpass);
+		die("failed to get '%s' from %s\n", prompt, cmd);
 
 	close(pass.out);
 
