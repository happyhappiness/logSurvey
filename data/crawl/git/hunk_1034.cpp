 {
 	int fd = *(int *)cb;
 	if (graft->nr_parent == -1)
-		packet_write(fd, "shallow %s\n", oid_to_hex(&graft->oid));
+		packet_write_fmt(fd, "shallow %s\n", oid_to_hex(&graft->oid));
 	return 0;
 }
 