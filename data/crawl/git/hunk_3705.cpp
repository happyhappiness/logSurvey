 		}
 
 	if (tracking.matches > 1)
-		return error("Not tracking: ambiguous information for ref %s",
+		return error(_("Not tracking: ambiguous information for ref %s"),
 				orig_ref);
 
 	install_branch_config(config_flags, new_ref, tracking.remote,
