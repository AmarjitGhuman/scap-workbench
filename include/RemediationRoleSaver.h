/*
 * Copyright 2013 Red Hat Inc., Durham, North Carolina.
 * All Rights Reserved.
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
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authors:
 *      Martin Preisler <mpreisle@redhat.com>
 */

#ifndef SCAP_WORKBENCH_REMEDIATION_ROLE_SAVER_H_
#define SCAP_WORKBENCH_REMEDIATION_ROLE_SAVER_H_

#include "ForwardDecls.h"
#include "ScanningSession.h"

#include <QString>
#include <QFile>
#include <QFileDialog>

extern "C"
{
#include <xccdf_benchmark.h>
#include <xccdf_policy.h>
#include <xccdf_session.h>
}


class RemediationSaverBase
{
    public:
    RemediationSaverBase(QWidget* parentWindow, ScanningSession* session): mParentWindow(parentWindow), mScanningSession(session) {}
        void SelectFilenameAndSaveRole();

    protected:
        const ScanningSession* mScanningSession;
        QWidget* mParentWindow;

        QString mSaveMessage;
        QString mFiletypeExtension;
        QString mFiletypeTemplate;
        QString mFixTemplate;

    private:
        int SaveToFile(const QString& filename);
        QString guessFilenameStem();
};


class BashRemediationSaver : public RemediationSaverBase
{
    public:
        BashRemediationSaver(QWidget* parentWindow, ScanningSession* session);
};


class AnsibleRemediationSaver : public RemediationSaverBase
{
    public:
        AnsibleRemediationSaver(QWidget* parentWindow, ScanningSession* session);
};

#endif // SCAP_WORKBENCH_REMEDIATION_ROLE_SAVER_H_
