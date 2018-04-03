 	args_gpg[0] = gpg_program;
 	fd = git_mkstemp(path, PATH_MAX, ".git_vtag_tmpXXXXXX");
 	if (fd < 0)
-		return error("could not create temporary file '%s': %s",
+		return error(_("could not create temporary file '%s': %s"),
 			     path, strerror(errno));
 	if (write_in_full(fd, signature, signature_size) < 0)
-		return error("failed writing detached signature to '%s': %s",
+		return error(_("failed writing detached signature to '%s': %s"),
 			     path, strerror(errno));
 	close(fd);
 
