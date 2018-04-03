 				close_pair(fdin);
 			else if (async->in)
 				close(async->in);
-			return error("cannot create pipe: %s", strerror(errno));
+			return error_errno("cannot create pipe");
 		}
 		async->out = fdout[0];
 	}
