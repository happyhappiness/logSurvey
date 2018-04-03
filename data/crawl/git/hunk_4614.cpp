 		goto err_ret;
 	data = xmalloc(*sz + 1);
 	if (st.st_size != read_in_full(i, data, *sz)) {
-		error("'%s': short read %s", filename, strerror(errno));
+		error(_("'%s': short read %s"), filename, strerror(errno));
 		close(i);
 		free(data);
 		return 0;
