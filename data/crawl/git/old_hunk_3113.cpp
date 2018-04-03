	}
}

static void batch_one_object(const char *obj_name, struct batch_options *opt,
			     struct expand_data *data)
{
	struct strbuf buf = STRBUF_INIT;
	struct object_context ctx;
	int flags = opt->follow_symlinks ? GET_SHA1_FOLLOW_SYMLINKS : 0;
	enum follow_symlinks_result result;
