 	if (pack_to_stdout != !base_name)
 		usage(pack_usage);
 
+	if (pack_to_stdout && pack_size_limit)
+		die("--max-pack-size cannot be used to build a pack for transfer.");
+
 	if (!pack_to_stdout && thin)
 		die("--thin cannot be used to build an indexable pack.");
 