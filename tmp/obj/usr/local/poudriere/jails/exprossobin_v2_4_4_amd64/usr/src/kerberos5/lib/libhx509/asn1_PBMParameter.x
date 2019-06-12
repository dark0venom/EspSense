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
encode_PBMParameter(unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, const PBMParameter *data, size_t *size)
{
size_t ret HEIMDAL_UNUSED_ATTRIBUTE = 0;
size_t l HEIMDAL_UNUSED_ATTRIBUTE;
int i HEIMDAL_UNUSED_ATTRIBUTE, e HEIMDAL_UNUSED_ATTRIBUTE;

/* mac */
{
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = encode_AlgorithmIdentifier(p, len, &(data)->mac, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
/* iterationCount */
{
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = der_put_heim_integer(p, len, &(data)->iterationCount, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, PRIM, UT_Integer, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
/* owf */
{
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = encode_AlgorithmIdentifier(p, len, &(data)->owf, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
/* salt */
{
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = der_put_octet_string(p, len, &(data)->salt, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, PRIM, UT_OctetString, &l);
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
decode_PBMParameter(const unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, PBMParameter *data, size_t *size)
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
size_t salt_datalen, salt_oldlen;
Der_type salt_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &salt_type, UT_OctetString, &salt_datalen, &l);
if (e == 0 && salt_type != PRIM) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
salt_oldlen = len;
if (salt_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = salt_datalen;
e = der_get_octet_string(p, len, &(data)->salt, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = salt_oldlen - salt_datalen;
}
e = decode_AlgorithmIdentifier(p, len, &(data)->owf, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
{
size_t iterationCount_datalen, iterationCount_oldlen;
Der_type iterationCount_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &iterationCount_type, UT_Integer, &iterationCount_datalen, &l);
if (e == 0 && iterationCount_type != PRIM) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
iterationCount_oldlen = len;
if (iterationCount_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = iterationCount_datalen;
e = der_get_heim_integer(p, len, &(data)->iterationCount, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = iterationCount_oldlen - iterationCount_datalen;
}
e = decode_AlgorithmIdentifier(p, len, &(data)->mac, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = Top_oldlen - Top_datalen;
}
if(size) *size = ret;
return 0;
fail:
free_PBMParameter(data);
return e;
}

void ASN1CALL
free_PBMParameter(PBMParameter *data)
{
der_free_octet_string(&(data)->salt);
free_AlgorithmIdentifier(&(data)->owf);
der_free_heim_integer(&(data)->iterationCount);
free_AlgorithmIdentifier(&(data)->mac);
}

size_t ASN1CALL
length_PBMParameter(const PBMParameter *data)
{
size_t ret = 0;
{
size_t Top_tag_oldret = ret;
ret = 0;
ret += der_length_octet_string(&(data)->salt);
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
{
size_t Top_tag_oldret = ret;
ret = 0;
ret += length_AlgorithmIdentifier(&(data)->owf);
ret += Top_tag_oldret;
}
{
size_t Top_tag_oldret = ret;
ret = 0;
ret += der_length_heim_integer(&(data)->iterationCount);
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
{
size_t Top_tag_oldret = ret;
ret = 0;
ret += length_AlgorithmIdentifier(&(data)->mac);
ret += Top_tag_oldret;
}
ret += 1 + der_length_len (ret);
return ret;
}

int ASN1CALL
copy_PBMParameter(const PBMParameter *from, PBMParameter *to)
{
memset(to, 0, sizeof(*to));
if(der_copy_octet_string(&(from)->salt, &(to)->salt)) goto fail;
if(copy_AlgorithmIdentifier(&(from)->owf, &(to)->owf)) goto fail;
if(der_copy_heim_integer(&(from)->iterationCount, &(to)->iterationCount)) goto fail;
if(copy_AlgorithmIdentifier(&(from)->mac, &(to)->mac)) goto fail;
return 0;
fail:
free_PBMParameter(to);
return ENOMEM;
}



