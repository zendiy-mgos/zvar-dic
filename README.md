# ZenVar Dictionary
## Overview
Mongoose OS library implementing dictionary data-type for variant variables (key/value pair dictionary).

```c
// Explicit dictionary creation 
mgos_zvar_t var = mgos_zvar_new_dic();

// Implicit dictionary creation 
mgos_zvar_t var = mgos_zvar_new();
mgos_zvar_add_key(var, "Name", mgos_zvar_new_str("Mark));
```
## C/C++ API Reference
### mgos_zvar_new_dic()
```c
mgos_zvar_t mgos_zvar_new_dic();
```
Creates an empty dictionary. Returns `NULL` in case of error. 
### mgos_zvar_is_dic()
```c
bool mgos_zvar_is_dic(mgos_zvarc_t var);
```
Returns `true` if the the variable is a dictionary, otherwise `false`.

|Parameter||
|--|--|
|var|Variant variable.|
### mgos_zvar_remove_keys()
```c
void mgos_zvar_remove_keys(mgos_zvar_t var);
```
Removes all keys from the dictionary. Removed keys are also deallocated.

|Parameter||
|--|--|
|var|Dictionary variable.|
### mgos_zvar_remove_key()
```c
void mgos_zvar_remove_key(mgos_zvar_t var, const char *key);
```
Removes the key from the dictionary. Removed key is also deallocated.

|Parameter||
|--|--|
|var|Dictionary variable.|
|key|The name of the key to be removed.|
### mgos_zvar_has_key()
```c
bool mgos_zvar_has_key(mgos_zvarc_t var, const char *key);
```
Returns `true` if the dictionary contains the key, otherwise `false`.

|Parameter||
|--|--|
|var|Dictionary variable.|
|key|Key name.|
### mgos_zvar_get_keys()
```c
mgos_zvar_enum_t mgos_zvar_get_keys(mgos_zvar_t var);
```
Returns the keys enumerator used by `mgos_zvar_get_next_key`. Returns `NULL` if error.

|Parameter||
|--|--|
|var|Dictionary variable.|
### mgos_zvar_get_next_key()
```c
bool mgos_zvar_get_next_key(mgos_zvar_enum_t *key_enum, mgos_zvar_t *out, const char **key_name);
```
Gets next key from the enumerator returned by `mgos_zvar_get_keys`. Returns `false` if the end of the enumerator is reached or if error, otherwise `true`.

|Parameter||
|--|--|
|key_enum|Reference to the keys enumerator.|
|out|Optional. Reference to the output key value. If `NULL` no key value is returned.|
|key_name|Optional. Reference to the output key name. If `NULL` no key name is returned.|
```c
// Enumerating dictionary keys
mgos_zvar_t key_val;
const char *key_name;
mgos_zvar_enum_t keys = mgos_zvar_get_keys(var);
while (mgos_zvar_get_next_key(&keys, &key_val, &key_name)) {
  // do something...
}
```
### mgos_zvarc_get_keys()
```c
mgos_zvarc_enum_t mgos_zvarc_get_keys(mgos_zvarc_t var);
```
Returns the keys enumerator used by `mgos_zvarc_get_next_key`. Returns `NULL` if error.

|Parameter||
|--|--|
|var|Dictionary variable.|
### mgos_zvarc_get_next_key()
```c
bool mgos_zvarc_get_next_key(mgos_zvarc_enum_t *key_enum, mgos_zvarc_t *out, const char **key_name);
```
Gets next constant key from the enumerator returned by `mgos_zvarc_get_keys`. Returns `false` if the end of the enumerator is reached or if error, otherwise `true`.

|Parameter||
|--|--|
|key_enum|Reference to the keys enumerator.|
|out|Optional. Reference to the output constant key value. If `NULL` no key value is returned.|
|key_name|Optional. Reference to the output key name. If `NULL` no key name is returned.|
```c
// Enumerating dictionary keys
mgos_zvarc_t key_val;
const char *key_name;
mgos_zvarc_enum_t keys = mgos_zvarc_get_keys(var);
while (mgos_zvarc_get_next_key(&keys, &key_val, &key_name)) {
  // do something...
}
```
### mgos_zvar_merge()
```c
bool mgos_zvar_merge(mgos_zvarc_t src_var, mgos_zvar_t dest_var);
```
Merges the source dictionary into the destination one. Returns `true` if merged successfully, otherwise `false`.

|Parameter||
|--|--|
|src_var|Source dictionary variable.|
|dest_var|Destination dictionary variable.|
### mgos_zvar_get_key()
```c
mgos_zvar_t mgos_zvar_get_key(mgos_zvar_t var, const char *key);;
```
Returns a key value.

|Parameter||
|--|--|
|var|Dictionary variable.|
|key|Name of the key to be returned.|
### mgos_zvar_get_ckey()
```c
mgos_zvarc_t mgos_zvar_get_ckey(mgos_zvarc_t var, const char *key);
```
Returns a key value.

|Parameter||
|--|--|
|var|Dictionary variable.|
|key|Name of the key to be returned.|
### mgos_zvar_try_get_key()
```c
bool mgos_zvar_try_get_key(mgos_zvar_t var, const char *key, mgos_zvar_t *out);
```
Try to get a key value. Returns `true` if the key exists, otherwise `false`.

|Parameter||
|--|--|
|var|Dictionary variable.|
|out|Optional. Reference to the output key value. If `NULL` no key value is returned.|
### mgos_zvar_try_get_ckey()
```c
bool mgos_zvar_try_get_ckey(mgos_zvarc_t var, const char *key, mgos_zvarc_t *out);
```
Try to get a key value. Returns `true` if the key exists, otherwise `false`.

|Parameter||
|--|--|
|var|Dictionary variable.|
|out|Optional. Reference to the output constant key value. If `NULL` no key value is returned.|
### mgos_zvar_add_key()
```c
bool mgos_zvar_add_key(mgos_zvar_t var, const char *key, mgos_zvar_t val);
```
Adds the key to the dictionary. Returns `true` if successfully added, otherwise `false`.

|Parameter||
|--|--|
|var|Dictionary variable.|
|key|Key name.|
|val|Key value.|