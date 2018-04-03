 					die("Multiple --remote specified");
 				remote = arg + 9;
 				continue;
+			} else if (!strcmp(arg, "--remote")) {
+				if (remote)
+					die("Multiple --remote specified");
+				if (++ix >= cnt)
+					die("option --remote requires a value");
+				remote = av[ix];
+				continue;
 			}
 			if (arg[0] != '-')
 				no_more_options = 1;