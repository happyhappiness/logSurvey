		/* the lifetime should be greater than curtime */
		lft = comm_get_fd_lifetime(i);
		to = comm_get_fd_timeout(i);
		sprintf(line, "{\t\t(%3d = %3d, %3d) NET %s}\n",
		    i,
		    (int) (lft > 0 ? lft - squid_curtime : -1),
		    (int) max((to - squid_curtime), 0),
		    fd_note(i, NULL));
		break;
	    case File:
		sprintf(line, "{\t\t(%3d = FILE) %s}\n", i,
		    (s = diskFileName(i)) ? s : "Unknown");
		break;
	    case Pipe:
		sprintf(line, "{\t\t(%3d = PIPE) %s}\n", i, fd_note(i, NULL));
		break;
	    case LOG:
		sprintf(line, "{\t\t(%3d = LOG) %s}\n", i, fd_note(i, NULL));
		break;
	    case Unknown:
	    default:
		sprintf(line, "{\t\t(%3d = UNKNOWN) %s}\n", i, fd_note(i, NULL));
		break;
	    }
	    storeAppend(sentry, line, strlen(line));
	}
    }


    sprintf(line, "{Stop List:}\n");
    storeAppend(sentry, line, strlen(line));
    if ((p = getHttpStoplist())) {
	sprintf(line, "{\tHTTP:}\n");
	storeAppend(sentry, line, strlen(line));
	while (p) {
	    sprintf(line, "{\t\t%s}\n", p->key);
	    storeAppend(sentry, line, strlen(line));
	    p = p->next;
	}
    }
    if ((p = getGopherStoplist())) {
	sprintf(line, "{\tGOPHER:}\n");
	storeAppend(sentry, line, strlen(line));
	while (p) {
	    sprintf(line, "{\t\t%s}\n", p->key);
	    storeAppend(sentry, line, strlen(line));
	    p = p->next;
	}
    }
    if ((p = getFtpStoplist())) {
	sprintf(line, "{\tFTP:}\n");
	storeAppend(sentry, line, strlen(line));
	while (p) {
	    sprintf(line, "{\t\t%s}\n", p->key);
	    storeAppend(sentry, line, strlen(line));
	    p = p->next;
	}
    }
    sprintf(line, "{Internal Data Structures:}\n");
    storeAppend(sentry, line, strlen(line));
    sprintf(line, "{Meta Data:}\n");
    storeAppend(sentry, line, strlen(line));

    sprintf(line, "{\t\tStoreEntry %d x %d bytes = %d KB}\n",
	meta_data.store_entries,
	(int) sizeof(StoreEntry),
	(int) (meta_data.store_entries * sizeof(StoreEntry) >> 10));
    storeAppend(sentry, line, strlen(line));

    sprintf(line, "{\t\tStoreMemObject %d x %d bytes = %d KB}\n",
	meta_data.store_in_mem_objects,
	(int) sizeof(MemObject),
	(int) (meta_data.store_in_mem_objects * sizeof(MemObject) >> 10));
    storeAppend(sentry, line, strlen(line));

    sprintf(line, "{\t\tIPCacheEntry %d x %d bytes = %d KB}\n",
	meta_data.ipcache_count,
	(int) sizeof(ipcache_entry),
	(int) (meta_data.ipcache_count * sizeof(ipcache_entry) >> 10));
    storeAppend(sentry, line, strlen(line));

    sprintf(line, "{\t\tHash link  %d x %d bytes = %d KB}\n",
	meta_data.hash_links = hash_links_allocated,
	(int) sizeof(hash_link),
	(int) (meta_data.hash_links * sizeof(hash_link) >> 10));
    storeAppend(sentry, line, strlen(line));

    sprintf(line, "{\t\tURL strings %d KB}\n",
	meta_data.url_strings >> 10);
    storeAppend(sentry, line, strlen(line));

    sprintf(line, "{\t\tHot Object Cache Items %d}\n", meta_data.hot_vm);
    storeAppend(sentry, line, strlen(line));

    sprintf(line, "{\t\tPool for disk I/O %d KB (Free %d KB)}\n",
	disk_stats.total_pages_allocated * disk_stats.page_size >> 10,
	(disk_stats.total_pages_allocated - disk_stats.n_pages_in_use) * disk_stats.page_size >> 10);
    storeAppend(sentry, line, strlen(line));

    sprintf(line, "{\t\tPool for in-memory objects %d KB (Free %d KB)}\n",
	sm_stats.total_pages_allocated * sm_stats.page_size >> 10,
	(sm_stats.total_pages_allocated - sm_stats.n_pages_in_use) * sm_stats.page_size >> 10);
    storeAppend(sentry, line, strlen(line));

    sprintf(line, "{\tTotal Accounted %d KB}\n",
	(int) (meta_data.store_entries * sizeof(StoreEntry) +
	    meta_data.store_in_mem_objects * sizeof(MemObject) +
	    meta_data.ipcache_count * sizeof(ipcache_entry) +
	    meta_data.hash_links * sizeof(hash_link) +
	    sm_stats.total_pages_allocated * sm_stats.page_size +
	    disk_stats.total_pages_allocated * disk_stats.page_size +
	    meta_data.url_strings) >> 10);
    storeAppend(sentry, line, strlen(line));

    storeAppend(sentry, close_bracket, strlen(close_bracket));
}


