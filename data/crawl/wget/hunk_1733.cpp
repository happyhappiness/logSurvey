   logputs (LOG_VERBOSE, !authoritative ? _(" (unauthoritative)\n") : "\n");
 }
 
+static uerr_t ftp_get_listing (struct url *, ccon *, struct fileinfo **);
+
 /* Retrieves a file with denoted parameters through opening an FTP
    connection to the server.  It always closes the data connection,
    and closes the control connection in case of error.  */
