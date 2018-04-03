 		}
 	}
 
+	if (recurse_submodules && (!use_index || untracked || list.nr))
+		die(_("option not supported with --recurse-submodules."));
+
 	if (!show_in_pager && !opt.status_only)
 		setup_pager();
 
