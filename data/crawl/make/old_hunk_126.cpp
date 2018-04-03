  while (isspace ((unsigned char)*--q))
    *q = '\0';

  if (strncmp (cmd, "builtin_", 8) == 0)
    {
      child->pid = 270163;
      child->efn = 0;
      child->cstatus = 1;

      DB (DB_JOBS, (_("BUILTIN [%s][%s]\n"), cmd, cmd+8));

      p = cmd + 8;

      if ((*(p) == 'c')
          && (*(p+1) == 'd')
          && ((*(p+2) == ' ') || (*(p+2) == '\t')))
        {
          p += 3;
          while ((*p == ' ') || (*p == '\t'))
            p++;
          DB (DB_JOBS, (_("BUILTIN CD %s\n"), p));
          if (chdir (p))
            return 0;
          else
            return 1;
        }
      else if ((*(p) == 'e')
               && (*(p+1) == 'c')
               && (*(p+2) == 'h')
               && (*(p+3) == 'o')
            && ((*(p+4) == ' ') || (*(p+4) == '\t') || (*(p+4) == '\0')))
        {
          /* This is not a real builtin, it is a built in pre-processing
             for the VMS/DCL echo (write sys$output) to ensure the to be echoed
             string is correctly quoted (with the DCL quote character '"'). */
#define VMS_EMPTY_ECHO "$ write sys$output \"\""
          char *vms_echo;
          p += 4;
          if (*p == '\0')
            {
              cmd = VMS_EMPTY_ECHO;
            }
          else
            {
              p++;
              while ((*p == ' ') || (*p == '\t'))
                p++;
              if (*p == '\0')
                cmd = VMS_EMPTY_ECHO;
              else
                {
                  vms_echo = alloca(strlen(p) + sizeof VMS_EMPTY_ECHO);
                  strcpy(vms_echo, VMS_EMPTY_ECHO);
                  vms_echo[sizeof VMS_EMPTY_ECHO - 2] = '\0';
                  strcat(vms_echo, p);
                  strcat(vms_echo, "\"");
                  cmd = vms_echo;
                }
            }
          DB(DB_JOBS, (_("BUILTIN ECHO %s\n"), p));
        }
      else
        {
          printf (_("Unknown builtin command '%s'\n"), cmd);
          fflush (stdout);
          return 0;
        }
    }

  /* Create a *.com file if either the command is too long for
     lib$spawn, or the command contains a newline, or if redirection
     is desired. Forcing commands with newlines into DCLs allows to
