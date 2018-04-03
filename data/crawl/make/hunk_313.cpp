     case cs_finished:
       switch (f->update_status)
         {
-        case -1:
+        case us_none:
           break;
-        case 0:
+        case us_success:
           puts (_("#  Successfully updated."));
           break;
-        case 1:
+        case us_question:
           assert (question_flag);
           puts (_("#  Needs to be updated (-q is set)."));
           break;
-        case 2:
+        case us_failed:
           puts (_("#  Failed to be updated."));
           break;
-        default:
-          puts (_("#  Invalid value in 'update_status' member!"));
-          fflush (stdout);
-          fflush (stderr);
-          abort ();
         }
       break;
     default:
