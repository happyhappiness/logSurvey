 		       ce_stage(ce));
 	}
 	write_name(ce->name, ce_namelen(ce));
+	if (debug_mode) {
+		printf("  ctime: %d:%d\n", ce->ce_ctime.sec, ce->ce_ctime.nsec);
+		printf("  mtime: %d:%d\n", ce->ce_mtime.sec, ce->ce_mtime.nsec);
+		printf("  dev: %d\tino: %d\n", ce->ce_dev, ce->ce_ino);
+		printf("  uid: %d\tgid: %d\n", ce->ce_uid, ce->ce_gid);
+		printf("  size: %d\tflags: %x\n", ce->ce_size, ce->ce_flags);
+	}
 }
 
 static int show_one_ru(struct string_list_item *item, void *cbdata)
