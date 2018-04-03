#include "refs.h"
#include "utf8.h"
#include "strbuf.h"
#include "tree-walk.h"

struct entry {
	unsigned char commit_sha1[20];
	unsigned char notes_sha1[20];
};

struct hash_map {
	struct entry *entries;
	off_t count, size;
};

static int initialized;
static struct hash_map hash_map;

static int hash_index(struct hash_map *map, const unsigned char *sha1)
{
	int i = ((*(unsigned int *)sha1) % map->size);

	for (;;) {
		unsigned char *current = map->entries[i].commit_sha1;

		if (!hashcmp(sha1, current))
			return i;

		if (is_null_sha1(current))
			return -1 - i;

		if (++i == map->size)
			i = 0;
	}
}

static void add_entry(const unsigned char *commit_sha1,
		const unsigned char *notes_sha1)
{
	int index;

	if (hash_map.count + 1 > hash_map.size >> 1) {
		int i, old_size = hash_map.size;
		struct entry *old = hash_map.entries;

		hash_map.size = old_size ? old_size << 1 : 64;
		hash_map.entries = (struct entry *)
			xcalloc(sizeof(struct entry), hash_map.size);

		for (i = 0; i < old_size; i++)
			if (!is_null_sha1(old[i].commit_sha1)) {
				index = -1 - hash_index(&hash_map,
						old[i].commit_sha1);
				memcpy(hash_map.entries + index, old + i,
					sizeof(struct entry));
			}
		free(old);
	}

	index = hash_index(&hash_map, commit_sha1);
	if (index < 0) {
		index = -1 - index;
		hash_map.count++;
	}

	hashcpy(hash_map.entries[index].commit_sha1, commit_sha1);
	hashcpy(hash_map.entries[index].notes_sha1, notes_sha1);
}

static void initialize_hash_map(const char *notes_ref_name)
{
	unsigned char sha1[20], commit_sha1[20];
	unsigned mode;
	struct tree_desc desc;
	struct name_entry entry;
	void *buf;

	if (!notes_ref_name || read_ref(notes_ref_name, commit_sha1) ||
	    get_tree_entry(commit_sha1, "", sha1, &mode))
		return;

	buf = fill_tree_descriptor(&desc, sha1);
	if (!buf)
		die("Could not read %s for notes-index", sha1_to_hex(sha1));

	while (tree_entry(&desc, &entry))
		if (!get_sha1(entry.path, commit_sha1))
			add_entry(commit_sha1, entry.sha1);
	free(buf);
}

static unsigned char *lookup_notes(const unsigned char *commit_sha1)
{
	int index;

	if (!hash_map.size)
		return NULL;

	index = hash_index(&hash_map, commit_sha1);
	if (index < 0)
		return NULL;
	return hash_map.entries[index].notes_sha1;
}

void get_commit_notes(const struct commit *commit, struct strbuf *sb,
		const char *output_encoding)
{
	static const char *utf8 = "utf-8";
	unsigned char *sha1;
	char *msg;
	unsigned long msgoffset, msglen;
	enum object_type type;
