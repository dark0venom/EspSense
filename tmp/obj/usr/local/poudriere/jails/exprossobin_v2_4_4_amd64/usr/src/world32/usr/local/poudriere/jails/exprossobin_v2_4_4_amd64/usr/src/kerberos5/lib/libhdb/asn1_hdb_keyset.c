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
encode_hdb_keyset(unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, const hdb_keyset *data, size_t *size)
{
size_t ret HEIMDAL_UNUSED_ATTRIBUTE = 0;
size_t l HEIMDAL_UNUSED_ATTRIBUTE;
int i HEIMDAL_UNUSED_ATTRIBUTE, e HEIMDAL_UNUSED_ATTRIBUTE;

/* keys */
{
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
for(i = (int)(&(data)->keys)->len - 1; i >= 0; --i) {
size_t keys_tag_tag_for_oldret = ret;
ret = 0;
e = encode_Key(p, len, &(&(data)->keys)->val[i], &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += keys_tag_tag_for_oldret;
}
e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, CONS, UT_Sequence, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, CONS, 0, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
/* kvno */
{
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = der_put_unsigned(p, len, &(data)->kvno, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, PRIM, UT_Integer, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_CONTEXT, CONS, 1, &l);
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
decode_hdb_keyset(const unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, hdb_keyset *data, size_t *size)
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
size_t kvno_datalen, kvno_oldlen;
Der_type kvno_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &kvno_type, 1, &kvno_datalen, &l);
if (e == 0 && kvno_type != CONS) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
kvno_oldlen = len;
if (kvno_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = kvno_datalen;
{
size_t kvno_Tag_datalen, kvno_Tag_oldlen;
Der_type kvno_Tag_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &kvno_Tag_type, UT_Integer, &kvno_Tag_datalen, &l);
if (e == 0 && kvno_Tag_type != PRIM) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
kvno_Tag_oldlen = len;
if (kvno_Tag_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = kvno_Tag_datalen;
e = der_get_unsigned(p, len, &(data)->kvno, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = kvno_Tag_oldlen - kvno_Tag_datalen;
}
len = kvno_oldlen - kvno_datalen;
}
{
size_t keys_datalen, keys_oldlen;
Der_type keys_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &keys_type, 0, &keys_datalen, &l);
if (e == 0 && keys_type != CONS) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
keys_oldlen = len;
if (keys_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = keys_datalen;
{
size_t keys_Tag_datalen, keys_Tag_oldlen;
Der_type keys_Tag_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &keys_Tag_type, UT_Sequence, &keys_Tag_datalen, &l);
if (e == 0 && keys_Tag_type != CONS) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
keys_Tag_oldlen = len;
if (keys_Tag_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = keys_Tag_datalen;
{
size_t keys_Tag_Tag_origlen = len;
size_t keys_Tag_Tag_oldret = ret;
size_t keys_Tag_Tag_olen = 0;
void *keys_Tag_Tag_tmp;
ret = 0;
(&(data)->keys)->len = 0;
(&(data)->keys)->val = NULL;
while(ret < keys_Tag_Tag_origlen) {
size_t keys_Tag_Tag_nlen = keys_Tag_Tag_olen + sizeof(*((&(data)->keys)->val));
if (keys_Tag_Tag_olen > keys_Tag_Tag_nlen) { e = ASN1_OVERFLOW; goto fail; }
keys_Tag_Tag_olen = keys_Tag_Tag_nlen;
keys_Tag_Tag_tmp = realloc((&(data)->keys)->val, keys_Tag_Tag_olen);
if (keys_Tag_Tag_tmp == NULL) { e = ENOMEM; goto fail; }
(&(data)->keys)->val = keys_Tag_Tag_tmp;
e = decode_Key(p, len, &(&(data)->keys)->val[(&(data)->keys)->len], &l);
if(e) goto fail;
p += l; len -= l; ret += l;
(&(data)->keys)->len++;
len = keys_Tag_Tag_origlen - ret;
}
ret += keys_Tag_Tag_oldret;
}
len = keys_Tag_oldlen - keys_Tag_datalen;
}
len = keys_oldlen - keys_datalen;
}
len = Top_oldlen - Top_datalen;
}
if(size) *size = ret;
return 0;
fail:
free_hdb_keyset(data);
return e;
}

void ASN1CALL
free_hdb_keyset(hdb_keyset *data)
{
while((&(data)->keys)->len){
free_Key(&(&(data)->keys)->val[(&(data)->keys)->len-1]);
(&(data)->keys)->len--;
}
free((&(data)->keys)->val);
(&(data)->keys)->val = NULL;
}

size_t ASN1CALL
length_hdb_keyset(const hdb_keyset *data)
{
size_t ret = 0;
{
size_t Top_tag_oldret = ret;
ret = 0;
ret += der_length_unsigned(&(data)->kvno);
ret += 1 + der_length_len (ret);
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
{
size_t Top_tag_oldret = ret;
ret = 0;
{
size_t keys_tag_tag_oldret = ret;
int i;
ret = 0;
for(i = (&(data)->keys)->len - 1; i >= 0; --i){
size_t keys_tag_tag_for_oldret = ret;
ret = 0;
ret += length_Key(&(&(data)->keys)->val[i]);
ret += keys_tag_tag_for_oldret;
}
ret += keys_tag_tag_oldret;
}
ret += 1 + der_length_len (ret);
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
ret += 1 + der_length_len (ret);
return ret;
}

int ASN1CALL
copy_hdb_keyset(const hdb_keyset *from, hdb_keyset *to)
{
memset(to, 0, sizeof(*to));
*(&(to)->kvno) = *(&(from)->kvno);
if(((&(to)->keys)->val = malloc((&(from)->keys)->len * sizeof(*(&(to)->keys)->val))) == NULL && (&(from)->keys)->len != 0)
goto fail;
for((&(to)->keys)->len = 0; (&(to)->keys)->len < (&(from)->keys)->len; (&(to)->keys)->len++){
if(copy_Key(&(&(from)->keys)->val[(&(to)->keys)->len], &(&(to)->keys)->val[(&(to)->keys)->len])) goto fail;
}
return 0;
fail:
free_hdb_keyset(to);
return ENOMEM;
}



