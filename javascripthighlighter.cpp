#include "javascripthighlighter.h"
#include "staticfunctions.h"

JavaScriptHighlighter::JavaScriptHighlighter(QTextDocument *parent) : QSyntaxHighlighter(parent)
{
  HighlightingRule rule;

  //Operators
  QStringList operatorPatterns = QStringList() << "\\+" << "\\-" << "\\*" << "/" << "=" << "<" << ">" << "!= "
                                               << ">=" << "<=" << ":=";
  rule.format.setForeground(Qt::red);
  for (int i = 0; i < operatorPatterns.count(); i++) {
    rule.pattern = QRegExp(QString("\\b%1\\b").arg(operatorPatterns.at(i)));
    highlightingRules.append(rule);
  }

  //Integers
  rule.format.setForeground(Qt::red);
  rule.pattern = QRegExp("\\d+");
  highlightingRules.append(rule);

  //Decimals
  rule.format.setForeground(Qt::darkBlue);
  rule.pattern = QRegExp("\\d+\\.\\d+");
  highlightingRules.append(rule);

  //Keywords
  rule.format.setForeground(Qt::blue);
  for (int i = 0; i < StaticFunctions::mysqlKeywords().count(); i++) {
    rule.pattern = QRegExp(QString("\\b%1\\b").arg(StaticFunctions::mysqlKeywords().at(i)), Qt::CaseInsensitive);
    highlightingRules.append(rule);
  }

  //Functions
  rule.format.setForeground(Qt::darkCyan);
  for (int i = 0; i < StaticFunctions::mysqlFunctions().count(); i++) {
    rule.pattern = QRegExp(QString("\\b%1\\b").arg(StaticFunctions::mysqlFunctions().at(i)), Qt::CaseInsensitive);
    highlightingRules.append(rule);
  }

  //Datatypes
  rule.format.setForeground(Qt::darkRed);
  for (int i = 0; i < StaticFunctions::mysqlDatatypes().count(); i++) {
    rule.pattern = QRegExp(QString("\\b%1\\b").arg(StaticFunctions::mysqlDatatypes().at(i)), Qt::CaseInsensitive);
    highlightingRules.append(rule);
  }

  //Charsets
  rule.format.setForeground(QBrush(QColor(0, 195, 195)));
  for (int i = 0; i < StaticFunctions::mysqlCharsets().count(); i++) {
    rule.pattern = QRegExp(QString("\\b%1\\b").arg(StaticFunctions::mysqlCharsets().at(i)), Qt::CaseInsensitive);
    highlightingRules.append(rule);
  }

  //Symbols
  rule.format.setForeground(Qt::darkGreen);
  rule.pattern = QRegExp("`[A-Za-z_\\d%]*`");
  highlightingRules.append(rule);

  //Result
  rule.format.setForeground(Qt::black);
  rule.pattern = QRegExp("^(\\+|\\|).*(\\+|\\|)");
  highlightingRules.append(rule);

//  //Strings
//  rule.format.setForeground(Qt::red);
//  rule.pattern = QRegExp("'.*'");
//  highlightingRules.append(rule);
//  rule.pattern = QRegExp("\".*\"");
//  highlightingRules.append(rule);

  //Comments
  rule.format.setForeground(QBrush(QColor(106, 182, 182)));
  rule.pattern = QRegExp("(#|-- ).*");
  highlightingRules.append(rule);
//  commentStartExpression = QRegExp("/\\*");
//  commentEndExpression = QRegExp("\\*/");

  stringStartExpression = QRegExp("'");
  stringEndExpression = QRegExp("'");

//  commentFormat.setForeground(QBrush(QColor(106, 182, 182)));
  stringFormat.setForeground(Qt::red);
}

void JavaScriptHighlighter::highlightBlock(const QString &text)
{
  //String strings
  int startIndex = 0;
  if (previousBlockState() != 1)
    startIndex = stringStartExpression.indexIn(text);

  while (startIndex >= 0) {
    int endIndex = stringEndExpression.indexIn(text, (startIndex + 1));
    int commentLength;
    if (endIndex == -1) {
      setCurrentBlockState(1);
      commentLength = text.length() - startIndex;
    } else {
      commentLength = endIndex - startIndex
                      + stringEndExpression.matchedLength();
    }
    setFormat(startIndex, commentLength, stringFormat);
    startIndex = stringStartExpression.indexIn(text, startIndex + commentLength);
  }

  //Everything else
  setCurrentBlockState(0);
  if (!text.isEmpty()) {
    foreach (const HighlightingRule &rule, highlightingRules) {
      QRegExp expression(rule.pattern);
      int index = expression.indexIn(text);
      while (index >= 0) {
        int length = expression.matchedLength();
        setFormat(index, length, rule.format);
        index = expression.indexIn(text, index + length);
      }
    }
  }

//  int startIndex = 0;
//  if (previousBlockState() != 1)
//    startIndex = commentStartExpression.indexIn(text);

//  while (startIndex >= 0) {
//    int endIndex = commentEndExpression.indexIn(text, startIndex);
//    int commentLength;
//    if (endIndex == -1) {
//      setCurrentBlockState(1);
//      commentLength = text.length() - startIndex;
//    } else {
//      commentLength = endIndex - startIndex
//                      + commentEndExpression.matchedLength();
//    }
//    setFormat(startIndex, commentLength, commentFormat);
//    startIndex = commentStartExpression.indexIn(text, startIndex + commentLength);
//  }
}

