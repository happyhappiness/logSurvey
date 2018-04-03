child_handler (sig)
     int sig;
{
  child_died = 1;
  return 0;
}

