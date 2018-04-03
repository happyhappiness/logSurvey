            error (NILF, _("warning: -jN forced in submake: disabling jobserver mode."));
        }
#ifndef WINDOWS32
#define FD_OK(_f) ((fcntl ((_f), F_GETFD) != -1) || (errno != EBADF))
      /* Create a duplicate pipe, that will be closed in the SIGCHLD
         handler.  If this fails with EBADF, the parent has closed the pipe
         on us because it didn't think we were a submake.  If so, print a
