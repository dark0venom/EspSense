/* Generated from /usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/crypto/heimdal/lib/hdb/hdb.asn1 */
/* Do not edit */

#define  ASN1_LIB

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <krb5-types.h>
#include <hdb_asn1.h>
#include <hdb_asn1-priv.h>
#include <asn1_err.h>
#include <der.h>
#include <der-private.h>
#include <asn1-template.h>
#include <parse_units.h>

int ASN1CALL
encode_Salt(unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, const Salt *data, size_t *size)
{
size_t ret HEIMDAL_UNUSED_ATTRIBUTE = 0;
size_t l HEIMDAL_UNUSED_ATTRIBUTE;
int i HEIMDAL_UNUSED_ATTRIBUTE, e HEIMDAL_UNUSED_ATTRIBUTE;

/* opaque */
if((data)->opaque) {
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = der_put_octet_string(p, len, (data)->opaque, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, PRIM, UT_OctetString, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, CONS, 2, &l);
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

e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, CONS, 1, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
/* type */
{
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = der_put_unsigned(p, len, &(data)->type, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, PRIM, UT_Integer, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, CONS, 0, &l);
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
decode_Salt(const unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, Salt *data, size_t *size)
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
size_t type_datalen, type_oldlen;
Der_type type_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &type_type, 0, &type_datalen, &l);
if (e == 0 && type_type != CONS) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
type_oldlen = len;
if (type_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = type_datalen;
{
size_t type_Tag_datalen, type_Tag_oldlen;
Der_type type_Tag_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &type_Tag_type, UT_Integer, &type_Tag_datalen, &l);
if (e == 0 && type_Tag_type != PRIM) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
type_Tag_oldlen = len;
if (type_Tag_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = type_Tag_datalen;
e = der_get_unsigned(p, len, &(data)->type, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = type_Tag_oldlen - type_Tag_datalen;
}
len = type_oldlen - type_datalen;
}
{
size_t salt_datalen, salt_oldlen;
Der_type salt_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &salt_type, 1, &salt_datalen, &l);
if (e == 0 && salt_type != CONS) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
salt_oldlen = len;
if (salt_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = salt_datalen;
{
size_t salt_Tag_datalen, salt_Tag_oldlen;
Der_type salt_Tag_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &salt_Tag_type, UT_OctetString, &salt_Tag_datalen, &l);
if (e == 0 && salt_Tag_type != PRIM) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
salt_Tag_oldlen = len;
if (salt_Tag_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = salt_Tag_datalen;
e = der_get_octet_string(p, len, &(data)->salt, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = salt_Tag_oldlen - salt_Tag_datalen;
}
len = salt_oldlen - salt_datalen;
}
{
size_t opaque_datalen, opaque_oldlen;
Der_type opaque_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &opaque_type, 2, &opaque_datalen, &l);
if (e == 0 && opaque_type != CONS) { e = ASN1_BAD_ID; }
if(e) {
(data)->opaque = NULL;
} else {
(data)->opaque = calloc(1, sizeof(*(data)->opaque));
if ((data)->opaque == NULL) { e = ENOMEM; goto fail; }
p += l; len -= l; ret += l;
opaque_oldlen = len;
if (opaque_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = opaque_datalen;
{
size_t opaque_Tag_datalen, opaque_Tag_oldlen;
Der_type opaque_Tag_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &opaque_Tag_type, UT_OctetString, &opaque_Tag_datalen, &l);
if (e == 0 && opaque_Tag_type != PRIM) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
opaque_Tag_oldlen = len;
if (opaque_Tag_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = opaque_Tag_datalen;
e = der_get_octet_string(p, len, (data)->opaque, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = opaque_Tag_oldlen - opaque_Tag_datalen;
}
len = opaque_oldlen - opaque_datalen;
}
}
len = Top_oldlen - Top_datalen;
}
if(size) *size = ret;
return 0;
fail:
free_Salt(data);
return e;
}

void ASN1CALL
free_Salt(Salt *data)
{
der_free_octet_string(&(data)->salt);
if((data)->opaque) {
der_free_octet_string((data)->opaque);
free((data)->opaque);
(data)->opaque = NULL;
}
}

size_t ASN1CALL
length_Salt(const Salt *data)
{
size_t ret = 0;
{
size_t Top_tag_oldret = ret;
ret = 0;
ret += der_length_unsigned(&(data)->type);
ret += 1 + der_length_len (ret);
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
{
size_t Top_tag_oldret = ret;
ret = 0;
ret += der_length_octet_string(&(data)->salt);
ret += 1 + der_length_len (ret);
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
if((data)->opaque){
size_t Top_tag_oldret = ret;
ret = 0;
ret += der_length_octet_string((data)->opaque);
ret += 1 + der_length_len (ret);
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
ret += 1 + der_length_len (ret);
return ret;
}

int ASN1CALL
copy_Salt(const Salt *from, Salt *to)
{
memset(to, 0, sizeof(*to));
*(&(to)->type) = *(&(from)->type);
if(der_copy_octet_string(&(from)->salt, &(to)->salt)) goto fail;
if((from)->opaque) {
(to)->opaque = malloc(sizeof(*(to)->opaque));
if((to)->opaque == NULL) goto fail;
if(der_copy_octet_string((from)->opaque, (to)->opaque)) goto fail;
}else
(to)->opaque = NULL;
return 0;
fail:
free_Salt(to);
return ENOMEM;
}



