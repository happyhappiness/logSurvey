      {                                                             \
        if (dst == buf + UINTMAX_STRSIZE_BOUND -1)                  \
          {                                                         \
-           ERROR ((0, 0, _("%s: numeric overflow in sparse archive member"),   \
+           ERROR ((0, 0, _("%s: numeric overflow in sparse archive member"), \
 	          file->stat_info->orig_file_name));               \
            return false;                                           \
          }                                                         \
-        if (src == endp)                                           \
+       if (src == endp)                                            \
 	 {                                                         \
 	   set_next_block_after (b);                               \
 	   b = find_next_block ();                                 \
