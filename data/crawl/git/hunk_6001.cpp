 			return -1;
 		}
 
+#ifdef WIN32
+		if (!(sb.st_mode & S_IWUSR) &&
+				chmod(argv[i], sb.st_mode | S_IWUSR)) {
+			fprintf(stderr, "Could not make user-writable %s: %s",
+				argv[i], strerror(errno));
+			return -1;
+		}
+#endif
+
 		utb.actime = sb.st_atime;
 		utb.modtime = set_eq ? set_time : sb.st_mtime + set_time;
 