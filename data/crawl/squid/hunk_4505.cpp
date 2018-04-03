          * Because if we print it before the swap file number, it'll break
          * the existing log format.
          */
-        logfilePrintf(storelog, "%9d.%03d %-7s %02d %08X %s %4d %9d %9d %9d %s %d/%d %s %s\n",
+        logfilePrintf(storelog, "%9d.%03d %-7s %02d %08X %s %4d %9d %9d %9d %s %"PRId64"/%"PRId64" %s %s\n",
                       (int) current_time.tv_sec,
                       (int) current_time.tv_usec / 1000,
                       storeLogTags[tag],
