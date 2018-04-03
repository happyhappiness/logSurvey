 
 static int myatoi PARAMS ((const char *s));
 
-/* Interpret VAL as an Internet address (a hostname or a dotted-quad
-   IP address), and write it (in network order) to a malloc-allocated
-   address.  That address gets stored to the memory pointed to by
-   CLOSURE.  COM is ignored, except for error messages.
-
-   #### IMHO it's a mistake to do this kind of work so early in the
-   process (before any download even started!)  opt.bind_address
-   should simply remember the provided value as a string.  Another
-   function should do the lookup, when needed, and cache the
-   result.  --hniksic  */
-static int
-cmd_address (const char *com, const char *val, void *closure)
-{
-  struct address_list *al;
-  wget_sockaddr sa;
-  wget_sockaddr **target = (wget_sockaddr **)closure;
-
-  memset (&sa, '\0', sizeof (sa));
-
-  al = lookup_host (val, 1);
-  if (!al)
-    {
-      fprintf (stderr, _("%s: %s: Cannot convert `%s' to an IP address.\n"),
-	       exec_name, com, val);
-      return 0;
-    }
-  sa.sa.sa_family = ip_default_family;
-  wget_sockaddr_set_port (&sa, 0);
-  address_list_copy_one (al, 0, wget_sockaddr_get_addr (&sa));
-  address_list_release (al);
-
-  FREE_MAYBE (*target);
-
-  *target = xmalloc (sizeof (sa));
-  memcpy (*target, &sa, sizeof (sa));
-
-  return 1;
-}
-
 /* Store the boolean value from VAL to CLOSURE.  COM is ignored,
    except for error messages.  */
 static int
