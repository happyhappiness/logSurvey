 		return error("packfile %s not found.", arg);
 
 	install_packed_git(pack);
-	err = verify_pack(pack);
 
-	if (verbose) {
+	if (!stat_only)
+		err = verify_pack(pack);
+	else
+		err = open_pack_index(pack);
+
+	if (verbose || stat_only) {
 		if (err)
 			printf("%s: bad\n", pack->pack_name);
 		else {
-			show_pack_info(pack);
-			printf("%s: ok\n", pack->pack_name);
+			show_pack_info(pack, flags);
+			if (!stat_only)
+				printf("%s: ok\n", pack->pack_name);
 		}
 	}
 
 	return err;
 }
 
 static const char * const verify_pack_usage[] = {
-	"git verify-pack [-v|--verbose] <pack>...",
+	"git verify-pack [-v|--verbose] [-s|--stat-only] <pack>...",
 	NULL
 };
 
 int cmd_verify_pack(int argc, const char **argv, const char *prefix)
 {
 	int err = 0;
-	int verbose = 0;
+	unsigned int flags = 0;
 	int i;
 	const struct option verify_pack_options[] = {
-		OPT__VERBOSE(&verbose),
+		OPT_BIT('v', "verbose", &flags, "verbose",
+			VERIFY_PACK_VERBOSE),
+		OPT_BIT('s', "stat-only", &flags, "show statistics only",
+			VERIFY_PACK_STAT_ONLY),
 		OPT_END()
 	};
 
