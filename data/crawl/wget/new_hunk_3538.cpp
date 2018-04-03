/* Change the links in an HTML document.  Accepts a structure that
   defines the positions of all the links.  */
void
convert_links (const char *file, struct urlpos *l)
{
  struct file_memory *fm;
  FILE               *fp;
  const char         *p;
  downloaded_file_t  downloaded_file_return;
  int to_url_count = 0, to_file_count = 0;

  logprintf (LOG_VERBOSE, _("Converting %s... "), file);

