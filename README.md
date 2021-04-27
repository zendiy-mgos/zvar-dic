# ZenVar Dictionary
## Overview
This Mongoose OS library allows you to create and manipulate dictionaries adding or removing keys, easily, like you do in javascript.
## Features
- **Dynamic size** - You can add or remove keys with no limits.
- **Dynamic data-type keys** - Key values haven't data type declared explicitly, but any of supported by [ZenVar library](https://github.com/zendiy-mgos/zvar).
- **Nested keys** - A dictionary's key value can be a dictionary, recursively, with no depth limits. 
- **JSON support** - You can dynamically create a dictionary from a JSON string or you can save it as JSON in a very easy way. Just include the [ZenVar JSON library](https://github.com/zendiy-mgos/zvar-json) into your project. 

## Get Started
Create an empty dictionary explicitly.
```c
mgos_zvar_t dic = mgos_zvar_new_dic();
```
Create a dictionary implicitly just adding one key to a previously created variant instance.
```c
// Example 1 - Dictionary from a type-less(NULL) variant instance 
mgos_zvar_t dic = mgos_zvar_new();
mgos_zvar_add_key(dic, "Name", mgos_zvar_new_str("Mark"));

// Example 2 - Dictionary from an integer variant instance 
mgos_zvar_t dic = mgos_zvar_new_integer(10);
mgos_zvar_add_key(dic, "Name", mgos_zvar_new_str("Mark"));
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
Returns `true` if the variable is a dictionary, or `false` otherwise.

|Parameter||
|--|--|
|var|A variant variable.|
### mgos_zvar_remove_keys()
```c
void mgos_zvar_remove_keys(mgos_zvar_t dic);
```
Removes all keys from the dictionary. Removed keys are also automatically deallocated.

|Parameter||
|--|--|
|dic|A dictionary.|
### mgos_zvar_remove_key()
```c
void mgos_zvar_remove_key(mgos_zvar_t dic, const char *key_name);
```
Removes the specified key from the dictionary. Removed key is also automatically deallocated.

|Parameter||
|--|--|
|dic|A dictionary.|
|key_name|The name of the key to remove.|
### mgos_zvar_has_key()
```c
bool mgos_zvar_has_key(mgos_zvarc_t dic, const char *key_name);
```
Returns `true` if the dictionary contains the key, or `false` otherwise.

|Parameter||
|--|--|
|dic|A dictionary.|
|key_name|The key name.|
### mgos_zvar_get_keys()
```c
mgos_zvar_enum_t mgos_zvar_get_keys(mgos_zvar_t dic);
```
Returns the keys enumerator of a dictionary, or `NULL` if error. The enumerator can be used with `mgos_zvar_get_next_key`.

|Parameter||
|--|--|
|dic|A dictionary.|
### mgos_zvar_get_next_key()
```c
bool mgos_zvar_get_next_key(mgos_zvar_enum_t *keys_enum, mgos_zvar_t *key_value, const char **key_name);
```
Gets the next key value iterating dictionary keys. Returns `false` if the end of the enumerator is reached, or `true` otherwise.

|Parameter||
|--|--|
|keys_enum|A reference to a keys enumerator.|
|key_value|The output key value. Optional, if `NULL` no key value is returned.|
|key_name|The output key name. Optional, if `NULL` no key name is returned.|
```c
// Example - Iterating dictionary keys
mgos_zvar_t key_value;
const char *key_name;
mgos_zvar_enum_t keys_enum = mgos_zvar_get_keys(dic);
while (mgos_zvar_get_next_key(&keys_enum, &key_value, &key_name)) {
  // do something...
}
```
### mgos_zvarc_get_keys()
```c
mgos_zvarc_enum_t mgos_zvarc_get_keys(mgos_zvarc_t dic);
```
Returns the keys enumerator of a readonly dictionary, or `NULL` if error. The enumerator can be used with `mgos_zvarc_get_next_key`.

|Parameter||
|--|--|
|dic|A readonly dictionary.|
### mgos_zvarc_get_next_key()
```c
bool mgos_zvarc_get_next_key(mgos_zvarc_enum_t *keys_enum, mgos_zvarc_t *key_value, const char **key_name);
```
Gets the next key value iterating readonly dictionary keys. Returns `false` if the end of the enumerator is reached, or `true` otherwise. The retreived key value is readonly.

|Parameter||
|--|--|
|keys_enum|A reference to a keys enumerator.|
|key_value|The output readonly key value. Optional, if `NULL` no key value is returned.|
|key_name|The output key name. Optional, if `NULL` no key name is returned.|
```c
// Example - Iterating readonly dictionary keys
mgos_zvarc_t key_value;
const char *key_name;
mgos_zvarc_enum_t keys_enum = mgos_zvarc_get_keys(var);
while (mgos_zvarc_get_next_key(&keys_enum, &key_value, &key_name)) {
  // do something...
}
```
### mgos_zvar_get_key()
```c
mgos_zvar_t mgos_zvar_get_key(mgos_zvar_t dir, const char *key_name);;
```
Returns the key value of a dictionary, or `NULL` if the key doesn't exist.

|Parameter||
|--|--|
|dic|A dictionary.|
|key_name|The name of the key to return.|
### mgos_zvarc_get_key()
```c
mgos_zvarc_t mgos_zvarc_get_key(mgos_zvarc_t dic, const char *key_name);
```
Returns the key value of a readonly dictionary, or `NULL` if the key doesn't exist. The returned value is readonly.

|Parameter||
|--|--|
|dic|A dictionary.|
|key_name|The name of the key to return.|
### mgos_zvar_try_get_key()
```c
bool mgos_zvar_try_get_key(mgos_zvar_t dic, const char *key_name, mgos_zvar_t *key_value);
```
Try to get the key value of a dictionary. Returns `true` if the key exists, or `false` otherwise.

|Parameter||
|--|--|
|dic|A dictionary.|
|key_name|The output key name. Optional, if `NULL` no key name is returned.|
|key_value|The output key value. Optional, if `NULL` no key value is returned.|
### mgos_zvarc_try_get_key()
```c
bool mgos_zvarc_try_get_key(mgos_zvarc_t dic, const char *key_name, mgos_zvarc_t *key_value);
```
Try to get the key value of a readonly dictionary. Returns `true` if the key exists, or `false` otherwise. The returned value is readonly.

|Parameter||
|--|--|
|dic|A dictionary.|
|key_name|The output key name. Optional, if `NULL` no key name is returned.|
|key_value|The output readonly key value. Optional, if `NULL` no key value is returned.|
### mgos_zvar_add_key()
```c
bool mgos_zvar_add_key(mgos_zvar_t dic, const char *key_name, mgos_zvar_t key_value);
```
Adds the key to a dictionary. Returns `true` if successfully added, or `false` otherwise.

|Parameter||
|--|--|
|dic|A dictionary.|
|key_name|The name of the key to add.|
|key_value|The key value.|
### mgos_zvar_merge()
```c
bool mgos_zvar_merge(mgos_zvarc_t src_var, mgos_zvar_t dest_var);
```
Merges a source dictionary into the destination one. If the source variable is not a dictionary it is just copied into the destination. Returns `true` if merged successfully, or `false` otherwise.

|Parameter||
|--|--|
|src_var|A source variant variable.|
|dest_var|A destination variant variable.|