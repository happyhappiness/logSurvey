		/* Store ref-to-be-updated into .git/NOTES_MERGE_REF */
		wt = find_shared_symref("NOTES_MERGE_REF", default_notes_ref());
		if (wt)
			die(_("a notes merge into %s is already in-progress at %s"),
			    default_notes_ref(), wt->path);
		if (create_symref("NOTES_MERGE_REF", default_notes_ref(), NULL))
			die(_("failed to store link to current notes ref (%s)"),
			    default_notes_ref());
		printf(_("Automatic notes merge failed. Fix conflicts in %s and "
			 "commit the result with 'git notes merge --commit', or "
