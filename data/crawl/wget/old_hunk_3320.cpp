      if (strncmp (res, "PASS", 4) != 0)
        logprintf (LOG_ALWAYS, "--> %s\n", res);
      else
        logputs (LOG_ALWAYS, "--> PASS Turtle Power!\n");
    }
  else
    DEBUGP (("\n--> %s\n", res));
