 
             router_list_ptr->local_ip = local.sin_addr;
 
-            /* Disconnect the sending socket */
-            router.sin_family = AF_UNSPEC;
+            /* Disconnect the sending socket. Note: FreeBSD returns error
+             * but disconnects anyway so we have to just assume it worked
+             */
+            if (wccp2_numrouters > 1)
 
-            if (connect(theWccp2Connection, (struct sockaddr *) &router, router_len))
-                fatal("Unable to disconnect WCCP out socket");
+                connect(theWccp2Connection, (struct sockaddr *) &null, router_len);
         }
 
         service_list_ptr = service_list_ptr->next;
     }
 
-    if (wccp2_numrouters == 1) {
-        router.sin_family = AF_INET;
-
-        connect(theWccp2Connection, (struct sockaddr *) &router, sizeof(router));
-    }
-
     wccp2_connected = 1;
 }
 
