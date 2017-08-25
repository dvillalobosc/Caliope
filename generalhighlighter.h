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

#ifndef GENERALHIGHLIGHTER_H
#define GENERALHIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QTextBlockUserData>
#include <QSettings>

#include "editortypes.h"

class QTextDocument;

struct BracketInfo
{
  char character;
  int position;
};

class GeneralHighlighter : public QSyntaxHighlighter
{
  Q_OBJECT

public:
  GeneralHighlighter(QTextDocument *parent = 0, EditorTypes::EditorType type = EditorTypes::NoEditor);
  void setFindPattern(const QString &exp);

protected:
  void highlightBlock(const QString &text);

private:
  struct HighlightingRule
  {
    QRegExp pattern;
    QTextCharFormat format;
  };
  QVector<HighlightingRule> thirdHighlightingRules;
  QVector<HighlightingRule> secondHighlightingRules;
  QVector<HighlightingRule> firstHighlightingRules;
  QRegExp commentStartExpression;
  QRegExp commentEndExpression;
  QRegExp stringStartExpression1;
  QRegExp stringEndExpression1;
  QRegExp stringStartExpression2;
  QRegExp stringEndExpression2;
  QTextCharFormat stringFormatSingleQuote;
  QTextCharFormat stringFormatDoubleQuote;
  HighlightingRule rule;
  HighlightingRule findRule;
  void highlightProcedure(HighlightingRule rule, const QString &text);
  void sqlHighlightRules();
  void diffHighlightRules();
  void svnHighlightRules();
  void commitHighlightRules();
  enum States {Normal, Commenting, CDATA, DoubleQuotes};
  QTextCharFormat commentFormat;
  void multiLineComments(const QString &text, const QString &startOfComment, const QString &endOfComment);
  void highlightCDTA(const QString &text, const QString &startText, const QString &endText);
  void singleQuotedStrings(const QString &text);
  void doubleQuotedStrings(const QString &text);
  EditorTypes::EditorType editorType;
  QTextCharFormat normalFormat;
  QTextDocument *document;
  QSettings settings;
 };

class TextBlockData : public QTextBlockUserData
{
public:
  TextBlockData();
  QVector<BracketInfo *> brackets();
  void insert(BracketInfo *info);

private:
  QVector<BracketInfo *> vectorBrackets;
};
#endif // GENERALHIGHLIGHTER_H
