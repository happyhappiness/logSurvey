 	unsigned char *idx_sha1;
 	long fd_flag;
 
+	if (!p->index_data && open_pack_index(p))
+		return error("packfile %s index unavailable", p->pack_name);
+
 	p->pack_fd = open(p->pack_name, O_RDONLY);
 	if (p->pack_fd < 0 || fstat(p->pack_fd, &st))
 		return -1;
