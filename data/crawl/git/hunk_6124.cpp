 	cnt = strlen(patch->new_name);
 	if (ARRAY_SIZE(namebuf) <= cnt + 5) {
 		cnt = ARRAY_SIZE(namebuf) - 5;
-		fprintf(stderr,
-			"warning: truncating .rej filename to %.*s.rej",
+		warning("truncating .rej filename to %.*s.rej",
 			cnt - 1, patch->new_name);
 	}
 	memcpy(namebuf, patch->new_name, cnt);
