 	struct origin *suspect = ent->suspect;
 	char hex[GIT_SHA1_HEXSZ + 1];
 
-	sha1_to_hex_r(hex, suspect->commit->object.sha1);
+	sha1_to_hex_r(hex, suspect->commit->object.oid.hash);
 	printf("%s %d %d %d\n",
 	       hex,
 	       ent->s_lno + 1,
