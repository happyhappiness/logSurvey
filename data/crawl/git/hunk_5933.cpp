 		release_pack_memory(length, fd);
 		ret = mmap(start, length, prot, flags, fd, offset);
 		if (ret == MAP_FAILED)
-			die("Out of memory? mmap failed: %s", strerror(errno));
+			die_errno("Out of memory? mmap failed");
 	}
 	return ret;
 }
