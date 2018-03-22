void report_difference (struct tar_stat_info *st, const char *message, ...);

/* Module sparse.c */
bool sparse_file_p (struct tar_stat_info *stat);
bool sparse_member_p (struct tar_stat_info *stat);
bool sparse_fixup_header (struct tar_stat_info *stat);
enum dump_status sparse_dump_file (int fd, struct tar_stat_info *stat);
enum dump_status sparse_extract_file (int fd, struct tar_stat_info *stat, off_t *size);
enum dump_status sparse_skip_file (struct tar_stat_info *stat);
bool sparse_diff_file (int fd, struct tar_stat_info *stat);

/* Module utf8.c */
bool string_ascii_p (const char *str);
bool utf8_convert(bool to_utf, const char *input, char **output);
