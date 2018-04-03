 				continue;
 			}
 			if (!strcmp(arg, "--default")) {
-				def = argv[i+1];
-				i++;
+				def = argv[++i];
+				if (!def)
+					die("--default requires an argument");
 				continue;
 			}
 			if (!strcmp(arg, "--prefix")) {
-				prefix = argv[i+1];
+				prefix = argv[++i];
+				if (!prefix)
+					die("--prefix requires an argument");
 				startup_info->prefix = prefix;
 				output_prefix = 1;
-				i++;
 				continue;
 			}
 			if (!strcmp(arg, "--revs-only")) {
