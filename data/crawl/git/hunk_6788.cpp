 			return 1;
 		}
 	}
-	die("git-fetch_pack: expected ACK/NAK, got '%s'", line);
+	die("git fetch_pack: expected ACK/NAK, got '%s'", line);
 }
 
 int path_match(const char *path, int nr, char **match)
