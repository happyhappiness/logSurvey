 		printf("no untracked cache\n");
 		return 0;
 	}
-	printf("info/exclude %s\n", sha1_to_hex(uc->ss_info_exclude.sha1));
-	printf("core.excludesfile %s\n", sha1_to_hex(uc->ss_excludes_file.sha1));
+	printf("info/exclude %s\n", oid_to_hex(&uc->ss_info_exclude.oid));
+	printf("core.excludesfile %s\n", oid_to_hex(&uc->ss_excludes_file.oid));
 	printf("exclude_per_dir %s\n", uc->exclude_per_dir);
 	printf("flags %08x\n", uc->dir_flags);
 	if (uc->root)