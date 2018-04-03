 		 * something went really wrong and we should stop
 		 * immediately.
 		 */
-		die(_("unknown error occured while reading the configuration files"));
+		die(_("unknown error occurred while reading the configuration files"));
 }
 
 static void configset_iter(struct config_set *cs, config_fn_t fn, void *data)