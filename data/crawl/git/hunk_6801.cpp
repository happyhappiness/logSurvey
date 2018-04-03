 			packet_write(1, "NAK\n");
 			return -1;
 		}
-		die("git-upload-pack: expected SHA1 list, got '%s'", line);
+		die("git upload-pack: expected SHA1 list, got '%s'", line);
 	}
 }
 
