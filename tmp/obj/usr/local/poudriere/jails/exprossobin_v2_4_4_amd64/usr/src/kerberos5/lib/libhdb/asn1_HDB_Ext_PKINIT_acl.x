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
encode_HDB_Ext_PKINIT_acl(unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, const HDB_Ext_PKINIT_acl *data, size_t *size)
{
size_t ret HEIMDAL_UNUSED_ATTRIBUTE = 0;
size_t l HEIMDAL_UNUSED_ATTRIBUTE;
int i HEIMDAL_UNUSED_ATTRIBUTE, e HEIMDAL_UNUSED_ATTRIBUTE;

for(i = (int)(data)->len - 1; i >= 0; --i) {
size_t Top_tag_for_oldret = ret;
ret = 0;
/* anchor */
if((&(data)->val[i])->anchor) {
size_t Top_tag_S_Of_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = der_put_utf8string(p, len, (&(data)->val[i])->anchor, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, PRIM, UT_UTF8String, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, CONS, 2, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_S_Of_tag_oldret;
}
/* issuer */
if((&(data)->val[i])->issuer) {
size_t Top_tag_S_Of_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = der_put_utf8string(p, len, (&(data)->val[i])->issuer, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, PRIM, UT_UTF8String, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, CONS, 1, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_S_Of_tag_oldret;
}
/* subject */
{
size_t Top_tag_S_Of_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = der_put_utf8string(p, len, &(&(data)->val[i])->subject, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, PRIM, UT_UTF8String, &l);
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
decode_HDB_Ext_PKINIT_acl(const unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, HDB_Ext_PKINIT_acl *data, size_t *size)
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
size_t subject_datalen, subject_oldlen;
Der_type subject_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &subject_type, 0, &subject_datalen, &l);
if (e == 0 && subject_type != CONS) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
subject_oldlen = len;
if (subject_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = subject_datalen;
{
size_t subject_Tag_datalen, subject_Tag_oldlen;
Der_type subject_Tag_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &subject_Tag_type, UT_UTF8String, &subject_Tag_datalen, &l);
if (e == 0 && subject_Tag_type != PRIM) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
subject_Tag_oldlen = len;
if (subject_Tag_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = subject_Tag_datalen;
e = der_get_utf8string(p, len, &(&(data)->val[(data)->len])->subject, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = subject_Tag_oldlen - subject_Tag_datalen;
}
len = subject_oldlen - subject_datalen;
}
{
size_t issuer_datalen, issuer_oldlen;
Der_type issuer_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &issuer_type, 1, &issuer_datalen, &l);
if (e == 0 && issuer_type != CONS) { e = ASN1_BAD_ID; }
if(e) {
(&(data)->val[(data)->len])->issuer = NULL;
} else {
(&(data)->val[(data)->len])->issuer = calloc(1, sizeof(*(&(data)->val[(data)->len])->issuer));
if ((&(data)->val[(data)->len])->issuer == NULL) { e = ENOMEM; goto fail; }
p += l; len -= l; ret += l;
issuer_oldlen = len;
if (issuer_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = issuer_datalen;
{
size_t issuer_Tag_datalen, issuer_Tag_oldlen;
Der_type issuer_Tag_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &issuer_Tag_type, UT_UTF8String, &issuer_Tag_datalen, &l);
if (e == 0 && issuer_Tag_type != PRIM) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
issuer_Tag_oldlen = len;
if (issuer_Tag_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = issuer_Tag_datalen;
e = der_get_utf8string(p, len, (&(data)->val[(data)->len])->issuer, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = issuer_Tag_oldlen - issuer_Tag_datalen;
}
len = issuer_oldlen - issuer_datalen;
}
}
{
size_t anchor_datalen, anchor_oldlen;
Der_type anchor_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &anchor_type, 2, &anchor_datalen, &l);
if (e == 0 && anchor_type != CONS) { e = ASN1_BAD_ID; }
if(e) {
(&(data)->val[(data)->len])->anchor = NULL;
} else {
(&(data)->val[(data)->len])->anchor = calloc(1, sizeof(*(&(data)->val[(data)->len])->anchor));
if ((&(data)->val[(data)->len])->anchor == NULL) { e = ENOMEM; goto fail; }
p += l; len -= l; ret += l;
anchor_oldlen = len;
if (anchor_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = anchor_datalen;
{
size_t anchor_Tag_datalen, anchor_Tag_oldlen;
Der_type anchor_Tag_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &anchor_Tag_type, UT_UTF8String, &anchor_Tag_datalen, &l);
if (e == 0 && anchor_Tag_type != PRIM) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
anchor_Tag_oldlen = len;
if (anchor_Tag_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = anchor_Tag_datalen;
e = der_get_utf8string(p, len, (&(data)->val[(data)->len])->anchor, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = anchor_Tag_oldlen - anchor_Tag_datalen;
}
len = anchor_oldlen - anchor_datalen;
}
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
free_HDB_Ext_PKINIT_acl(data);
return e;
}

void ASN1CALL
free_HDB_Ext_PKINIT_acl(HDB_Ext_PKINIT_acl *data)
{
while((data)->len){
der_free_utf8string(&(&(data)->val[(data)->len-1])->subject);
if((&(data)->val[(data)->len-1])->issuer) {
der_free_utf8string((&(data)->val[(data)->len-1])->issuer);
free((&(data)->val[(data)->len-1])->issuer);
(&(data)->val[(data)->len-1])->issuer = NULL;
}
if((&(data)->val[(data)->len-1])->anchor) {
der_free_utf8string((&(data)->val[(data)->len-1])->anchor);
free((&(data)->val[(data)->len-1])->anchor);
(&(data)->val[(data)->len-1])->anchor = NULL;
}
(data)->len--;
}
free((data)->val);
(data)->val = NULL;
}

size_t ASN1CALL
length_HDB_Ext_PKINIT_acl(const HDB_Ext_PKINIT_acl *data)
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
ret += der_length_utf8string(&(&(data)->val[i])->subject);
ret += 1 + der_length_len (ret);
ret += 1 + der_length_len (ret);
ret += Top_tag_S_Of_tag_oldret;
}
if((&(data)->val[i])->issuer){
size_t Top_tag_S_Of_tag_oldret = ret;
ret = 0;
ret += der_length_utf8string((&(data)->val[i])->issuer);
ret += 1 + der_length_len (ret);
ret += 1 + der_length_len (ret);
ret += Top_tag_S_Of_tag_oldret;
}
if((&(data)->val[i])->anchor){
size_t Top_tag_S_Of_tag_oldret = ret;
ret = 0;
ret += der_length_utf8string((&(data)->val[i])->anchor);
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
copy_HDB_Ext_PKINIT_acl(const HDB_Ext_PKINIT_acl *from, HDB_Ext_PKINIT_acl *to)
{
memset(to, 0, sizeof(*to));
if(((to)->val = malloc((from)->len * sizeof(*(to)->val))) == NULL && (from)->len != 0)
goto fail;
for((to)->len = 0; (to)->len < (from)->len; (to)->len++){
if(der_copy_utf8string(&(&(from)->val[(to)->len])->subject, &(&(to)->val[(to)->len])->subject)) goto fail;
if((&(from)->val[(to)->len])->issuer) {
(&(to)->val[(to)->len])->issuer = malloc(sizeof(*(&(to)->val[(to)->len])->issuer));
if((&(to)->val[(to)->len])->issuer == NULL) goto fail;
if(der_copy_utf8string((&(from)->val[(to)->len])->issuer, (&(to)->val[(to)->len])->issuer)) goto fail;
}else
(&(to)->val[(to)->len])->issuer = NULL;
if((&(from)->val[(to)->len])->anchor) {
(&(to)->val[(to)->len])->anchor = malloc(sizeof(*(&(to)->val[(to)->len])->anchor));
if((&(to)->val[(to)->len])->anchor == NULL) goto fail;
if(der_copy_utf8string((&(from)->val[(to)->len])->anchor, (&(to)->val[(to)->len])->anchor)) goto fail;
}else
(&(to)->val[(to)->len])->anchor = NULL;
}
return 0;
fail:
free_HDB_Ext_PKINIT_acl(to);
return ENOMEM;
}



