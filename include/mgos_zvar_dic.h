/*
 * Copyright (c) 2020 ZenDIY
 * All rights reserved
 *
 * Licensed under the Apache License, Version 2.0 (the ""License"");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an ""AS IS"" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef MGOS_ZVAR_DIC_H_
#define MGOS_ZVAR_DIC_H_

#include <stdlib.h>
#include <stdbool.h>
#include "mgos_zvar.h"

#ifdef MGOS_HAVE_MJS
#include "mjs.h"
#endif /* MGOS_HAVE_MJS */ 

#ifdef __cplusplus
extern "C" {
#endif

#define MGOS_ZVAR_TYPE_DIC 1

typedef struct mgos_zvariant *mgos_zvar_enum_t;

mgos_zvar_t mgos_zvar_new_dic();

bool mgos_zvar_is_dic(mgos_zvarc_t var);

void mgos_zvar_remove_keys(mgos_zvar_t var);
void mgos_zvar_remove_key(mgos_zvar_t var, const char *key);
bool mgos_zvar_has_key(mgos_zvarc_t var, const char *key);
mgos_zvar_enum_t mgos_zvar_get_keys(mgos_zvarc_t var);

bool mgos_zvar_merge(mgos_zvarc_t src_var, mgos_zvar_t dest_var);

mgos_zvarc_t mgos_zvar_get_ckey(mgos_zvarc_t var, const char *key);
bool mgos_zvar_try_get_ckey(mgos_zvarc_t var, const char *key, mgos_zvarc_t *out);
bool mgos_zvar_get_next_ckey(mgos_zvar_enum_t *key_enum, mgos_zvarc_t *out, const char **key_name);

mgos_zvar_t mgos_zvar_get_key(mgos_zvar_t var, const char *key);
bool mgos_zvar_try_get_key(mgos_zvar_t var, const char *key, mgos_zvar_t *out);
bool mgos_zvar_get_next_key(mgos_zvar_enum_t *key_enum, mgos_zvar_t *out, const char **key_name);

bool mgos_zvar_add_key(mgos_zvar_t var, const char *key, mgos_zvar_t val);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* MGOS_ZVAR_DIC_H_ */