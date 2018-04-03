 		info = item->util;
 		if (type == REMOTE) {
 			if (info->remote_name)
-				warning("more than one branch.%s", key);
+				warning("more than one %s", orig_key);
 			info->remote_name = xstrdup(value);
-		} else {
+		} else if (type == MERGE) {
 			char *space = strchr(value, ' ');
 			value = abbrev_branch(value);
 			while (space) {
