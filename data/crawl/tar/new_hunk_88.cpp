union block *start_private_header (const char *name, size_t size);
void write_eot (void);
void check_links (void);
void exclusion_tag_warning (const char *dirname, const char *tagname,
			    const char *message);
enum exclusion_tag_type check_exclusion_tags (char *dirname,
					      const char **tag_file_name);
     
#define GID_TO_CHARS(val, where) gid_to_chars (val, where, sizeof (where))
#define MAJOR_TO_CHARS(val, where) major_to_chars (val, where, sizeof (where))
#define MINOR_TO_CHARS(val, where) minor_to_chars (val, where, sizeof (where))
