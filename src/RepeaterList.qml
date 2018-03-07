/*
 * Copyright (C) 2018 EPFL
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see http://www.gnu.org/licenses/.
 */

/**
 * @file RepeaterList.qml
 * @brief Repeater that exposes its items
 * @author Ayberk Özgür
 * @date 2018-03-07
 */

import QtQuick 2.5

/**
 * @brief Repeater that exposes its items
 */
Repeater{

    /*
     * Public
     */

    /** type:list Read-only list of items */
    property var items: []

    /*
     * Private
     */

    /** @cond DO_NOT_DOCUMENT */

    function updateItemsList(){
        var newItems = [];
        for(var i=0;i<count;i++)
            newItems[i] = itemAt(i);
        items = newItems;
    }

    onItemAdded: updateItemsList()
    onItemRemoved: updateItemsList()

    /** @endcond */
}
