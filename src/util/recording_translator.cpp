/*
 *    Copyright 2013 Kai Pastor
 *
 *    This file is part of OpenOrienteering.
 *
 *    OpenOrienteering is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    OpenOrienteering is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with OpenOrienteering.  If not, see <http://www.gnu.org/licenses/>.
 */


#include "recording_translator.h"

#include <QDebug>


RecordingTranslator::RecordingTranslator(QObject* parent)
 : QTranslator(parent)
{
	; // nothing
}

RecordingTranslator::~RecordingTranslator()
{
	; // nothing
}

bool RecordingTranslator::isEmpty() const
{
	return false;
}

QString RecordingTranslator::translate(const char* context, const char* sourceText, const char* disambiguation, int n) const
{
	qDebug() << context << " " << sourceText << " " << disambiguation << " " << n;
	static const QString null_string;
	return null_string;
}
