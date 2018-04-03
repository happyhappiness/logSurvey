            blen += base64_encode_final(&ctx, result+blen);
            result[blen] = '\0';
            if (blen)
                httpHeaderPutStrf(hdr_out, HDR_AUTHORIZATION, "Basic %.*s", blen, result);
        }
    }

