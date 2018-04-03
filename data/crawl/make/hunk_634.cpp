   switch (f->command_state)
     {
     case cs_running:
-      puts (_("#  Commands currently running (THIS IS A BUG)."));
+      puts (_("#  Recipe currently running (THIS IS A BUG)."));
       break;
     case cs_deps_running:
-      puts (_("#  Dependencies commands running (THIS IS A BUG)."));
+      puts (_("#  Dependencies recipe running (THIS IS A BUG)."));
       break;
     case cs_not_started:
     case cs_finished:
