
        if (Config.adminEmail)
            mail_warranty();
	puts(dead_msg());
    }

    if (shutting_down)
	exit(1);

    abort();
}

