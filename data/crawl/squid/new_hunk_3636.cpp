
            checkUniqueness(pos);

            if (allServicesSame) {
                if (!baselineKey.size()) {
                    baselineKey = service->cfg().key;
                    baselineBypass = service->cfg().bypass;
                } else if (baselineBypass != service->cfg().bypass) {
                    debugs(93,0, "WARNING: Inconsistent bypass in " << kind <<
                           ' ' << id << " may produce surprising results: " <<
                           baselineKey << " vs. " << sid);
                }
            }
        } else {
            finalizeMsg("ERROR: Unknown adaptation name", sid, true);
        }
    }
