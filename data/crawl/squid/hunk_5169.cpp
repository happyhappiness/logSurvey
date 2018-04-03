         debugs(19, 1, "memCopy: could not find offset " << offset <<
                " in memory.");
         debugDump();
-        /* we shouldn't ever ask for absent offsets */
-        assert (0);
+        fatal("Squid has attempted to read data from memory that is not present. This is an indication of of (pre-3.0) code that hasn't been updated to deal with sparse objects in memory. Squid should coredump.allowing to review the cause. Immediately preceeding this message is a dump of the available data in the format [start,end). The [ means from the value, the ) means up to the value. I.e. [1,5) means that there are 4 bytes of data, at offsets 1,2,3,4.\n");
         return 0;
     }
 