static void
assign_time_option (char **sval, time_t *tval, const char *input)
{
  char *p;
  struct timespec t = decode_timespec (input, &p, false);
  if (! valid_timespec (t) || *p)
    ERROR ((0, 0, _("Time stamp is out of allowed range")));
  else
    {
      *tval = t.tv_sec;
      assign_string (sval, input);
    }
}
