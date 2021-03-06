/*
 *    Copyright 2014, 2017 Kai Pastor
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

#ifndef OPENORIENTEERING_AUTOSAVE_H
#define OPENORIENTEERING_AUTOSAVE_H

#include <QScopedPointer>

class AutosavePrivate;

/**
 * @brief Class Autosave implements autosaving behaviour.
 * 
 * Autosaving means that data which has been modified is automatically saved
 * after some period of time if no regular saving (typically triggered by the
 * user) happens before.
 * 
 * Classes which wish to implement autosaving may inherit from this class.
 * Inheriting classes must implement autosave(). Furthermore, they must call
 * setAutosaveNeeded() when changes need to be taken care of by Autosave, or
 * when normal saving has terminated the need to perform autosaving.
 * 
 * Autosaving, as implemented by autosave(), may succeed, fail temporary (e.g.
 * during editing), or fail permanent (e.g. for lack of disk space).
 * On success or permanent failure, autosave() will be called again after the
 * regular autosaving period.
 * On temporary failure, autosave() will be called again after five seconds.
 * 
 * The autosave period (in minutes) is taken from the setting
 * Settings::General_AutosaveInterval.
 */
class Autosave
{
public:
	/** @brief Possible results of autosave attempts. */
	enum AutosaveResult
	{
		Success,          ///< Autosaving succeeded.
		PermanentFailure, ///< Autosaving failed for some persistent reason.
		TemporaryFailure  ///< Autosaving failed for some transient reason and shall be retried soon.
	};
	
	/** @brief Returns the autosave file path for the given path. */
	virtual QString autosavePath(const QString &path) const;
	
	/** @brief Performs an autosave, if possible. */
	virtual AutosaveResult autosave() = 0;
	
	/** @brief Informs Autosave whether autosaving is needed or not. */
	void setAutosaveNeeded(bool);
	
	/** @brief Returns true if autosave is known to be needed. */
	bool autosaveNeeded() const;
	
protected:
	/** @brief Initializes the autosave feature. */
	Autosave();
	
	/** @brief Destructs the autosave feature. */
	virtual ~Autosave();
	
private:
	friend class AutosavePrivate;
	
	QScopedPointer<AutosavePrivate> autosave_controller;
};

#endif
