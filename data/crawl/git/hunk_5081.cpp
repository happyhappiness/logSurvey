 				if (!c) {
 					free(*argv);
 					*argv = NULL;
-					return error("cmdline ends with \\");
+					return -SPLIT_CMDLINE_BAD_ENDING;
 				}
 			}
 			cmdline[dst++] = c;
