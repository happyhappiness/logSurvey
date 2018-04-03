 	for (; i < 3; i++)
 		names[i] = argv[i + 1];
 
-	for (i = 0; i < 3; i++)
+	for (i = 0; i < 3; i++) {
 		if (read_mmfile(mmfs + i, argv[i + 1]))
 			return -1;
+		if (buffer_is_binary(mmfs[i].ptr, mmfs[i].size))
+			return error("Cannot merge binary files: %s\n",
+					argv[i + 1]);
+	}
 
 	ret = xdl_merge(mmfs + 1, mmfs + 0, names[0], mmfs + 2, names[2],
 			&xpp, XDL_MERGE_ZEALOUS, &result);
