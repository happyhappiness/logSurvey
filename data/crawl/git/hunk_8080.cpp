 		const char *path = p->one->path;
 		switch (p->status) {
 		default:
-			die("unexpacted diff status %c", p->status);
+			die("unexpected diff status %c", p->status);
 		case DIFF_STATUS_UNMERGED:
 		case DIFF_STATUS_MODIFIED:
 		case DIFF_STATUS_TYPE_CHANGED:
