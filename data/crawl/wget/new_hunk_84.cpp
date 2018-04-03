  return getpass("");
}


/* Execute external application opt.use_askpass */
void
run_use_askpass (char *question, char **answer)
{
  char tmp[1024];
  pid_t pid;
  int status;
  int com[2];
  ssize_t bytes = 0;
  char * const argv[] = { opt.use_askpass, question, NULL };
  posix_spawn_file_actions_t fa;

  if (pipe (com) == -1)
    {
      fprintf (stderr, _("Cannot create pipe"));
      exit (WGET_EXIT_GENERIC_ERROR);
    }

  status = posix_spawn_file_actions_init (&fa);
  if (status)
    {
      fprintf (stderr,
              _("Error initializing spawn file actions for use-askpass: %d"),
              status);
      exit (WGET_EXIT_GENERIC_ERROR);
    }

  status = posix_spawn_file_actions_adddup2 (&fa, com[1], STDOUT_FILENO);
  if (status)
    {
      fprintf (stderr,
              _("Error setting spawn file actions for use-askpass: %d"),
              status);
      exit (WGET_EXIT_GENERIC_ERROR);
    }

  status = posix_spawnp (&pid, opt.use_askpass, &fa, NULL, argv, environ);
  if (status)
    {
      fprintf (stderr, "Error spawning %s: %d", opt.use_askpass, status);
      exit (WGET_EXIT_GENERIC_ERROR);
    }

  /* Parent process reads from child. */
  close (com[1]);
  bytes = read (com[0], tmp, sizeof (tmp) - 1);
  if (bytes <= 0)
    {
      fprintf (stderr,
              _("Error reading response from command \"%s %s\": %s\n"),
              opt.use_askpass, question, strerror (errno));
      exit (WGET_EXIT_GENERIC_ERROR);
    }
  /* Set the end byte to \0, and decrement bytes */
  tmp[bytes--] = '\0';

  /* Remove a possible new line */
  while (bytes >= 0 &&
        (tmp[bytes] == '\0' || tmp[bytes] == '\n' || tmp[bytes] == '\r'))
    tmp[bytes--] = '\0';

  *answer = xmemdup (tmp, bytes + 2);
}

/* set the user name and password*/
void
use_askpass (struct url *u)
{
  static char question[1024];

  if (u->user == NULL || u->user[0] == '\0')
    {
      snprintf (question, sizeof (question),  _("Username for '%s%s': "),
                scheme_leading_string(u->scheme), u->host);
      /* Prompt for username */
      run_use_askpass (question, &u->user);
      if (opt.recursive)
        opt.user = xstrdup (u->user);
    }

  if (u->passwd == NULL || u->passwd[0] == '\0')
    {
      snprintf(question, sizeof (question), _("Password for '%s%s@%s': "),
               scheme_leading_string (u->scheme), u->user, u->host);
      /* Prompt for password */
      run_use_askpass (question, &u->passwd);
      if (opt.recursive)
        opt.passwd = xstrdup (u->passwd);
    }
}
/* Function that prints the line argument while limiting it
   to at most line_length. prefix is printed on the first line
   and an appropriate number of spaces are added on subsequent
