 	if (opts->allow_empty_message)
 		argv_array_push(&cmd.args, "--allow-empty-message");
 
+	if (cmd.err == -1) {
+		/* hide stderr on success */
+		struct strbuf buf = STRBUF_INIT;
+		int rc = pipe_command(&cmd,
+				      NULL, 0,
+				      /* stdout is already redirected */
+				      NULL, 0,
+				      &buf, 0);
+		if (rc)
+			fputs(buf.buf, stderr);
+		strbuf_release(&buf);
+		return rc;
+	}
 
 	return run_command(&cmd);
 }