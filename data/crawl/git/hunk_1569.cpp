 		 * empty to us here.
 		 */
 		if ((state->apply || state->check) &&
-		    (!patch->is_binary && !metadata_changes(patch)))
-			die(_("patch with only garbage at line %d"), state->linenr);
+		    (!patch->is_binary && !metadata_changes(patch))) {
+			error(_("patch with only garbage at line %d"), state->linenr);
+			return -128;
+		}
 	}
 
 	return offset + hdrsize + patchsize;
