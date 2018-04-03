 		return error("packfile %s not found.", arg);
 
 	install_packed_git(pack);
-	err = verify_pack(pack, verbose);
+	err = verify_pack(pack);
+
+	if (verbose) {
+		if (err)
+			printf("%s: bad\n", pack->pack_name);
+		else {
+			show_pack_info(pack);
+			printf("%s: ok\n", pack->pack_name);
+		}
+	}
 
 	return err;
 }
