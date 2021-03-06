/* Copyright (c) 2011-2015, EPFL/Blue Brain Project
 *                          Ahmet Bilgili <ahmet.bilgili@epfl.ch>
 *
 * This file is part of Monsteer <https://github.com/BlueBrain/Monsteer>
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License version 3.0 as published
 * by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef MONSTEER_QT_STEERINGWIDGET_H
#define MONSTEER_QT_STEERINGWIDGET_H

#include <monsteer/types.h>

#include <QWidget>

namespace monsteer
{
namespace qt
{

/**
 * Simulation controller widget that receives the cell ids through zeq
 * and can apply nest stimulation generators on selected cells using zeq.
 **/
class SteeringWidget : public QWidget
{
    Q_OBJECT

public:

    /**
     * Constructor
     * @param parentWgt Parent widget.
     */
    SteeringWidget( QWidget *parentWgt = 0 );
    ~SteeringWidget();

signals:

    void updateCellIdsTextBox( std::vector<uint32_t> cellIds );

private Q_SLOTS:

    void _playPauseSimulation();
    void _injectStimuli();
    void _generatorSelected( int index );

    void _updateCellIdsTextBox( std::vector<uint32_t> cellIds );

    void _propertiesChanged();

private:

    struct Impl;
    Impl *_impl;
};

}
}
#endif
