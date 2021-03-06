// THIS IS AN AUTOMATICALLY GENERATED FILE.  DO NOT MODIFY
// BY HAND!!
//
// Generated by lcm-gen

#include <string.h>
#include "mylcm_myBroadcast.h"

static int __mylcm_myBroadcast_hash_computed;
static uint64_t __mylcm_myBroadcast_hash;

uint64_t __mylcm_myBroadcast_hash_recursive(const __lcm_hash_ptr *p)
{
    const __lcm_hash_ptr *fp;
    for (fp = p; fp != NULL; fp = fp->parent)
        if (fp->v == __mylcm_myBroadcast_get_hash)
            return 0;

    __lcm_hash_ptr cp;
    cp.parent =  p;
    cp.v = (void*)__mylcm_myBroadcast_get_hash;
    (void) cp;

    uint64_t hash = (uint64_t)0xfef3c1bf01cf4f06LL
         + __int64_t_hash_recursive(&cp)
         + __int32_t_hash_recursive(&cp)
         + __mylcm_lidarObjInfor_hash_recursive(&cp)
        ;

    return (hash<<1) + ((hash>>63)&1);
}

int64_t __mylcm_myBroadcast_get_hash(void)
{
    if (!__mylcm_myBroadcast_hash_computed) {
        __mylcm_myBroadcast_hash = (int64_t)__mylcm_myBroadcast_hash_recursive(NULL);
        __mylcm_myBroadcast_hash_computed = 1;
    }

    return __mylcm_myBroadcast_hash;
}

int __mylcm_myBroadcast_encode_array(void *buf, int offset, int maxlen, const mylcm_myBroadcast *p, int elements)
{
    int pos = 0, element;
    int thislen;

    for (element = 0; element < elements; element++) {

        thislen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &(p[element].timestamp0), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int32_t_encode_array(buf, offset + pos, maxlen - pos, &(p[element].objNum), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __mylcm_lidarObjInfor_encode_array(buf, offset + pos, maxlen - pos, p[element].objs, p[element].objNum);
        if (thislen < 0) return thislen; else pos += thislen;

    }
    return pos;
}

int mylcm_myBroadcast_encode(void *buf, int offset, int maxlen, const mylcm_myBroadcast *p)
{
    int pos = 0, thislen;
    int64_t hash = __mylcm_myBroadcast_get_hash();

    thislen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &hash, 1);
    if (thislen < 0) return thislen; else pos += thislen;

    thislen = __mylcm_myBroadcast_encode_array(buf, offset + pos, maxlen - pos, p, 1);
    if (thislen < 0) return thislen; else pos += thislen;

    return pos;
}

int __mylcm_myBroadcast_encoded_array_size(const mylcm_myBroadcast *p, int elements)
{
    int size = 0, element;
    for (element = 0; element < elements; element++) {

        size += __int64_t_encoded_array_size(&(p[element].timestamp0), 1);

        size += __int32_t_encoded_array_size(&(p[element].objNum), 1);

        size += __mylcm_lidarObjInfor_encoded_array_size(p[element].objs, p[element].objNum);

    }
    return size;
}

int mylcm_myBroadcast_encoded_size(const mylcm_myBroadcast *p)
{
    return 8 + __mylcm_myBroadcast_encoded_array_size(p, 1);
}

int __mylcm_myBroadcast_decode_array(const void *buf, int offset, int maxlen, mylcm_myBroadcast *p, int elements)
{
    int pos = 0, thislen, element;

    for (element = 0; element < elements; element++) {

        thislen = __int64_t_decode_array(buf, offset + pos, maxlen - pos, &(p[element].timestamp0), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        thislen = __int32_t_decode_array(buf, offset + pos, maxlen - pos, &(p[element].objNum), 1);
        if (thislen < 0) return thislen; else pos += thislen;

        p[element].objs = (mylcm_lidarObjInfor*) lcm_malloc(sizeof(mylcm_lidarObjInfor) * p[element].objNum);
        thislen = __mylcm_lidarObjInfor_decode_array(buf, offset + pos, maxlen - pos, p[element].objs, p[element].objNum);
        if (thislen < 0) return thislen; else pos += thislen;

    }
    return pos;
}

int __mylcm_myBroadcast_decode_array_cleanup(mylcm_myBroadcast *p, int elements)
{
    int element;
    for (element = 0; element < elements; element++) {

        __int64_t_decode_array_cleanup(&(p[element].timestamp0), 1);

        __int32_t_decode_array_cleanup(&(p[element].objNum), 1);

        __mylcm_lidarObjInfor_decode_array_cleanup(p[element].objs, p[element].objNum);
        if (p[element].objs) free(p[element].objs);

    }
    return 0;
}

int mylcm_myBroadcast_decode(const void *buf, int offset, int maxlen, mylcm_myBroadcast *p)
{
    int pos = 0, thislen;
    int64_t hash = __mylcm_myBroadcast_get_hash();

    int64_t this_hash;
    thislen = __int64_t_decode_array(buf, offset + pos, maxlen - pos, &this_hash, 1);
    if (thislen < 0) return thislen; else pos += thislen;
    if (this_hash != hash) return -1;

    thislen = __mylcm_myBroadcast_decode_array(buf, offset + pos, maxlen - pos, p, 1);
    if (thislen < 0) return thislen; else pos += thislen;

    return pos;
}

int mylcm_myBroadcast_decode_cleanup(mylcm_myBroadcast *p)
{
    return __mylcm_myBroadcast_decode_array_cleanup(p, 1);
}

int __mylcm_myBroadcast_clone_array(const mylcm_myBroadcast *p, mylcm_myBroadcast *q, int elements)
{
    int element;
    for (element = 0; element < elements; element++) {

        __int64_t_clone_array(&(p[element].timestamp0), &(q[element].timestamp0), 1);

        __int32_t_clone_array(&(p[element].objNum), &(q[element].objNum), 1);

        q[element].objs = (mylcm_lidarObjInfor*) lcm_malloc(sizeof(mylcm_lidarObjInfor) * q[element].objNum);
        __mylcm_lidarObjInfor_clone_array(p[element].objs, q[element].objs, p[element].objNum);

    }
    return 0;
}

mylcm_myBroadcast *mylcm_myBroadcast_copy(const mylcm_myBroadcast *p)
{
    mylcm_myBroadcast *q = (mylcm_myBroadcast*) malloc(sizeof(mylcm_myBroadcast));
    __mylcm_myBroadcast_clone_array(p, q, 1);
    return q;
}

void mylcm_myBroadcast_destroy(mylcm_myBroadcast *p)
{
    __mylcm_myBroadcast_decode_array_cleanup(p, 1);
    free(p);
}

int mylcm_myBroadcast_publish(lcm_t *lc, const char *channel, const mylcm_myBroadcast *p)
{
      int max_data_size = mylcm_myBroadcast_encoded_size (p);
      uint8_t *buf = (uint8_t*) malloc (max_data_size);
      if (!buf) return -1;
      int data_size = mylcm_myBroadcast_encode (buf, 0, max_data_size, p);
      if (data_size < 0) {
          free (buf);
          return data_size;
      }
      int status = lcm_publish (lc, channel, buf, data_size);
      free (buf);
      return status;
}

struct _mylcm_myBroadcast_subscription_t {
    mylcm_myBroadcast_handler_t user_handler;
    void *userdata;
    lcm_subscription_t *lc_h;
};
static
void mylcm_myBroadcast_handler_stub (const lcm_recv_buf_t *rbuf,
                            const char *channel, void *userdata)
{
    int status;
    mylcm_myBroadcast p;
    memset(&p, 0, sizeof(mylcm_myBroadcast));
    status = mylcm_myBroadcast_decode (rbuf->data, 0, rbuf->data_size, &p);
    if (status < 0) {
        fprintf (stderr, "error %d decoding mylcm_myBroadcast!!!\n", status);
        return;
    }

    mylcm_myBroadcast_subscription_t *h = (mylcm_myBroadcast_subscription_t*) userdata;
    h->user_handler (rbuf, channel, &p, h->userdata);

    mylcm_myBroadcast_decode_cleanup (&p);
}

mylcm_myBroadcast_subscription_t* mylcm_myBroadcast_subscribe (lcm_t *lcm,
                    const char *channel,
                    mylcm_myBroadcast_handler_t f, void *userdata)
{
    mylcm_myBroadcast_subscription_t *n = (mylcm_myBroadcast_subscription_t*)
                       malloc(sizeof(mylcm_myBroadcast_subscription_t));
    n->user_handler = f;
    n->userdata = userdata;
    n->lc_h = lcm_subscribe (lcm, channel,
                                 mylcm_myBroadcast_handler_stub, n);
    if (n->lc_h == NULL) {
        fprintf (stderr,"couldn't reg mylcm_myBroadcast LCM handler!\n");
        free (n);
        return NULL;
    }
    return n;
}

int mylcm_myBroadcast_subscription_set_queue_capacity (mylcm_myBroadcast_subscription_t* subs,
                              int num_messages)
{
    return lcm_subscription_set_queue_capacity (subs->lc_h, num_messages);
}

int mylcm_myBroadcast_unsubscribe(lcm_t *lcm, mylcm_myBroadcast_subscription_t* hid)
{
    int status = lcm_unsubscribe (lcm, hid->lc_h);
    if (0 != status) {
        fprintf(stderr,
           "couldn't unsubscribe mylcm_myBroadcast_handler %p!\n", hid);
        return -1;
    }
    free (hid);
    return 0;
}

