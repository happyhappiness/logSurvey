    }
}

/* Extract a file from the archive.  */
void
extract_archive (void)
{
  union block *data_block;
  int fd;
  int status;
  size_t count;
  size_t written;
  int openflag;
  mode_t mode;
  off_t size;
  int interdir_made = 0;
  char typeflag;
  char *file_name;

