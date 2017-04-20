/*****************************************************************************
*
* This file is part of Calíope Database Administrator.
* Copyright (c) 2008-2018 David Villalobos Cambronero (dvillalobosc@yahoo.com).
*
* Calíope is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* Calíope is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*
*****************************************************************************/

import QtQuick 1.1

Rectangle {
  id: messageId
  property string message: qsTr(" ")
  Text {
    id: helloText
    text: message
    MouseArea {
      id: mouseArea
      anchors.fill: parent
    }
    states: State {
      name: "down"
      when: mouseArea.pressed === true
      PropertyChanges {
        target: helloText
        rotation: 180
        color: "blue"
      }
    }
    transitions: Transition {
      from: ""
      to: "down"
      reversible: true
      ParallelAnimation {
        NumberAnimation {
          properties: "y,rotation"
          duration: 500
          easing.type: Easing.InCubic
        }
        ColorAnimation {
          duration: 500
        }
      }
    }
  }
}
