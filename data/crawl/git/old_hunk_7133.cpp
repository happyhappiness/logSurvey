#include "diffcore.h"
#include "revision.h"
#include "cache-tree.h"
#include "path-list.h"
#include "unpack-trees.h"
#include "refs.h"

/*
 * diff-files
 */

static int read_directory(const char *path, struct path_list *list)
{
	DIR *dir;
	struct dirent *e;

	if (!(dir = opendir(path)))
		return error("Could not open directory %s", path);

	while ((e = readdir(dir)))
		if (strcmp(".", e->d_name) && strcmp("..", e->d_name))
			path_list_insert(e->d_name, list);

	closedir(dir);
	return 0;
}

static int get_mode(const char *path, int *mode)
{
	struct stat st;

	if (!path || !strcmp(path, "/dev/null"))
		*mode = 0;
	else if (!strcmp(path, "-"))
		*mode = create_ce_mode(0666);
	else if (stat(path, &st))
		return error("Could not access '%s'", path);
	else
		*mode = st.st_mode;
	return 0;
}

static int queue_diff(struct diff_options *o,
		const char *name1, const char *name2)
{
	int mode1 = 0, mode2 = 0;

	if (get_mode(name1, &mode1) || get_mode(name2, &mode2))
		return -1;

	if (mode1 && mode2 && S_ISDIR(mode1) != S_ISDIR(mode2))
		return error("file/directory conflict: %s, %s", name1, name2);

	if (S_ISDIR(mode1) || S_ISDIR(mode2)) {
		char buffer1[PATH_MAX], buffer2[PATH_MAX];
		struct path_list p1 = {NULL, 0, 0, 1}, p2 = {NULL, 0, 0, 1};
		int len1 = 0, len2 = 0, i1, i2, ret = 0;

		if (name1 && read_directory(name1, &p1))
			return -1;
		if (name2 && read_directory(name2, &p2)) {
			path_list_clear(&p1, 0);
			return -1;
		}

		if (name1) {
			len1 = strlen(name1);
			if (len1 > 0 && name1[len1 - 1] == '/')
				len1--;
			memcpy(buffer1, name1, len1);
			buffer1[len1++] = '/';
		}

		if (name2) {
			len2 = strlen(name2);
			if (len2 > 0 && name2[len2 - 1] == '/')
				len2--;
			memcpy(buffer2, name2, len2);
			buffer2[len2++] = '/';
		}

		for (i1 = i2 = 0; !ret && (i1 < p1.nr || i2 < p2.nr); ) {
			const char *n1, *n2;
			int comp;

			if (i1 == p1.nr)
				comp = 1;
			else if (i2 == p2.nr)
				comp = -1;
			else
				comp = strcmp(p1.items[i1].path,
					p2.items[i2].path);

			if (comp > 0)
				n1 = NULL;
			else {
				n1 = buffer1;
				strncpy(buffer1 + len1, p1.items[i1++].path,
						PATH_MAX - len1);
			}

			if (comp < 0)
				n2 = NULL;
			else {
				n2 = buffer2;
				strncpy(buffer2 + len2, p2.items[i2++].path,
						PATH_MAX - len2);
			}

			ret = queue_diff(o, n1, n2);
		}
		path_list_clear(&p1, 0);
		path_list_clear(&p2, 0);

		return ret;
	} else {
		struct diff_filespec *d1, *d2;

		if (DIFF_OPT_TST(o, REVERSE_DIFF)) {
			unsigned tmp;
			const char *tmp_c;
			tmp = mode1; mode1 = mode2; mode2 = tmp;
			tmp_c = name1; name1 = name2; name2 = tmp_c;
		}

		if (!name1)
			name1 = "/dev/null";
		if (!name2)
			name2 = "/dev/null";
		d1 = alloc_filespec(name1);
		d2 = alloc_filespec(name2);
		fill_filespec(d1, null_sha1, mode1);
		fill_filespec(d2, null_sha1, mode2);

		diff_queue(&diff_queued_diff, d1, d2);
		return 0;
	}
}

/*
 * Does the path name a blob in the working tree, or a directory
 * in the working tree?
 */
static int is_in_index(const char *path)
{
	int len, pos;
	struct cache_entry *ce;

	len = strlen(path);
	while (path[len-1] == '/')
		len--;
	if (!len)
		return 1; /* "." */
	pos = cache_name_pos(path, len);
	if (0 <= pos)
		return 1;
	pos = -1 - pos;
	while (pos < active_nr) {
		ce = active_cache[pos++];
		if (ce_namelen(ce) <= len ||
		    strncmp(ce->name, path, len) ||
		    (ce->name[len] > '/'))
			break; /* path cannot be a prefix */
		if (ce->name[len] == '/')
			return 1;
	}
	return 0;
}

static int handle_diff_files_args(struct rev_info *revs,
				  int argc, const char **argv,
				  unsigned int *options)
{
	*options = 0;

	/* revs->max_count == -2 means --no-index */
	while (1 < argc && argv[1][0] == '-') {
		if (!strcmp(argv[1], "--base"))
			revs->max_count = 1;
		else if (!strcmp(argv[1], "--ours"))
			revs->max_count = 2;
		else if (!strcmp(argv[1], "--theirs"))
			revs->max_count = 3;
		else if (!strcmp(argv[1], "-n") ||
				!strcmp(argv[1], "--no-index")) {
			revs->max_count = -2;
			DIFF_OPT_SET(&revs->diffopt, EXIT_WITH_STATUS);
			DIFF_OPT_SET(&revs->diffopt, NO_INDEX);
		}
		else if (!strcmp(argv[1], "-q"))
			*options |= DIFF_SILENT_ON_REMOVED;
		else
			return error("invalid option: %s", argv[1]);
		argv++; argc--;
	}

	if (revs->max_count == -1 && revs->diffopt.nr_paths == 2) {
		/*
		 * If two files are specified, and at least one is untracked,
		 * default to no-index.
		 */
		read_cache();
		if (!is_in_index(revs->diffopt.paths[0]) ||
					!is_in_index(revs->diffopt.paths[1])) {
			revs->max_count = -2;
			DIFF_OPT_SET(&revs->diffopt, NO_INDEX);
		}
	}

	/*
	 * Make sure there are NO revision (i.e. pending object) parameter,
	 * rev.max_count is reasonable (0 <= n <= 3),
	 * there is no other revision filtering parameters.
	 */
	if (revs->pending.nr || revs->max_count > 3 ||
	    revs->min_age != -1 || revs->max_age != -1)
		return error("no revision allowed with diff-files");

	if (revs->max_count == -1 &&
	    (revs->diffopt.output_format & DIFF_FORMAT_PATCH))
		revs->combine_merges = revs->dense_combined_merges = 1;

	return 0;
}

static int is_outside_repo(const char *path, int nongit, const char *prefix)
{
	int i;
	if (nongit || !strcmp(path, "-") || is_absolute_path(path))
		return 1;
	if (prefixcmp(path, "../"))
		return 0;
	if (!prefix)
		return 1;
	for (i = strlen(prefix); !prefixcmp(path, "../"); ) {
		while (i > 0 && prefix[i - 1] != '/')
			i--;
		if (--i < 0)
			return 1;
		path += 3;
	}
	return 0;
}

int setup_diff_no_index(struct rev_info *revs,
		int argc, const char ** argv, int nongit, const char *prefix)
{
	int i;
	for (i = 1; i < argc; i++)
		if (argv[i][0] != '-' || argv[i][1] == '\0')
			break;
		else if (!strcmp(argv[i], "--")) {
			i++;
			break;
		} else if (i < argc - 3 && !strcmp(argv[i], "--no-index")) {
			i = argc - 3;
			DIFF_OPT_SET(&revs->diffopt, EXIT_WITH_STATUS);
			break;
		}
	if (nongit && argc != i + 2)
		die("git diff [--no-index] takes two paths");

	if (argc != i + 2 || (!is_outside_repo(argv[i + 1], nongit, prefix) &&
				!is_outside_repo(argv[i], nongit, prefix)))
		return -1;

	diff_setup(&revs->diffopt);
	for (i = 1; i < argc - 2; )
		if (!strcmp(argv[i], "--no-index"))
			i++;
		else {
			int j = diff_opt_parse(&revs->diffopt,
					argv + i, argc - i);
			if (!j)
				die("invalid diff option/value: %s", argv[i]);
			i += j;
		}

	if (prefix) {
		int len = strlen(prefix);

		revs->diffopt.paths = xcalloc(2, sizeof(char*));
		for (i = 0; i < 2; i++) {
			const char *p = argv[argc - 2 + i];
			/*
			 * stdin should be spelled as '-'; if you have
			 * path that is '-', spell it as ./-.
			 */
			p = (strcmp(p, "-")
			     ? xstrdup(prefix_filename(prefix, len, p))
			     : p);
			revs->diffopt.paths[i] = p;
		}
	}
	else
		revs->diffopt.paths = argv + argc - 2;
	revs->diffopt.nr_paths = 2;
	DIFF_OPT_SET(&revs->diffopt, NO_INDEX);
	revs->max_count = -2;
	if (diff_setup_done(&revs->diffopt) < 0)
		die("diff_setup_done failed");
	return 0;
}

int run_diff_files_cmd(struct rev_info *revs, int argc, const char **argv)
{
	unsigned int options;

	if (handle_diff_files_args(revs, argc, argv, &options))
		return -1;

	if (DIFF_OPT_TST(&revs->diffopt, NO_INDEX)) {
		if (revs->diffopt.nr_paths != 2)
			return error("need two files/directories with --no-index");
		if (queue_diff(&revs->diffopt, revs->diffopt.paths[0],
				revs->diffopt.paths[1]))
			return -1;
		diffcore_std(&revs->diffopt);
		diff_flush(&revs->diffopt);
		/*
		 * The return code for --no-index imitates diff(1):
		 * 0 = no changes, 1 = changes, else error
		 */
		return revs->diffopt.found_changes;
	}

	if (read_cache() < 0) {
		perror("read_cache");
		return -1;
	}
	return run_diff_files(revs, options);
}

/*
 * Has the work tree entity been removed?
 *
