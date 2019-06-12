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
encode_HDB_Ext_Password(unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, const HDB_Ext_Password *data, size_t *size)
{
size_t ret HEIMDAL_UNUSED_ATTRIBUTE = 0;
size_t l HEIMDAL_UNUSED_ATTRIBUTE;
int i HEIMDAL_UNUSED_ATTRIBUTE, e HEIMDAL_UNUSED_ATTRIBUTE;

/* password */
{
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = der_put_octet_string(p, len, &(data)->password, &l);
if (e) return e;
p -= l; len -= l; ret += l;

e = der_put_length_and_tag (p, len, ret, ASN1_C_UNIV, PRIM, UT_OctetString, &l);
if (e) return e;
p -= l; len -= l; ret += l;

ret += Top_tag_oldret;
}
/* mkvno */
if((data)->mkvno) {
size_t Top_tag_oldret HEIMDAL_UNUSED_ATTRIBUTE = ret;
ret = 0;
e = der_put_unsigned(p, len, (data)->mkvno, &l);
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
decode_HDB_Ext_Password(const unsigned char *p HEIMDAL_UNUSED_ATTRIBUTE, size_t len HEIMDAL_UNUSED_ATTRIBUTE, HDB_Ext_Password *data, size_t *size)
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
size_t mkvno_datalen, mkvno_oldlen;
Der_type mkvno_type;
e = der_match_tag_and_length(p, len, ASN1_C_CONTEXT, &mkvno_type, 0, &mkvno_datalen, &l);
if (e == 0 && mkvno_type != CONS) { e = ASN1_BAD_ID; }
if(e) {
(data)->mkvno = NULL;
} else {
(data)->mkvno = calloc(1, sizeof(*(data)->mkvno));
if ((data)->mkvno == NULL) { e = ENOMEM; goto fail; }
p += l; len -= l; ret += l;
mkvno_oldlen = len;
if (mkvno_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = mkvno_datalen;
{
size_t mkvno_Tag_datalen, mkvno_Tag_oldlen;
Der_type mkvno_Tag_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &mkvno_Tag_type, UT_Integer, &mkvno_Tag_datalen, &l);
if (e == 0 && mkvno_Tag_type != PRIM) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
mkvno_Tag_oldlen = len;
if (mkvno_Tag_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = mkvno_Tag_datalen;
e = der_get_unsigned(p, len, (data)->mkvno, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = mkvno_Tag_oldlen - mkvno_Tag_datalen;
}
len = mkvno_oldlen - mkvno_datalen;
}
}
{
size_t password_datalen, password_oldlen;
Der_type password_type;
e = der_match_tag_and_length(p, len, ASN1_C_UNIV, &password_type, UT_OctetString, &password_datalen, &l);
if (e == 0 && password_type != PRIM) { e = ASN1_BAD_ID; }
if(e) goto fail;
p += l; len -= l; ret += l;
password_oldlen = len;
if (password_datalen > len) { e = ASN1_OVERRUN; goto fail; }
len = password_datalen;
e = der_get_octet_string(p, len, &(data)->password, &l);
if(e) goto fail;
p += l; len -= l; ret += l;
len = password_oldlen - password_datalen;
}
len = Top_oldlen - Top_datalen;
}
if(size) *size = ret;
return 0;
fail:
free_HDB_Ext_Password(data);
return e;
}

void ASN1CALL
free_HDB_Ext_Password(HDB_Ext_Password *data)
{
if((data)->mkvno) {
free((data)->mkvno);
(data)->mkvno = NULL;
}
der_free_octet_string(&(data)->password);
}

size_t ASN1CALL
length_HDB_Ext_Password(const HDB_Ext_Password *data)
{
size_t ret = 0;
if((data)->mkvno){
size_t Top_tag_oldret = ret;
ret = 0;
ret += der_length_unsigned((data)->mkvno);
ret += 1 + der_length_len (ret);
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
{
size_t Top_tag_oldret = ret;
ret = 0;
ret += der_length_octet_string(&(data)->password);
ret += 1 + der_length_len (ret);
ret += Top_tag_oldret;
}
ret += 1 + der_length_len (ret);
return ret;
}

int ASN1CALL
copy_HDB_Ext_Password(const HDB_Ext_Password *from, HDB_Ext_Password *to)
{
memset(to, 0, sizeof(*to));
if((from)->mkvno) {
(to)->mkvno = malloc(sizeof(*(to)->mkvno));
if((to)->mkvno == NULL) goto fail;
*((to)->mkvno) = *((from)->mkvno);
}else
(to)->mkvno = NULL;
if(der_copy_octet_string(&(from)->password, &(to)->password)) goto fail;
return 0;
fail:
free_HDB_Ext_Password(to);
return ENOMEM;
}



