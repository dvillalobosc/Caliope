#include "csshighlighter.h"
#include "staticfunctions.h"

CSSHighlighter::CSSHighlighter(QTextDocument *parent) : QSyntaxHighlighter(parent)
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

  //Properties
  rule.format.setForeground(Qt::blue);
  for (int i = 0; i < StaticFunctions::cssProperties().count(); i++) {
    rule.pattern = QRegExp(QString("\\b%1\\b").arg(StaticFunctions::cssProperties().at(i)), Qt::CaseInsensitive);
    highlightingRules.append(rule);
  }

  //Hex values
  rule.format.setForeground(Qt::darkYellow);
  rule.pattern = QRegExp("#\\d{6}");
  highlightingRules.append(rule);

  //Comments
  stringStartExpression = QRegExp("/\\*");
  stringEndExpression = QRegExp("\\*/");
  stringFormat.setForeground(QBrush(QColor(106, 182, 182)));
}

void CSSHighlighter::highlightBlock(const QString &text)
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
}

