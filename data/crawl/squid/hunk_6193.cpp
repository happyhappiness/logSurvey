 #include <netinet/in.h>
 main ()
 {
+	FILE *fp;
         int fd,val=0,len=sizeof(int);
 	if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) exit(1);
         if (getsockopt(fd, SOL_SOCKET, SO_RCVBUF, &val, &len) < 0) exit(1);
 	if (val <= 0) exit(1);
-        fprintf (fopen("conftestval", "w"), "%d\n", val);
+	fp = fopen("conftestval", "w"); 
+	fprintf (fp, "%d\n", val);
 	exit(0);
 }
 ],
