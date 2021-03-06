/*****************************************************************************
*
* This file is part of Calíope Database Administrator.
* Copyright (c) 2008-2018 David Villalobos Cambronero (david.villalobos.c@gmail.com).
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

#include <QTextDocument>
#include <QApplication>

#include "generalhighlighter.h"
#include "staticfunctions.h"

#include "QDebug"

TextBlockData::TextBlockData()
{
}

QVector<BracketInfo *> TextBlockData::brackets()
{
  return vectorBrackets;
}

void TextBlockData::insert(BracketInfo *info)
{
  int i = 0;
  while (i < vectorBrackets.size() && info->position > vectorBrackets.at(i)->position)
    ++i;
  vectorBrackets.insert(i, info);
}

/*******************************************************************/
GeneralHighlighter::GeneralHighlighter(QTextDocument *parent, EditorTypes::EditorType type) : QSyntaxHighlighter(parent)
{
  document = parent;
  commentFormat.setForeground(Qt::gray);
  commentFormat.setFontItalic(true);
  editorType = type;
  normalFormat.setForeground(Qt::black);
  normalFormat.setFontWeight(QFont::Normal);
  findRule.format.setBackground(QBrush(QColor(255, 239, 11)));
  findRule.pattern.setPattern("");

  //Comments
  /**
    If needed, place this lines in the *HighlightRules
    to override this format
  **/
//  stringStartExpression1 = QRegExp("(^')|([^\\\\])'");
//  stringEndExpression1 = QRegExp("(^')|([^\\\\])'");
//  stringFormatSingleQuote.setForeground(Qt::red);
//  stringStartExpression2 = QRegExp("(^\")|([^\\\\])\"");
//  stringEndExpression2 = QRegExp("(^\")|([^\\\\])\"");
//  stringFormatDoubleQuote.setForeground(Qt::darkCyan);

  stringStartExpression1 = QRegExp("[^\\\\]'");
  stringEndExpression1 = QRegExp("[^\\\\]'");
  stringFormatSingleQuote.setForeground(Qt::red);
  stringStartExpression2 = QRegExp("[^\\\\]\"");
  stringEndExpression2 = QRegExp("[^\\\\]\"");
  stringFormatDoubleQuote.setForeground(Qt::darkCyan);

  switch(editorType) {
  case EditorTypes::SQLQuery:
    sqlHighlightRules();
    break;
  case EditorTypes::SVNLog:
    svnHighlightRules();
    break;
  case EditorTypes::Diff:
    diffHighlightRules();
    break;
  case EditorTypes::Commit:
    commitHighlightRules();
    break;
  case EditorTypes::NoEditor:
    break;
  // default: Q_ASSERT(false);
  }
}

void GeneralHighlighter::setFindPattern(const QString &exp)
{
  findRule.pattern = QRegExp(exp, Qt::CaseInsensitive);
}

void GeneralHighlighter::highlightBlock(const QString &text)
{
  TextBlockData *data = new TextBlockData;
  foreach (char leftBracket, StaticFunctions::bracketLeftList()) {
    int leftPos = text.indexOf(leftBracket);
    while (leftPos != -1) {
      BracketInfo *info = new BracketInfo;
      info->character = leftBracket;
      info->position = leftPos;
      data->insert(info);
      leftPos = text.indexOf(leftBracket, leftPos + 1);
    }
    char rightBracket = StaticFunctions::rightBracketMatch(leftBracket);
    int rightPos = text.indexOf(rightBracket);
    while (rightPos != -1) {
      BracketInfo *info = new BracketInfo;
      info->character = rightBracket;
      info->position = rightPos;
      data->insert(info);
      rightPos = text.indexOf(rightBracket, rightPos +1);
    }
  }
  setCurrentBlockUserData(data);

  foreach (const HighlightingRule &rule, firstHighlightingRules)
    highlightProcedure(rule, text);

  //Everything else
  setCurrentBlockState(0);
  foreach (const HighlightingRule &rule, secondHighlightingRules)
    highlightProcedure(rule, text);

  //String strings with '
  setCurrentBlockState(0);
  singleQuotedStrings(text);

  //String strings with "
  setCurrentBlockState(0);
  doubleQuotedStrings(text);

  //Single line comments
  setCurrentBlockState(0);
  foreach (const HighlightingRule &rule, thirdHighlightingRules)
    highlightProcedure(rule, text);

  setCurrentBlockState(0);
  switch(editorType) {
  case EditorTypes::SQLQuery:
  case EditorTypes::SVNLog:
  case EditorTypes::Diff:
  case EditorTypes::Commit:
    multiLineComments(text, "/*", "*/");
    break;
  case EditorTypes::NoEditor:
    break;
  // default: Q_ASSERT(false);
  }
  //Highlight find results
  if (!findRule.pattern.isEmpty()) {
    setCurrentBlockState(0);
    highlightProcedure(findRule, text);
  }
}

void GeneralHighlighter::multiLineComments(const QString &text, const QString &startOfComment, const QString &endOfComment)
{
  if (previousBlockState() > -1 && (previousBlockState() & Commenting) == Commenting) {
    int end = text.indexOf(endOfComment);
    if (end == -1) {
      setFormat(0, text.length(), commentFormat);
      setCurrentBlockState(currentBlockState() | Commenting);
      return;
    } else {
      setFormat(0, end + endOfComment.length(), commentFormat);
    }
  }

  int start = text.lastIndexOf(startOfComment);
  if (start != -1) {
    int end = text.lastIndexOf(endOfComment);
    if (end < start) {
      setFormat(start, text.length(), commentFormat);
      setCurrentBlockState(currentBlockState() | Commenting);
    }
  }
}

void GeneralHighlighter::highlightCDTA(const QString &text, const QString &startText, const QString &endText)
{
  if (previousBlockState() > -1 && (previousBlockState() & CDATA) == CDATA) {
    int end = text.indexOf(endText);
    if (end == -1) {
      setFormat(0, text.length(), normalFormat);
      setCurrentBlockState(currentBlockState() | CDATA);
      return;
    } else {
      setFormat(0, end + endText.length(), normalFormat);
    }
  }

  int start = text.lastIndexOf(startText);
  if (start != -1) {
    int end = text.lastIndexOf(endText);
    if (end < start) {
      setFormat(start, text.length(), normalFormat);
      setCurrentBlockState(currentBlockState() | CDATA);
    }
  }
}

void GeneralHighlighter::singleQuotedStrings(const QString &text)
{
  if (!stringEndExpression1.isEmpty()) {
    int startIndex = 0;
    if (previousBlockState() != 1)
      startIndex = stringStartExpression1.indexIn(text);

    while (startIndex >= 0) {
      int endIndex = stringEndExpression1.indexIn(text, (startIndex + 1));
      int commentLength;
      if (endIndex == -1) {
        setCurrentBlockState(1);
        commentLength = text.length() - startIndex;
      } else {
        commentLength = endIndex - startIndex + stringEndExpression1.matchedLength();
      }
      setFormat(startIndex + 1, commentLength - 1, stringFormatSingleQuote);
      startIndex = stringStartExpression1.indexIn(text, startIndex + commentLength);
    }
  }
}

void GeneralHighlighter::doubleQuotedStrings(const QString &text)
{
  if (!stringEndExpression2.isEmpty()) {
    int startIndex = 0;
    if (previousBlockState() != 1)
      startIndex = stringStartExpression2.indexIn(text);

    while (startIndex >= 0) {
      int endIndex = stringEndExpression2.indexIn(text, (startIndex + 1));
      int commentLength;
      if (endIndex == -1) {
        setCurrentBlockState(1);
        commentLength = text.length() - startIndex;
      } else {
        commentLength = endIndex - startIndex + stringEndExpression2.matchedLength();
      }
      setFormat(startIndex + 1, commentLength - 1, stringFormatDoubleQuote);
      startIndex = stringStartExpression2.indexIn(text, startIndex + commentLength);
    }
  }
}

void GeneralHighlighter::highlightProcedure(HighlightingRule rule, const QString &text)
{
  int index = rule.pattern.indexIn(text);
  while (index >= 0) {
    int length = rule.pattern.matchedLength();
    setFormat(index, length, rule.format);
    index = rule.pattern.indexIn(text, index + length);
  }
}

void GeneralHighlighter::diffHighlightRules()
{
  //-
  rule.format.setForeground(Qt::red);
  rule.pattern = QRegExp("^\\-.*");
  secondHighlightingRules.append(rule);

  //+
  rule.format.setForeground(Qt::darkGreen);
  rule.pattern = QRegExp("^\\+.*");
  secondHighlightingRules.append(rule);

  //@
  rule.format.setForeground(Qt::blue);
  rule.pattern = QRegExp("^@.*");
  secondHighlightingRules.append(rule);

  //Index
  rule.format.setForeground(Qt::darkBlue);
  rule.pattern = QRegExp("^Index.*");
  secondHighlightingRules.append(rule);

  //===
  rule.format.setForeground(Qt::darkBlue);
  rule.pattern = QRegExp("^=.*");
  secondHighlightingRules.append(rule);
}

void GeneralHighlighter::svnHighlightRules()
{
  //Entry start
  rule.format.setForeground(Qt::black);
  rule.format.setFontWeight(QFont::Bold);
  rule.pattern = QRegExp("^-{10,}");
  secondHighlightingRules.append(rule);

  //Entry detail
  rule.format.setForeground(Qt::black);
  rule.format.setFontWeight(QFont::Bold);
  rule.pattern = QRegExp("^r\\d{1,}.*");
  secondHighlightingRules.append(rule);

  rule.format.setFontWeight(QFont::Normal);

  //Entry module
  rule.format.setForeground(Qt::black);
//  rule.format.setFontWeight(QFont::Bold);
  rule.format.setFontItalic(true);
  rule.pattern = QRegExp("^\\[.*\\]");
  secondHighlightingRules.append(rule);

  rule.format.setFontItalic(false);

  //NEW
  rule.format.setForeground(Qt::blue);
  rule.pattern = QRegExp("^\\* NEW: ");
  secondHighlightingRules.append(rule);

  //OPT
  rule.format.setForeground(Qt::darkGreen);
  rule.pattern = QRegExp("^\\* OPT: ");
  secondHighlightingRules.append(rule);

  //BUG
  rule.format.setForeground(Qt::red);
  rule.pattern = QRegExp("^\\* BUG: ");
  secondHighlightingRules.append(rule);
}

void GeneralHighlighter::commitHighlightRules()
{
  //NEW
  rule.format.setForeground(Qt::blue);
  rule.pattern = QRegExp("^\\* NEW: ");
  secondHighlightingRules.append(rule);

  //OPT
  rule.format.setForeground(Qt::darkGreen);
  rule.pattern = QRegExp("^\\* OPT: ");
  secondHighlightingRules.append(rule);

  //BUG
  rule.format.setForeground(Qt::red);
  rule.pattern = QRegExp("^\\* BUG: ");
  secondHighlightingRules.append(rule);
}

void GeneralHighlighter::sqlHighlightRules()
{
  //Operators
  QStringList operatorPatterns = QStringList() << "\\+" << "\\-" << "\\*" << "/" << "=" << "<" << ">" << "!= "
                                               << ">=" << "<=" << ":=";
  rule.format.setForeground(Qt::red);
  for (int i = 0; i < operatorPatterns.count(); i++) {
    rule.pattern = QRegExp(QString("\\b%1\\b").arg(operatorPatterns.at(i)));
    secondHighlightingRules.append(rule);
  }

  //Integers
  rule.format.setForeground(Qt::red);
  rule.pattern = QRegExp("\\d+");
  secondHighlightingRules.append(rule);

  //Decimals
  rule.format.setForeground(Qt::darkBlue);
  rule.pattern = QRegExp("\\d+\\.\\d+");
  secondHighlightingRules.append(rule);

//  QColor color;
//  QFont font;

  switch(qApp->property("DBMSType").toInt()) {
  case StaticFunctions::MySQL:
  case StaticFunctions::MariaDB:
    //Functions
    rule.format.setForeground(Qt::darkCyan);
    for (int i = 0; i < StaticFunctions::mariadbFunctions().count(); i++) {
      rule.pattern = QRegExp(QString("\\b%1\\b").arg(StaticFunctions::mariadbFunctions().at(i)), Qt::CaseInsensitive);
      secondHighlightingRules.append(rule);
    }

    //Keywords
//    color = QColor(settings.value("Theme/SQLKeywords-Foreground-ColorName", "#0000ff").toString());
//    color.setAlpha(settings.value("Theme/SQLKeywords-Foreground-ColorAlpha", 255).toInt());
//    rule.format.setFontFamily(settings.value("Theme/SQLKeywords-Foreground-FontFamily").toString());
//    rule.format.setFontPointSize(settings.value("Theme/SQLKeywords-Foreground-FontSize", 9).toInt());
//    font = QFont(rule.format.font());
//    font.setStyle(static_cast<QFont::Style>(settings.value("Theme/SQLKeywords-Foreground-FontStyle", 0).toInt()));
//    rule.format.setFont(font);
//    rule.format.setForeground(color);

    rule.format.setForeground(Qt::blue);
    for (int i = 0; i < StaticFunctions::mariadbKeywords().count(); i++) {
      rule.pattern = QRegExp(QString("\\b%1\\b").arg(StaticFunctions::mariadbKeywords().at(i)), Qt::CaseInsensitive);
      secondHighlightingRules.append(rule);
    }

    //Datatypes
    rule.format.setForeground(Qt::darkRed);
    for (int i = 0; i < StaticFunctions::mariadbDatatypes().count(); i++) {
      rule.pattern = QRegExp(QString("\\b%1\\b").arg(StaticFunctions::mariadbDatatypes().at(i)), Qt::CaseInsensitive);
      secondHighlightingRules.append(rule);
    }

    //Charsets
    rule.format.setForeground(QBrush(QColor(0, 195, 195)));
    for (int i = 0; i < StaticFunctions::mariadbCharsets().count(); i++) {
      rule.pattern = QRegExp(QString("\\b%1\\b").arg(StaticFunctions::mariadbCharsets().at(i)), Qt::CaseInsensitive);
      secondHighlightingRules.append(rule);
    }

    //Symbols
    rule.format.setForeground(Qt::darkGreen);
    rule.pattern = QRegExp("`[A-Za-z_\\d%\\- ]*`");
    secondHighlightingRules.append(rule);


    //Code errors
    rule.format.setForeground(Qt::red);
    rule.format.setFontUnderline(true);
    for (int i = 0; i < StaticFunctions::mariadbCodeErrorsNotCommaBothSides().count(); i++) {
      rule.pattern = QRegExp(QString(",\\s*%1\\s*,").arg(StaticFunctions::mariadbCodeErrorsNotCommaBothSides().at(i)), Qt::CaseInsensitive);
      secondHighlightingRules.append(rule);
      rule.pattern = QRegExp(QString(",\\s*%1").arg(StaticFunctions::mariadbCodeErrorsNotCommaBothSides().at(i)), Qt::CaseInsensitive);
      secondHighlightingRules.append(rule);
      rule.pattern = QRegExp(QString("%1\\s*,").arg(StaticFunctions::mariadbCodeErrorsNotCommaBothSides().at(i)), Qt::CaseInsensitive);
      secondHighlightingRules.append(rule);

      //Pending
//      rule.pattern = QRegExp(QString(",\\n*%1\\n*,").arg(StaticFunctions::mariadbCodeErrorsNotComma().at(i)), Qt::CaseInsensitive);
//      secondHighlightingRules.append(rule);
//      rule.pattern = QRegExp(QString(",\\n*%1").arg(StaticFunctions::mariadbCodeErrorsNotComma().at(i)), Qt::CaseInsensitive);
//      secondHighlightingRules.append(rule);
//      rule.pattern = QRegExp(QString("%1\\n*,").arg(StaticFunctions::mariadbCodeErrorsNotComma().at(i)), Qt::CaseInsensitive);
//      secondHighlightingRules.append(rule);

//      rule.pattern = QRegExp(QString(",\\r*%1\\r*,").arg(StaticFunctions::mariadbCodeErrorsNotComma().at(i)), Qt::CaseInsensitive);
//      secondHighlightingRules.append(rule);
//      rule.pattern = QRegExp(QString(",\\r*%1").arg(StaticFunctions::mariadbCodeErrorsNotComma().at(i)), Qt::CaseInsensitive);
//      secondHighlightingRules.append(rule);
//      rule.pattern = QRegExp(QString("%1\\r*,").arg(StaticFunctions::mariadbCodeErrorsNotComma().at(i)), Qt::CaseInsensitive);
//      secondHighlightingRules.append(rule);

//      rule.pattern = QRegExp(QString(",\\t*%1\\t*,").arg(StaticFunctions::mariadbCodeErrorsNotComma().at(i)), Qt::CaseInsensitive);
//      secondHighlightingRules.append(rule);
//      rule.pattern = QRegExp(QString(",\\t*%1").arg(StaticFunctions::mariadbCodeErrorsNotComma().at(i)), Qt::CaseInsensitive);
//      secondHighlightingRules.append(rule);
//      rule.pattern = QRegExp(QString("%1\\t*,").arg(StaticFunctions::mariadbCodeErrorsNotComma().at(i)), Qt::CaseInsensitive);
//      secondHighlightingRules.append(rule);
    }
    for (int i = 0; i < StaticFunctions::mariadbCodeErrorsNotCommaOnLeft().count(); i++) {
      rule.pattern = QRegExp(QString("%1\\s*,").arg(StaticFunctions::mariadbCodeErrorsNotCommaOnLeft().at(i)), Qt::CaseInsensitive);
      secondHighlightingRules.append(rule);
    }

    break;
  case StaticFunctions::Undefined:
  default:
    break;
  }


  //Result
  rule.format.setForeground(Qt::black);
  rule.pattern = QRegExp("^(\\+|\\|).*(\\+|\\|)");
  secondHighlightingRules.append(rule);

  //Comments
  rule.format.setForeground(QBrush(QColor(106, 182, 182)));
  rule.pattern = QRegExp("(#|-- ).*");
  thirdHighlightingRules.append(rule);

  //Commnets like /*----------*/
  rule.format.setForeground(Qt::gray);
  rule.pattern = QRegExp("/\\*.*\\*/");
  thirdHighlightingRules.append(rule);
}
