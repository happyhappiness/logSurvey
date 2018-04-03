 			git_config_get_bool("advice.amworkdir", &advice_amworkdir);
 
 			if (advice_amworkdir)
-				printf_ln(_("The copy of the patch that failed is found in: %s"),
-						am_path(state, "patch"));
+				printf_ln(_("Use 'git am --show-current-patch' to see the failed patch"));
 
 			die_user_resolve(state);
 		}
