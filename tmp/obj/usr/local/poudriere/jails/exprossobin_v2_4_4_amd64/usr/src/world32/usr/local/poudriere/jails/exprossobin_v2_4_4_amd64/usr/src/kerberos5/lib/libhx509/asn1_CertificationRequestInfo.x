/* Generated from /usr/local/poudriere/jails/exprossobin_v2_4_4_amd64/usr/src/crypto/heimdal/lib/hx509/pkcs10.asn1 */
/* Do not edit */

#define  ASN1_LIB

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <krb5-types.h>
#include <pkcs10_asn1.h>
#include <pkcs10_asn1-priv.h>
#include <asn1_err.h>
#include <der.h>
#include <der-private.h>
#include <asn1-template.h>
#include <parse_units.h>

int ASN1CALL
encode_CertificationRequestInfo(unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, const CertificationRequestInfo *data, size_t *size)
{
size_t ret HEIMDAL_UNUSED_ATTRIBUTE = 0;
size_t l HEIMDAL_UNUSED_ATTRIBUTE;
int i HEIMDAL_UNUSED_ATTRIBUTE, e HEIMDAL_UNUSED_ATTRIBUTE;

/* attributes */
if((data)->attributes) {
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
{
struct heim_octet_string *val;
size_t elen = 0, totallen = 0;
int eret = 0;
if (((data)->attributes)->len > UINT_MAX/sizeof(val[0]))
return ERANGE;
val = malloc(sizeof(val[0]) * ((data)->attributes)->len);
if (val == NULL && ((data)->attributes)->len != 0) return ENOMEM;
for(i = 0; i < (int)((data)->attributes)->len; i++) {
ASN1_MALLOC_ENCODE(Attribute, val[i].data, val[i].length, &((data)->attributes)->val[i], &elen, eret);
if(eret) {
i--;
while (i >= 0) {
free(val[i].data);
i--;
}
free(val);
return eret;
}
totallen += elen;
}
if (totallen > len) {
for (i = 0; i < (int)((data)->attributes)->len; i++) {
free(val[i].data);
}
free(val);
return ASN1_OVERFLOW;
}
qsort(val, ((data)->attributes)->len, sizeof(val[0]), _heim_der_set_sort);
for(i = (int)((data)->attributes)->len - 1; i >= 0; --i) {
p -= val[i].length;
ret += val[i].length;
memcpy(p + 1, val[i].data, val[i].length);
free(val[i].data);
}
free(val);
}
e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, CONS, 0, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
/* subjectPKInfo */
{
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = encode_SubjectPublicKeyInfo(p, len, &(data)->subjectPKInfo, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
/* subject */
{
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = encode_Name(p, len, &(data)->subject, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
/* version */
{
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
{
int enumint = (int)*&(data)->version;
e = der_put_integer(p, len, &enumint, &l);
if (e) return e;
p -= l; len -= l; ret += l;

}
;e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, PRIM, UT_Integer, &l);
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
decode_CertificationRequestInfo(const unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, CertificationRequestInfo *data, size_t *size)
{
size_t ret = 0;
size_t l HEIMDAL_UNUSED_ATTRIBUTE;
int e HEIMDAL_UNUSED_ATTRIBUTE;
const unsigned char *begin = p;

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
size_t version_datalen, version_oldlen;
Der_type version_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &version_type, UT_Integer, &version_datalen, &l);
if (e == 0 && version_type != PRIM) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
version_oldlen = len;
if (version_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = version_datalen;
{
int enumint;
e = der_get_integer(p, len, &enumint, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
*&(data)->version = enumint;
}
len = version_oldlen - version_datalen;
}
e = decode_Name(p, len, &(data)->subject, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
e = decode_SubjectPublicKeyInfo(p, len, &(data)->subjectPKInfo, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
{
size_t attributes_datalen, attributes_oldlen;
Der_type attributes_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &attributes_type, 0, &attributes_datalen, &l);
if (e == 0 && attributes_type != CONS) { e = ASN1_BAD_ID; }
if(e) {
(data)->attributes = NULL;
} else {
(data)->attributes = calloc(1, sizeof(*(data)->attributes));
if ((data)->attributes == NULL) { e = ENOMEM; goto fail; }
p += l; len -= l; ret += l;
attributes_oldlen = len;
if (attributes_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = attributes_datalen;
{
size_t attributes_Tag_origlen = len;
size_t attributes_Tag_oldret = ret;
size_t attributes_Tag_olen = 0;
void *attributes_Tag_tmp;
ret = 0;
((data)->attributes)->len = 0;
((data)->attributes)->val = NULL;
while(ret < attributes_Tag_origlen) {
size_t attributes_Tag_nlen = attributes_Tag_olen + sizeof(*(((data)->attributes)->val));
if (attributes_Tag_olen > attributes_Tag_nlen) { e = ASN1_OVERFLOW; goto fail; }
attributes_Tag_olen = attributes_Tag_nlen;
attributes_Tag_tmp = realloc(((data)->attributes)->val, attributes_Tag_olen);
if (attributes_Tag_tmp == NULL) { e = ENOMEM; goto fail; }
((data)->attributes)->val = attributes_Tag_tmp;
e = decode_Attribute(p, len, &((data)->attributes)->val[((data)->attributes)->len], &l);
if(e) goto fail;
p += l; len -= l; ret += l;
((data)->attributes)->len++;
len = attributes_Tag_origlen - ret;
}
ret += attributes_Tag_oldret;
}
len = attributes_oldlen - attributes_datalen;
}
}
len = Top_oldlen - Top_datalen;
}
data->_save.data = calloc(1, ret);
if (data->_save.data == NULL) { 
e = ENOMEM; goto fail; 
}
data->_save.length = ret;
memcpy(data->_save.data, begin, ret);
if(size) *size = ret;
return 0;
fail:
free_CertificationRequestInfo(data);
return e;
}

void ASN1CALL
free_CertificationRequestInfo(CertificationRequestInfo *data)
{
der_free_octet_string(&data->_save);
free_Name(&(data)->subject);
free_SubjectPublicKeyInfo(&(data)->subjectPKInfo);
if((data)->attributes) {
while(((data)->attributes)->len){
free_Attribute(&((data)->attributes)->val[((data)->attributes)->len-1]);
((data)->attributes)->len--;
}
free(((data)->attributes)->val);
((data)->attributes)->val = NULL;
free((data)->attributes);
(data)->attributes = NULL;
}
}

size_t ASN1CALL
length_CertificationRequestInfo(const CertificationRequestInfo *data)
{
size_t ret = 0;
{
size_t Top_tag_oldret = ret;
ret = 0;
{
int enumint = *&(data)->version;
ret += der_length_integer(&enumint);
}
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
{
size_t Top_tag_oldret = ret;
ret = 0;
ret += length_Name(&(data)->subject);
ret += Top_tag_oldret;
}
{
size_t Top_tag_oldret = ret;
ret = 0;
ret += length_SubjectPublicKeyInfo(&(data)->subjectPKInfo);
ret += Top_tag_oldret;
}
if((data)->attributes){
size_t Top_tag_oldret = ret;
ret = 0;
{
size_t attributes_tag_oldret = ret;
int i;
ret = 0;
for(i = ((data)->attributes)->len - 1; i >= 0; --i){
size_t attributes_tag_for_oldret = ret;
ret = 0;
ret += length_Attribute(&((data)->attributes)->val[i]);
ret += attributes_tag_for_oldret;
}
ret += attributes_tag_oldret;
}
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
ret += 1 + der_length_len (ret);
return ret;
}

int ASN1CALL
copy_CertificationRequestInfo(const CertificationRequestInfo *from, CertificationRequestInfo *to)
{
memset(to, 0, sizeof(*to));
{ int ret;
ret = der_copy_octet_string(&(from)->_save, &(to)->_save);
if (ret) goto fail;
}
*(&(to)->version) = *(&(from)->version);
if(copy_Name(&(from)->subject, &(to)->subject)) goto fail;
if(copy_SubjectPublicKeyInfo(&(from)->subjectPKInfo, &(to)->subjectPKInfo)) goto fail;
if((from)->attributes) {
(to)->attributes = malloc(sizeof(*(to)->attributes));
if((to)->attributes == NULL) goto fail;
if((((to)->attributes)->val = malloc(((from)->attributes)->len * sizeof(*((to)->attributes)->val))) == NULL && ((from)->attributes)->len != 0)
goto fail;
for(((to)->attributes)->len = 0; ((to)->attributes)->len < ((from)->attributes)->len; ((to)->attributes)->len++){
if(copy_Attribute(&((from)->attributes)->val[((to)->attributes)->len], &((to)->attributes)->val[((to)->attributes)->len])) goto fail;
}
}else
(to)->attributes = NULL;
return 0;
fail:
free_CertificationRequestInfo(to);
return ENOMEM;
}



