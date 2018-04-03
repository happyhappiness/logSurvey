 				  "\tPlease update the configuration manually if necessary."),
 				buf2.buf);
 
-		if (git_config_set_multivar(buf.buf, buf2.buf, "^$", 0))
-			return error(_("Could not append '%s'"), buf.buf);
+		git_config_set_multivar_or_die(buf.buf, buf2.buf, "^$", 0);
 	}
 
 	read_branches();
