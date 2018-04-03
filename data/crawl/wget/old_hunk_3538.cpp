/* Change the links in an HTML document.  Accepts a structure that
   defines the positions of all the links.  */
void
convert_links (const char *file, urlpos *l)
{
  struct file_memory *fm;
  FILE               *fp;
  const char         *p;
  downloaded_file_t  downloaded_file_return;

  logprintf (LOG_VERBOSE, _("Converting %s... "), file);

