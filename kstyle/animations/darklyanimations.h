#ifndef darklyanimations_h
#define darklyanimations_h

/*************************************************************************
 * Copyright (C) 2014 by Hugo Pereira Da Costa <hugo.pereira@free.fr>    *
 *                                                                       *
 * This program is free software; you can redistribute it and/or modify  *
 * it under the terms of the GNU General Public License as published by  *
 * the Free Software Foundation; either version 2 of the License, or     *
 * (at your option) any later version.                                   *
 *                                                                       *
 * This program is distributed in the hope that it will be useful,       *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 * GNU General Public License for more details.                          *
 *                                                                       *
 * You should have received a copy of the GNU General Public License     *
 * along with this program; if not, write to the                         *
 * Free Software Foundation, Inc.,                                       *
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA .        *
 *************************************************************************/

#include "darklybusyindicatorengine.h"
#include "darklydialengine.h"
#include "darklyheaderviewengine.h"
#include "darklyscrollbarengine.h"
#include "darklyspinboxengine.h"
#include "darklystackedwidgetengine.h"
#include "darklytabbarengine.h"
#include "darklytoolboxengine.h"
#include "darklywidgetstateengine.h"

#include <QList>
#include <QObject>

namespace Darkly
{

//* stores engines
class Animations : public QObject
{
    Q_OBJECT

public:
    //* constructor
    explicit Animations(QObject *);

    //* register animations corresponding to given widget, depending on its type.
    void registerWidget(QWidget *widget) const;

    /** unregister all animations associated to a widget */
    void unregisterWidget(QWidget *widget) const;

    //* enability engine
    WidgetStateEngine &widgetEnabilityEngine() const
    {
        return *_widgetEnabilityEngine;
    }

    //* abstractButton engine
    WidgetStateEngine &widgetStateEngine() const
    {
        return *_widgetStateEngine;
    }

    //* editable combobox arrow hover engine
    WidgetStateEngine &comboBoxEngine() const
    {
        return *_comboBoxEngine;
    }

    //* Tool buttons arrow hover engine
    WidgetStateEngine &toolButtonEngine() const
    {
        return *_toolButtonEngine;
    }

    //* item view engine
    WidgetStateEngine &inputWidgetEngine() const
    {
        return *_inputWidgetEngine;
    }

    //* busy indicator
    BusyIndicatorEngine &busyIndicatorEngine() const
    {
        return *_busyIndicatorEngine;
    }

    //* header view engine
    HeaderViewEngine &headerViewEngine() const
    {
        return *_headerViewEngine;
    }

    //* scrollbar engine
    ScrollBarEngine &scrollBarEngine() const
    {
        return *_scrollBarEngine;
    }

    //* dial engine
    DialEngine &dialEngine() const
    {
        return *_dialEngine;
    }

    //* spinbox engine
    SpinBoxEngine &spinBoxEngine() const
    {
        return *_spinBoxEngine;
    }

    //* tabbar
    TabBarEngine &tabBarEngine() const
    {
        return *_tabBarEngine;
    }

    //* toolbox
    ToolBoxEngine &toolBoxEngine() const
    {
        return *_toolBoxEngine;
    }

    //* setup engines
    void setupEngines();

protected Q_SLOTS:

    //* enregister engine
    void unregisterEngine(QObject *);

private:
    //* register new engine
    void registerEngine(BaseEngine *);

    //* busy indicator
    BusyIndicatorEngine *_busyIndicatorEngine = nullptr;

    //* headerview hover effect
    HeaderViewEngine *_headerViewEngine = nullptr;

    //* widget enability engine
    WidgetStateEngine *_widgetEnabilityEngine = nullptr;

    //* abstract button engine
    WidgetStateEngine *_widgetStateEngine = nullptr;

    //* editable combobox arrow hover effect
    WidgetStateEngine *_comboBoxEngine = nullptr;

    //* mennu toolbutton arrow hover effect
    WidgetStateEngine *_toolButtonEngine = nullptr;

    //* item view engine
    WidgetStateEngine *_inputWidgetEngine = nullptr;

    //* scrollbar engine
    ScrollBarEngine *_scrollBarEngine = nullptr;

    //* dial engine
    DialEngine *_dialEngine = nullptr;

    //* spinbox engine
    SpinBoxEngine *_spinBoxEngine = nullptr;

    //* stacked widget engine
    StackedWidgetEngine *_stackedWidgetEngine = nullptr;

    //* tabbar engine
    TabBarEngine *_tabBarEngine = nullptr;

    //* toolbar engine
    ToolBoxEngine *_toolBoxEngine = nullptr;

    //* keep list of existing engines
    QList<BaseEngine::Pointer> _engines;
};

}

#endif
