#include "string-list.h"
#include "mailmap.h"

#define DEBUG_MAILMAP 0
#if DEBUG_MAILMAP
#define debug_mm(...) fprintf(stderr, __VA_ARGS__)
#else
static inline void debug_mm(const char *format, ...) {}
#endif

const char *git_mailmap_file;

struct mailmap_info {
	char *name;
	char *email;
};

struct mailmap_entry {
	/* name and email for the simple mail-only case */
	char *name;
	char *email;

	/* name and email for the complex mail and name matching case */
	struct string_list namemap;
};

static void free_mailmap_info(void *p, const char *s)
{
	struct mailmap_info *mi = (struct mailmap_info *)p;
	debug_mm("mailmap: -- complex: '%s' -> '%s' <%s>\n", s, mi->name, mi->email);
	free(mi->name);
	free(mi->email);
}

static void free_mailmap_entry(void *p, const char *s)
{
	struct mailmap_entry *me = (struct mailmap_entry *)p;
	debug_mm("mailmap: removing entries for <%s>, with %d sub-entries\n", s, me->namemap.nr);
	debug_mm("mailmap: - simple: '%s' <%s>\n", me->name, me->email);
	free(me->name);
	free(me->email);

	me->namemap.strdup_strings = 1;
	string_list_clear_func(&me->namemap, free_mailmap_info);
}

static void add_mapping(struct string_list *map,
			char *new_name, char *new_email, char *old_name, char *old_email)
{
	struct mailmap_entry *me;
	int index;
	if (old_email == NULL) {
		old_email = new_email;
		new_email = NULL;
	}

	if ((index = string_list_find_insert_index(map, old_email, 1)) < 0) {
		/* mailmap entry exists, invert index value */
		index = -1 - index;
	} else {
		/* create mailmap entry */
		struct string_list_item *item = string_list_insert_at_index(index, old_email, map);
		item->util = xmalloc(sizeof(struct mailmap_entry));
		memset(item->util, 0, sizeof(struct mailmap_entry));
		((struct mailmap_entry *)item->util)->namemap.strdup_strings = 1;
	}
	me = (struct mailmap_entry *)map->items[index].util;

	if (old_name == NULL) {
		debug_mm("mailmap: adding (simple) entry for %s at index %d\n", old_email, index);
		/* Replace current name and new email for simple entry */
		free(me->name);
		free(me->email);
		if (new_name)
			me->name = xstrdup(new_name);
		if (new_email)
			me->email = xstrdup(new_email);
	} else {
		struct mailmap_info *mi = xmalloc(sizeof(struct mailmap_info));
		debug_mm("mailmap: adding (complex) entry for %s at index %d\n", old_email, index);
		if (new_name)
			mi->name = xstrdup(new_name);
		if (new_email)
			mi->email = xstrdup(new_email);
		string_list_insert(old_name, &me->namemap)->util = mi;
	}

	debug_mm("mailmap:  '%s' <%s> -> '%s' <%s>\n",
		 old_name, old_email, new_name, new_email);
}

static char *parse_name_and_email(char *buffer, char **name, char **email)
{
	char *left, *right, *nstart, *nend;
	*name = *email = 0;

	if ((left = strchr(buffer, '<')) == NULL)
		return NULL;
	if ((right = strchr(left+1, '>')) == NULL)
		return NULL;
	if (left+1 == right)
		return NULL;

	/* remove whitespace from beginning and end of name */
	nstart = buffer;
	while (isspace(*nstart) && nstart < left)
		++nstart;
	nend = left-1;
	while (isspace(*nend) && nend > nstart)
		--nend;

	*name = (nstart < nend ? nstart : NULL);
	*email = left+1;
	*(nend+1) = '\0';
	*right++ = '\0';

	return (*right == '\0' ? NULL : right);
}

static int read_single_mailmap(struct string_list *map, const char *filename, char **repo_abbrev)
{
	char buffer[1024];
