 * Returns number of bytes sent
 * Returns -1 on error
 */
int net_send(int sockfd, char *buff, int len)
{
   int rc;
   short pktsiz;

   /* send short containing size of data packet */
   pktsiz = htons((short)len);
   rc = write_nbytes(sockfd, (char *)&pktsiz, sizeof(short));
   if (rc != sizeof(short)) {
      net_errmsg = "net_send: write_nbytes error of length prefix\n";
      return -1;
   }

   /* send data packet */
   rc = write_nbytes(sockfd, buff, len);
   if (rc != len) {
      net_errmsg = "net_send: write_nbytes error\n";
      return -1;
   }

   return rc;
}


/* Get and print status from apcupsd NIS server */
static void do_pthreads_status(char *host, int port, struct apc_detail_s *apcups_detail)
{
  int sockfd, n;
  char recvline[MAXSTRING + 1];
  char *tokptr;

  if ((sockfd = net_open(host, NULL, port)) < 0)
    Error_abort0(net_errmsg);
  
  net_send(sockfd, "status", 6);
  
  while ((n = net_recv(sockfd, recvline, sizeof(recvline))) > 0) {
    recvline[n] = 0;
#ifdef APCMAIN
    fputs(recvline, stdout);
    int printit = 1;
#else
    int printit = 0;
#endif /* ifdef APCMAIN */

    tokptr = strtok(recvline,":");
    while(tokptr != NULL) {
      /* Look for Limit_Add */
      if(strncmp("LINEV",tokptr,5) == 0) { 
	if(printit) fprintf(stdout,"  Found LINEV.\n");
	tokptr = strtok(NULL," \t");
	if(tokptr == NULL) continue;
	if(printit) fprintf(stdout,"  Value %s.\n",tokptr);
	apcups_detail->linev = atof (tokptr);
      }else if(strncmp("BATTV",tokptr,5) == 0) { 
	if(printit) fprintf(stdout,"  Found BATTV.\n");
	tokptr = strtok(NULL," \t");
	if(tokptr == NULL) continue;
	if(printit) fprintf(stdout,"  Value %s.\n",tokptr);
	apcups_detail->battv = atof (tokptr);
      }else if(strncmp("ITEMP",tokptr,5) == 0) { 
	if(printit) fprintf(stdout,"  Found ITEMP.\n");
	tokptr = strtok(NULL," \t");
	if(tokptr == NULL) continue;
	if(printit) fprintf(stdout,"  Value %s.\n",tokptr);
	apcups_detail->itemp = atof (tokptr);
      }else if(strncmp("LOADPCT",tokptr,7) == 0) { 
	if(printit) fprintf(stdout,"  Found LOADPCT.\n");
	tokptr = strtok(NULL," \t");
	if(tokptr == NULL) continue;
	if(printit) fprintf(stdout,"  Value %s.\n",tokptr);
	apcups_detail->loadpct = atof (tokptr);
      }else if(strncmp("BCHARGE",tokptr,7) == 0) { 
	if(printit) fprintf(stdout,"  Found BCHARGE.\n");
	tokptr = strtok(NULL," \t");
	if(tokptr == NULL) continue;
	if(printit) fprintf(stdout,"  Value %s.\n",tokptr);
	apcups_detail->bcharge = atof (tokptr);
      }else if(strncmp("OUTPUTV",tokptr,7) == 0) { 
	if(printit) fprintf(stdout,"  Found OUTPUTV.\n");
	tokptr = strtok(NULL," \t");
	if(tokptr == NULL) continue;
	if(printit) fprintf(stdout,"  Value %s.\n",tokptr);
	apcups_detail->outputv = atof (tokptr);
      }else if(strncmp("LINEFREQ",tokptr,8) == 0) { 
	if(printit) fprintf(stdout,"  Found LINEFREQ.\n");
	tokptr = strtok(NULL," \t");
	if(tokptr == NULL) continue;
	if(printit) fprintf(stdout,"  Value %s.\n",tokptr);
	apcups_detail->linefreq = atof (tokptr);
      }else if(strncmp("TIMELEFT",tokptr,8) == 0) { 
	if(printit) fprintf(stdout,"  Found TIMELEFT.\n");
	tokptr = strtok(NULL," \t");
	if(tokptr == NULL) continue;
	if(printit) fprintf(stdout,"  Value %s.\n",tokptr);
	apcups_detail->timeleft = atof (tokptr);
      } /* */
      tokptr = strtok(NULL,":");
    }
  }

  if (n < 0)
    Error_abort0(net_errmsg);
  
  net_close(sockfd);
}

#ifdef APCMAIN
int main(int argc, char **argv)
{
  /* we are not really going to use this */
  struct apc_detail_s apcups_detail;

  if (!*host || strcmp(host, "0.0.0.0") == 0)
    host = "localhost";
  
  do_pthreads_status(host, port, &apcups_detail);
  
  return 0;
}
#else
static void apcups_init (void)