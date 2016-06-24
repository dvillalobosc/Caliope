#ifndef CODESNIPPETS_H
#define CODESNIPPETS_H

#include <QWidget>
#include <QSettings>

class QPlainTextEdit;
class QDialogButtonBox;

class CodeSnippets : public QWidget
{
  Q_OBJECT

public:
  CodeSnippets();
  void retranslateUi();
  QStringList getCodeSnippets();
  QString getCodeSnippet(const QString key);

private:
  QSettings settings;
  QPlainTextEdit *codeSnippetsPlainTextEdit;
  QDialogButtonBox *buttonBox;
  QString loadCodeSnippets();

private slots:
  void helpCodeSnippets();
  void saveCodeSnippets();
};

#endif // CODESNIPPETS_H
