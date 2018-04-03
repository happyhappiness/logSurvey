 		write_author_script(state);
 		write_commit_msg(state);
 
-		/* NEEDSWORK: Patch application not implemented yet */
+		printf_ln(_("Applying: %.*s"), linelen(state->msg), state->msg);
+
+		if (run_apply(state) < 0) {
+			int advice_amworkdir = 1;
+
+			printf_ln(_("Patch failed at %s %.*s"), msgnum(state),
+				linelen(state->msg), state->msg);
+
+			git_config_get_bool("advice.amworkdir", &advice_amworkdir);
+
+			if (advice_amworkdir)
+				printf_ln(_("The copy of the patch that failed is found in: %s"),
+						am_path(state, "patch"));
+
+			exit(128);
+		}
+
+		/*
+		 * NEEDSWORK: After the patch has been applied to the index
+		 * with git-apply, we need to make commit as well.
+		 */
 
 next:
 		am_next(state);
