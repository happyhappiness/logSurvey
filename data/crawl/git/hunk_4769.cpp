 			if (!quiet)
 				printf("Fetching submodule %s%s\n", prefix, ce->name);
 			cp.dir = submodule_path.buf;
+			argv[default_argc] = default_argv;
 			argv[argc] = submodule_prefix.buf;
 			if (run_command(&cp))
 				result = 1;