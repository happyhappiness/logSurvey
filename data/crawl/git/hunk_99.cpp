 
 	if (mkdir(state->dir, 0777) < 0 && errno != EEXIST)
 		die_errno(_("failed to create directory '%s'"), state->dir);
+	delete_ref(NULL, "REBASE_HEAD", NULL, REF_NO_DEREF);
 
 	if (split_mail(state, patch_format, paths, keep_cr) < 0) {
 		am_destroy(state);
