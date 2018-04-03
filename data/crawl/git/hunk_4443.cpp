 			return;
 		}
 		if (unannotated_cnt)
-			die("No annotated tags can describe '%s'.\n"
-			    "However, there were unannotated tags: try --tags.",
+			die(_("No annotated tags can describe '%s'.\n"
+			    "However, there were unannotated tags: try --tags."),
 			    sha1_to_hex(sha1));
 		else
-			die("No tags can describe '%s'.\n"
-			    "Try --always, or create some tags.",
+			die(_("No tags can describe '%s'.\n"
+			    "Try --always, or create some tags."),
 			    sha1_to_hex(sha1));
 	}
 
