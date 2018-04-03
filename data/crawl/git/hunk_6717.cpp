 				return 1;
 			}
 			if (opt->name_only) {
-				printf("%s\n", name);
+				show_name(opt, name);
 				return 1;
 			}
 			/* Hit at this line.  If we haven't shown the
