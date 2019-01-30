// DateiLesenSchreiben.cpp 
// csv-datei lesen und im xml-format schreiben
// Erweitert um die Erzeugung einer sql-Steuerdatei (für Projekt DBLesen - csv import ist da aber einfacher...)
//
//
// liest aus der Eingabedatei die erste Zeile und interpretiert sie als Kopfzeile
// Die xml-Datei hat dann folgendes Format
//
//
// source (csv):
// 1. Zeile: a,b,c,d
// 2. Zeile: 1,11113,1q1q1qa,f
// 3. Zeile: 2,11113,1q1q1qa,f
// 
// dest. (xml):
//xml:
//	< ? xml version = "1.0" encoding = "UTF-8" ? >
//	<policyids>
//		<a id = "1">
//			<b>11113 </b >
//			<c>1q1q1qa</c>
//			<d>f</d>OK
//		</a>
//		<a id = "2">
//			<b>11113 </b >
//			<c>1q1q1qa</c>
//			<d>f</d>
//		</a>
// ...
//	</policyids>
//

//Udo Wallasch

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>


using namespace std;

const char DELIMITER = ',';
const int MAX_RECORDS = 1000;
const string DB_TABLE_NAME = "policies";
const string SQL_DELIMITER = ",";

struct attribute {
	string name;
	string value;
};

void writeSQLInsert(fstream&);
void writeSQLValue(fstream&,string& ,string);
void writeSQLEnd(fstream&);

void writeXmlHeader(fstream&);
void writeXmlStartElement(fstream&, string&, vector<attribute>&);
void writeXmlStartElement(fstream&, string&);
void writeXmlEndElement(fstream& ,string&);
void writeXmlText(fstream&, string&);

vector<string> readHeader(fstream&);
string readElement(fstream&);

vector<string> elements;
string element;
vector<attribute> attributes;

int main()
{
	fstream f, x, s;
	string header = "";
	string tmp = "";
	string dat = "daten";

	string in = dat + ".csv";
	string out = dat + ".xml";
	//zur Erzeugung einer sqlSteuerdatei füe SQlite3
	string sql = dat + ".sql";

	std::cout << "\n Bearbeite die ersten "<< MAX_RECORDS <<" Datensaetze aus "<<in<< "...\n";

	f.open(in, ios::in);
	if (!f) {
		std::cout << "\nEingabedatei " << in << " kann nicht geoeffnet werden!";
		exit(0);
	};
	x.open(out, ios::out);
	if (!x) {
		std::cout << "\nAusgabedatei " << out << "kann nicht geoeffnet werden!";
		exit(0);
	};
	s.open(sql, ios::out);
	if (!s) {
		std::cout << "\nAusgabedatei " << sql << "kann nicht geoeffnet werden!";
		exit(0);
	};

	//Lesen der ersten Zeile der Datei und erzeugen der tags im vector elements
	elements = readHeader(f);

	writeXmlHeader(x);
	string docRoot = "policyids";

	string first = elements.at(0);
	string last = elements.at(elements.size()-1);
	bool ready = false;
	int cnt = 0;

	//Schleife über die Datensätze
	while (++cnt<= MAX_RECORDS && !ready) {
		std::cout << "\x0d Datensatz # "<<cnt;

		//Schleife über einen Datensatz
		for (string e : elements) {
			if (e == first) {
				attribute a;
				a.name = "id";
				a.value = readElement(f);
				if (a.value == "") {
					ready = true;
					break;
				}
				attributes.clear();
				attributes.push_back(a);
				writeXmlStartElement(x, first, attributes);

				writeSQLInsert(s);
				writeSQLValue(s, a.value, SQL_DELIMITER);

				continue;
			}
			string element = readElement(f);
			if (element == "") {
				writeXmlEndElement(x, e);
				writeXmlEndElement(x, first);
				ready = true;
				break;
			}
			writeXmlStartElement(x, e);
			writeXmlText(x, element);
			writeXmlEndElement(x, e);

			if (e != last) writeSQLValue(s, element, SQL_DELIMITER);

			if (e == last) {
				writeXmlEndElement(x, first);
				writeSQLValue(s, element, "");
				writeSQLEnd(s);
			}
		}
	}

	writeXmlEndElement(x, docRoot);

	x.close();
	f.close();
	s.close();

	std::cout << "\n Fertig!\n\n";

}

//Die erste Zeile der Eingabedatei enthält den Kopf der Tabelle
//diese wird in den vector elements gelesen
vector<string> readHeader(fstream& f) {
	bool ready = false;
	string header;

	string line;
	getline(f,line);

	vector<string>v;
	v.clear();
	string tag;
	int pos = 0;
	int npos = line.find(DELIMITER, pos);
	while (npos > 0) {
		tag = line.substr(pos, (npos-pos));
		pos = npos+1;
		npos = line.find(DELIMITER, pos);
		if (tag != "") v.push_back(tag);
	}
	tag = line.substr(pos, (line.length() - pos));
	if (tag != "") v.push_back(tag);

	return v;
}

//Zeichenweises Einlesen vom eingabe-stream des nächsten Datums bis zum nächsten DELIMITER 
string readElement(fstream& f) {

	string element = "";
	char c; //actual char
	while (true) {
		c = f.get();
		if (c == EOF) break;
		if (c == DELIMITER) break;
		if (c == '\n') break;
		element += c;		
	}
	return element;
}

void writeXmlHeader(fstream& x) {
	x << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
}

void writeXmlStartElement(fstream& x, string& e, vector<attribute>& as) {
	x << "<" << e;
	for (attribute a : as) {
		x << " " << a.name << " = \"" << a.value << "\"";
	}
	x << ">\n";
}

void writeXmlStartElement(fstream& x, string& e) {
	x << "<" << e << ">";
}

void writeXmlEndElement(fstream& x, string& e) {
	x << "</" << e << ">\n";
}

void writeXmlText(fstream& x, string& text) {
	x << text;
}

void writeSQLInsert(fstream& sql) {
	sql << "insert into " << DB_TABLE_NAME << " values(";
}

void writeSQLValue(fstream& sql, string& s, string del) {
	sql << "\'" << s << " varchar(20)\'" << del;
}
void writeSQLEnd(fstream& sql) {
	sql << ");\n";
}