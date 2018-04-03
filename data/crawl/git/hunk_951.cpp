 		if (max_depth > MAX_DEPTH)
 			max_depth = MAX_DEPTH;
 	}
-	if (!git_config_get_int("pack.compression", &pack_compression_level)) {
-		if (pack_compression_level == -1)
-			pack_compression_level = Z_DEFAULT_COMPRESSION;
-		else if (pack_compression_level < 0 ||
-			 pack_compression_level > Z_BEST_COMPRESSION)
-			git_die_config("pack.compression",
-					"bad pack compression level %d", pack_compression_level);
-		pack_compression_seen = 1;
-	}
 	if (!git_config_get_int("pack.indexversion", &indexversion_value)) {
 		pack_idx_opts.version = indexversion_value;
 		if (pack_idx_opts.version > 2)
