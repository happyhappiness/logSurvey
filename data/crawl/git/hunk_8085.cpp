+/*
+ * "git reset" builtin command
+ *
+ * Copyright (c) 2007 Carlos Rica
+ *
+ * Based on git-reset.sh, which is
+ *
+ * Copyright (c) 2005, 2006 Linus Torvalds and Junio C Hamano
+ */
+#include "cache.h"
+#include "tag.h"
+#include "object.h"
+#include "commit.h"
+#include "run-command.h"
+#include "refs.h"
+#include "diff.h"
+#include "diffcore.h"
+#include "tree.h"
+
+static const char builtin_reset_usage[] =
+"git-reset [--mixed | --soft | --hard]  [<commit-ish>] [ [--] <paths>...]";
+
+static char *args_to_str(const char **argv)
+{
+	char *buf = NULL;
+	unsigned long len, space = 0, nr = 0;
+
+	for (; *argv; argv++) {
+		len = strlen(*argv);
+		ALLOC_GROW(buf, nr + 1 + len, space);
+		if (nr)
+			buf[nr++] = ' ';
+		memcpy(buf + nr, *argv, len);
+		nr += len;
+	}
+	ALLOC_GROW(buf, nr + 1, space);
+	buf[nr] = '\0';
+
+	return buf;
+}
+
+static inline int is_merge(void)
+{
+	return !access(git_path("MERGE_HEAD"), F_OK);
+}
+
+static int unmerged_files(void)
+{
+	char b;
+	ssize_t len;
+	struct child_process cmd;
+	const char *argv_ls_files[] = {"ls-files", "--unmerged", NULL};
+
+	memset(&cmd, 0, sizeof(cmd));
+	cmd.argv = argv_ls_files;
+	cmd.git_cmd = 1;
+	cmd.out = -1;
+
+	if (start_command(&cmd))
+		die("Could not run sub-command: git ls-files");
+
+	len = xread(cmd.out, &b, 1);
+	if (len < 0)
+		die("Could not read output from git ls-files: %s",
+						strerror(errno));
+	finish_command(&cmd);
+
+	return len;
+}
+
+static int reset_index_file(const unsigned char *sha1, int is_hard_reset)
+{
+	int i = 0;
+	const char *args[6];
+
+	args[i++] = "read-tree";
+	args[i++] = "-v";
+	args[i++] = "--reset";
+	if (is_hard_reset)
+		args[i++] = "-u";
+	args[i++] = sha1_to_hex(sha1);
+	args[i] = NULL;
+
+	return run_command_v_opt(args, RUN_GIT_CMD);
+}
+
+static void print_new_head_line(struct commit *commit)
+{
+	const char *hex, *dots = "...", *body;
+
+	hex = find_unique_abbrev(commit->object.sha1, DEFAULT_ABBREV);
+	if (!hex) {
+		hex = sha1_to_hex(commit->object.sha1);
+		dots = "";
+	}
+	printf("HEAD is now at %s%s", hex, dots);
+	body = strstr(commit->buffer, "\n\n");
+	if (body) {
+		const char *eol;
+		size_t len;
+		body += 2;
+		eol = strchr(body, '\n');
+		len = eol ? eol - body : strlen(body);
+		printf(" %.*s\n", (int) len, body);
+	}
+	else
+		printf("\n");
+}
+
+static int update_index_refresh(void)
+{
+	const char *argv_update_index[] = {"update-index", "--refresh", NULL};
+	return run_command_v_opt(argv_update_index, RUN_GIT_CMD);
+}
+
+static void update_index_from_diff(struct diff_queue_struct *q,
+		struct diff_options *opt, void *data)
+{
+	int i;
+
+	/* do_diff_cache() mangled the index */
+	discard_cache();
+	read_cache();
+
+	for (i = 0; i < q->nr; i++) {
+		struct diff_filespec *one = q->queue[i]->one;
+		if (one->mode) {
+			struct cache_entry *ce;
+			ce = make_cache_entry(one->mode, one->sha1, one->path,
+				0, 0);
+			add_cache_entry(ce, ADD_CACHE_OK_TO_ADD |
+				ADD_CACHE_OK_TO_REPLACE);
+		} else
+			remove_file_from_cache(one->path);
+	}
+}
+
+static int read_from_tree(const char *prefix, const char **argv,
+		unsigned char *tree_sha1)
+{
+        struct lock_file *lock = xcalloc(1, sizeof(struct lock_file));
+	int index_fd;
+	struct diff_options opt;
+
+	memset(&opt, 0, sizeof(opt));
+	diff_tree_setup_paths(get_pathspec(prefix, (const char **)argv), &opt);
+	opt.output_format = DIFF_FORMAT_CALLBACK;
+	opt.format_callback = update_index_from_diff;
+
+	index_fd = hold_locked_index(lock, 1);
+	read_cache();
+	if (do_diff_cache(tree_sha1, &opt))
+		return 1;
+	diffcore_std(&opt);
+	diff_flush(&opt);
+	return write_cache(index_fd, active_cache, active_nr) ||
+		close(index_fd) ||
+		commit_locked_index(lock);
+}
+
+static void prepend_reflog_action(const char *action, char *buf, size_t size)
+{
+	const char *sep = ": ";
+	const char *rla = getenv("GIT_REFLOG_ACTION");
+	if (!rla)
+		rla = sep = "";
+	if (snprintf(buf, size, "%s%s%s", rla, sep, action) >= size)
+		warning("Reflog action message too long: %.*s...", 50, buf);
+}
+
+enum reset_type { MIXED, SOFT, HARD, NONE };
+static char *reset_type_names[] = { "mixed", "soft", "hard", NULL };
+
+int cmd_reset(int argc, const char **argv, const char *prefix)
+{
+	int i = 1, reset_type = NONE, update_ref_status = 0;
+	const char *rev = "HEAD";
+	unsigned char sha1[20], *orig = NULL, sha1_orig[20],
+				*old_orig = NULL, sha1_old_orig[20];
+	struct commit *commit;
+	char *reflog_action, msg[1024];
+
+	git_config(git_default_config);
+
+	reflog_action = args_to_str(argv);
+	setenv("GIT_REFLOG_ACTION", reflog_action, 0);
+
+	if (i < argc) {
+		if (!strcmp(argv[i], "--mixed")) {
+			reset_type = MIXED;
+			i++;
+		}
+		else if (!strcmp(argv[i], "--soft")) {
+			reset_type = SOFT;
+			i++;
+		}
+		else if (!strcmp(argv[i], "--hard")) {
+			reset_type = HARD;
+			i++;
+		}
+	}
+
+	if (i < argc && argv[i][0] != '-')
+		rev = argv[i++];
+
+	if (get_sha1(rev, sha1))
+		die("Failed to resolve '%s' as a valid ref.", rev);
+
+	commit = lookup_commit_reference(sha1);
+	if (!commit)
+		die("Could not parse object '%s'.", rev);
+	hashcpy(sha1, commit->object.sha1);
+
+	if (i < argc && !strcmp(argv[i], "--"))
+		i++;
+	else if (i < argc && argv[i][0] == '-')
+		usage(builtin_reset_usage);
+
+	/* git reset tree [--] paths... can be used to
+	 * load chosen paths from the tree into the index without
+	 * affecting the working tree nor HEAD. */
+	if (i < argc) {
+		if (reset_type == MIXED)
+			warning("--mixed option is deprecated with paths.");
+		else if (reset_type != NONE)
+			die("Cannot do %s reset with paths.",
+					reset_type_names[reset_type]);
+		if (read_from_tree(prefix, argv + i, sha1))
+			return 1;
+		return update_index_refresh() ? 1 : 0;
+	}
+	if (reset_type == NONE)
+		reset_type = MIXED; /* by default */
+
+	/* Soft reset does not touch the index file nor the working tree
+	 * at all, but requires them in a good order.  Other resets reset
+	 * the index file to the tree object we are switching to. */
+	if (reset_type == SOFT) {
+		if (is_merge() || unmerged_files())
+			die("Cannot do a soft reset in the middle of a merge.");
+	}
+	else if (reset_index_file(sha1, (reset_type == HARD)))
+		die("Could not reset index file to revision '%s'.", rev);
+
+	/* Any resets update HEAD to the head being switched to,
+	 * saving the previous head in ORIG_HEAD before. */
+	if (!get_sha1("ORIG_HEAD", sha1_old_orig))
+		old_orig = sha1_old_orig;
+	if (!get_sha1("HEAD", sha1_orig)) {
+		orig = sha1_orig;
+		prepend_reflog_action("updating ORIG_HEAD", msg, sizeof(msg));
+		update_ref(msg, "ORIG_HEAD", orig, old_orig, 0, MSG_ON_ERR);
+	}
+	else if (old_orig)
+		delete_ref("ORIG_HEAD", old_orig);
+	prepend_reflog_action("updating HEAD", msg, sizeof(msg));
+	update_ref_status = update_ref(msg, "HEAD", sha1, orig, 0, MSG_ON_ERR);
+
+	switch (reset_type) {
+	case HARD:
+		if (!update_ref_status)
+			print_new_head_line(commit);
+		break;
+	case SOFT: /* Nothing else to do. */
+		break;
+	case MIXED: /* Report what has not been updated. */
+		update_index_refresh();
+		break;
+	}
+
+	unlink(git_path("MERGE_HEAD"));
+	unlink(git_path("rr-cache/MERGE_RR"));
+	unlink(git_path("MERGE_MSG"));
+	unlink(git_path("SQUASH_MSG"));
+
+	free(reflog_action);
+
+	return update_ref_status;
+}
