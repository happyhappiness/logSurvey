  return dir;
}

static struct fileinfo *
ftp_parse_winnt_ls (const char *file)
{
  FILE *fp;
  int len;
  int year, month, day;         /* for time analysis */
  int hour, min, sec;
  struct tm timestruct;

  char *line, *tok;             /* tokenizer */
  struct fileinfo *dir, *l, cur; /* list creation */

  fp = fopen (file, "rb");
  if (!fp)
    {
      logprintf (LOG_NOTQUIET, "%s: %s\n", file, strerror (errno));
      return NULL;
    }
  dir = l = NULL;

  /* Line loop to end of file: */
  while ((line = read_whole_line (fp)))
    {
      DEBUGP (("%s\n", line));
      len = strlen (line);
      /* Destroy <CR><LF> if present.  */
      if (len && line[len - 1] == '\n')
        line[--len] = '\0';
      if (len && line[len - 1] == '\r')
        line[--len] = '\0';

      /* Extracting name is a bit of black magic and we have to do it
         before `strtok' inserted extra \0 characters in the line
         string. For the moment let us just suppose that the name starts at
         column 39 of the listing. This way we could also recognize
         filenames that begin with a series of space characters (but who
         really wants to use such filenames anyway?). */
      if (len < 40) continue;
      tok = line + 39;
      cur.name = xstrdup(tok);
      DEBUGP(("Name: '%s'\n", cur.name));

      /* First column: mm-dd-yy */
      tok = strtok(line, "-");
      month = atoi(tok);
      tok = strtok(NULL, "-");
      day = atoi(tok);
      tok = strtok(NULL, " ");
      year = atoi(tok);
      /* Assuming the epoch starting at 1.1.1970 */
      if (year <= 70) year += 100;

      /* Second column: hh:mm[AP]M */
      tok = strtok(NULL,  ":");
      hour = atoi(tok);
      tok = strtok(NULL,  "M");
      min = atoi(tok);
      /* Adjust hour from AM/PM */
      tok+=2;
      if (*tok == 'P') hour += 12;
      /* Listing does not contain value for seconds */
      sec = 0;

      DEBUGP(("YYYY/MM/DD HH:MM - %d/%02d/%02d %02d:%02d\n", 
              year+1900, month, day, hour, min));
      
      /* Build the time-stamp (copy & paste from above) */
      timestruct.tm_sec   = sec;
      timestruct.tm_min   = min;
      timestruct.tm_hour  = hour;
      timestruct.tm_mday  = day;
      timestruct.tm_mon   = month;
      timestruct.tm_year  = year;
      timestruct.tm_wday  = 0;
      timestruct.tm_yday  = 0;
      timestruct.tm_isdst = -1;
      cur.tstamp = mktime (&timestruct); /* store the time-stamp */

      DEBUGP(("Timestamp: %ld\n", cur.tstamp));

      /* Third column: Either file length, or <DIR>. We also set the
         permissions (guessed as 0644 for plain files and 0755 for
         directories as the listing does not give us a clue) and filetype
         here. */
      tok = strtok(NULL, " ");
      while (*tok == '\0')  tok = strtok(NULL, " ");
      if (*tok == '<')
      {
        cur.type  = FT_DIRECTORY;
        cur.size  = 0;
        cur.perms = 493; /* my gcc does not like 0755 ?? */
        DEBUGP(("Directory\n"));
      }
      else
      {
        cur.type  = FT_PLAINFILE;
        cur.size  = atoi(tok);
        cur.perms = 420; /* 0664 octal */
        DEBUGP(("File, size %ld bytes\n", cur.size));
      }

      cur.linkto = NULL;

      /* And put everything into the linked list */
      if (!dir)
      {
        l = dir = (struct fileinfo *)xmalloc (sizeof (struct fileinfo));
        memcpy (l, &cur, sizeof (cur));
        l->prev = l->next = NULL;
      }
      else
      {
        cur.prev = l;
        l->next = (struct fileinfo *)xmalloc (sizeof (struct fileinfo));
        l = l->next;
        memcpy (l, &cur, sizeof (cur));
        l->next = NULL;
      }

      xfree(line);
    }

  fclose(fp);
  return dir;
}


#ifdef HAVE_FTPPARSE

/* This is a "glue function" that connects the ftpparse interface to
