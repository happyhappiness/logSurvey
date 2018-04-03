#include "fetch-pack.h"
#include "walker.h"
#include "bundle.h"
#include "dir.h"
#include "refs.h"

/* rsync support */

/*
 * We copy packed-refs and refs/ into a temporary file, then read the
 * loose refs recursively (sorting whenever possible), and then inserting
 * those packed refs that are not yet in the list (not validating, but
 * assuming that the file is sorted).
 *
 * Appears refactoring this from refs.c is too cumbersome.
 */

static int str_cmp(const void *a, const void *b)
{
	const char *s1 = a;
	const char *s2 = b;

	return strcmp(s1, s2);
}

/* path->buf + name_offset is expected to point to "refs/" */

static int read_loose_refs(struct strbuf *path, int name_offset,
		struct ref **tail)
{
	DIR *dir = opendir(path->buf);
	struct dirent *de;
	struct {
		char **entries;
		int nr, alloc;
	} list;
	int i, pathlen;

	if (!dir)
		return -1;

	memset (&list, 0, sizeof(list));

	while ((de = readdir(dir))) {
		if (de->d_name[0] == '.' && (de->d_name[1] == '\0' ||
				(de->d_name[1] == '.' &&
				 de->d_name[2] == '\0')))
			continue;
		ALLOC_GROW(list.entries, list.nr + 1, list.alloc);
		list.entries[list.nr++] = xstrdup(de->d_name);
	}
	closedir(dir);

	/* sort the list */

	qsort(list.entries, list.nr, sizeof(char *), str_cmp);

	pathlen = path->len;
	strbuf_addch(path, '/');

	for (i = 0; i < list.nr; i++, strbuf_setlen(path, pathlen + 1)) {
		strbuf_addstr(path, list.entries[i]);
		if (read_loose_refs(path, name_offset, tail)) {
			int fd = open(path->buf, O_RDONLY);
			char buffer[40];
			struct ref *next;

			if (fd < 0)
				continue;
			next = alloc_ref(path->len - name_offset + 1);
			if (read_in_full(fd, buffer, 40) != 40 ||
					get_sha1_hex(buffer, next->old_sha1)) {
				close(fd);
				free(next);
				continue;
			}
			close(fd);
			strcpy(next->name, path->buf + name_offset);
			(*tail)->next = next;
			*tail = next;
		}
	}
	strbuf_setlen(path, pathlen);

	for (i = 0; i < list.nr; i++)
		free(list.entries[i]);
	free(list.entries);

	return 0;
}

/* insert the packed refs for which no loose refs were found */

static void insert_packed_refs(const char *packed_refs, struct ref **list)
{
	FILE *f = fopen(packed_refs, "r");
	static char buffer[PATH_MAX];

	if (!f)
		return;

	for (;;) {
		int cmp, len;

		if (!fgets(buffer, sizeof(buffer), f)) {
			fclose(f);
			return;
		}

		if (hexval(buffer[0]) > 0xf)
			continue;
		len = strlen(buffer);
		if (buffer[len - 1] == '\n')
			buffer[--len] = '\0';
		if (len < 41)
			continue;
		while ((*list)->next &&
				(cmp = strcmp(buffer + 41,
				      (*list)->next->name)) > 0)
			list = &(*list)->next;
		if (!(*list)->next || cmp < 0) {
			struct ref *next = alloc_ref(len - 40);
			buffer[40] = '\0';
			if (get_sha1_hex(buffer, next->old_sha1)) {
				warning ("invalid SHA-1: %s", buffer);
				free(next);
				continue;
			}
			strcpy(next->name, buffer + 41);
			next->next = (*list)->next;
			(*list)->next = next;
			list = &(*list)->next;
		}
	}
}

static struct ref *get_refs_via_rsync(const struct transport *transport)
{
	struct strbuf buf = STRBUF_INIT, temp_dir = STRBUF_INIT;
	struct ref dummy, *tail = &dummy;
	struct child_process rsync;
	const char *args[5];
	int temp_dir_len;

	/* copy the refs to the temporary directory */

	strbuf_addstr(&temp_dir, git_path("rsync-refs-XXXXXX"));
	if (!mkdtemp(temp_dir.buf))
		die ("Could not make temporary directory");
	temp_dir_len = temp_dir.len;

	strbuf_addstr(&buf, transport->url);
	strbuf_addstr(&buf, "/refs");

	memset(&rsync, 0, sizeof(rsync));
	rsync.argv = args;
	rsync.stdout_to_stderr = 1;
	args[0] = "rsync";
	args[1] = transport->verbose ? "-rv" : "-r";
	args[2] = buf.buf;
	args[3] = temp_dir.buf;
	args[4] = NULL;

	if (run_command(&rsync))
		die ("Could not run rsync to get refs");

	strbuf_reset(&buf);
	strbuf_addstr(&buf, transport->url);
	strbuf_addstr(&buf, "/packed-refs");

	args[2] = buf.buf;

	if (run_command(&rsync))
		die ("Could not run rsync to get refs");

	/* read the copied refs */

	strbuf_addstr(&temp_dir, "/refs");
	read_loose_refs(&temp_dir, temp_dir_len + 1, &tail);
	strbuf_setlen(&temp_dir, temp_dir_len);

	tail = &dummy;
	strbuf_addstr(&temp_dir, "/packed-refs");
	insert_packed_refs(temp_dir.buf, &tail);
	strbuf_setlen(&temp_dir, temp_dir_len);

	if (remove_dir_recursively(&temp_dir, 0))
		warning ("Error removing temporary directory %s.",
				temp_dir.buf);

	strbuf_release(&buf);
	strbuf_release(&temp_dir);

	return dummy.next;
}

static int fetch_objs_via_rsync(struct transport *transport,
				 int nr_objs, struct ref **to_fetch)
{
	struct strbuf buf = STRBUF_INIT;
	struct child_process rsync;
	const char *args[8];
	int result;

	strbuf_addstr(&buf, transport->url);
	strbuf_addstr(&buf, "/objects/");

	memset(&rsync, 0, sizeof(rsync));
	rsync.argv = args;
	rsync.stdout_to_stderr = 1;
	args[0] = "rsync";
	args[1] = transport->verbose ? "-rv" : "-r";
	args[2] = "--ignore-existing";
	args[3] = "--exclude";
	args[4] = "info";
	args[5] = buf.buf;
	args[6] = get_object_directory();
	args[7] = NULL;

	/* NEEDSWORK: handle one level of alternates */
	result = run_command(&rsync);

	strbuf_release(&buf);

	return result;
}

static int write_one_ref(const char *name, const unsigned char *sha1,
		int flags, void *data)
{
	struct strbuf *buf = data;
	int len = buf->len;
	FILE *f;

	/* when called via for_each_ref(), flags is non-zero */
	if (flags && prefixcmp(name, "refs/heads/") &&
			prefixcmp(name, "refs/tags/"))
		return 0;

	strbuf_addstr(buf, name);
	if (safe_create_leading_directories(buf->buf) ||
			!(f = fopen(buf->buf, "w")) ||
			fprintf(f, "%s\n", sha1_to_hex(sha1)) < 0 ||
			fclose(f))
		return error("problems writing temporary file %s", buf->buf);
	strbuf_setlen(buf, len);
	return 0;
}

static int write_refs_to_temp_dir(struct strbuf *temp_dir,
		int refspec_nr, const char **refspec)
{
	int i;

	for (i = 0; i < refspec_nr; i++) {
		unsigned char sha1[20];
		char *ref;

		if (dwim_ref(refspec[i], strlen(refspec[i]), sha1, &ref) != 1)
			return error("Could not get ref %s", refspec[i]);

		if (write_one_ref(ref, sha1, 0, temp_dir)) {
			free(ref);
			return -1;
		}
		free(ref);
	}
	return 0;
}

static int rsync_transport_push(struct transport *transport,
		int refspec_nr, const char **refspec, int flags)
{
	struct strbuf buf = STRBUF_INIT, temp_dir = STRBUF_INIT;
	int result = 0, i;
	struct child_process rsync;
	const char *args[8];

	/* first push the objects */

	strbuf_addstr(&buf, transport->url);
	strbuf_addch(&buf, '/');

	memset(&rsync, 0, sizeof(rsync));
	rsync.argv = args;
	rsync.stdout_to_stderr = 1;
	args[0] = "rsync";
	args[1] = transport->verbose ? "-av" : "-a";
	args[2] = "--ignore-existing";
	args[3] = "--exclude";
	args[4] = "info";
	args[5] = get_object_directory();;
	args[6] = buf.buf;
	args[7] = NULL;

	if (run_command(&rsync))
		return error("Could not push objects to %s", transport->url);

	/* copy the refs to the temporary directory; they could be packed. */

	strbuf_addstr(&temp_dir, git_path("rsync-refs-XXXXXX"));
	if (!mkdtemp(temp_dir.buf))
		die ("Could not make temporary directory");
	strbuf_addch(&temp_dir, '/');

	if (flags & TRANSPORT_PUSH_ALL) {
		if (for_each_ref(write_one_ref, &temp_dir))
			return -1;
	} else if (write_refs_to_temp_dir(&temp_dir, refspec_nr, refspec))
		return -1;

	i = (flags & TRANSPORT_PUSH_FORCE) ? 2 : 3;
	args[i++] = temp_dir.buf;
	args[i++] = transport->url;
	args[i++] = NULL;
	if (run_command(&rsync))
		result = error("Could not push to %s", transport->url);

	if (remove_dir_recursively(&temp_dir, 0))
		warning ("Could not remove temporary directory %s.",
				temp_dir.buf);

	strbuf_release(&buf);
	strbuf_release(&temp_dir);

	return result;
}

/* Generic functions for using commit walkers */

