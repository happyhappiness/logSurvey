	fclose(f);
}

static const char fast_import_usage[] =
"git-fast-import [--date-format=f] [--max-pack-size=n] [--depth=n] [--active-branches=n] [--export-marks=marks.file]";

int main(int argc, const char **argv)
{
	unsigned int i, show_stats = 1;

	git_config(git_default_config);
	alloc_objects(object_entry_alloc);
	strbuf_init(&command_buf, 0);
	atom_table = xcalloc(atom_table_sz, sizeof(struct atom_str*));