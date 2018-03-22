void report_difference (struct tar_stat_info *st, const char *message, ...);

/* Module sparse.c */
bool sparse_file_p (struct tar_stat_info *);
bool sparse_member_p (struct tar_stat_info *);
bool sparse_fixup_header (struct tar_stat_info *);
enum dump_status sparse_dump_file (int, struct tar_stat_info *);
enum dump_status sparse_extract_file (int, struct tar_stat_info *, off_t *);
enum dump_status sparse_skip_file (struct tar_stat_info *);
bool sparse_diff_file (int, struct tar_stat_info *);

/* Module utf8.c */
bool string_ascii_p (const char *str);
bool utf8_convert (bool to_utf, char const *input, char **output);
