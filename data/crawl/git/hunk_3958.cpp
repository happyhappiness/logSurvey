 
 		if (S_ISDIR(st.st_mode)) {
 			strbuf_addstr(&directory, ent->name);
-			qname = quote_path_relative(directory.buf, directory.len, &buf, prefix);
-			if (show_only && (remove_directories ||
-			    (matches == MATCHED_EXACTLY))) {
-				printf(_("Would remove %s\n"), qname);
-			} else if (remove_directories ||
-				   (matches == MATCHED_EXACTLY)) {
-				if (!quiet)
-					printf(_("Removing %s\n"), qname);
-				if (remove_dir_recursively(&directory,
-							   rm_flags) != 0) {
-					warning(_("failed to remove %s"), qname);
+			if (remove_directories || (matches == MATCHED_EXACTLY)) {
+				if (remove_dirs(&directory, prefix, rm_flags, dry_run, quiet, &gone))
 					errors++;
+				if (gone && !quiet) {
+					qname = quote_path_relative(directory.buf, directory.len, &buf, prefix);
+					printf(dry_run ? _(msg_would_remove) : _(msg_remove), qname);
 				}
-			} else if (show_only) {
-				printf(_("Would not remove %s\n"), qname);
-			} else {
-				printf(_("Not removing %s\n"), qname);
 			}
 			strbuf_reset(&directory);
 		} else {
 			if (pathspec && !matches)
 				continue;
-			qname = quote_path_relative(ent->name, -1, &buf, prefix);
-			if (show_only) {
-				printf(_("Would remove %s\n"), qname);
-				continue;
-			} else if (!quiet) {
-				printf(_("Removing %s\n"), qname);
-			}
-			if (unlink(ent->name) != 0) {
-				warning(_("failed to remove %s"), qname);
+			res = dry_run ? 0 : unlink(ent->name);
+			if (res) {
+				qname = quote_path_relative(ent->name, -1, &buf, prefix);
+				warning(_(msg_warn_remove_failed), qname);
 				errors++;
+			} else if (!quiet) {
+				qname = quote_path_relative(ent->name, -1, &buf, prefix);
+				printf(dry_run ? _(msg_would_remove) : _(msg_remove), qname);
 			}
 		}
 	}