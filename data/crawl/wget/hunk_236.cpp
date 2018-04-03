     if (dp->rows == dp->initial_length / ROW_BYTES)
       bytes_this_row -= dp->initial_length % ROW_BYTES;
     rate = calc_rate (bytes_this_row, dltime - dp->last_timer_value, &units);
-    logprintf (LOG_VERBOSE, " %4.*f%c",
+    logprintf (LOG_PROGRESS, " %4.*f%c",
                rate >= 99.95 ? 0 : rate >= 9.995 ? 1 : 2,
                rate, names[units]);
     dp->last_timer_value = dltime;
