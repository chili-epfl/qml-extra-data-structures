# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`namespace `[`QMLExtraDataStructures`](#namespaceQMLExtraDataStructures) | QML data structures and utilities that are either useful or are missing an official QML API.
`class `[`RepeaterList`](#classRepeaterList) | Repeater that exposes its items.

# namespace `QMLExtraDataStructures` 

QML data structures and utilities that are either useful or are missing an official QML API.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`QMLExtraDataStructures::AssociativeArray`](#classQMLExtraDataStructures_1_1AssociativeArray) | Associative array, i.e QHash.
`class `[`QMLExtraDataStructures::CircularBuffer`](#classQMLExtraDataStructures_1_1CircularBuffer) | Limited size buffer that keeps the most recent N elements.

# class `QMLExtraDataStructures::AssociativeArray` 

```
class QMLExtraDataStructures::AssociativeArray
  : public QQuickItem
```  

Associative array, i.e QHash.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`{property} QVariant `[`defaultValue`](#classQMLExtraDataStructures_1_1AssociativeArray_1a4751d5b183e712fdc723552655816c55) | The default value to return if a key is not found.
`{slot} public `[`QMLExtraDataStructures::AssociativeArray`](#classQMLExtraDataStructures_1_1AssociativeArray)` * `[`copy`](#classQMLExtraDataStructures_1_1AssociativeArray_1a1ceb05283fcf934e695fc4164dc758b2)`()` | Returns a shallow copy of this object.
`{slot} public void `[`clear`](#classQMLExtraDataStructures_1_1AssociativeArray_1a58581bd8fda01852e2fa773a7d8ed6ca)`()` | Removes all key-value pairs from the array.
`{slot} public QVariant `[`get`](#classQMLExtraDataStructures_1_1AssociativeArray_1ac25d41a948a1a40de4fe8d29a2f5494a)`(QString const & key) const` | Gets a value.
`{slot} public void `[`set`](#classQMLExtraDataStructures_1_1AssociativeArray_1abf679242ca149a0f392b1da6b64e00ee)`(QString const & key,QVariant const & value)` | Sets a key-value pair.
`{slot} public QList< QString > `[`keys`](#classQMLExtraDataStructures_1_1AssociativeArray_1a645daa0a666d7d8e81d7eca789b4911a)`() const` | Returns a list of the keys.
`{slot} public bool `[`del`](#classQMLExtraDataStructures_1_1AssociativeArray_1a8389e7e812b5d8fc8c0af72e817296e5)`(QString const & key)` | Deletes a key.
`{slot} public QList< QVariant > `[`values`](#classQMLExtraDataStructures_1_1AssociativeArray_1a28c51a0614480bd37ea9874f38bbcaa4)`() const` | Returns a list of all values.

## Members

#### `{property} QVariant `[`defaultValue`](#classQMLExtraDataStructures_1_1AssociativeArray_1a4751d5b183e712fdc723552655816c55) 

The default value to return if a key is not found.

#### `{slot} public `[`QMLExtraDataStructures::AssociativeArray`](#classQMLExtraDataStructures_1_1AssociativeArray)` * `[`copy`](#classQMLExtraDataStructures_1_1AssociativeArray_1a1ceb05283fcf934e695fc4164dc758b2)`()` 

Returns a shallow copy of this object.

#### Returns
Shallow copy with the pointer to the same internal array

#### `{slot} public void `[`clear`](#classQMLExtraDataStructures_1_1AssociativeArray_1a58581bd8fda01852e2fa773a7d8ed6ca)`()` 

Removes all key-value pairs from the array.

#### `{slot} public QVariant `[`get`](#classQMLExtraDataStructures_1_1AssociativeArray_1ac25d41a948a1a40de4fe8d29a2f5494a)`(QString const & key) const` 

Gets a value.

#### Parameters
* `key` Key associated with the value

#### `{slot} public void `[`set`](#classQMLExtraDataStructures_1_1AssociativeArray_1abf679242ca149a0f392b1da6b64e00ee)`(QString const & key,QVariant const & value)` 

Sets a key-value pair.

#### Parameters
* `key` The key 

* `value` The associated value

#### `{slot} public QList< QString > `[`keys`](#classQMLExtraDataStructures_1_1AssociativeArray_1a645daa0a666d7d8e81d7eca789b4911a)`() const` 

Returns a list of the keys.

#### Returns
List of keys

#### `{slot} public bool `[`del`](#classQMLExtraDataStructures_1_1AssociativeArray_1a8389e7e812b5d8fc8c0af72e817296e5)`(QString const & key)` 

Deletes a key.

#### Parameters
* `key` The key 

#### Returns
True if the key existed, False otherwise

#### `{slot} public QList< QVariant > `[`values`](#classQMLExtraDataStructures_1_1AssociativeArray_1a28c51a0614480bd37ea9874f38bbcaa4)`() const` 

Returns a list of all values.

#### Returns
Returns a list containing all the values in the hash, in an arbitrary order

# class `QMLExtraDataStructures::CircularBuffer` 

```
class QMLExtraDataStructures::CircularBuffer
  : public QQuickItem
```  

Limited size buffer that keeps the most recent N elements.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`{property} int `[`size`](#classQMLExtraDataStructures_1_1CircularBuffer_1ad3fe0831f3d5061b0fa0f58b18ed6a51) | Size of the buffer.
`{property} QVariantList `[`elements`](#classQMLExtraDataStructures_1_1CircularBuffer_1a88358232bcaf61954350832fa16a9089) | List of current elements.
`{signal} public void `[`elementAdded`](#classQMLExtraDataStructures_1_1CircularBuffer_1ab5d4bfbfc7e7bf84679d89e98d1bd407)`(QVariant const & element)` | Emitted when a new element is added.
`{signal} public void `[`elementRemoved`](#classQMLExtraDataStructures_1_1CircularBuffer_1aed587ec80926423faa02d7a09ecf6d35)`(QVariant const & element)` | Emitted when an element is removed, possibly due to buffer being full.
`{slot} public void `[`clear`](#classQMLExtraDataStructures_1_1CircularBuffer_1aa53f1d60dbff4255fdbc0707af863c76)`()` | Removes all elements from the buffer.
`{slot} public QVariant `[`get`](#classQMLExtraDataStructures_1_1CircularBuffer_1a743197c9d839a1e708c99514ea485c6a)`(int index) const` | Gets the element at the given index, 0 is tail, size - 1 is head.
`{slot} public void `[`add`](#classQMLExtraDataStructures_1_1CircularBuffer_1a75b14d6428efa319cf60f0c16ce20571)`(QVariant const & element)` | Adds the given element to the head, removing an element from the tail if buffer is full.
`{slot} public void `[`remove`](#classQMLExtraDataStructures_1_1CircularBuffer_1ac098d03930bbeefc2a5bd2f8898fd239)`(int index)` | Removes the element at the given index.

## Members

#### `{property} int `[`size`](#classQMLExtraDataStructures_1_1CircularBuffer_1ad3fe0831f3d5061b0fa0f58b18ed6a51) 

Size of the buffer.

Number of elements that can be contained in the buffer.

#### `{property} QVariantList `[`elements`](#classQMLExtraDataStructures_1_1CircularBuffer_1a88358232bcaf61954350832fa16a9089) 

List of current elements.

#### `{signal} public void `[`elementAdded`](#classQMLExtraDataStructures_1_1CircularBuffer_1ab5d4bfbfc7e7bf84679d89e98d1bd407)`(QVariant const & element)` 

Emitted when a new element is added.

#### Parameters
* `element` The newly added element

#### `{signal} public void `[`elementRemoved`](#classQMLExtraDataStructures_1_1CircularBuffer_1aed587ec80926423faa02d7a09ecf6d35)`(QVariant const & element)` 

Emitted when an element is removed, possibly due to buffer being full.

#### Parameters
* `element` The removed element

#### `{slot} public void `[`clear`](#classQMLExtraDataStructures_1_1CircularBuffer_1aa53f1d60dbff4255fdbc0707af863c76)`()` 

Removes all elements from the buffer.

#### `{slot} public QVariant `[`get`](#classQMLExtraDataStructures_1_1CircularBuffer_1a743197c9d839a1e708c99514ea485c6a)`(int index) const` 

Gets the element at the given index, 0 is tail, size - 1 is head.

#### Parameters
* `index` The desired index

#### Returns
The element at index, undefined if out of bounds

#### `{slot} public void `[`add`](#classQMLExtraDataStructures_1_1CircularBuffer_1a75b14d6428efa319cf60f0c16ce20571)`(QVariant const & element)` 

Adds the given element to the head, removing an element from the tail if buffer is full.

#### Parameters
* `element` The element to add

#### `{slot} public void `[`remove`](#classQMLExtraDataStructures_1_1CircularBuffer_1ac098d03930bbeefc2a5bd2f8898fd239)`(int index)` 

Removes the element at the given index.

#### Parameters
* `index` Index of the element to remove, does nothing if out of bounds

# class `RepeaterList` 

```
class RepeaterList
  : public Repeater
```  

Repeater that exposes its items.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`{property} list `[`items`](#classRepeaterList_1ab7be20ea52e0ea32fae0e6e628773991) | Read-only list of items

## Members

#### `{property} list `[`items`](#classRepeaterList_1ab7be20ea52e0ea32fae0e6e628773991) 

Read-only list of items

Generated by [Moxygen](https://sourcey.com/moxygen)