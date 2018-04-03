 			st.st_mtime = 0;
 	}
 
-	printf("connect to %s\n", dest);
-
 	pid = git_connect(fd, (char *)dest, uploadpack,
                           verbose ? CONNECT_VERBOSE : 0);
 	if (pid < 0)
