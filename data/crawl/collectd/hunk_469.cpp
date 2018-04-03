   char *tc_type;
   char tc_inst[DATA_MAX_NAME_LEN];
 
-  printf ("=== qos_filter ===\n");
-
   if (nmh->nlmsg_type == RTM_NEWQDISC)
     tc_type = "qdisc";
   else if (nmh->nlmsg_type == RTM_NEWTCLASS)
