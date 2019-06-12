/* Generated from /usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/crypto/heimdal/lib/hx509/ocsp.asn1 */
/* Do not edit */

#define  ASN1_LIB

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <krb5-types.h>
#include <ocsp_asn1.h>
#include <ocsp_asn1-priv.h>
#include <asn1_err.h>
#include <der.h>
#include <der-private.h>
#include <asn1-template.h>
#include <parse_units.h>

int ASN1CALL
encode_OCSPResponseStatus(unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, const OCSPResponseStatus *data, size_t *size)
{
size_t ret HEIMDAL_UNUSED_ATTRIBUTE = 0;
size_t l HEIMDAL_UNUSED_ATTRIBUTE;
int i HEIMDAL_UNUSED_ATTRIBUTE, e HEIMDAL_UNUSED_ATTRIBUTE;

{
int enumint = (int)*data;
e = der_put_integer(p, len, &enumint, &l);
if (e) return e;
p -= l; len -= l; ret += l;

}
;e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, PRIM, UT_Enumerated, &l);
if (e) return e;
p -= l; len -= l; ret += l;

*size = ret;
return 0;
}

int ASN1CALL
decode_OCSPResponseStatus(const unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, OCSPResponseStatus *data, size_t *size)
{
size_t ret = 0;
size_t l HEIMDAL_UNUSED_ATTRIBUTE;
int e HEIMDAL_UNUSED_ATTRIBUTE;

memset(data, 0, sizeof(*data));
{
size_t Top_datalen, Top_oldlen;
Der_type Top_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &Top_type, UT_Enumerated, &Top_datalen, &l);
if (e == 0 && Top_type != PRIM) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
Top_oldlen = len;
if (Top_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = Top_datalen;
{
int enumint;
e = der_get_integer(p, len, &enumint, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
*data = enumint;
}
len = Top_oldlen - Top_datalen;
}
if(size) *size = ret;
return 0;
fail:
free_OCSPResponseStatus(data);
return e;
}

void ASN1CALL
free_OCSPResponseStatus(OCSPResponseStatus *data)
{
}

size_t ASN1CALL
length_OCSPResponseStatus(const OCSPResponseStatus *data)
{
size_t ret = 0;
{
int enumint = *data;
ret += der_length_integer(&enumint);
}
ret += 1 + der_length_len (ret);
return ret;
}

int ASN1CALL
copy_OCSPResponseStatus(const OCSPResponseStatus *from, OCSPResponseStatus *to)
{
memset(to, 0, sizeof(*to));
*(to) = *(from);
return 0;
}



