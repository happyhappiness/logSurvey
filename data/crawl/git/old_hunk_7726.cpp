	}
}

static void store_updated_refs(const char *url, struct ref *ref_map)
{
	FILE *fp;
	struct commit *commit;
	int url_len, i, note_len, shown_url = 0;
	char note[1024];
	const char *what, *kind;
	struct ref *rm;

	fp = fopen(git_path("FETCH_HEAD"), "a");
	for (rm = ref_map; rm; rm = rm->next) {
		struct ref *ref = NULL;

