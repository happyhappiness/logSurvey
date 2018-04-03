#include "cache.h"
#include "xdiff/xdiff.h"
#include "xdiff-interface.h"

static const char merge_file_usage[] =
"git merge-file [-p | --stdout] [--diff3] [-q | --quiet] [-L name1 [-L orig [-L name2]]] file1 orig_file file2";

int cmd_merge_file(int argc, const char **argv, const char *prefix)
{
	const char *names[3];
	mmfile_t mmfs[3];
	mmbuffer_t result = {NULL, 0};
	xpparam_t xpp = {XDF_NEED_MINIMAL};
	int ret = 0, i = 0, to_stdout = 0;
	int merge_level = XDL_MERGE_ZEALOUS_ALNUM;
	int merge_style = 0;
	int nongit;

	prefix = setup_git_directory_gently(&nongit);
	if (!nongit) {
		/* Read the configuration file */
