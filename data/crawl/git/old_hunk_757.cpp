{
	struct ref_filter *rf = opt->value;
	unsigned char sha1[20];

	rf->merge = starts_with(opt->long_name, "no")
		? REF_FILTER_MERGED_OMIT
		: REF_FILTER_MERGED_INCLUDE;

