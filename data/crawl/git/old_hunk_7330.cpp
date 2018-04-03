#include "progress.h"
#include "refs.h"

#define DBRT_DEBUG 1

struct tree_entry_list {
	struct tree_entry_list *next;
	unsigned int mode;
	const char *name;
	const unsigned char *sha1;
};

static struct tree_entry_list *create_tree_entry_list(struct tree_desc *desc)
{
	struct name_entry one;
	struct tree_entry_list *ret = NULL;
	struct tree_entry_list **list_p = &ret;

	while (tree_entry(desc, &one)) {
		struct tree_entry_list *entry;

		entry = xmalloc(sizeof(struct tree_entry_list));
		entry->name = one.path;
		entry->sha1 = one.sha1;
		entry->mode = one.mode;
		entry->next = NULL;

		*list_p = entry;
		list_p = &entry->next;
	}
	return ret;
}

static int entcmp(const char *name1, int dir1, const char *name2, int dir2)
{
	int len1 = strlen(name1);
	int len2 = strlen(name2);
	int len = len1 < len2 ? len1 : len2;
	int ret = memcmp(name1, name2, len);
	unsigned char c1, c2;
	if (ret)
		return ret;
	c1 = name1[len];
	c2 = name2[len];
	if (!c1 && dir1)
		c1 = '/';
	if (!c2 && dir2)
		c2 = '/';
	ret = (c1 < c2) ? -1 : (c1 > c2) ? 1 : 0;
	if (c1 && c2 && !ret)
		ret = len1 - len2;
	return ret;
}

static inline void remove_entry(int remove)
{
	if (remove >= 0)
		remove_cache_entry_at(remove);
}

static int unpack_trees_rec(struct tree_entry_list **posns, int len,
			    const char *base, struct unpack_trees_options *o,
			    struct tree_entry_list *df_conflict_list)
{
	int remove;
	int baselen = strlen(base);
	int src_size = len + 1;
	int retval = 0;

	do {
		int i;
		const char *first;
		int firstdir = 0;
		int pathlen;
		unsigned ce_size;
		struct tree_entry_list **subposns;
		struct cache_entry **src;
		int any_files = 0;
		int any_dirs = 0;
		char *cache_name;
		int ce_stage;
		int skip_entry = 0;

		/* Find the first name in the input. */

		first = NULL;
		cache_name = NULL;

		/* Check the cache */
		if (o->merge && o->pos < active_nr) {
			/* This is a bit tricky: */
			/* If the index has a subdirectory (with
			 * contents) as the first name, it'll get a
			 * filename like "foo/bar". But that's after
			 * "foo", so the entry in trees will get
			 * handled first, at which point we'll go into
			 * "foo", and deal with "bar" from the index,
			 * because the base will be "foo/". The only
			 * way we can actually have "foo/bar" first of
			 * all the things is if the trees don't
			 * contain "foo" at all, in which case we'll
			 * handle "foo/bar" without going into the
			 * directory, but that's fine (and will return
			 * an error anyway, with the added unknown
			 * file case.
			 */

			cache_name = active_cache[o->pos]->name;
			if (strlen(cache_name) > baselen &&
			    !memcmp(cache_name, base, baselen)) {
				cache_name += baselen;
				first = cache_name;
			} else {
				cache_name = NULL;
			}
		}

#if DBRT_DEBUG > 1
		if (first)
			fprintf(stderr, "index %s\n", first);
#endif
		for (i = 0; i < len; i++) {
			if (!posns[i] || posns[i] == df_conflict_list)
				continue;
#if DBRT_DEBUG > 1
			fprintf(stderr, "%d %s\n", i + 1, posns[i]->name);
#endif
			if (!first || entcmp(first, firstdir,
					     posns[i]->name,
					     S_ISDIR(posns[i]->mode)) > 0) {
				first = posns[i]->name;
				firstdir = S_ISDIR(posns[i]->mode);
			}
		}
		/* No name means we're done */
		if (!first)
			goto leave_directory;

		pathlen = strlen(first);
		ce_size = cache_entry_size(baselen + pathlen);

		src = xcalloc(src_size, sizeof(struct cache_entry *));

		subposns = xcalloc(len, sizeof(struct tree_list_entry *));

		remove = -1;
		if (cache_name && !strcmp(cache_name, first)) {
			any_files = 1;
			src[0] = active_cache[o->pos];
			remove = o->pos;
			if (o->skip_unmerged && ce_stage(src[0]))
				skip_entry = 1;
		}

		for (i = 0; i < len; i++) {
			struct cache_entry *ce;

			if (!posns[i] ||
			    (posns[i] != df_conflict_list &&
			     strcmp(first, posns[i]->name))) {
				continue;
			}

			if (posns[i] == df_conflict_list) {
				src[i + o->merge] = o->df_conflict_entry;
				continue;
			}

			if (S_ISDIR(posns[i]->mode)) {
				struct tree *tree = lookup_tree(posns[i]->sha1);
				struct tree_desc t;
				any_dirs = 1;
				parse_tree(tree);
				init_tree_desc(&t, tree->buffer, tree->size);
				subposns[i] = create_tree_entry_list(&t);
				posns[i] = posns[i]->next;
				src[i + o->merge] = o->df_conflict_entry;
				continue;
			}

			if (skip_entry) {
				subposns[i] = df_conflict_list;
				posns[i] = posns[i]->next;
				continue;
			}

			if (!o->merge)
				ce_stage = 0;
			else if (i + 1 < o->head_idx)
				ce_stage = 1;
			else if (i + 1 > o->head_idx)
				ce_stage = 3;
			else
				ce_stage = 2;

			ce = xcalloc(1, ce_size);
			ce->ce_mode = create_ce_mode(posns[i]->mode);
			ce->ce_flags = create_ce_flags(baselen + pathlen,
						       ce_stage);
			memcpy(ce->name, base, baselen);
			memcpy(ce->name + baselen, first, pathlen + 1);

			any_files = 1;

			hashcpy(ce->sha1, posns[i]->sha1);
			src[i + o->merge] = ce;
			subposns[i] = df_conflict_list;
			posns[i] = posns[i]->next;
		}
		if (any_files) {
			if (skip_entry) {
				o->pos++;
				while (o->pos < active_nr &&
				       !strcmp(active_cache[o->pos]->name,
					       src[0]->name))
					o->pos++;
			} else if (o->merge) {
				int ret;

#if DBRT_DEBUG > 1
				fprintf(stderr, "%s:\n", first);
				for (i = 0; i < src_size; i++) {
					fprintf(stderr, " %d ", i);
					if (src[i])
						fprintf(stderr, "%06x %s\n", src[i]->ce_mode, sha1_to_hex(src[i]->sha1));
					else
						fprintf(stderr, "\n");
				}
#endif
				ret = o->fn(src, o, remove);
				if (ret < 0)
					return ret;

#if DBRT_DEBUG > 1
				fprintf(stderr, "Added %d entries\n", ret);
#endif
				o->pos += ret;
			} else {
				remove_entry(remove);
				for (i = 0; i < src_size; i++) {
					if (src[i]) {
						add_cache_entry(src[i], ADD_CACHE_OK_TO_ADD|ADD_CACHE_SKIP_DFCHECK);
					}
				}
			}
		}
		if (any_dirs) {
			char *newbase = xmalloc(baselen + 2 + pathlen);
			memcpy(newbase, base, baselen);
			memcpy(newbase + baselen, first, pathlen);
			newbase[baselen + pathlen] = '/';
			newbase[baselen + pathlen + 1] = '\0';
			if (unpack_trees_rec(subposns, len, newbase, o,
					     df_conflict_list)) {
				retval = -1;
				goto leave_directory;
			}
			free(newbase);
		}
		free(subposns);
		free(src);
	} while (1);

 leave_directory:
	return retval;
}

/* Unlink the last component and attempt to remove leading
 * directories, in case this unlink is the removal of the
 * last entry in the directory -- empty directories are removed.
