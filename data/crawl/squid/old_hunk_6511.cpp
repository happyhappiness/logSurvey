	    }
	    orp = rp;
	}
	if (freeme != NULL){
	    xfree((char *)freeme);
	    freeme = NULL;
	}
    }
}


/* Print some API stats */
void snmp_api_stats(void *outP)
{
  struct session_list *slp;
  struct request_list *rp;
  struct snmp_internal_session *isp;
  FILE *out = (FILE *)outP;

  int active = 0;
  int requests = 0;
  int count = 0;
  int rcount = 0;

  fprintf(out, "LIBSNMP: Session List Dump\n");
  fprintf(out, "LIBSNMP: ----------------------------------------\n");
  for(slp = Sessions; slp; slp = slp->next){

    isp = slp->internal;
    active++;
    count++;
    fprintf(out, "LIBSNMP: %2d: Host %s\n", count, 
	    (slp->session->peername == NULL) ? "NULL" : slp->session->peername);

    if (isp->requests) {
      /* found another session with outstanding requests */
      requests++;
      rcount=0;
      for (rp=isp->requests; rp; rp=rp->next_request) {
	rcount++;
	{
	  struct hostent *hp;
	  hp = gethostbyaddr((char *)&(rp->pdu->address), 
			     sizeof(u_int), AF_INET);
	  fprintf(out, "LIBSNMP: %2d: ReqId %d (%s) (%s)\n", 
		  rcount, rp->request_id, snmp_pdu_type(rp->pdu),
		  (hp == NULL) ? "NULL" : hp->h_name);
	}
      }
    }
    fprintf(out, "LIBSNMP: ----------------------------------------\n");
  }
  fprintf(out, "LIBSNMP: Session List: %d active, %d have requests pending.\n",
	  active, requests);
}
#endif
