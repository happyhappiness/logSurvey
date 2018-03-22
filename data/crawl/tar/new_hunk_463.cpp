enum backup_type get_version ();

/* FIXME: We should use a conversion routine that does reasonable error
   checking -- atol doesn't.  For now, punt.  */
#define intconv	atol

time_t get_date ();

