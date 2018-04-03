	Con_Handle->Encrypt_Key_Len = SVAL(SMB_Hdr(pkt), SMB_negrLM_ekl_offset);

	p = (SMB_Hdr(pkt) + SMB_negrLM_buf_offset);
	fprintf(stderr, "%d", (int) (SMB_Hdr(pkt) + SMB_negrLM_buf_offset));
	memcpy(Con_Handle->Encrypt_Key, p, 8);

	p = (SMB_Hdr(pkt) + SMB_negrLM_buf_offset + Con_Handle->Encrypt_Key_Len);
