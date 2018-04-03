			char errbuf[1024];
			regerror(err, &regex, errbuf, 1024);
			regfree(&regex);
			die("invalid regex: %s", errbuf);
		}
		regexp = &regex;
	} else {