 		name = orig_name;
 		len = strlen(name);
 		if (isnull)
-			die("git-apply: bad git-diff - expected /dev/null, got %s on line %d", name, linenr);
+			die("git apply: bad git-diff - expected /dev/null, got %s on line %d", name, linenr);
 		another = find_name(line, NULL, p_value, TERM_TAB);
 		if (!another || memcmp(another, name, len))
-			die("git-apply: bad git-diff - inconsistent %s filename on line %d", oldnew, linenr);
+			die("git apply: bad git-diff - inconsistent %s filename on line %d", oldnew, linenr);
 		free(another);
 		return orig_name;
 	}
 	else {
 		/* expect "/dev/null" */
 		if (memcmp("/dev/null", line, 9) || line[9] != '\n')
-			die("git-apply: bad git-diff - expected /dev/null on line %d", linenr);
+			die("git apply: bad git-diff - expected /dev/null on line %d", linenr);
 		return NULL;
 	}
 }
