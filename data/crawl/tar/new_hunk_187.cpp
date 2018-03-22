bool sys_file_is_archive (struct tar_stat_info *p);
bool sys_compare_links (struct stat *link_data, struct stat *stat_data);
int sys_truncate (int fd);
pid_t sys_child_open_for_compress (void);
pid_t sys_child_open_for_uncompress (void);
size_t sys_write_archive_buffer (void);
bool sys_get_archive_stat (void);

/* Module compare.c */
void report_difference (struct tar_stat_info *st, const char *message, ...);
