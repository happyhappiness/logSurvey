		} else {
			ep = sp + strlen(sp);
		}
		if (gp) {
			rs[i].pattern = 1;
			ep = gp;
		}
		rs[i].src = xstrndup(sp, ep - sp);
	}
	return rs;
}
