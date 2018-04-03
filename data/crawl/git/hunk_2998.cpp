 				"This means the bug has been fixed "
 				"between %s and [%s].\n",
 				bad_hex, bad_hex, good_hex);
+		} else if (!strcmp(term_bad, "new") && !strcmp(term_good, "old")) {
+			fprintf(stderr, "The merge base %s is new.\n"
+				"The property has changed "
+				"between %s and [%s].\n",
+				bad_hex, bad_hex, good_hex);
 		} else {
 			fprintf(stderr, "The merge base %s is %s.\n"
 				"This means the first '%s' commit is "
