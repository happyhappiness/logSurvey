enum backup_type get_version ();

/* FIXME: We should use a conversion routine that does reasonable error
   checking -- atoi doesn't.  For now, punt.  */
#define intconv	atoi

time_t get_date ();
