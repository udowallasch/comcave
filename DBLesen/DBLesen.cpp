// DBLesen.cpp db
// Daten werden aus einer SQlit3 DB  lesen und im xml-format geschrieben.
//
//
//
// Die xml-Datei hat dann folgendes Format
//
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
// 
//Udo Wallasch

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "sqlite3.h"

using namespace std;

const char DELIMITER = ',';
const int MAX_RECORDS = 1000;

struct attribute {
	string name;
	string value;
};

void writeXmlHeader(fstream&);
void writeXmlStartElement(fstream&, string&, vector<attribute>&);
void writeXmlStartElement(fstream&, string&);
void writeXmlEndElement(fstream&, string&);
void writeXmlText(fstream&, string&);

int getQuery();
vector<string> readHeader();
string readElement(int, int);

vector<string> elements;
string element;
vector<attribute> attributes;

sqlite3 *db;
char** queryResult;
char* errMsg;
int rowCount;
int columnCount;

int main()
{
	fstream x;
	string header = "";
	string tmp = "";
	string dat = "daten";
	string out = dat + ".xml";
	string in = dat + ".db";

	std::cout << "\n Bearbeite die ersten " << MAX_RECORDS << " Datensaetze aus Datenbank " << in<<".\n";
	
	x.open(out, ios::out);
	if (!x) {
		std::cout << "\nAusgabedatei " << out << "kann nicht geoeffnet werden!";
		exit(0);
	};

	int rc;
	rc = sqlite3_open(in.c_str(), &db);
	if (rc) {
		std::cout << "\nEingabe Datenbank " << in << "kann nicht geoeffnet werden: "<< sqlite3_errmsg(db);
		sqlite3_close(db);
		exit(0);	
	}

	rc = getQuery();
	if (rc) {
		std::cout << "\nEingabe Datenbank " << in << "kann nicht gelesen werden: " << errMsg;
		sqlite3_close(db);
		exit(0);
	}

	//Lesen der ersten Zeile der Tabelle und Erzeugen der tags im vector elements
	elements = readHeader();

	writeXmlHeader(x);
	string docRoot = "policyids";
	writeXmlStartElement(x, docRoot);

	string first = elements.at(0);
	string last = elements.at(elements.size() - 1);
	bool ready = false;
	int row = 0;
	//Schleife über die Datensätze
	while (++row <= MAX_RECORDS && !ready) {
		std::cout << "\x0d Datensatz # " << row;
		//Schleife über einen Datensatz
		for (int col = 0; col < columnCount; col++) {
			if (col == 0) {
				attribute a;
				a.name = "id";
				a.value = readElement(row,col);
				if (a.value == "") {
					ready = true;
					break;
				}
				attributes.clear();
				attributes.push_back(a);
				writeXmlStartElement(x, first, attributes);
				continue;
			}
			string element = readElement(row, col);
			if (element == "") {
				//TODO: Endeerkennung der DB??
				writeXmlEndElement(x, elements.at(col));
				writeXmlEndElement(x, first);
				ready = true;
				break;
			}
			writeXmlStartElement(x, elements.at(col));
			writeXmlText(x, element);
			writeXmlEndElement(x, elements.at(col));
			if (col == columnCount -1) {
				writeXmlEndElement(x, first);
			}
		}
	}

	writeXmlEndElement(x, docRoot);

	x.close();
	sqlite3_close(db);

	std::cout << "\n Fertig! \n Ergebnis in " << out << ".\n\n";

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

int getQuery() {
	const char * stmt = "select * from policies;";
	int rc = sqlite3_get_table(db, stmt, &queryResult, &rowCount, &columnCount, &errMsg);
	return rc;
}

vector<string> readHeader() {

	vector<string> e;
	for (int i = 0; i < columnCount; i++) {
		e.push_back(queryResult[i]);
	}
	return e;
}

string readElement(int row, int col) {
	return queryResult[(columnCount * row) + col];
}
