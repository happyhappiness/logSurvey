 
 static int cow_read (void)
 {
-  char *buffer;
-  size_t buffer_size;
-  int status;
-
-  char *buffer_ptr;
-  char *dummy;
-  char *saveptr;
-
-  status = OW_get ("/uncached/", &buffer, &buffer_size);
-  if (status < 0)
-  {
-    ERROR ("onewire plugin: OW_get (\"/\") failed. status = %#x;",
-        status);
-    return (-1);
-  }
-
-  printf ("-- 8< --\n");
-
-  dummy = buffer;
-  saveptr = NULL;
-  while ((buffer_ptr = strtok_r (dummy, ",/", &saveptr)) != NULL)
-  {
-    dummy = NULL;
-    if (strncmp ("bus", buffer_ptr, strlen ("bus")) == 0)
-    {
-      cow_read_bus (buffer_ptr);
-    }
-  } /* while (strtok_r) */
-
-  printf ("-- >8 --\n");
-
-  free (buffer);
-
-  return (0);
+  return (cow_read_bus ("/"));
 } /* int cow_read */
 
 static int cow_shutdown (void)