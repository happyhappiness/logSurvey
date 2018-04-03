 					die("unknown date format %s", arg);
 				continue;
 			}
+			if (!strcmp(arg, "--log-size")) {
+				revs->show_log_size = 1;
+				continue;
+			}
 
 			/*
 			 * Grepping the commit log
