# ZenVar Dictionary
## Overview
Mongoose OS library implementing dictionary data-type for variant variables (key/value pair dictionary).

```c
// Explicit dictionary creation 
mgos_zvar_t dic1 = mgos_zvar_new_dic();
mgos_zvar_add_key(dic1, "Name", mgos_zvar_new_str("Mark"));
mgos_zvar_add_key(dic1, "Gender", mgos_zvar_new_str("Male"));
mgos_zvar_add_key(dic1, "Age", mgos_zvar_new_integer(25));

// Implicit dictionary creation 
mgos_zvar_t dic2 = mgos_zvar_new();
mgos_zvar_add_key(dic2, "Name", mgos_zvar_new_str("Jenny"));
mgos_zvar_add_key(dic2, "Gender", mgos_zvar_new_str("Female"));
mgos_zvar_add_key(dic2, "Age", mgos_zvar_new_integer(22));
```
## C/C++ API Reference
### mgos_zvar_new_dic()
```c
mgos_zvar_t mgos_zvar_new_dic();
```
Creates an empty dictionary. Returns `NULL` if error. 
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
void mgos_zvar_remove_keys(mgos_zvar_t dic);
```
Removes all keys from the dictionary. Removed keys are also deallocated.

|Parameter||
|--|--|
|dic|Dictionary variable.|
### mgos_zvar_remove_key()
```c
void mgos_zvar_remove_key(mgos_zvar_t dic, const char *key_name);
```
Removes the key from the dictionary. Removed key is also deallocated.

|Parameter||
|--|--|
|dic|Dictionary variable.|
|key_name|The name of the key to be removed.|
### mgos_zvar_has_key()
```c
bool mgos_zvar_has_key(mgos_zvarc_t dic, const char *key_name);
```
Returns `true` if the dictionary contains the key, otherwise `false`.

|Parameter||
|--|--|
|dic|Dictionary variable.|
|key_name|Key name.|
### mgos_zvar_get_keys()
```c
mgos_zvar_enum_t mgos_zvar_get_keys(mgos_zvar_t dic);
```
Returns the keys enumerator used by `mgos_zvar_get_next_key`. Returns `NULL` if error.

|Parameter||
|--|--|
|dic|Dictionary variable.|
### mgos_zvar_get_next_key()
```c
bool mgos_zvar_get_next_key(mgos_zvar_enum_t *keys_enum, mgos_zvar_t *key_value, const char **key_name);
```
Gets next key from the enumerator returned by `mgos_zvar_get_keys`. Returns `false` if the end of the enumerator is reached or if error, otherwise `true`.

|Parameter||
|--|--|
|keys_enum|Reference to the keys enumerator.|
|key_value|Optional. Reference to the output key value. If `NULL` no key value is returned.|
|key_name|Optional. Reference to the output key name. If `NULL` no key name is returned.|
```c
// Enumerating dictionary keys
mgos_zvar_t key_val;
const char *key_name;
mgos_zvar_enum_t keys = mgos_zvar_get_keys(dic);
while (mgos_zvar_get_next_key(&keys, &key_val, &key_name)) {
  // do something...
}
```
### mgos_zvarc_get_keys()
```c
mgos_zvarc_enum_t mgos_zvarc_get_keys(mgos_zvarc_t dic);
```
Returns the keys enumerator used by `mgos_zvarc_get_next_key`. Returns `NULL` if error.

|Parameter||
|--|--|
|dic|Dictionary variable.|
### mgos_zvarc_get_next_key()
```c
bool mgos_zvarc_get_next_key(mgos_zvarc_enum_t *keys_enum, mgos_zvarc_t *key_value, const char **key_name);
```
Gets next constant key from the enumerator returned by `mgos_zvarc_get_keys`. Returns `false` if the end of the enumerator is reached or if error, otherwise `true`.

|Parameter||
|--|--|
|keys_enum|Reference to the keys enumerator.|
|key_value|Optional. Reference to the output constant key value. If `NULL` no key value is returned.|
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
mgos_zvar_t mgos_zvar_get_key(mgos_zvar_t dir, const char *key_name);;
```
Returns a key value.

|Parameter||
|--|--|
|dic|Dictionary variable.|
|key_name|Name of the key to be returned.|
### mgos_zvar_get_ckey()
```c
mgos_zvarc_t mgos_zvar_get_ckey(mgos_zvarc_t dic, const char *key_name);
```
Returns a key value.

|Parameter||
|--|--|
|dic|Dictionary variable.|
|key_name|Name of the key to be returned.|
### mgos_zvar_try_get_key()
```c
bool mgos_zvar_try_get_key(mgos_zvar_t dic, const char *key_name, mgos_zvar_t *key_value);
```
Try to get a key value. Returns `true` if the key exists, otherwise `false`.

|Parameter||
|--|--|
|dic|Dictionary variable.|
|key_name|Optional. Reference to the output key name. If `NULL` no key name is returned.|
|key_value|Optional. Reference to the output key value. If `NULL` no key value is returned.|
### mgos_zvarc_try_get_key()
```c
bool mgos_zvarc_try_get_key(mgos_zvarc_t dic, const char *key_name, mgos_zvarc_t *key_value);
```
Try to get a key value. Returns `true` if the key exists, otherwise `false`.

|Parameter||
|--|--|
|dic|Dictionary variable.|
|key_name|Optional. Reference to the output key name. If `NULL` no key name is returned.|
|key_value|Optional. Reference to the output key value. If `NULL` no key value is returned.|
### mgos_zvar_add_key()
```c
bool mgos_zvar_add_key(mgos_zvar_t dic, const char *key_name, mgos_zvar_t key_value);
```
Adds the key to the dictionary. Returns `true` if successfully added, otherwise `false`.

|Parameter||
|--|--|
|dic|Dictionary variable.|
|key_name|Key name.|
|key_value|Key value.|