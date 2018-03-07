import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Controls 1.2

import QMLExtraDataStructures 1.0

ApplicationWindow {
    visible: true
    minimumHeight: height
    minimumWidth: width

    Column{
        spacing: 5

        GroupBox{
            title: "AssociativeArray"

            Row{
                spacing: 5

                TextField{
                    id: key
                    placeholderText: "Key"
                }

                TextField{
                    id: value
                    placeholderText: "Value"
                }

                Button{
                    text: "Set"
                    onClicked: associativeArray.set(key.text, value.text)
                }

                Button{
                    text: "Get"
                    onClicked: value.text = associativeArray.get(key.text)
                }

                Button{
                    text: "Clear"
                    onClicked: associativeArray.clear()
                }

                AssociativeArray{
                    id: associativeArray
                    defaultValue: "undefined"
                }
            }
        }

        GroupBox{
            title: "CircularBuffer"

            Row{
                spacing: 5

                TextField{
                    id: element
                    placeholderText: "Element"
                }

                Button{
                    text: "Add"
                    onClicked: circularBuffer.add(element.text)
                }

                Button{
                    text: "Remove Last"
                    onClicked: circularBuffer.remove(circularBuffer.elements.length - 1)
                }

                Button{
                    text: "Clear"
                    onClicked: circularBuffer.clear()
                }

                Text{ text: "Contents: [" + circularBuffer.elements + "]" }

                Text{
                    text: {
                        var sum = 0;
                        for(var i=0;i<circularBuffer.elements.length;i++)
                            sum += parseInt(circularBuffer.elements[i]);
                        return "Sum of contents (if number): " + sum;
                    }
                }

                CircularBuffer{
                    id: circularBuffer
                    size: 5
                }
            }
        }

        GroupBox{
            title: "RepeaterList"

            Row{
                spacing: 5

                TextField{
                    placeholderText: "Number of 3's in RepeaterList"
                    onTextChanged: repeaterList.model = parseInt(text)
                }

                Text{
                    text: {
                        var sum = 0;
                        for(var i=0;i<repeaterList.items.length;i++)
                            if(repeaterList.items[i])
                                sum += repeaterList.items[i].content;
                        return "Sum of contents: " + sum;
                    }
                }

                RepeaterList{
                    id: repeaterList

                    Item{ property int content: 3 }
                }
            }
        }
    }
}
