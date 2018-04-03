
unmap:
	munmap(mmap, mmap_size);
	die("index file corrupt");
}

