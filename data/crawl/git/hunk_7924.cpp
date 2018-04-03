 
 		sprintf(pathname + len, "%02x/", i);
 		d = opendir(pathname);
-		if (opts == VERBOSE && (d || i == 255))
-			fprintf(stderr, "Removing unused objects %d%%...\015",
-				((i+1) * 100) / 256);
 		if (!d)
 			continue;
 		prune_dir(i, d, pathname, len + 3, opts);
 		closedir(d);
 	}
 	if (opts == VERBOSE)
-		fprintf(stderr, "\nDone.\n");
+		stop_progress(&progress);
 }
 
 int cmd_prune_packed(int argc, const char **argv, const char *prefix)