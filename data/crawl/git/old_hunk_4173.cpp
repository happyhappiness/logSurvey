		diff_words_show(ecbdata->diff_words);
}

static void free_diff_words_data(struct emit_callback *ecbdata)
{
	if (ecbdata->diff_words) {
