/* Generated from /usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/crypto/heimdal/lib/hx509/crmf.asn1 */
/* Do not edit */

#define  ASN1_LIB

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <krb5-types.h>
#include <crmf_asn1.h>
#include <crmf_asn1-priv.h>
#include <asn1_err.h>
#include <der.h>
#include <der-private.h>
#include <asn1-template.h>
#include <parse_units.h>

int ASN1CALL
encode_PKMACValue(unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, const PKMACValue *data, size_t *size)
{
size_t ret HEIMDAL_UNUSED_ATTRIBUTE = 0;
size_t l HEIMDAL_UNUSED_ATTRIBUTE;
int i HEIMDAL_UNUSED_ATTRIBUTE, e HEIMDAL_UNUSED_ATTRIBUTE;

/* value */
{
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = der_put_bit_string(p, len, &(data)->value, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, PRIM, UT_BitString, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
/* algId */
{
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = encode_AlgorithmIdentifier(p, len, &(data)->algId, &l);
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
decode_PKMACValue(const unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, PKMACValue *data, size_t *size)
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
e = decode_AlgorithmIdentifier(p, len, &(data)->algId, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
{
size_t value_datalen, value_oldlen;
Der_type value_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &value_type, UT_BitString, &value_datalen, &l);
if (e == 0 && value_type != PRIM) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
value_oldlen = len;
if (value_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = value_datalen;
e = der_get_bit_string(p, len, &(data)->value, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = value_oldlen - value_datalen;
}
len = Top_oldlen - Top_datalen;
}
if(size) *size = ret;
return 0;
fail:
free_PKMACValue(data);
return e;
}

void ASN1CALL
free_PKMACValue(PKMACValue *data)
{
free_AlgorithmIdentifier(&(data)->algId);
der_free_bit_string(&(data)->value);
}

size_t ASN1CALL
length_PKMACValue(const PKMACValue *data)
{
size_t ret = 0;
{
size_t Top_tag_oldret = ret;
ret = 0;
ret += length_AlgorithmIdentifier(&(data)->algId);
ret += Top_tag_oldret;
}
{
size_t Top_tag_oldret = ret;
ret = 0;
ret += der_length_bit_string(&(data)->value);
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
ret += 1 + der_length_len (ret);
return ret;
}

int ASN1CALL
copy_PKMACValue(const PKMACValue *from, PKMACValue *to)
{
memset(to, 0, sizeof(*to));
if(copy_AlgorithmIdentifier(&(from)->algId, &(to)->algId)) goto fail;
if(der_copy_bit_string(&(from)->value, &(to)->value)) goto fail;
return 0;
fail:
free_PKMACValue(to);
return ENOMEM;
}



