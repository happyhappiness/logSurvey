#if USE_QOS_NFMARK
int
Ip::Qos::GetNfMarkCallback(enum nf_conntrack_msg_type type,
              struct nf_conntrack *ct,
              void *data)
{
    fatal ("Not implemented");
}
