 	if (!submodule_dot_git)
 		die_errno(_("cannot open file '%s'"), sb.buf);
 
-	fprintf(submodule_dot_git, "gitdir: %s\n",
-		relative_path(sm_gitdir, path, &rel_path));
+	fprintf_or_die(submodule_dot_git, "gitdir: %s\n",
+		       relative_path(sm_gitdir, path, &rel_path));
 	if (fclose(submodule_dot_git))
 		die(_("could not close file %s"), sb.buf);
 	strbuf_reset(&sb);