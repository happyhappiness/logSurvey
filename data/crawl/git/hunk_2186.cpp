 		return find_name(line, NULL, p_value, TERM_TAB);
 
 	if (orig_name) {
-		int len;
-		const char *name;
+		int len = strlen(orig_name);
 		char *another;
-		name = orig_name;
-		len = strlen(name);
 		if (isnull)
-			die(_("git apply: bad git-diff - expected /dev/null, got %s on line %d"), name, linenr);
+			die(_("git apply: bad git-diff - expected /dev/null, got %s on line %d"),
+			    orig_name, linenr);
 		another = find_name(line, NULL, p_value, TERM_TAB);
-		if (!another || memcmp(another, name, len + 1))
+		if (!another || memcmp(another, orig_name, len + 1))
 			die((side == DIFF_NEW_NAME) ?
 			    _("git apply: bad git-diff - inconsistent new filename on line %d") :
 			    _("git apply: bad git-diff - inconsistent old filename on line %d"), linenr);
 		free(another);
 		return orig_name;
-	}
-	else {
+	} else {
 		/* expect "/dev/null" */
 		if (memcmp("/dev/null", line, 9) || line[9] != '\n')
 			die(_("git apply: bad git-diff - expected /dev/null on line %d"), linenr);