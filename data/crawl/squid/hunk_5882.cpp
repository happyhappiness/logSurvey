     }
     if (numcontrollers == 0) {
 	fprintf(stderr, "You must specify at least one domain-controller!\n");
+	usage();
 	exit(1);
     }
     last_dc->next = controllers;	/* close the queue, now it's circular */
