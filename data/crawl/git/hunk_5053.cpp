 {
 	svndump_init(NULL);
 	svndump_read((argc > 1) ? argv[1] : NULL);
+	svndump_deinit();
 	svndump_reset();
 	return 0;
 }
