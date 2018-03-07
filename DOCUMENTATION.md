# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`AssociativeArray`](#classAssociativeArray) | 
`class `[`CircularBuffer`](#classCircularBuffer) | Limited size buffer that keeps the most recent N elements.

# class `AssociativeArray` 

```
class AssociativeArray
  : public QQuickItem
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`{property} QVariant `[`defaultValue`](#classAssociativeArray_1aaf5a91a1d42fd38b8257903923dff7d9) | The default value to return if a key is not found.
`public  `[`AssociativeArray`](#classAssociativeArray_1a667e8ce8d40d056e1411122424b46e3c)`(QQuickItem * parent)` | Creates new associative array.
`public  `[`AssociativeArray`](#classAssociativeArray_1aa7128fa4ebcff6eb266bf09344217021)`(QSharedPointer< QHash< QString, QVariant >> existingArray,QQuickItem * parent)` | Creates new associative array with existing internal array.
`public  `[`~AssociativeArray`](#classAssociativeArray_1ae1f93f3a477623163b57ca45be61bfc9)`()` | Destroys this associative array.
`{slot} public `[`AssociativeArray`](#classAssociativeArray)` * `[`copy`](#classAssociativeArray_1a800f31b43915fa77989e5884e43b86a7)`()` | Returns a shallow copy of this object.
`{slot} public void `[`clear`](#classAssociativeArray_1a5d5d2811c46992bb883ed987109cda4b)`()` | Removes all key-value pairs from the array.
`{slot} public QVariant `[`get`](#classAssociativeArray_1aa19b34889b19e4f299b278ae9b3ece94)`(QString const & key) const` | Gets a value.
`{slot} public void `[`set`](#classAssociativeArray_1a385f0a6126de906ef0144533c29a1427)`(QString const & key,QVariant const & value)` | Sets a key-value pair.

## Members

#### `{property} QVariant `[`defaultValue`](#classAssociativeArray_1aaf5a91a1d42fd38b8257903923dff7d9) 

The default value to return if a key is not found.

#### `public  `[`AssociativeArray`](#classAssociativeArray_1a667e8ce8d40d056e1411122424b46e3c)`(QQuickItem * parent)` 

Creates new associative array.

#### Parameters
* `parent` The QML parent

#### `public  `[`AssociativeArray`](#classAssociativeArray_1aa7128fa4ebcff6eb266bf09344217021)`(QSharedPointer< QHash< QString, QVariant >> existingArray,QQuickItem * parent)` 

Creates new associative array with existing internal array.

#### Parameters
* `existingArray` The existing internal array 

* `parent` The QML parent

#### `public  `[`~AssociativeArray`](#classAssociativeArray_1ae1f93f3a477623163b57ca45be61bfc9)`()` 

Destroys this associative array.

#### `{slot} public `[`AssociativeArray`](#classAssociativeArray)` * `[`copy`](#classAssociativeArray_1a800f31b43915fa77989e5884e43b86a7)`()` 

Returns a shallow copy of this object.

#### Returns
Shallow copy with the pointer to the same internal array

#### `{slot} public void `[`clear`](#classAssociativeArray_1a5d5d2811c46992bb883ed987109cda4b)`()` 

Removes all key-value pairs from the array.

#### `{slot} public QVariant `[`get`](#classAssociativeArray_1aa19b34889b19e4f299b278ae9b3ece94)`(QString const & key) const` 

Gets a value.

#### Parameters
* `key` Key associated with the value

#### `{slot} public void `[`set`](#classAssociativeArray_1a385f0a6126de906ef0144533c29a1427)`(QString const & key,QVariant const & value)` 

Sets a key-value pair.

#### Parameters
* `key` The key 

* `value` The associated value

# class `CircularBuffer` 

```
class CircularBuffer
  : public QQuickItem
```  

Limited size buffer that keeps the most recent N elements.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`{property} int `[`size`](#classCircularBuffer_1a7a7d84c020ab0d9adf9ece1c1e774d37) | Size of the buffer.
`{property} QVariantList `[`elements`](#classCircularBuffer_1ad93bb2946ad657a061ffae5237d570dc) | List of current elements.
`{signal} public void `[`elementAdded`](#classCircularBuffer_1a2544f9274f55deaad070c8d092b826b2)`(QVariant const & element)` | Emitted when a new element is added.
`{signal} public void `[`elementRemoved`](#classCircularBuffer_1aa63b5a240bcba2ec8d2bccd224e55a43)`(QVariant const & element)` | Emitted when an element is removed, possibly due to buffer being full.
`{slot} public void `[`clear`](#classCircularBuffer_1ae3acd33319508f7499654995ec7f0384)`()` | Removes all elements from the buffer.
`{slot} public QVariant `[`get`](#classCircularBuffer_1a0723efbbf738f43c76cc555046d64de6)`(int index) const` | Gets the element at the given index, 0 is tail, size - 1 is head.
`{slot} public void `[`add`](#classCircularBuffer_1aa224562fa982063bf93fc73e279ddd20)`(QVariant const & element)` | Adds the given element to the head, removing an element from the tail if buffer is full.
`{slot} public void `[`remove`](#classCircularBuffer_1a5d70b2ebde87284083fc73fa875f5b82)`(int index)` | Removes the element at the given index.

## Members

#### `{property} int `[`size`](#classCircularBuffer_1a7a7d84c020ab0d9adf9ece1c1e774d37) 

Size of the buffer.

Number of elements that can be contained in the buffer.

#### `{property} QVariantList `[`elements`](#classCircularBuffer_1ad93bb2946ad657a061ffae5237d570dc) 

List of current elements.

#### `{signal} public void `[`elementAdded`](#classCircularBuffer_1a2544f9274f55deaad070c8d092b826b2)`(QVariant const & element)` 

Emitted when a new element is added.

#### Parameters
* `element` The newly added element

#### `{signal} public void `[`elementRemoved`](#classCircularBuffer_1aa63b5a240bcba2ec8d2bccd224e55a43)`(QVariant const & element)` 

Emitted when an element is removed, possibly due to buffer being full.

#### Parameters
* `element` The removed element

#### `{slot} public void `[`clear`](#classCircularBuffer_1ae3acd33319508f7499654995ec7f0384)`()` 

Removes all elements from the buffer.

#### `{slot} public QVariant `[`get`](#classCircularBuffer_1a0723efbbf738f43c76cc555046d64de6)`(int index) const` 

Gets the element at the given index, 0 is tail, size - 1 is head.

#### Parameters
* `index` The desired index

#### Returns
The element at index, undefined if out of bounds

#### `{slot} public void `[`add`](#classCircularBuffer_1aa224562fa982063bf93fc73e279ddd20)`(QVariant const & element)` 

Adds the given element to the head, removing an element from the tail if buffer is full.

#### Parameters
* `element` The element to add

#### `{slot} public void `[`remove`](#classCircularBuffer_1a5d70b2ebde87284083fc73fa875f5b82)`(int index)` 

Removes the element at the given index.

#### Parameters
* `index` Index of the element to remove, does nothing if out of bounds

Generated by [Moxygen](https://sourcey.com/moxygen)