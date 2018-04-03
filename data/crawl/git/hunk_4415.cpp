 	}
 	strbuf_release(&buf);
 	if (fclose(show_out))
-		die_errno("failed to close pipe to 'show' for object '%s'",
+		die_errno(_("failed to close pipe to 'show' for object '%s'"),
 			  sha1_to_hex(object));
 	if (finish_command(&show))
-		die("failed to finish 'show' for object '%s'",
+		die(_("failed to finish 'show' for object '%s'"),
 		    sha1_to_hex(object));
 }
 
