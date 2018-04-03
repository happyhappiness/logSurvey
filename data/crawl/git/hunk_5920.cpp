 		}
 		if (!ret)
 			die("write error (disk full?)");
-		die("write error (%s)", strerror(errno));
+		die_errno("write error");
 	}
 	return nn;
 }
