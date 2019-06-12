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
encode_HDB_Ext_PKINIT_hash(unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, const HDB_Ext_PKINIT_hash *data, size_t *size)
{
size_t ret HEIMDAL_UNUSED_ATTRIBUTE = 0;
size_t l HEIMDAL_UNUSED_ATTRIBUTE;
int i HEIMDAL_UNUSED_ATTRIBUTE, e HEIMDAL_UNUSED_ATTRIBUTE;

for(i = (int)(data)->len - 1; i >= 0; --i) {
size_t Top_tag_for_oldret = ret;
ret = 0;
/* digest */
{
size_t Top_tag_S_Of_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = der_put_octet_string(p, len, &(&(data)->val[i])->digest, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, PRIM, UT_OctetString, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, CONS, 1, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_S_Of_tag_oldret;
}
/* digest-type */
{
size_t Top_tag_S_Of_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = der_put_oid(p, len, &(&(data)->val[i])->digest_type, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, PRIM, UT_OID, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, CONS, 0, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_S_Of_tag_oldret;
}
e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, CONS, UT_Sequence, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_for_oldret;
}
e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, CONS, UT_Sequence, &l);
if (e) return e;
p -= l; len -= l; ret += l;

*size = ret;
return 0;
}

int ASN1CALL
decode_HDB_Ext_PKINIT_hash(const unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, HDB_Ext_PKINIT_hash *data, size_t *size)
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
size_t Top_Tag_origlen = len;
size_t Top_Tag_oldret = ret;
size_t Top_Tag_olen = 0;
void *Top_Tag_tmp;
ret = 0;
(data)->len = 0;
(data)->val = NULL;
while(ret < Top_Tag_origlen) {
size_t Top_Tag_nlen = Top_Tag_olen + sizeof(*((data)->val));
if (Top_Tag_olen > Top_Tag_nlen) { e = ASN1_OVERFLOW; goto fail; }
Top_Tag_olen = Top_Tag_nlen;
Top_Tag_tmp = realloc((data)->val, Top_Tag_olen);
if (Top_Tag_tmp == NULL) { e = ENOMEM; goto fail; }
(data)->val = Top_Tag_tmp;
{
size_t Top_Tag_s_of_datalen, Top_Tag_s_of_oldlen;
Der_type Top_Tag_s_of_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &Top_Tag_s_of_type, UT_Sequence, &Top_Tag_s_of_datalen, &l);
if (e == 0 && Top_Tag_s_of_type != CONS) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
Top_Tag_s_of_oldlen = len;
if (Top_Tag_s_of_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = Top_Tag_s_of_datalen;
{
size_t digest_type_datalen, digest_type_oldlen;
Der_type digest_type_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &digest_type_type, 0, &digest_type_datalen, &l);
if (e == 0 && digest_type_type != CONS) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
digest_type_oldlen = len;
if (digest_type_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = digest_type_datalen;
{
size_t digest_type_Tag_datalen, digest_type_Tag_oldlen;
Der_type digest_type_Tag_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &digest_type_Tag_type, UT_OID, &digest_type_Tag_datalen, &l);
if (e == 0 && digest_type_Tag_type != PRIM) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
digest_type_Tag_oldlen = len;
if (digest_type_Tag_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = digest_type_Tag_datalen;
e = der_get_oid(p, len, &(&(data)->val[(data)->len])->digest_type, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = digest_type_Tag_oldlen - digest_type_Tag_datalen;
}
len = digest_type_oldlen - digest_type_datalen;
}
{
size_t digest_datalen, digest_oldlen;
Der_type digest_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &digest_type, 1, &digest_datalen, &l);
if (e == 0 && digest_type != CONS) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
digest_oldlen = len;
if (digest_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = digest_datalen;
{
size_t digest_Tag_datalen, digest_Tag_oldlen;
Der_type digest_Tag_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &digest_Tag_type, UT_OctetString, &digest_Tag_datalen, &l);
if (e == 0 && digest_Tag_type != PRIM) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
digest_Tag_oldlen = len;
if (digest_Tag_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = digest_Tag_datalen;
e = der_get_octet_string(p, len, &(&(data)->val[(data)->len])->digest, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = digest_Tag_oldlen - digest_Tag_datalen;
}
len = digest_oldlen - digest_datalen;
}
len = Top_Tag_s_of_oldlen - Top_Tag_s_of_datalen;
}
(data)->len++;
len = Top_Tag_origlen - ret;
}
ret += Top_Tag_oldret;
}
len = Top_oldlen - Top_datalen;
}
if(size) *size = ret;
return 0;
fail:
free_HDB_Ext_PKINIT_hash(data);
return e;
}

void ASN1CALL
free_HDB_Ext_PKINIT_hash(HDB_Ext_PKINIT_hash *data)
{
while((data)->len){
der_free_oid(&(&(data)->val[(data)->len-1])->digest_type);
der_free_octet_string(&(&(data)->val[(data)->len-1])->digest);
(data)->len--;
}
free((data)->val);
(data)->val = NULL;
}

size_t ASN1CALL
length_HDB_Ext_PKINIT_hash(const HDB_Ext_PKINIT_hash *data)
{
size_t ret = 0;
{
size_t Top_tag_oldret = ret;
int i;
ret = 0;
for(i = (data)->len - 1; i >= 0; --i){
size_t Top_tag_for_oldret = ret;
ret = 0;
{
size_t Top_tag_S_Of_tag_oldret = ret;
ret = 0;
ret += der_length_oid(&(&(data)->val[i])->digest_type);
ret += 1 + der_length_len (ret);
ret += 1 + der_length_len (ret);
ret += Top_tag_S_Of_tag_oldret;
}
{
size_t Top_tag_S_Of_tag_oldret = ret;
ret = 0;
ret += der_length_octet_string(&(&(data)->val[i])->digest);
ret += 1 + der_length_len (ret);
ret += 1 + der_length_len (ret);
ret += Top_tag_S_Of_tag_oldret;
}
ret += 1 + der_length_len (ret);
ret += Top_tag_for_oldret;
}
ret += Top_tag_oldret;
}
ret += 1 + der_length_len (ret);
return ret;
}

int ASN1CALL
copy_HDB_Ext_PKINIT_hash(const HDB_Ext_PKINIT_hash *from, HDB_Ext_PKINIT_hash *to)
{
memset(to, 0, sizeof(*to));
if(((to)->val = malloc((from)->len * sizeof(*(to)->val))) == NULL && (from)->len != 0)
goto fail;
for((to)->len = 0; (to)->len < (from)->len; (to)->len++){
if(der_copy_oid(&(&(from)->val[(to)->len])->digest_type, &(&(to)->val[(to)->len])->digest_type)) goto fail;
if(der_copy_octet_string(&(&(from)->val[(to)->len])->digest, &(&(to)->val[(to)->len])->digest)) goto fail;
}
return 0;
fail:
free_HDB_Ext_PKINIT_hash(to);
return ENOMEM;
}



