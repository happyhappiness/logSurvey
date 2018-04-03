	break;
    case AUTHENTICATE_STATE_RESPONSE:
	sent_string = xstrdup(ntlm_request->ntlmauthenticate);
	assert(ntlm_request->authhelper);
	debug(29, 9) ("authenticateNTLMStart: Asking NTLMauthenticator '%d'.\n", ntlm_request->authhelper);
	break;
    default:
	fatal("Invalid authenticate state for NTLMStart");
