 {
 	const struct ref *rm = mapped_refs;
 
+	if (0 <= option_verbosity)
+		printf(_("Checking connectivity... "));
 	if (check_everything_connected(iterate_ref_map, 0, &rm))
 		die(_("remote did not send all necessary objects"));
+	if (0 <= option_verbosity)
+		printf(_("done\n"));
 
 	if (refs) {
 		write_remote_refs(mapped_refs);