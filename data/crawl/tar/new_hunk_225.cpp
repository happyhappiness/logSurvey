bool sys_get_archive_stat (void);

/* Module compare.c */
void report_difference (struct tar_stat_info *st, const char *message, ...);

/* Module sparse.c */
bool sparse_file_p (struct tar_stat_info *stat);
enum dump_status sparse_dump_file (int fd, struct tar_stat_info *stat);
enum dump_status sparse_extract_file (int fd, struct tar_stat_info *stat, off_t *size);
bool sparse_diff_file (int fd, struct tar_stat_info *stat);
