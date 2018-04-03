	}
}

int cmd_fast_export(int argc, const char **argv, const char *prefix)
{
	struct rev_info revs;
	struct object_array commits = { 0, 0, NULL };
	struct path_list extra_refs = { NULL, 0, 0, 0 };
	struct commit *commit;
	struct option options[] = {
		OPT_INTEGER(0, "progress", &progress,
			    "show progress after <n> objects"),
		OPT_CALLBACK(0, "signed-tags", &signed_tag_mode, "mode",
			     "select handling of signed tags",
			     parse_opt_signed_tag_mode),
		OPT_END()
	};

