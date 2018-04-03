 
 	if (is_empty_file(am_path(state, "patch"))) {
 		printf_ln(_("Patch is empty. Was it split wrong?"));
-		exit(128);
+		die_user_resolve(state);
 	}
 
 	strbuf_addstr(&msg, "\n\n");
