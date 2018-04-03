 
     if (Con_Handle->protocol == SMB_P_Unknown) {	/* No good ... */
 
-	RFCNB_Free_Pkt(pkt);
-	SMBlib_errno = SMBlibE_ProtUnknown;
-	return (SMBlibE_BAD);
+        RFCNB_Free_Pkt(pkt);
+        SMBlib_errno = SMBlibE_ProtUnknown;
+        return (SMBlibE_BAD);
 
     }
     switch (CVAL(SMB_Hdr(pkt), SMB_hdr_wct_offset)) {
 
     case 0x01:			/* No more info ... */
 
-	break;
+        break;
 
     case 13:			/* Up to and including LanMan 2.1 */
 
-	Con_Handle->Security = SVAL(SMB_Hdr(pkt), SMB_negrLM_sec_offset);
-	Con_Handle->encrypt_passwords = ((Con_Handle->Security & SMB_sec_encrypt_mask) != 0x00);
-	Con_Handle->Security = Con_Handle->Security & SMB_sec_user_mask;
+        Con_Handle->Security = SVAL(SMB_Hdr(pkt), SMB_negrLM_sec_offset);
+        Con_Handle->encrypt_passwords = ((Con_Handle->Security & SMB_sec_encrypt_mask) != 0x00);
+        Con_Handle->Security = Con_Handle->Security & SMB_sec_user_mask;
 
-	Con_Handle->max_xmit = SVAL(SMB_Hdr(pkt), SMB_negrLM_mbs_offset);
-	Con_Handle->MaxMPX = SVAL(SMB_Hdr(pkt), SMB_negrLM_mmc_offset);
-	Con_Handle->MaxVC = SVAL(SMB_Hdr(pkt), SMB_negrLM_mnv_offset);
-	Con_Handle->Raw_Support = SVAL(SMB_Hdr(pkt), SMB_negrLM_rm_offset);
-	Con_Handle->SessionKey = IVAL(SMB_Hdr(pkt), SMB_negrLM_sk_offset);
-	Con_Handle->SvrTZ = SVAL(SMB_Hdr(pkt), SMB_negrLM_stz_offset);
-	Con_Handle->Encrypt_Key_Len = SVAL(SMB_Hdr(pkt), SMB_negrLM_ekl_offset);
+        Con_Handle->max_xmit = SVAL(SMB_Hdr(pkt), SMB_negrLM_mbs_offset);
+        Con_Handle->MaxMPX = SVAL(SMB_Hdr(pkt), SMB_negrLM_mmc_offset);
+        Con_Handle->MaxVC = SVAL(SMB_Hdr(pkt), SMB_negrLM_mnv_offset);
+        Con_Handle->Raw_Support = SVAL(SMB_Hdr(pkt), SMB_negrLM_rm_offset);
+        Con_Handle->SessionKey = IVAL(SMB_Hdr(pkt), SMB_negrLM_sk_offset);
+        Con_Handle->SvrTZ = SVAL(SMB_Hdr(pkt), SMB_negrLM_stz_offset);
+        Con_Handle->Encrypt_Key_Len = SVAL(SMB_Hdr(pkt), SMB_negrLM_ekl_offset);
 
-	p = (SMB_Hdr(pkt) + SMB_negrLM_buf_offset);
-	memcpy(Con_Handle->Encrypt_Key, p, 8);
+        p = (SMB_Hdr(pkt) + SMB_negrLM_buf_offset);
+        memcpy(Con_Handle->Encrypt_Key, p, 8);
 
-	p = (SMB_Hdr(pkt) + SMB_negrLM_buf_offset + Con_Handle->Encrypt_Key_Len);
+        p = (SMB_Hdr(pkt) + SMB_negrLM_buf_offset + Con_Handle->Encrypt_Key_Len);
 
-	strncpy(p, Con_Handle->Svr_PDom, sizeof(Con_Handle->Svr_PDom) - 1);
+        strncpy(p, Con_Handle->Svr_PDom, sizeof(Con_Handle->Svr_PDom) - 1);
 
-	break;
+        break;
 
     case 17:			/* NT LM 0.12 and LN LM 1.0 */
 
-	Con_Handle->Security = SVAL(SMB_Hdr(pkt), SMB_negrNTLM_sec_offset);
-	Con_Handle->encrypt_passwords = ((Con_Handle->Security & SMB_sec_encrypt_mask) != 0x00);
-	Con_Handle->Security = Con_Handle->Security & SMB_sec_user_mask;
+        Con_Handle->Security = SVAL(SMB_Hdr(pkt), SMB_negrNTLM_sec_offset);
+        Con_Handle->encrypt_passwords = ((Con_Handle->Security & SMB_sec_encrypt_mask) != 0x00);
+        Con_Handle->Security = Con_Handle->Security & SMB_sec_user_mask;
 
-	Con_Handle->max_xmit = IVAL(SMB_Hdr(pkt), SMB_negrNTLM_mbs_offset);
-	Con_Handle->MaxMPX = SVAL(SMB_Hdr(pkt), SMB_negrNTLM_mmc_offset);
-	Con_Handle->MaxVC = SVAL(SMB_Hdr(pkt), SMB_negrNTLM_mnv_offset);
-	Con_Handle->MaxRaw = IVAL(SMB_Hdr(pkt), SMB_negrNTLM_mrs_offset);
-	Con_Handle->SessionKey = IVAL(SMB_Hdr(pkt), SMB_negrNTLM_sk_offset);
-	Con_Handle->SvrTZ = SVAL(SMB_Hdr(pkt), SMB_negrNTLM_stz_offset);
-	Con_Handle->Encrypt_Key_Len = CVAL(SMB_Hdr(pkt), SMB_negrNTLM_ekl_offset);
+        Con_Handle->max_xmit = IVAL(SMB_Hdr(pkt), SMB_negrNTLM_mbs_offset);
+        Con_Handle->MaxMPX = SVAL(SMB_Hdr(pkt), SMB_negrNTLM_mmc_offset);
+        Con_Handle->MaxVC = SVAL(SMB_Hdr(pkt), SMB_negrNTLM_mnv_offset);
+        Con_Handle->MaxRaw = IVAL(SMB_Hdr(pkt), SMB_negrNTLM_mrs_offset);
+        Con_Handle->SessionKey = IVAL(SMB_Hdr(pkt), SMB_negrNTLM_sk_offset);
+        Con_Handle->SvrTZ = SVAL(SMB_Hdr(pkt), SMB_negrNTLM_stz_offset);
+        Con_Handle->Encrypt_Key_Len = CVAL(SMB_Hdr(pkt), SMB_negrNTLM_ekl_offset);
 
-	p = (SMB_Hdr(pkt) + SMB_negrNTLM_buf_offset);
-	memcpy(Con_Handle->Encrypt_Key, p, 8);
-	p = (SMB_Hdr(pkt) + SMB_negrNTLM_buf_offset + Con_Handle->Encrypt_Key_Len);
+        p = (SMB_Hdr(pkt) + SMB_negrNTLM_buf_offset);
+        memcpy(Con_Handle->Encrypt_Key, p, 8);
+        p = (SMB_Hdr(pkt) + SMB_negrNTLM_buf_offset + Con_Handle->Encrypt_Key_Len);
 
-	strncpy(p, Con_Handle->Svr_PDom, sizeof(Con_Handle->Svr_PDom) - 1);
+        strncpy(p, Con_Handle->Svr_PDom, sizeof(Con_Handle->Svr_PDom) - 1);
 
-	break;
+        break;
 
     default:
 
 #ifdef DEBUG
-	fprintf(stderr, "Unknown NegProt response format ... Ignored\n");
-	fprintf(stderr, "  wct = %i\n", CVAL(SMB_Hdr(pkt), SMB_hdr_wct_offset));
+        fprintf(stderr, "Unknown NegProt response format ... Ignored\n");
+        fprintf(stderr, "  wct = %i\n", CVAL(SMB_Hdr(pkt), SMB_hdr_wct_offset));
 #endif
 
-	break;
+        break;
     }
 
 #ifdef DEBUG
