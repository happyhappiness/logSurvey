 	int cnt;
 	const char *cp;
 	struct origin *suspect = ent->suspect;
-	char hex[41];
+	char hex[GIT_SHA1_HEXSZ + 1];
 
-	strcpy(hex, sha1_to_hex(suspect->commit->object.sha1));
+	sha1_to_hex_r(hex, suspect->commit->object.sha1);
 	printf("%s %d %d %d\n",
 	       hex,
 	       ent->s_lno + 1,
