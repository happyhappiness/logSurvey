 		if (!has_sha1_pack(sha1, NULL))
 			continue;
 		memcpy(pathname + len, de->d_name, 38);
+		if (opts == VERBOSE)
+			display_progress(&progress, i + 1);
 		if (opts & DRY_RUN)
 			printf("rm -f %s\n", pathname);
 		else if (unlink(pathname) < 0)
