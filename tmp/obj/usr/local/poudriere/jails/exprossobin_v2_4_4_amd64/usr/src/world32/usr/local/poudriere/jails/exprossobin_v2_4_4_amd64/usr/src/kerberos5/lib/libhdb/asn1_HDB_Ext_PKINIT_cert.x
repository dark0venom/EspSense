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
encode_HDB_Ext_PKINIT_cert(unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, const HDB_Ext_PKINIT_cert *data, size_t *size)
{
size_t ret HEIMDAL_UNUSED_ATTRIBUTE = 0;
size_t l HEIMDAL_UNUSED_ATTRIBUTE;
int i HEIMDAL_UNUSED_ATTRIBUTE, e HEIMDAL_UNUSED_ATTRIBUTE;

for(i = (int)(data)->len - 1; i >= 0; --i) {
size_t Top_tag_for_oldret = ret;
ret = 0;
/* cert */
{
size_t Top_tag_S_Of_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = der_put_octet_string(p, len, &(&(data)->val[i])->cert, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, PRIM, UT_OctetString, &l);
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
decode_HDB_Ext_PKINIT_cert(const unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, HDB_Ext_PKINIT_cert *data, size_t *size)
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
size_t cert_datalen, cert_oldlen;
Der_type cert_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &cert_type, 0, &cert_datalen, &l);
if (e == 0 && cert_type != CONS) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
cert_oldlen = len;
if (cert_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = cert_datalen;
{
size_t cert_Tag_datalen, cert_Tag_oldlen;
Der_type cert_Tag_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &cert_Tag_type, UT_OctetString, &cert_Tag_datalen, &l);
if (e == 0 && cert_Tag_type != PRIM) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
cert_Tag_oldlen = len;
if (cert_Tag_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = cert_Tag_datalen;
e = der_get_octet_string(p, len, &(&(data)->val[(data)->len])->cert, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = cert_Tag_oldlen - cert_Tag_datalen;
}
len = cert_oldlen - cert_datalen;
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
free_HDB_Ext_PKINIT_cert(data);
return e;
}

void ASN1CALL
free_HDB_Ext_PKINIT_cert(HDB_Ext_PKINIT_cert *data)
{
while((data)->len){
der_free_octet_string(&(&(data)->val[(data)->len-1])->cert);
(data)->len--;
}
free((data)->val);
(data)->val = NULL;
}

size_t ASN1CALL
length_HDB_Ext_PKINIT_cert(const HDB_Ext_PKINIT_cert *data)
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
ret += der_length_octet_string(&(&(data)->val[i])->cert);
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
copy_HDB_Ext_PKINIT_cert(const HDB_Ext_PKINIT_cert *from, HDB_Ext_PKINIT_cert *to)
{
memset(to, 0, sizeof(*to));
if(((to)->val = malloc((from)->len * sizeof(*(to)->val))) == NULL && (from)->len != 0)
goto fail;
for((to)->len = 0; (to)->len < (from)->len; (to)->len++){
if(der_copy_octet_string(&(&(from)->val[(to)->len])->cert, &(&(to)->val[(to)->len])->cert)) goto fail;
}
return 0;
fail:
free_HDB_Ext_PKINIT_cert(to);
return ENOMEM;
}



