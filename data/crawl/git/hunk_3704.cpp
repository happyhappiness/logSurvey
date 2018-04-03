 	int config_flags = quiet ? 0 : BRANCH_CONFIG_VERBOSE;
 
 	if (strlen(new_ref) > 1024 - 7 - 7 - 1)
-		return error("Tracking not set up: name too long: %s",
+		return error(_("Tracking not set up: name too long: %s"),
 				new_ref);
 
 	memset(&tracking, 0, sizeof(tracking));
