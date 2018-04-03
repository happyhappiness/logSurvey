 extern int errno;
 #endif
 
-/* Mapping between all known hosts to their addresses (n.n.n.n). */
+#define IP4_ADDRESS_LENGTH 4
 
-/* #### We should map to *lists* of IP addresses. */
+/* Mapping between known hosts and to lists of their addresses. */
 
-struct hash_table *host_name_address_map;
+struct hash_table *host_name_addresses_map;
 
-#if 0
+/* Lists of addresses.  This should eventually be extended to handle
+   IPv6.  */
 
-/* This function is no longer used. */
+struct address_list {
+  int count;			/* number of adrresses */
+  unsigned char *buffer;	/* buffer which holds all of them. */
 
-/* The same as gethostbyname, but supports internet addresses of the
-   form `N.N.N.N'.  On some systems gethostbyname() knows how to do
-   this automatically.  */
-struct hostent *
-ngethostbyname (const char *name)
+  int refcount;			/* so we know whether to free it or
+				   not. */
+};
+
+#define ADDR_LOCATION(al, index) ((al)->buffer + index * IP4_ADDRESS_LENGTH)
+
+/* Return the number of addresses in the list. */
+
+int
+address_list_count (struct address_list *al)
 {
-  struct hostent *hp;
-  unsigned long addr;
+  return al->count;
+}
 
-  addr = (unsigned long)inet_addr (name);
-  if ((int)addr != -1)
-    hp = gethostbyaddr ((char *)&addr, sizeof (addr), AF_INET);
-  else
-    hp = gethostbyname (name);
-  return hp;
+/* Copy address number INDEX to IP_STORE.  */
+
+void
+address_list_copy_one (struct address_list *al, int index,
+		       unsigned char *ip_store)
+{
+  memcpy (ip_store, ADDR_LOCATION (al, index), IP4_ADDRESS_LENGTH);
 }
-#endif
 
-/* Add host name HOST with the address ADDR_TEXT to the cache.  */
+/* Check whether two address lists have all their IPs in common.  */
+
+int
+address_list_match_all (struct address_list *al1, struct address_list *al2)
+{
+  if (al1 == al2)
+    return 1;
+  if (al1->count != al2->count)
+    return 0;
+  return 0 == memcmp (al1->buffer, al2->buffer,
+		      al1->count * IP4_ADDRESS_LENGTH);
+}
+
+/* Create an address_list out of a NULL-terminated list of addresses,
+   as returned by gethostbyname.  */
+
+static struct address_list *
+address_list_new (char **h_addr_list)
+{
+  int count = 0, i;
+
+  struct address_list *al = xmalloc (sizeof (struct address_list));
+
+  while (h_addr_list[count])
+    ++count;
+  assert (count > 0);
+  al->count    = count;
+  al->buffer   = xmalloc (count * IP4_ADDRESS_LENGTH);
+  al->refcount = 1;
+
+  for (i = 0; i < count; i++)
+    memcpy (ADDR_LOCATION (al, i), h_addr_list[i], IP4_ADDRESS_LENGTH);
+
+  return al;
+}
 
 static void
-add_host_to_cache (const char *host, const char *addr_text)
+address_list_delete (struct address_list *al)
 {
-  DEBUGP (("Caching %s => %s\n", host, addr_text));
+  xfree (al->buffer);
+  xfree (al);
+}
 
-  if (!host_name_address_map)
-    host_name_address_map = make_nocase_string_hash_table (0);
+void
+address_list_release (struct address_list *al)
+{
+  --al->refcount;
+  DEBUGP (("Releasing %p (new refcount %d).\n", al, al->refcount));
+  if (al->refcount <= 0)
+    {
+      DEBUGP (("Deleting unused %p.\n", al));
+      address_list_delete (al);
+    }
+}
+
+/* The same as inet_ntoa, but without the need for a cast, or for
+   #including the netinet stuff.  */
 
-  hash_table_put (host_name_address_map,
-		  xstrdup_lower (host), xstrdup (addr_text));
+char *
+pretty_print_address (const unsigned char *addr)
+{
+  return inet_ntoa (*(struct in_addr *)addr);
 }
 
-/* Store the address of HOSTNAME, internet-style (four octets in
-   network order), to WHERE.  First try to get the address from the
-   cache; if it is not available, call the DNS functions and update
-   the cache.
+/* Add host name HOST with the address ADDR_TEXT to the cache.
+   ADDR_LIST is a NULL-terminated list of addresses, as in struct
+   hostent.  */
 
-   Return 1 on successful finding of the hostname, 0 otherwise.  */
-int
-lookup_host (const char *hostname, unsigned char *store_ip)
+static void
+cache_host_lookup (const char *host, struct address_list *al)
 {
+  if (!host_name_addresses_map)
+    host_name_addresses_map = make_nocase_string_hash_table (0);
+
+  ++al->refcount;
+  hash_table_put (host_name_addresses_map, xstrdup_lower (host), al);
+
+#ifdef DEBUG
+  if (opt.debug)
+    {
+      int i;
+      debug_logprintf ("Caching %s =>", host);
+      for (i = 0; i < al->count; i++)
+	debug_logprintf (" %s",
+			 pretty_print_address (ADDR_LOCATION (al, i)));
+      debug_logprintf ("\n");
+    }
+#endif
+}
+
+struct address_list *
+lookup_host (const char *host, int silent)
+{
+  struct address_list *al = NULL;
   unsigned long addr;
-  char *addr_text = NULL;
   struct hostent *hptr;
-  struct in_addr in;
-  char *inet_s;
 
   /* If the address is of the form d.d.d.d, no further lookup is
      needed.  */
-  addr = (unsigned long)inet_addr (hostname);
+  addr = (unsigned long)inet_addr (host);
   if ((int)addr != -1)
     {
+      unsigned char tmpstore[IP4_ADDRESS_LENGTH];
+      char *lst[] = { tmpstore, NULL };
+
       /* ADDR is defined to be in network byte order, which is what
 	 this returns, so we can just copy it to STORE_IP.  However,
 	 on big endian 64-bit architectures the value will be stored
 	 in the *last*, not first four bytes.  OFFSET makes sure that
 	 we copy the correct four bytes.  */
       int offset;
-    have_addr:
 #ifdef WORDS_BIGENDIAN
-      offset = sizeof (unsigned long) - 4;
+      offset = sizeof (unsigned long) - IP4_ADDRESS_LENGTH;
 #else
       offset = 0;
 #endif
-      memcpy (store_ip, (char *)&addr + offset, 4);
-      return 1;
+      memcpy (tmpstore, (char *)&addr + offset, IP4_ADDRESS_LENGTH);
+      return address_list_new (lst);
     }
 
   /* By now we know that the host name we got is not of the form
      d.d.d.d.  Try to find it in our cache of host names.  */
-  if (host_name_address_map)
-    addr_text = hash_table_get (host_name_address_map, hostname);
+  if (host_name_addresses_map)
+    al = hash_table_get (host_name_addresses_map, host);
 
-  if (addr_text)
+  if (al)
     {
-      DEBUGP (("Found %s in host_name_address_map: %s\n",
-	       hostname, addr_text));
-      addr = (unsigned long)inet_addr (addr_text);
-      goto have_addr;
+      DEBUGP (("Found %s in host_name_addresses_map (%p)\n", host, al));
+      ++al->refcount;
+      return al;
     }
 
+  if (!silent)
+    logprintf (LOG_VERBOSE, _("Resolving %s... "), host);
+
   /* Look up the host using gethostbyname().  Note that we use
      gethostbyname() rather than ngethostbyname(), because we already
      know that the address is not numerical.  */
-  hptr = gethostbyname (hostname);
+  hptr = gethostbyname (host);
   if (!hptr)
-    return 0;
+    {
+      if (!silent)
+	logprintf (LOG_VERBOSE, _("failed: %s.\n"), herrmsg (h_errno));
+      return NULL;
+    }
 
-  /* Store the IP address to the desired location. */
-  assert (hptr->h_length == 4);
-  memcpy (store_ip, hptr->h_addr_list[0], hptr->h_length);
+  if (!silent)
+    logprintf (LOG_VERBOSE, _("done.\n"));
 
-  /* Now that we've successfully looked up the host, store this
-     information in the cache.  */
+  al = address_list_new (hptr->h_addr_list);
 
-  /* Originally, we copied to in.s_addr, but it appears to be missing
-     on some systems.  */
-  memcpy (&in, *hptr->h_addr_list, sizeof (in));
-  inet_s = inet_ntoa (in);
-  add_host_to_cache (hostname, inet_s);
+  /* Cache the lookup information. */
+  cache_host_lookup (host, al);
 
-  return 1;
+  return al;
 }
-
+
 /* Determine whether a URL is acceptable to be followed, according to
    a list of domains to accept.  */
 int
