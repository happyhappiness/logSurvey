             opt_store_doublecheck = 1;
             break;
 
-        case 'V':
-
-            if (Config.Sockaddr.http)
-                Config.Sockaddr.http->vhost = 1;
-
-#if USE_SSL
-
-            else if (Config.Sockaddr.https)
-                Config.Sockaddr.https->http.vhost = 1;
-
-#endif
-
-            else
-                fatal("No http_port specified\n");
-
-            break;
-
         case 'X':
             /* force full debugging */
             sigusr2_handle(SIGUSR2);