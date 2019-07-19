#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <map>
using namespace std;

class taghrml {
  private:
    map<string, string> _attrs;
    vector<taghrml> _children;
    string _name;
    bool _tagopen;

  public:
    taghrml(string name) : _tagopen(true), _name(name) {}

    void addattribute(string name, string value) {
      _attrs[name] = value;
    }

    void addchild(taghrml & child) {
      if (_children.size() && _children.back().isopen()) {
        _children.back().addchild(child);
      } else {
        _children.push_back(child);
      }
    }

    void closetag() {
      if (_tagopen) {
        if ((_children.size() && ! _children.back().isopen()) ||
            ! _children.size()) {
          _tagopen = false;
        }
        else if (_children.size() && _children.back().isopen()) {
          _children.back().closetag();
        }
      }
    }

    bool getpath(string & path, bool & found, size_t pos = 0) {
      bool tilda = false;
      if (checkpathtag(path, pos, tilda)) {
        if (tilda) {
          string attr = path.substr(pos, string::npos);
          try {
            cout << _attrs.at(attr) << endl;
            found = true;
          }
          catch (...) {}
        }
        else {
          for (vector<taghrml>::iterator i = _children.begin();
              i != _children.end();
              ++i) {
            if (i->getpath(path, found, pos)) {
              break;
            }
          }
        }
        return(true);
      } else {
        return(false);
      }
    }

    bool isopen() {
      return(_tagopen);
    }

  private:
    bool checkpathtag(string & path, size_t & pos, bool & tilda) {
      size_t startpos = pos;

      size_t dotpos = path.find(".", startpos);
      size_t tildapos = path.find("~", startpos);

      size_t endpos = min(dotpos, tildapos);

      string tag = path.substr(startpos, endpos - startpos);

      bool retval = false;

      if (endpos == tildapos) {
        tilda = true;
      }
      if (0 == tag.compare(_name)) {
        pos = endpos + 1;
        retval = true;
      }

      return(retval);
    }
};

class dochrml {
  private:
    vector<taghrml> _children;

  public:
    dochrml() {}

    void readpaths(int nlines) {
      for (int i = 0; i < nlines; ++i) {
        parsepathline();
      }
    }

    void readhrml(int nlines) {
      for (int i = 0; i < nlines; ++i) {
        parsehrmlline();
      }
    }

  private:
    void gethrmlattr(
        string & line, size_t & pos, string & name, string & value
        ) {
      size_t startpos = pos;

      size_t equalpos = line.find("=", startpos);
      size_t greaterpos = line.find(">", startpos);
      size_t spacepos = line.find(" ", startpos);

      size_t endpos = min(equalpos, spacepos);
      if (string::npos == endpos) {
        name = "";
        value = "";
        pos = endpos;
      } else {
        name = line.substr(startpos, endpos - startpos);

        startpos = equalpos + 1;

        size_t oldspacepos = equalpos;
        spacepos = line.find(" ", startpos);
        while ((spacepos == oldspacepos + 1) && (string::npos != spacepos)){
          oldspacepos = spacepos;
          spacepos = line.find(" ", ++startpos);
        }

        size_t endpos = min(greaterpos, spacepos);
        value = line.substr(startpos, endpos - startpos);

        oldspacepos = spacepos - 1;
        startpos = spacepos;
        while ((spacepos == oldspacepos + 1) && (string::npos != spacepos)){
          oldspacepos = spacepos;
          spacepos = line.find(" ", ++startpos);
        }

        endpos = min(greaterpos, oldspacepos);
        if (line.length() == endpos + 1) {
          pos = endpos;
        } else {
          pos = endpos + 1;
        }
      }
    }

    void gethrmltag(string & line, size_t & pos, string & name) {
      size_t startpos = pos;

      size_t greaterpos = line.find(">", startpos);
      size_t spacepos = line.find(" ", startpos);

      size_t endpos = min(greaterpos, spacepos);
      name = line.substr(startpos, endpos - startpos);

      size_t oldspacepos = spacepos - 1;
      startpos = spacepos;
      while ((spacepos == oldspacepos + 1) && (string::npos != spacepos)){
        oldspacepos = spacepos;
        spacepos = line.find(" ", ++startpos);
      }

      endpos = min(greaterpos, oldspacepos);
      if (line.length() == endpos + 1) {
        pos = endpos;
      } else {
        pos = endpos + 1;
      }
    }

    void parsehrmlline() {
      string line;

      getline(cin, line);
      tokenizehrml(line);
    }

    void parsepathline() {
      string line;

      getline(cin, line);

      bool found = false;

      for (vector<taghrml>::iterator i = _children.begin();
          i != _children.end();
          ++i) {
        if (i->getpath(line, found)) {
          break;
        }
      }

      if (! found) {
        cout << "Not Found!" << endl;
      }
    }

    void tokenizehrml(string & line) {
      if ("/" == line.substr(1,1)) {
        size_t pos = 2;

        string name = line.substr(pos, line.find(">") - pos);

        _children.back().closetag();
      }
      else {
        size_t pos = 1;
        string attrname;
        string attrvalue;
        string tagname;

        gethrmltag(line, pos, tagname);

        taghrml newtag(tagname);

        size_t firstquote = 0;
        size_t secondquote = 0;
        while (line.length() > pos + 1) {
          gethrmlattr(line, pos, attrname, attrvalue);
          firstquote = attrvalue.find("\"");
          secondquote = attrvalue.find("\"", firstquote + 1);

          newtag.addattribute(
              attrname,
              attrvalue.substr(firstquote + 1, secondquote - firstquote - 1)
              );
        }

        if (_children.size() && _children.back().isopen()) {
          _children.back().addchild(newtag);
        } else {
          _children.push_back(newtag);
        }
      }
    }
};

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int n, q;
  string line1;

  cin >> n >> q;
  getline(cin, line1);

  dochrml doc;
  doc.readhrml(n);
  doc.readpaths(q);

  return 0;
}
