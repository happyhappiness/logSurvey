 		if (S_ISGITLINK(p->two->mode))
 			d->new_submodule_commits = !!oidcmp(&p->one->oid,
 							    &p->two->oid);
+
+		switch (p->status) {
+		case DIFF_STATUS_ADDED:
+			die("BUG: worktree status add???");
+			break;
+
+		case DIFF_STATUS_DELETED:
+			d->mode_index = p->one->mode;
+			oidcpy(&d->oid_index, &p->one->oid);
+			/* mode_worktree is zero for a delete. */
+			break;
+
+		case DIFF_STATUS_MODIFIED:
+		case DIFF_STATUS_TYPE_CHANGED:
+		case DIFF_STATUS_UNMERGED:
+			d->mode_index = p->one->mode;
+			d->mode_worktree = p->two->mode;
+			oidcpy(&d->oid_index, &p->one->oid);
+			break;
+
+		case DIFF_STATUS_UNKNOWN:
+			die("BUG: worktree status unknown???");
+			break;
+		}
+
 	}
 }
 