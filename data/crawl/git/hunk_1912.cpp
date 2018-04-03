 			/* When cloning, it is not unusual to have
 			 * no common commit.
 			 */
-			warning("no common commits");
+			warning(_("no common commits"));
 
 	if (args->stateless_rpc)
 		packet_flush(fd[1]);
