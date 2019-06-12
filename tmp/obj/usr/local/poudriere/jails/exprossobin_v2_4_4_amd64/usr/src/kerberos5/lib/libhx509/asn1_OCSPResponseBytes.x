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
encode_OCSPResponseBytes(unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, const OCSPResponseBytes *data, size_t *size)
{
size_t ret HEIMDAL_UNUSED_ATTRIBUTE = 0;
size_t l HEIMDAL_UNUSED_ATTRIBUTE;
int i HEIMDAL_UNUSED_ATTRIBUTE, e HEIMDAL_UNUSED_ATTRIBUTE;

/* response */
{
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = der_put_octet_string(p, len, &(data)->response, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, PRIM, UT_OctetString, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
/* responseType */
{
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = der_put_oid(p, len, &(data)->responseType, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, PRIM, UT_OID, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, CONS, UT_Sequence, &l);
if (e) return e;
p -= l; len -= l; ret += l;

*size = ret;
return 0;
}

int ASN1CALL
decode_OCSPResponseBytes(const unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, OCSPResponseBytes *data, size_t *size)
{
size_t ret = 0;
size_t l HEIMDAL_UNUSED_ATTRIBUTE;
int e HEIMDAL_UNUSED_ATTRIBUTE;

memset(data, 0, sizeof(*data));
{
size_t Top_datalen, Top_oldlen;
Der_type Top_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &Top_type, UT_Sequence, &Top_datalen, &l);
if (e == 0 && Top_type != CONS) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
Top_oldlen = len;
if (Top_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = Top_datalen;
{
size_t responseType_datalen, responseType_oldlen;
Der_type responseType_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &responseType_type, UT_OID, &responseType_datalen, &l);
if (e == 0 && responseType_type != PRIM) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
responseType_oldlen = len;
if (responseType_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = responseType_datalen;
e = der_get_oid(p, len, &(data)->responseType, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = responseType_oldlen - responseType_datalen;
}
{
size_t response_datalen, response_oldlen;
Der_type response_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &response_type, UT_OctetString, &response_datalen, &l);
if (e == 0 && response_type != PRIM) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
response_oldlen = len;
if (response_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = response_datalen;
e = der_get_octet_string(p, len, &(data)->response, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = response_oldlen - response_datalen;
}
len = Top_oldlen - Top_datalen;
}
if(size) *size = ret;
return 0;
fail:
free_OCSPResponseBytes(data);
return e;
}

void ASN1CALL
free_OCSPResponseBytes(OCSPResponseBytes *data)
{
der_free_oid(&(data)->responseType);
der_free_octet_string(&(data)->response);
}

size_t ASN1CALL
length_OCSPResponseBytes(const OCSPResponseBytes *data)
{
size_t ret = 0;
{
size_t Top_tag_oldret = ret;
ret = 0;
ret += der_length_oid(&(data)->responseType);
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
{
size_t Top_tag_oldret = ret;
ret = 0;
ret += der_length_octet_string(&(data)->response);
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
ret += 1 + der_length_len (ret);
return ret;
}

int ASN1CALL
copy_OCSPResponseBytes(const OCSPResponseBytes *from, OCSPResponseBytes *to)
{
memset(to, 0, sizeof(*to));
if(der_copy_oid(&(from)->responseType, &(to)->responseType)) goto fail;
if(der_copy_octet_string(&(from)->response, &(to)->response)) goto fail;
return 0;
fail:
free_OCSPResponseBytes(to);
return ENOMEM;
}



