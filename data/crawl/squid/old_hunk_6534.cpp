    xfree(fi);
}

static void
fileIteratorAdvance(FileIterator *fi)
{
    int res;
    assert(fi);
    do {
	time_t last_time = fi->inner_time;
	res = fi->reader(fi);
	fi->line_count++;
        if (res == frError)
	    fi->bad_line_count++;
	else
	if (res == frEof)
	    fi->inner_time = -1;
	else
	if (fi->inner_time < last_time) {
	    assert(last_time >= 0);
	    fi->time_warp_count++;
	    fi->inner_time = last_time;
	}
	/* report progress */
	if (!(fi->line_count % 50000))
	    fprintf(stderr, "%s scanned %d K entries (%d bad)\n",
		fi->fname, fi->line_count / 1000, fi->bad_line_count);
    } while (res < 0);
}

