 	} while (1);
 	inflateEnd(&stream);
 
-	fchmod(local, 0444);
-	if (close(local) != 0)
-		die("unable to write sha1 file");
+	close_sha1_file(local);
 	SHA1_Final(real_sha1, &c);
 	if (ret != Z_STREAM_END) {
 		unlink(tmpfile);