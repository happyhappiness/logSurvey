 		die (_("unrecognized argument: %s"), argv[1]);
 
 	if (rev.diffopt.output_format & DIFF_FORMAT_NAME)
-		die("--name-only does not make sense");
+		die(_("--name-only does not make sense"));
 	if (rev.diffopt.output_format & DIFF_FORMAT_NAME_STATUS)
-		die("--name-status does not make sense");
+		die(_("--name-status does not make sense"));
 	if (rev.diffopt.output_format & DIFF_FORMAT_CHECKDIFF)
-		die("--check does not make sense");
+		die(_("--check does not make sense"));
 
 	if (!use_patch_format &&
 		(!rev.diffopt.output_format ||
