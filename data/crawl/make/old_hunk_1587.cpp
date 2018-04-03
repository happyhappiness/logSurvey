	      switch (f->command_state)
		{
		case cs_running:
		  puts ("#  Commands currently running (?!).");
		  break;
		case cs_deps_running:
		  puts ("#  Dependencies currently being made (?!).");
		  break;
		case cs_not_started:
		case cs_finished:
