	  error (NILF, "*** Waiting for unfinished jobs....");
	}

#ifndef WAIT_NOHANG
      /* We have one less dead child to reap.
	 The test and decrement are not atomic; if it is compiled into:
	 	register = dead_children - 1;
		dead_children = register;
