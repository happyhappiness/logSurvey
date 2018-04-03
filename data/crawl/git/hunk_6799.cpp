 
  fail:
 	send_client_data(3, abort_msg, sizeof(abort_msg));
-	die("git-upload-pack: %s", abort_msg);
+	die("git upload-pack: %s", abort_msg);
 }
 
 static int got_sha1(char *hex, unsigned char *sha1)
