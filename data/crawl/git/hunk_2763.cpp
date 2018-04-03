 		 */
 		if (shared_repository < 0)
 			/* force to the mode value */
-			sprintf(buf, "0%o", -shared_repository);
+			xsnprintf(buf, sizeof(buf), "0%o", -shared_repository);
 		else if (shared_repository == PERM_GROUP)
-			sprintf(buf, "%d", OLD_PERM_GROUP);
+			xsnprintf(buf, sizeof(buf), "%d", OLD_PERM_GROUP);
 		else if (shared_repository == PERM_EVERYBODY)
-			sprintf(buf, "%d", OLD_PERM_EVERYBODY);
+			xsnprintf(buf, sizeof(buf), "%d", OLD_PERM_EVERYBODY);
 		else
-			die("oops");
+			die("BUG: invalid value for shared_repository");
 		git_config_set("core.sharedrepository", buf);
 		git_config_set("receive.denyNonFastforwards", "true");
 	}