                x = x->rn_r;
            else
                x = x->rn_l;
        } while (b > (unsigned) x->rn_b);	/* x->rn_b < b && x->rn_b >= 0 */
#ifdef RN_DEBUG
        if (rn_debug)
            fprintf(stderr, "squid_rn_insert: Going In:\n");
