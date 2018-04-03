 					continue;
 				}
 				if (!getcwd(cwd, PATH_MAX))
-					die("unable to get current working directory");
+					die_errno("unable to get current working directory");
 				printf("%s/.git\n", cwd);
 				continue;
 			}
