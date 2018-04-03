 	    sb = httpHeaderGetListMember(&request->header, format->header_id, format->member, format->separator);
 	    str = strBuf(sb);
 	    break;
+#if USE_SSL
+	case _external_acl_format::EXT_ACL_USER_CERT:
+	    if (cbdataReferenceValid(ch->conn)) {
+		SSL *ssl = fd_table[ch->conn->fd].ssl;
+		if (ssl)
+		    str = sslGetUserAttribute(ssl, format->header);
+	    }
+	    break;
+	case _external_acl_format::EXT_ACL_CA_CERT:
+	    if (cbdataReferenceValid(ch->conn)) {
+		SSL *ssl = fd_table[ch->conn->fd].ssl;
+		if (ssl)
+		    str = sslGetCAAttribute(ssl, format->header);
+	    }
+	    break;
+#endif
+	case _external_acl_format::EXT_ACL_UNKNOWN:
+	case _external_acl_format::EXT_ACL_END:
+	    fatal("unknown external_acl format error");
+	    break;
 	}
 	if (str)
 	    if (!*str)
