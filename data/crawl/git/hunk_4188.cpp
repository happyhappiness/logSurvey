 		show_stats(patch);
 	}
 
-	printf(" %d files changed, %d insertions(+), %d deletions(-)\n", files, adds, dels);
+	print_stat_summary(stdout, files, adds, dels);
 }
 
 static void numstat_patch_list(struct patch *patch)