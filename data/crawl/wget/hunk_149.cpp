         case RETRFINISHED:
           /* Deal with you later.  */
           break;
+#ifdef HAVE_METALINK
+        case RETR_WITH_METALINK:
+          {
+            if (hstat.metalink == NULL)
+              {
+                logputs (LOG_NOTQUIET,
+                         _("Could not find Metalink data in HTTP response. "
+                           "Downloading file using HTTP GET.\n"));
+                *dt &= ~METALINK_METADATA;
+                *dt &= ~HEAD_ONLY;
+                got_head = true;
+                continue;
+              }
+
+            logputs (LOG_VERBOSE,
+                     _("Metalink headers found. "
+                       "Switching to Metalink mode.\n"));
+
+            ret = retrieve_from_metalink (hstat.metalink);
+            goto exit;
+          }
+          break;
+#endif
         default:
           /* All possibilities should have been exhausted.  */
           abort ();
