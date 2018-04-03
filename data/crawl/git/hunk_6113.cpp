 				symbolic = SHOW_SYMBOLIC_FULL;
 				continue;
 			}
+			if (!prefixcmp(arg, "--abbrev-ref") &&
+			    (!arg[12] || arg[12] == '=')) {
+				abbrev_ref = 1;
+				abbrev_ref_strict = warn_ambiguous_refs;
+				if (arg[12] == '=') {
+					if (!strcmp(arg + 13, "strict"))
+						abbrev_ref_strict = 1;
+					else if (!strcmp(arg + 13, "loose"))
+						abbrev_ref_strict = 0;
+					else
+						die("unknown mode for %s", arg);
+				}
+				continue;
+			}
 			if (!strcmp(arg, "--all")) {
 				for_each_ref(show_reference, NULL);
 				continue;