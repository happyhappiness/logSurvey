 			if (ret >= 0)   /* normal exit */
 				exit(ret);
 
-			die_errno("While expanding alias '%s': '%s'",
+			die_errno("while expanding alias '%s': '%s'",
 			    alias_command, alias_string + 1);
 		}
 		count = split_cmdline(alias_string, &new_argv);
