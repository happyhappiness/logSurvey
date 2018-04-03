 
 		switch (p->status) {
 		case DIFF_STATUS_ADDED:
-			die("BUG: worktree status add???");
+			d->mode_worktree = p->two->mode;
 			break;
 
 		case DIFF_STATUS_DELETED:
