    SwapDir *tmp = NULL;
    if ((path = strtok(NULL, w_space)) == NULL)
	self_destruct();
    GetInteger(i);
    size = i << 10;		/* Mbytes to kbytes */
    GetInteger(i);
