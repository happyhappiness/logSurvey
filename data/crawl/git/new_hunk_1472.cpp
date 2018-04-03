	struct strbuf buf = STRBUF_INIT;

	if (!data->skip_object_info &&
	    sha1_object_info_extended(data->oid.hash, &data->info, LOOKUP_REPLACE_OBJECT) < 0) {
		printf("%s missing\n",
		       obj_name ? obj_name : oid_to_hex(&data->oid));
		fflush(stdout);
		return;
	}