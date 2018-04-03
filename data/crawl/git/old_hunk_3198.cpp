			    struct expand_data *data)
{
	struct strbuf buf = STRBUF_INIT;

	if (!obj_name)
	   return 1;

	if (get_sha1(obj_name, data->sha1)) {
		printf("%s missing\n", obj_name);
		fflush(stdout);
		return 0;
	}
