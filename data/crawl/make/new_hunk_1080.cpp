  register unsigned int i, dirs, files, impossible;
  register struct directory *dir;

  puts (_("\n# Directories\n"));

  dirs = files = impossible = 0;
  for (i = 0; i < DIRECTORY_BUCKETS; ++i)
