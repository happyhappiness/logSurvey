 void xheader_read (union block *, size_t);
 void xheader_finish (struct xheader *);
 void xheader_destroy (struct xheader *);
+
+/* Module system.c */
+
+void sys_detect_dev_null_output (void);
+void sys_save_archive_dev_ino (void);
+void sys_drain_input_pipe (void);
+void sys_wait_for_child (pid_t);
+void sys_spawn_shell (void);
+void sys_compare_uid_gid (struct stat *a, struct stat *b);
+bool sys_file_is_archive (struct tar_stat_info *p);
+void sys_compare_links (struct stat *link_data, struct stat *stat_data);
+int sys_truncate (int fd);
+void sys_reset_uid_gid (void);
+pid_t sys_child_open_for_compress (void);
+pid_t sys_child_open_for_uncompress (void);
+ssize_t sys_write_archive_buffer (void);
+bool sys_get_archive_stat (void);
+
+/* Module compare.c */
+void report_difference (const char *message, ...);
