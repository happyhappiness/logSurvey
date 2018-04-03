 			if (ret >= 0 && WIFEXITED(ret) &&
 			    WEXITSTATUS(ret) != 127)
 				exit(WEXITSTATUS(ret));
-			die("Failed to run '%s' when expanding alias '%s'\n",
+			die("Failed to run '%s' when expanding alias '%s'",
 			    alias_string + 1, alias_command);
 		}
 		count = split_cmdline(alias_string, &new_argv);
