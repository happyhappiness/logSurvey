		only_include_assumed = "Explicit paths specified without -i nor -o; assuming --only paths...";
		also = 0;
	}

	if (all && argc > 0)
		die("Paths with -a does not make sense.");
