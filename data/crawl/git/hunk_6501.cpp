 		return "funny refname";
 	}
 
-	switch (deny_current_branch) {
-	case DENY_IGNORE:
-		break;
-	case DENY_WARN:
-		if (!is_ref_checked_out(name))
+	if (is_ref_checked_out(name)) {
+		switch (deny_current_branch) {
+		case DENY_IGNORE:
 			break;
-		warning("updating the currently checked out branch; this may"
-			" cause confusion,\n"
-			"as the index and working tree do not reflect changes"
-			" that are now in HEAD.");
-		break;
-	case DENY_REFUSE:
-		if (!is_ref_checked_out(name))
+		case DENY_UNCONFIGURED:
+		case DENY_WARN:
+			warning("updating the current branch");
+			if (deny_current_branch == DENY_UNCONFIGURED)
+				warn_unconfigured_deny();
 			break;
-		error("refusing to update checked out branch: %s", name);
-		return "branch is currently checked out";
+		case DENY_REFUSE:
+			error("refusing to update checked out branch: %s", name);
+			return "branch is currently checked out";
+		}
 	}
 
 	if (!is_null_sha1(new_sha1) && !has_sha1_file(new_sha1)) {
