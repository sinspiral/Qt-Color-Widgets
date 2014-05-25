/**

@author Mattia Basaglia

@section License

    Copyright (C) 2013-2014 Mattia Basaglia
    Copyright (C) 2014 Calle Laakkonen

    This software is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This software is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Color Widgets.  If not, see <http://www.gnu.org/licenses/>.

*/
#ifndef GRADIENT_SLIDER_HPP
#define GRADIENT_SLIDER_HPP

#include "colorpicker_global.hpp"

#include <QSlider>
#include <QGradient>

/**
 * \brief A slider that mover on top of a gradient
 */
class QCP_EXPORT Gradient_Slider : public QSlider
{
    Q_OBJECT
    Q_PROPERTY(QBrush background READ background WRITE setBackground)
    Q_PROPERTY(QGradientStops colors READ colors WRITE setColors DESIGNABLE false)
    Q_PROPERTY(QColor firstColor READ firstColor WRITE setFirstColor STORED false)
    Q_PROPERTY(QColor lastColor READ lastColor WRITE setLastColor STORED false)

public:
    explicit Gradient_Slider(QWidget *parent = 0);
    explicit Gradient_Slider(Qt::Orientation orientation, QWidget *parent = 0);
    ~Gradient_Slider();

    /// Get the background, it's visible for transparent gradient stops
    QBrush background() const;
    /// Set the background, it's visible for transparent gradient stops
    void setBackground(const QBrush &bg);

    /// Get the colors that make up the gradient
    QGradientStops colors() const;
    /// Set the colors that make up the gradient
    void setColors(const QGradientStops &colors);

    /**
     * Overload: create an evenly distributed gradient of the given colors
     */
    void setColors(const QVector<QColor> &colors);

    /**
     * Set the first color of the gradient
     *
     * If the gradient is currently empty it will create a stop with the given color
     */
    void setFirstColor(const QColor &c);

    /**
     * Set the last color of the gradient
     *
     * If the gradient is has less than two colors,
     * it will create a stop with the given color
     */
    void setLastColor(const QColor &c);

    /**
     * Get the first color
     *
     * Returns QColor() con empty gradient
     */
    QColor firstColor() const;

    /**
     * Get the last color
     *
     * Returns QColor() con empty gradient
     */
    QColor lastColor() const;
    
protected:
    void paintEvent(QPaintEvent *ev);

private:
    class Private;
    Private * const p;
};

#endif // GRADIENT_SLIDER_HPP