/*-
 *
 *  This file is part of Oracle NoSQL Database
 *  Copyright (C) 2011, 2014 Oracle and/or its affiliates.  All rights reserved.
 *
 * If you have received this file as part of Oracle NoSQL Database the
 * following applies to the work as a whole:
 *
 *   Oracle NoSQL Database server software is free software: you can
 *   redistribute it and/or modify it under the terms of the GNU Affero
 *   General Public License as published by the Free Software Foundation,
 *   version 3.
 *
 *   Oracle NoSQL Database is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *   Affero General Public License for more details.
 *
 * If you have received this file as part of Oracle NoSQL Database Client or
 * distributed separately the following applies:
 *
 *   Oracle NoSQL Database client software is free software: you can
 *   redistribute it and/or modify it under the terms of the Apache License
 *   as published by the Apache Software Foundation, version 2.0.
 *
 * You should have received a copy of the GNU Affero General Public License
 * and/or the Apache License in the LICENSE file along with Oracle NoSQL
 * Database client or server distribution.  If not, see
 * <http://www.gnu.org/licenses/>
 * or
 * <http://www.apache.org/licenses/LICENSE-2.0>.
 *
 * An active Oracle commercial licensing agreement for this product supersedes
 * these licenses and in such case the license notices, but not the copyright
 * notice, may be removed by you in connection with your distribution that is
 * in accordance with the commercial licensing terms.
 *
 * For more information please contact:
 *
 * berkeleydb-info_us@oracle.com
 *
 */

#ifndef __R_KVSTORE_H__
#define __R_KVSTORE_H__

#include <Rinternals.h>

/* KVstore open, close. */
SEXP rkv_open_store(SEXP kvhome, SEXP host, SEXP port, SEXP kvname);
SEXP rkv_close_store(SEXP store);

/* Key/Value: create, release */
SEXP rkv_create_key(SEXP store, SEXP major, SEXP minor);
SEXP rkv_create_key_from_uri(SEXP store, SEXP uri);
SEXP rkv_get_key_uri(SEXP key);
/*SEXP rkv_get_key_major(SEXP key);
SEXP rkv_get_key_minor(SEXP key);*/
SEXP rkv_release_key(SEXP key);
SEXP rkv_create_value(SEXP store, SEXP data);
SEXP rkv_get_value(SEXP value);
SEXP rkv_get_avro_value(SEXP value);
SEXP rkv_release_value(SEXP value);

/* put, get, delete */
SEXP rkv_put(SEXP store, SEXP key, SEXP value);
SEXP rkv_get(SEXP store, SEXP key);
SEXP rkv_delete(SEXP store, SEXP key);
SEXP rkv_multi_delete(SEXP store, SEXP key, SEXP start, SEXP end);

/* Itearator related APIs */
SEXP rkv_multiget_iterator(SEXP store, SEXP key, SEXP start,
                           SEXP end, SEXP keyonly);
SEXP rkv_store_iterator(SEXP store, SEXP key, SEXP start,
                        SEXP end, SEXP keyonly);
SEXP rkv_iterator_size(SEXP iterator);
SEXP rkv_iterator_next(SEXP iterator);
SEXP rkv_iterator_get_key(SEXP iterator);
SEXP rkv_iterator_get_value(SEXP iterator);
SEXP rkv_release_iterator(SEXP iterator);
SEXP rkv_multiget_values(SEXP store, SEXP key, SEXP schema,
                         SEXP start, SEXP end);

/* Avro value related APIs */
SEXP rkv_create_avro_value(SEXP store, SEXP schema);
SEXP rkv_avro_value_set_int(SEXP avroValue, SEXP name, SEXP value);
SEXP rkv_avro_value_get_int(SEXP avroValue, SEXP name);
SEXP rkv_avro_value_set_long(SEXP avroValue, SEXP name, SEXP value);
SEXP rkv_avro_value_get_long(SEXP avroValue, SEXP name);
SEXP rkv_avro_value_set_string(SEXP avroValue, SEXP name, SEXP value);
SEXP rkv_avro_value_get_string(SEXP avroValue, SEXP name);
SEXP rkv_avro_value_set_double(SEXP avroValue, SEXP name, SEXP value);
SEXP rkv_avro_value_get_double(SEXP avroValue, SEXP name);
SEXP rkv_avro_value_set_boolean(SEXP avroValue, SEXP name, SEXP value);
SEXP rkv_avro_value_get_boolean(SEXP avroValue, SEXP name);
/*SEXP rkv_avro_value_set_bytes(SEXP avroValue, SEXP name, SEXP value);
SEXP rkv_avro_value_set_null(SEXP avroValue, SEXP name); */
SEXP rkv_release_avro_value(SEXP avroValue);
SEXP rkv_avro_value_print(SEXP avroValue);

#endif
