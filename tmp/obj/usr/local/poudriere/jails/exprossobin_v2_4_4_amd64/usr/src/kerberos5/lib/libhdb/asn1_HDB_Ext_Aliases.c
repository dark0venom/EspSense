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
encode_HDB_Ext_Aliases(unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, const HDB_Ext_Aliases *data, size_t *size)
{
size_t ret HEIMDAL_UNUSED_ATTRIBUTE = 0;
size_t l HEIMDAL_UNUSED_ATTRIBUTE;
int i HEIMDAL_UNUSED_ATTRIBUTE, e HEIMDAL_UNUSED_ATTRIBUTE;

/* aliases */
{
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
for(i = (int)(&(data)->aliases)->len - 1; i >= 0; --i) {
size_t aliases_tag_tag_for_oldret = ret;
ret = 0;
e = encode_Principal(p, len, &(&(data)->aliases)->val[i], &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += aliases_tag_tag_for_oldret;
}
e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, CONS, UT_Sequence, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, CONS, 1, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
/* case-insensitive */
{
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = der_put_boolean(p, len, &(data)->case_insensitive, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, PRIM, UT_Boolean, &l);
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
decode_HDB_Ext_Aliases(const unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, HDB_Ext_Aliases *data, size_t *size)
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
size_t case_insensitive_datalen, case_insensitive_oldlen;
Der_type case_insensitive_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &case_insensitive_type, 0, &case_insensitive_datalen, &l);
if (e == 0 && case_insensitive_type != CONS) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
case_insensitive_oldlen = len;
if (case_insensitive_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = case_insensitive_datalen;
{
size_t case_insensitive_Tag_datalen, case_insensitive_Tag_oldlen;
Der_type case_insensitive_Tag_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &case_insensitive_Tag_type, UT_Boolean, &case_insensitive_Tag_datalen, &l);
if (e == 0 && case_insensitive_Tag_type != PRIM) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
case_insensitive_Tag_oldlen = len;
if (case_insensitive_Tag_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = case_insensitive_Tag_datalen;
e = der_get_boolean(p, len, &(data)->case_insensitive, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = case_insensitive_Tag_oldlen - case_insensitive_Tag_datalen;
}
len = case_insensitive_oldlen - case_insensitive_datalen;
}
{
size_t aliases_datalen, aliases_oldlen;
Der_type aliases_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &aliases_type, 1, &aliases_datalen, &l);
if (e == 0 && aliases_type != CONS) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
aliases_oldlen = len;
if (aliases_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = aliases_datalen;
{
size_t aliases_Tag_datalen, aliases_Tag_oldlen;
Der_type aliases_Tag_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &aliases_Tag_type, UT_Sequence, &aliases_Tag_datalen, &l);
if (e == 0 && aliases_Tag_type != CONS) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
aliases_Tag_oldlen = len;
if (aliases_Tag_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = aliases_Tag_datalen;
{
size_t aliases_Tag_Tag_origlen = len;
size_t aliases_Tag_Tag_oldret = ret;
size_t aliases_Tag_Tag_olen = 0;
void *aliases_Tag_Tag_tmp;
ret = 0;
(&(data)->aliases)->len = 0;
(&(data)->aliases)->val = NULL;
while(ret < aliases_Tag_Tag_origlen) {
size_t aliases_Tag_Tag_nlen = aliases_Tag_Tag_olen + sizeof(*((&(data)->aliases)->val));
if (aliases_Tag_Tag_olen > aliases_Tag_Tag_nlen) { e = ASN1_OVERFLOW; goto fail; }
aliases_Tag_Tag_olen = aliases_Tag_Tag_nlen;
aliases_Tag_Tag_tmp = realloc((&(data)->aliases)->val, aliases_Tag_Tag_olen);
if (aliases_Tag_Tag_tmp == NULL) { e = ENOMEM; goto fail; }
(&(data)->aliases)->val = aliases_Tag_Tag_tmp;
e = decode_Principal(p, len, &(&(data)->aliases)->val[(&(data)->aliases)->len], &l);
if(e) goto fail;
p += l; len -= l; ret += l;
(&(data)->aliases)->len++;
len = aliases_Tag_Tag_origlen - ret;
}
ret += aliases_Tag_Tag_oldret;
}
len = aliases_Tag_oldlen - aliases_Tag_datalen;
}
len = aliases_oldlen - aliases_datalen;
}
len = Top_oldlen - Top_datalen;
}
if(size) *size = ret;
return 0;
fail:
free_HDB_Ext_Aliases(data);
return e;
}

void ASN1CALL
free_HDB_Ext_Aliases(HDB_Ext_Aliases *data)
{
while((&(data)->aliases)->len){
free_Principal(&(&(data)->aliases)->val[(&(data)->aliases)->len-1]);
(&(data)->aliases)->len--;
}
free((&(data)->aliases)->val);
(&(data)->aliases)->val = NULL;
}

size_t ASN1CALL
length_HDB_Ext_Aliases(const HDB_Ext_Aliases *data)
{
size_t ret = 0;
{
size_t Top_tag_oldret = ret;
ret = 0;
ret += 1;
ret += 1 + der_length_len (ret);
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
{
size_t Top_tag_oldret = ret;
ret = 0;
{
size_t aliases_tag_tag_oldret = ret;
int i;
ret = 0;
for(i = (&(data)->aliases)->len - 1; i >= 0; --i){
size_t aliases_tag_tag_for_oldret = ret;
ret = 0;
ret += length_Principal(&(&(data)->aliases)->val[i]);
ret += aliases_tag_tag_for_oldret;
}
ret += aliases_tag_tag_oldret;
}
ret += 1 + der_length_len (ret);
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
ret += 1 + der_length_len (ret);
return ret;
}

int ASN1CALL
copy_HDB_Ext_Aliases(const HDB_Ext_Aliases *from, HDB_Ext_Aliases *to)
{
memset(to, 0, sizeof(*to));
*(&(to)->case_insensitive) = *(&(from)->case_insensitive);
if(((&(to)->aliases)->val = malloc((&(from)->aliases)->len * sizeof(*(&(to)->aliases)->val))) == NULL && (&(from)->aliases)->len != 0)
goto fail;
for((&(to)->aliases)->len = 0; (&(to)->aliases)->len < (&(from)->aliases)->len; (&(to)->aliases)->len++){
if(copy_Principal(&(&(from)->aliases)->val[(&(to)->aliases)->len], &(&(to)->aliases)->val[(&(to)->aliases)->len])) goto fail;
}
return 0;
fail:
free_HDB_Ext_Aliases(to);
return ENOMEM;
}



