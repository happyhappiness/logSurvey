				 int checkpoint_number);

/* Module compare.c */
void report_difference (struct tar_stat_info *st, const char *message, ...)
  __attribute__ ((format (printf, 2, 3)));

/* Module sparse.c */
bool sparse_member_p (struct tar_stat_info *st);
