	(!memcmp (input_token.value, ntlmProtocol, sizeof ntlmProtocol))) {
      if (debug)
	fprintf(stderr, "%s| %s: received type %d NTLM token\n", LogTime(), PROGRAM, (int) *((unsigned char *)input_token.value + sizeof ntlmProtocol));
      fprintf(stdout, "NA received type %d NTLM token\n",(int) *((unsigned char *)input_token.value + sizeof ntlmProtocol));
      goto cleanup;
    } 
#endif
