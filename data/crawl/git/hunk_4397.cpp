 	}
 
 	if (res) {
-		error("could not %s %s... %s",
-		      action == REVERT ? "revert" : "apply",
+		error(action == REVERT
+		      ? _("could not revert %s... %s")
+		      : _("could not apply %s... %s"),
 		      find_unique_abbrev(commit->object.sha1, DEFAULT_ABBREV),
 		      msg.subject);
 		print_advice();
