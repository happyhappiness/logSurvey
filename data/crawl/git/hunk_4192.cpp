 	pass.out = -1;
 
 	if (start_command(&pass))
-		exit(1);
+		return NULL;
 
 	if (strbuf_read(&buffer, pass.out, 20) < 0)
-		die("failed to get '%s' from %s\n", prompt, cmd);
+		err = 1;
 
 	close(pass.out);
 
 	if (finish_command(&pass))
-		exit(1);
+		err = 1;
+
+	if (err) {
+		error("unable to read askpass response from '%s'", cmd);
+		strbuf_release(&buffer);
+		return NULL;
+	}
 
 	strbuf_setlen(&buffer, strcspn(buffer.buf, "\r\n"));
 
