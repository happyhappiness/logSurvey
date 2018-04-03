             puts("OK");
         else {
             syslog(LOG_INFO, "'%s' login failed", username);
-error:
             puts("ERR");
         }
         err = 0;