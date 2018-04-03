#include "cache.h"
#include "xdiff/xdiff.h"
#include "xdiff-interface.h"
#include "parse-options.h"

static const char *const merge_file_usage[] = {
	"git merge-file [options] [-L name1 [-L orig [-L name2]]] file1 orig_file file2",
	NULL
};

static int label_cb(const struct option *opt, const char *arg, int unset)
{
	static int label_count = 0;
	const char **names = (const char **)opt->value;

	if (label_count >= 3)
		return error("too many labels on the command line");
	names[label_count++] = arg;
	return 0;
}

int cmd_merge_file(int argc, const char **argv, const char *prefix)
{
	const char *names[3] = { NULL, NULL, NULL };
	mmfile_t mmfs[3];
	mmbuffer_t result = {NULL, 0};
	xpparam_t xpp = {XDF_NEED_MINIMAL};
	int ret = 0, i = 0, to_stdout = 0;
	int merge_level = XDL_MERGE_ZEALOUS_ALNUM;
	int merge_style = 0, quiet = 0;
	int nongit;

	struct option options[] = {
		OPT_BOOLEAN('p', "stdout", &to_stdout, "send results to standard output"),
		OPT_SET_INT(0, "diff3", &merge_style, "use a diff3 based merge", XDL_MERGE_DIFF3),
		OPT__QUIET(&quiet),
		OPT_CALLBACK('L', NULL, names, "name",
			     "set labels for file1/orig_file/file2", &label_cb),
		OPT_END(),
	};

	prefix = setup_git_directory_gently(&nongit);
	if (!nongit) {
		/* Read the configuration file */
