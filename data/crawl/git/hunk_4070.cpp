 		 */
 		if (!need_to_gc())
 			return 0;
-		if (quiet)
-			fprintf(stderr, _("Auto packing the repository for optimum performance.\n"));
-		else
+		if (!quiet)
 			fprintf(stderr,
 					_("Auto packing the repository for optimum performance. You may also\n"
 					"run \"git gc\" manually. See "
