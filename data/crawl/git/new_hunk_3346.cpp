	return sha1fd(fd, *pack_tmp_name);
}

void finish_tmp_packfile(struct strbuf *name_buffer,
			 const char *pack_tmp_name,
			 struct pack_idx_entry **written_list,
			 uint32_t nr_written,
			 struct pack_idx_option *pack_idx_opts,
			 unsigned char sha1[])
{
	const char *idx_tmp_name;
	int basename_len = name_buffer->len;

	if (adjust_shared_perm(pack_tmp_name))
		die_errno("unable to make temporary pack file readable");
