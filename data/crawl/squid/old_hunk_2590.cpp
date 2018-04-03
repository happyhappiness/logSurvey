		} printf("\n"); assert(b); \
	}

Ip::Address::Address()
{
    SetEmpty();
}

Ip::Address::~Address()
{
    memset(this,0,sizeof(Ip::Address));
}

int
Ip::Address::GetCIDR() const
{
