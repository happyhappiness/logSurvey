 	}
 	write_name(ce->name, ce_namelen(ce));
 	if (debug_mode) {
-		printf("  ctime: %d:%d\n", ce->ce_ctime.sec, ce->ce_ctime.nsec);
-		printf("  mtime: %d:%d\n", ce->ce_mtime.sec, ce->ce_mtime.nsec);
-		printf("  dev: %d\tino: %d\n", ce->ce_dev, ce->ce_ino);
-		printf("  uid: %d\tgid: %d\n", ce->ce_uid, ce->ce_gid);
-		printf("  size: %d\tflags: %x\n", ce->ce_size, ce->ce_flags);
+		struct stat_data *sd = &ce->ce_stat_data;
+
+		printf("  ctime: %d:%d\n", sd->sd_ctime.sec, sd->sd_ctime.nsec);
+		printf("  mtime: %d:%d\n", sd->sd_mtime.sec, sd->sd_mtime.nsec);
+		printf("  dev: %d\tino: %d\n", sd->sd_dev, sd->sd_ino);
+		printf("  uid: %d\tgid: %d\n", sd->sd_uid, sd->sd_gid);
+		printf("  size: %d\tflags: %x\n", sd->sd_size, ce->ce_flags);
 	}
 }
 
