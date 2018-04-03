 			i++;
 			break;
 		}
-		if (arg[0] == '-') {
-			if (extra_argc > MAX_EXTRA_ARGS - 1)
-				die("Too many extra options");
-			extra_argv[extra_argc++] = arg;
+		if (arg[0] == '-' && isdigit(arg[1]) && arg[2] == '\0') {
+			compression_level = arg[1] - '0';
 			continue;
 		}
+		if (arg[0] == '-')
+			die("Unknown argument: %s", arg);
 		break;
 	}
 
