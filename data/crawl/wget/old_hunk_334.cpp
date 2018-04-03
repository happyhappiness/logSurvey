void
touch (const char *file, time_t tm)
{
  struct timespec timespecs[2];
  int fd;

