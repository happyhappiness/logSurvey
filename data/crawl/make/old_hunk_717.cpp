          break;
      else
          fprintf(stderr,
                  _("make reaped child pid %d, still waiting for pid %d\n"),
                  hWaitPID, hPID);
    }

  /* return child's exit code as our exit code */
