/*  XmlTemplateCreator.h
 *
 *  Copyright (C) 2013  Jim Evins <evins@snaught.com>
 *
 *  This file is part of gLabels-qt.
 *
 *  gLabels-qt is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  gLabels-qt is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with gLabels-qt.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef libglabels_XmlTemplateCreator_h
#define libglabels_XmlTemplateCreator_h


#include <QString>
#include <QDomElement>

#include "Template.h"
#include "FrameRect.h"
#include "FrameCd.h"
#include "FrameRound.h"
#include "FrameEllipse.h"
#include "Layout.h"
#include "Markup.h"


namespace libglabels
{

	class XmlTemplateCreator
	{
	public:
		XmlTemplateCreator() {}

		bool writeTemplates( const QList<const Template*> tmplates, const QString& fileName );
		bool writeTemplate( const Template* tmplate, const QString& fileName );
		void createTemplateNode( QDomElement& parent, const Template* tmplate );

	private:
		void createMetaNode( QDomElement& parent, const QString& attr, const QString& value );
		void createLabelNode( QDomElement& parent, const Frame* frame );
		void createLabelRectangleNode( QDomElement& parent, const FrameRect* frame );
		void createLabelEllipseNode( QDomElement& parent, const FrameEllipse* frame );
		void createLabelRoundNode( QDomElement& parent, const FrameRound* frame );
		void createLabelCdNode( QDomElement& parent, const FrameCd* frame );
		void createLabelNodeCommon( QDomElement& node, const Frame* frame );
		void createLayoutNode( QDomElement& parent, const Layout* layout );
		void createMarkupMarginNode( QDomElement& parent, const MarkupMargin* markupMargin );
		void createMarkupLineNode( QDomElement& parent, const MarkupLine* markupLine );
		void createMarkupCircleNode( QDomElement& parent, const MarkupCircle* markupCircle );
		void createMarkupRectNode( QDomElement& parent, const MarkupRect* markupRect );
		void createMarkupEllipseNode( QDomElement& parent, const MarkupEllipse* markupEllipse );

	};

}

#endif // libglabels_XmlTemplateCreator_h