	      switch (f->command_state)
		{
		case cs_running:
		  puts ("#  Commands currently running (THIS IS A BUG).");
		  break;
		case cs_deps_running:
		  puts ("#  Dependencies commands running (THIS IS A BUG).");
		  break;
		case cs_not_started:
		case cs_finished:
