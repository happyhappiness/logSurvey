 				   if we can't backspace the output and have
 				   to null out the first part of the block */
 
-extern void skip_file();
-extern void skip_extended_headers();
+extern void skip_file ();
+extern void skip_extended_headers ();
 
 extern union record *head;
 extern struct stat hstat;
 
-void append_file();
-void close_archive();
-int confirm();
-void decode_header();
-void fl_read();
-void fl_write();
-void flush_archive();
-int move_arch();
-struct name *name_scan();
-char	*name_from_list();
-void name_expand();
-void name_gather();
-void names_notfound();
-void open_archive();
-int read_header();
-void reset_eof();
-void write_block();
-void write_eot();
+void append_file ();
+void close_archive ();
+int confirm ();
+void decode_header ();
+void fl_read ();
+void fl_write ();
+void flush_archive ();
+int move_arch ();
+struct name *name_scan ();
+char *name_from_list ();
+void name_expand ();
+void name_gather ();
+void names_notfound ();
+void open_archive ();
+int read_header ();
+void reset_eof ();
+void write_block ();
+void write_eot ();
 
 /* Implement the 'r' (add files to end of archive), and 'u' (add files to
    end of archive if they arent there, or are more up to date than the
    version in the archive.) commands.*/
 void
-update_archive()
+update_archive ()
 {
-	int	found_end = 0;
-	int	status = 3;
-	int	prev_status;
-	char	*p;
-	struct name *name;
-	extern void dump_file();
-
-	name_gather();
-	if(cmd_mode==CMD_UPDATE)
-		name_expand();
-	open_archive(2);	/* Open for updating */
-
-	do {
-		prev_status=status;
-		status=read_header();
-		switch(status) {
-		case EOF:
-			found_end=1;
-			break;
-
-		case 0:		/* A bad record */
-			userec(head);
-			switch(prev_status) {
-			case 3:
-				msg("This doesn't look like a tar archive.");
-				/* FALL THROUGH */
-			case 2:
-			case 1:
-				msg("Skipping to next header");
-			case 0:
-				break;
-			}
-			break;
-
-			/* A good record */
-		case 1:
- /* printf("File %s\n",head->header.name); */
-			/* head->header.name[NAMSIZ-1]='\0'; */
-			if(cmd_mode==CMD_UPDATE && (name=name_scan(current_file_name)))
-			  {
-			    
-				/* struct stat hstat; */
-				struct stat nstat;
-				int head_standard;
-
-				decode_header(head,&hstat,&head_standard,0);
-				if(stat(current_file_name,&nstat)<0) {
-					msg_perror("can't stat %s:",current_file_name);
-				} else {
-					if(hstat.st_mtime>=nstat.st_mtime)
-						name->found++;
-				}
-			}
-			userec(head);
-			if (head->header.isextended)
-				skip_extended_headers();
-			skip_file((long)hstat.st_size);
-			break;
-
-		case 2:
-			ar_record=head;
-			found_end = 1;
-			break;
+  int found_end = 0;
+  int status = 3;
+  int prev_status;
+  char *p;
+  struct name *name;
+  extern void dump_file ();
+
+  name_gather ();
+  if (cmd_mode == CMD_UPDATE)
+    name_expand ();
+  open_archive (2);		/* Open for updating */
+
+  do
+    {
+      prev_status = status;
+      status = read_header ();
+      switch (status)
+	{
+	case EOF:
+	  found_end = 1;
+	  break;
+
+	case 0:		/* A bad record */
+	  userec (head);
+	  switch (prev_status)
+	    {
+	    case 3:
+	      msg ("This doesn't look like a tar archive.");
+	      /* FALL THROUGH */
+	    case 2:
+	    case 1:
+	      msg ("Skipping to next header");
+	    case 0:
+	      break;
+	    }
+	  break;
+
+	  /* A good record */
+	case 1:
+	  /* printf("File %s\n",head->header.name); */
+	  /* head->header.name[NAMSIZ-1]='\0'; */
+	  if (cmd_mode == CMD_UPDATE && (name = name_scan (current_file_name)))
+	    {
+
+	      /* struct stat hstat; */
+	      struct stat nstat;
+	      int head_standard;
+
+	      decode_header (head, &hstat, &head_standard, 0);
+	      if (stat (current_file_name, &nstat) < 0)
+		{
+		  msg_perror ("can't stat %s:", current_file_name);
 		}
-	} while(!found_end);
-
-	reset_eof();
-	time_to_start_writing = 1;
-	output_start=ar_record->charptr;
-
-	while(p=name_from_list()) {
-		if(f_confirm && !confirm("add", p))
-			continue;
-		if(cmd_mode==CMD_CAT)
-			append_file(p);
-		else
-			dump_file(p,-1, 1);
+	      else
+		{
+		  if (hstat.st_mtime >= nstat.st_mtime)
+		    name->found++;
+		}
+	    }
+	  userec (head);
+	  if (head->header.isextended)
+	    skip_extended_headers ();
+	  skip_file ((long) hstat.st_size);
+	  break;
+
+	case 2:
+	  ar_record = head;
+	  found_end = 1;
+	  break;
 	}
-
-	write_eot();
-	close_archive();
-	names_notfound();
+    }
+  while (!found_end);
+
+  reset_eof ();
+  time_to_start_writing = 1;
+  output_start = ar_record->charptr;
+
+  while (p = name_from_list ())
+    {
+      if (f_confirm && !confirm ("add", p))
+	continue;
+      if (cmd_mode == CMD_CAT)
+	append_file (p);
+      else
+	dump_file (p, -1, 1);
+    }
+
+  write_eot ();
+  close_archive ();
+  names_notfound ();
 }
 
 /* Catenate file p to the archive without creating a header for it.  It had
    better be a tar file or the archive is screwed */
 
 void
-append_file(p)
-char *p;
+append_file (p)
+     char *p;
 {
-	int	fd;
-	struct stat statbuf;
-	long	bytes_left;
-	union record *start;
-	long	bufsiz,count;
-
-	if(0 != stat(p,&statbuf) || (fd=open(p,O_RDONLY|O_BINARY))<0) {
-		msg_perror("can't open file %s",p);
-		errors++;
-		return;
+  int fd;
+  struct stat statbuf;
+  long bytes_left;
+  union record *start;
+  long bufsiz, count;
+
+  if (0 != stat (p, &statbuf) || (fd = open (p, O_RDONLY | O_BINARY)) < 0)
+    {
+      msg_perror ("can't open file %s", p);
+      errors++;
+      return;
+    }
+
+  bytes_left = statbuf.st_size;
+
+  while (bytes_left > 0)
+    {
+      start = findrec ();
+      bufsiz = endofrecs ()->charptr - start->charptr;
+      if (bytes_left < bufsiz)
+	{
+	  bufsiz = bytes_left;
+	  count = bufsiz % RECORDSIZE;
+	  if (count)
+	    bzero (start->charptr + bytes_left, (int) (RECORDSIZE - count));
 	}
-
-	bytes_left = statbuf.st_size;
-
-	while(bytes_left>0) {
-		start=findrec();
-		bufsiz=endofrecs()->charptr - start->charptr;
-		if(bytes_left < bufsiz) {
-			bufsiz = bytes_left;
-			count = bufsiz % RECORDSIZE;
-			if(count)
-				bzero(start->charptr + bytes_left,(int)(RECORDSIZE-count));
-		}
-		count=read(fd,start->charptr,bufsiz);
-		if(count<0) {
-			msg_perror("read error at byte %ld reading %d bytes in file %s",statbuf.st_size-bytes_left,bufsiz,p);
-			exit(EX_ARGSBAD);		/* FOO */
-		}
-		bytes_left-=count;
-		userec(start+(count-1)/RECORDSIZE);
-		if(count!=bufsiz) {
-			msg("%s: file shrunk by %d bytes, yark!",p,bytes_left);
-			abort();
-		}
+      count = read (fd, start->charptr, bufsiz);
+      if (count < 0)
+	{
+	  msg_perror ("read error at byte %ld reading %d bytes in file %s", statbuf.st_size - bytes_left, bufsiz, p);
+	  exit (EX_ARGSBAD);	/* FOO */
 	}
-	(void)close(fd);
+      bytes_left -= count;
+      userec (start + (count - 1) / RECORDSIZE);
+      if (count != bufsiz)
+	{
+	  msg ("%s: file shrunk by %d bytes, yark!", p, bytes_left);
+	  abort ();
+	}
+    }
+  (void) close (fd);
 }
 
 #ifdef DONTDEF
-bprint(fp,buf,num)
-FILE *fp;
-char *buf;
+bprint (fp, buf, num)
+     FILE *fp;
+     char *buf;
 {
-	int	c;
-
-	if(num==0 || num==-1)
-		return;
-	fputs(" '",fp);
-	while(num--) {
-		c= *buf++;
-		if(c=='\\') fputs("\\\\",fp);
-		else if(c>=' ' && c<='~')
-			putc(c,fp);
-		else switch(c) {
-		case '\n':
-			fputs("\\n",fp);
-			break;
-		case '\r':
-			fputs("\\r",fp);
-			break;
-		case '\b':
-			fputs("\\b",fp);
-			break;
-		case '\0':
-			/* fputs("\\-",fp); */
-			break;
-		default:
-			fprintf(fp,"\\%03o",c);
-			break;
-		}
-	}
-	fputs("'\n",fp);
+  int c;
+
+  if (num == 0 || num == -1)
+    return;
+  fputs (" '", fp);
+  while (num--)
+    {
+      c = *buf++;
+      if (c == '\\')
+	fputs ("\\\\", fp);
+      else if (c >= ' ' && c <= '~')
+	putc (c, fp);
+      else
+	switch (c)
+	  {
+	  case '\n':
+	    fputs ("\\n", fp);
+	    break;
+	  case '\r':
+	    fputs ("\\r", fp);
+	    break;
+	  case '\b':
+	    fputs ("\\b", fp);
+	    break;
+	  case '\0':
+	    /* fputs("\\-",fp); */
+	    break;
+	  default:
+	    fprintf (fp, "\\%03o", c);
+	    break;
+	  }
+    }
+  fputs ("'\n", fp);
 }
+
 #endif
 
 int number_of_blocks_read = 0;
