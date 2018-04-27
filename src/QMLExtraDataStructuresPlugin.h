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
 * @mainpage qml-extra-data-structures
 *
 * QML data structures and utilities that are either useful or are missing an official QML API. See README.md for more information.
 */

/**
 * @file QMLExtraDataStructuresPlugin.h
 * @brief Object that exposes the QMLExtraDataStructures plugin components as QML objects
 * @author Ayberk Özgür
 * @date 2018-03-06
 */

#ifndef QMLEXTRADATASTRUCTURESPLUGIN_H
#define QMLEXTRADATASTRUCTURESPLUGIN_H

#include <QQmlExtensionPlugin>
#include <qqml.h>

namespace QMLExtraDataStructures{

/** @cond DO_NOT_DOCUMENT */

class QMLExtraDataStructuresPlugin : public QQmlExtensionPlugin {
    /* *INDENT-OFF* */
    Q_OBJECT
    /* *INDENT-ON* */
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char* uri);
};

}

/** @endcond */

#endif /* QMLEXTRADATASTRUCTURESPLUGIN_H */
