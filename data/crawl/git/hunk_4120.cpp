 
 unmap:
 	munmap(mmap, mmap_size);
-	errno = EINVAL;
 	die("index file corrupt");
 }
 
