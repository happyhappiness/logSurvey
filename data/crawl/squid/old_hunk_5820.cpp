	storeAppendPrintf(sentry, "FS Block Size %d Bytes\n",
	    SD->fs.blksize);
	SD->statfs(SD, sentry);
    }
}

