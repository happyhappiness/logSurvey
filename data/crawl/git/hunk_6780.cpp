 
 	n = read_in_full(0, buffer, HEADERSIZE);
 	if (n < HEADERSIZE)
-		die("git-get-tar-commit-id: read error");
+		die("git get-tar-commit-id: read error");
 	if (header->typeflag[0] != 'g')
 		return 1;
 	if (memcmp(content, "52 comment=", 11))
 		return 1;
 
 	n = write_in_full(1, content + 11, 41);
 	if (n < 41)
-		die("git-get-tar-commit-id: write error");
+		die("git get-tar-commit-id: write error");
 
 	return 0;
 }
