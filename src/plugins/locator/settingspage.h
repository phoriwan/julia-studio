/****************************************************************************
**
** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
****************************************************************************/

#ifndef SETTINGSPAGE_H
#define SETTINGSPAGE_H

#include "ui_settingspage.h"

#include <QPointer>
#include <QHash>

#include <coreplugin/dialogs/ioptionspage.h>

QT_BEGIN_NAMESPACE
class QListWidgetItem;
QT_END_NAMESPACE

namespace Locator {

class ILocatorFilter;

namespace Internal {

class LocatorPlugin;

class SettingsPage : public Core::IOptionsPage
{
    Q_OBJECT

public:
    explicit SettingsPage(LocatorPlugin *plugin);

    QWidget *createPage(QWidget *parent);
    void apply();
    void finish();
    bool matches(const QString &) const;

private slots:
    void updateButtonStates();
    void configureFilter(QListWidgetItem *item = 0);
    void addCustomFilter();
    void removeCustomFilter();

private:
    void updateFilterList();
    void saveFilterStates();
    void restoreFilterStates();
    void requestRefresh();

    Ui::SettingsWidget m_ui;
    LocatorPlugin *m_plugin;
    QWidget* m_page;
    QList<ILocatorFilter *> m_filters;
    QList<ILocatorFilter *> m_addedFilters;
    QList<ILocatorFilter *> m_removedFilters;
    QList<ILocatorFilter *> m_customFilters;
    QList<ILocatorFilter *> m_refreshFilters;
    QHash<ILocatorFilter *, QByteArray> m_filterStates;
    QString m_searchKeywords;
};

} // namespace Internal
} // namespace Locator

#endif // SETTINGSPAGE_H
