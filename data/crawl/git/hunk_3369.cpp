 		 */
 		if (!need_to_gc())
 			return 0;
-		if (!quiet)
-			fprintf(stderr,
-					_("Auto packing the repository for optimum performance. You may also\n"
-					"run \"git gc\" manually. See "
-					"\"git help gc\" for more information.\n"));
+		if (!quiet) {
+			if (detach_auto)
+				fprintf(stderr, _("Auto packing the repository in background for optimum performance.\n"));
+			else
+				fprintf(stderr, _("Auto packing the repository for optimum performance.\n"));
+			fprintf(stderr, _("See \"git help gc\" for manual housekeeping.\n"));
+		}
+		if (detach_auto)
+			/*
+			 * failure to daemonize is ok, we'll continue
+			 * in foreground
+			 */
+			daemonize();
 	} else
 		add_repack_all_option();
 
