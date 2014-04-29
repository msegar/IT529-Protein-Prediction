#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <sstream>
#include <algorithm>
#include <RInside.h>                    // for the embedded R via RInside

using namespace std;


int getAtoms(string &seq){
	int num = 0;
	num += std::count(seq.begin(), seq.end(), 'A') * 13; // A
	num += std::count(seq.begin(), seq.end(), 'R') * 26; // R
	num += std::count(seq.begin(), seq.end(), 'N') * 17; // N
	num += std::count(seq.begin(), seq.end(), 'D') * 16; // D
	num += std::count(seq.begin(), seq.end(), 'C') * 14; // C
	num += std::count(seq.begin(), seq.end(), 'Q') * 20; // Q
	num += std::count(seq.begin(), seq.end(), 'E') * 19; // E
	num += std::count(seq.begin(), seq.end(), 'G') * 10; // H
	num += std::count(seq.begin(), seq.end(), 'H') * 20; // H
	num += std::count(seq.begin(), seq.end(), 'I') * 22; // I
	num += std::count(seq.begin(), seq.end(), 'L') * 22; // L
	num += std::count(seq.begin(), seq.end(), 'K') * 24; // K
	num += std::count(seq.begin(), seq.end(), 'M') * 20; // M
	num += std::count(seq.begin(), seq.end(), 'F') * 23; // F
	num += std::count(seq.begin(), seq.end(), 'P') * 17; // P
	num += std::count(seq.begin(), seq.end(), 'S') * 14; // S
	num += std::count(seq.begin(), seq.end(), 'T') * 17; // T
	num += std::count(seq.begin(), seq.end(), 'W') * 27; // W
	num += std::count(seq.begin(), seq.end(), 'Y') * 24; // Y
	num += std::count(seq.begin(), seq.end(), 'V') * 19; // V
	return num;
}

double getCarbonAtoms(string &seq){
	double num = 0;
	num += std::count(seq.begin(), seq.end(), 'A') * 	3;
	num += std::count(seq.begin(), seq.end(), 'C') * 	3;
	num += std::count(seq.begin(), seq.end(), 'D') * 	4;
	num += std::count(seq.begin(), seq.end(), 'E') * 	5;
	num += std::count(seq.begin(), seq.end(), 'F') * 	9;
	num += std::count(seq.begin(), seq.end(), 'G') * 	2;
	num += std::count(seq.begin(), seq.end(), 'H') * 	6;
	num += std::count(seq.begin(), seq.end(), 'I') * 	6;
	num += std::count(seq.begin(), seq.end(), 'K') * 	6;
	num += std::count(seq.begin(), seq.end(), 'L') * 	6;
	num += std::count(seq.begin(), seq.end(), 'M') * 	5;
	num += std::count(seq.begin(), seq.end(), 'N') * 	4;
	num += std::count(seq.begin(), seq.end(), 'P') * 	5;
	num += std::count(seq.begin(), seq.end(), 'Q') * 	5;
	num += std::count(seq.begin(), seq.end(), 'R') * 	6;
	num += std::count(seq.begin(), seq.end(), 'S') * 	3;
	num += std::count(seq.begin(), seq.end(), 'T') * 	4;
	num += std::count(seq.begin(), seq.end(), 'V') * 	5;
	num += std::count(seq.begin(), seq.end(), 'W') * 	11;
	num += std::count(seq.begin(), seq.end(), 'Y') * 	9;

	return num;
}

double getHydrogenAtoms(string &seq){
	double num = 0;
	num += std::count(seq.begin(), seq.end(), 'A') * 	7;
	num += std::count(seq.begin(), seq.end(), 'C') * 	7;
	num += std::count(seq.begin(), seq.end(), 'D') * 	7;
	num += std::count(seq.begin(), seq.end(), 'E') * 	9;
	num += std::count(seq.begin(), seq.end(), 'F') * 	11;
	num += std::count(seq.begin(), seq.end(), 'G') * 	5;
	num += std::count(seq.begin(), seq.end(), 'H') * 	9;
	num += std::count(seq.begin(), seq.end(), 'I') * 	13;
	num += std::count(seq.begin(), seq.end(), 'K') * 	14;
	num += std::count(seq.begin(), seq.end(), 'L') * 	13;
	num += std::count(seq.begin(), seq.end(), 'M') * 	11;
	num += std::count(seq.begin(), seq.end(), 'N') * 	8;
	num += std::count(seq.begin(), seq.end(), 'P') * 	9;
	num += std::count(seq.begin(), seq.end(), 'Q') * 	10;
	num += std::count(seq.begin(), seq.end(), 'R') * 	14;
	num += std::count(seq.begin(), seq.end(), 'S') * 	7;
	num += std::count(seq.begin(), seq.end(), 'T') * 	9;
	num += std::count(seq.begin(), seq.end(), 'V') * 	11;
	num += std::count(seq.begin(), seq.end(), 'W') * 	12;
	num += std::count(seq.begin(), seq.end(), 'Y') * 	11;

	return num;
}

double getNitrogenAtoms(string &seq){
	double num = 0;
	num += std::count(seq.begin(), seq.end(), 'A') * 	1;
	num += std::count(seq.begin(), seq.end(), 'C') * 	1;
	num += std::count(seq.begin(), seq.end(), 'D') * 	1;
	num += std::count(seq.begin(), seq.end(), 'E') * 	1;
	num += std::count(seq.begin(), seq.end(), 'F') * 	1;
	num += std::count(seq.begin(), seq.end(), 'G') * 	1;
	num += std::count(seq.begin(), seq.end(), 'H') * 	3;
	num += std::count(seq.begin(), seq.end(), 'I') * 	1;
	num += std::count(seq.begin(), seq.end(), 'K') * 	2;
	num += std::count(seq.begin(), seq.end(), 'L') * 	1;
	num += std::count(seq.begin(), seq.end(), 'M') * 	1;
	num += std::count(seq.begin(), seq.end(), 'N') * 	2;
	num += std::count(seq.begin(), seq.end(), 'P') * 	1;
	num += std::count(seq.begin(), seq.end(), 'Q') * 	2;
	num += std::count(seq.begin(), seq.end(), 'R') * 	4;
	num += std::count(seq.begin(), seq.end(), 'S') * 	1;
	num += std::count(seq.begin(), seq.end(), 'T') * 	1;
	num += std::count(seq.begin(), seq.end(), 'V') * 	1;
	num += std::count(seq.begin(), seq.end(), 'W') * 	2;
	num += std::count(seq.begin(), seq.end(), 'Y') * 	1;

	return num;
}

double getOxygenAtoms(string &seq){
	double num = 0;
	num += std::count(seq.begin(), seq.end(), 'A') * 	2;
	num += std::count(seq.begin(), seq.end(), 'C') * 	2;
	num += std::count(seq.begin(), seq.end(), 'D') * 	4;
	num += std::count(seq.begin(), seq.end(), 'E') * 	4;
	num += std::count(seq.begin(), seq.end(), 'F') * 	2;
	num += std::count(seq.begin(), seq.end(), 'G') * 	2;
	num += std::count(seq.begin(), seq.end(), 'H') * 	2;
	num += std::count(seq.begin(), seq.end(), 'I') * 	2;
	num += std::count(seq.begin(), seq.end(), 'K') * 	2;
	num += std::count(seq.begin(), seq.end(), 'L') * 	2;
	num += std::count(seq.begin(), seq.end(), 'M') * 	2;
	num += std::count(seq.begin(), seq.end(), 'N') * 	3;
	num += std::count(seq.begin(), seq.end(), 'P') * 	2;
	num += std::count(seq.begin(), seq.end(), 'Q') * 	3;
	num += std::count(seq.begin(), seq.end(), 'R') * 	2;
	num += std::count(seq.begin(), seq.end(), 'S') * 	3;
	num += std::count(seq.begin(), seq.end(), 'T') * 	3;
	num += std::count(seq.begin(), seq.end(), 'V') * 	2;
	num += std::count(seq.begin(), seq.end(), 'W') * 	2;
	num += std::count(seq.begin(), seq.end(), 'Y') * 	3;

	return num;
}

double getSulfurAtoms(string &seq){
	double num = 0;
	num += std::count(seq.begin(), seq.end(), 'A') * 	0	;
	num += std::count(seq.begin(), seq.end(), 'C') * 	1	;
	num += std::count(seq.begin(), seq.end(), 'D') * 	0	;
	num += std::count(seq.begin(), seq.end(), 'E') * 	0	;
	num += std::count(seq.begin(), seq.end(), 'F') * 	0	;
	num += std::count(seq.begin(), seq.end(), 'G') * 	0	;
	num += std::count(seq.begin(), seq.end(), 'H') * 	0	;
	num += std::count(seq.begin(), seq.end(), 'I') * 	0	;
	num += std::count(seq.begin(), seq.end(), 'K') * 	0	;
	num += std::count(seq.begin(), seq.end(), 'L') * 	0	;
	num += std::count(seq.begin(), seq.end(), 'M') * 	1	;
	num += std::count(seq.begin(), seq.end(), 'N') * 	0	;
	num += std::count(seq.begin(), seq.end(), 'P') * 	0	;
	num += std::count(seq.begin(), seq.end(), 'Q') * 	0	;
	num += std::count(seq.begin(), seq.end(), 'R') * 	0	;
	num += std::count(seq.begin(), seq.end(), 'S') * 	0	;
	num += std::count(seq.begin(), seq.end(), 'T') * 	0	;
	num += std::count(seq.begin(), seq.end(), 'V') * 	0	;
	num += std::count(seq.begin(), seq.end(), 'W') * 	0	;
	num += std::count(seq.begin(), seq.end(), 'Y') * 	0	;

	return num;
}

double percentResidue1(string &seq, int length){
	double weight = 0;
	weight += (double) std::count(seq.begin(), seq.end(), 'L') * 100 / (double) length; // L
	weight += (double) std::count(seq.begin(), seq.end(), 'R') * 100 / (double) length; // R
	
	return weight;
}

double percentResidue2(string &seq, int length){
	double weight = 0;
	weight += (double) std::count(seq.begin(), seq.end(), 'L') * 100 / (double) length; // L
	weight += (double) std::count(seq.begin(), seq.end(), 'R') * 100 / (double) length; // R
	weight += (double) std::count(seq.begin(), seq.end(), 'H') * 100 / (double) length; // H
	
	return weight;
}

double getMolWeight(string &seq){
	double weight = 0;
	
	weight += (double) std::count(seq.begin(), seq.end(), 'A') * 71.0788; // A
	weight += (double) std::count(seq.begin(), seq.end(), 'R') * 156.1875; // R
	weight += (double) std::count(seq.begin(), seq.end(), 'N') * 114.1038; // N
	weight += (double) std::count(seq.begin(), seq.end(), 'D') * 115.0886; // D
	weight += (double) std::count(seq.begin(), seq.end(), 'C') * 103.1388; // C
	weight += (double) std::count(seq.begin(), seq.end(), 'Q') * 128.1307; // Q
	weight += (double) std::count(seq.begin(), seq.end(), 'E') * 129.1155; // E
	weight += (double) std::count(seq.begin(), seq.end(), 'G') * 57.0519; // H
	weight += (double) std::count(seq.begin(), seq.end(), 'H') * 137.1411; // H
	weight += (double) std::count(seq.begin(), seq.end(), 'I') * 113.1594; // I
	weight += (double) std::count(seq.begin(), seq.end(), 'L') * 113.1594; // L
	weight += (double) std::count(seq.begin(), seq.end(), 'K') * 128.1741; // K
	weight += (double) std::count(seq.begin(), seq.end(), 'M') * 131.1926; // M
	weight += (double) std::count(seq.begin(), seq.end(), 'F') * 147.1766; // F
	weight += (double) std::count(seq.begin(), seq.end(), 'P') * 97.1167; // P
	weight += (double) std::count(seq.begin(), seq.end(), 'S') * 87.0782; // S
	weight += (double) std::count(seq.begin(), seq.end(), 'T') * 101.1051; // T
	weight += (double) std::count(seq.begin(), seq.end(), 'W') * 186.2132; // W
	weight += (double) std::count(seq.begin(), seq.end(), 'Y') * 163.1760; // Y
	weight += (double) std::count(seq.begin(), seq.end(), 'V') * 99.1326; // V
	
	return weight;
	
}

vector<double> getAAPercent(string &seq, int size){
	vector<double> v;

	v.push_back((double) std::count(seq.begin(), seq.end(), 'A') * 100 / (double) size); // A
	v.push_back((double) std::count(seq.begin(), seq.end(), 'R') * 100 / (double) size); // R
	v.push_back((double) std::count(seq.begin(), seq.end(), 'N') * 100 / (double) size); // N
	v.push_back((double) std::count(seq.begin(), seq.end(), 'D') * 100 / (double) size); // D
	v.push_back((double) std::count(seq.begin(), seq.end(), 'C') * 100 / (double) size); // C
	v.push_back((double) std::count(seq.begin(), seq.end(), 'Q') * 100 / (double) size); // Q
	v.push_back((double) std::count(seq.begin(), seq.end(), 'E') * 100 / (double) size); // E
	v.push_back((double) std::count(seq.begin(), seq.end(), 'G') * 100 / (double) size); // H
	v.push_back((double) std::count(seq.begin(), seq.end(), 'H') * 100 / (double) size); // H
	v.push_back((double) std::count(seq.begin(), seq.end(), 'I') * 100 / (double) size); // I
	v.push_back((double) std::count(seq.begin(), seq.end(), 'L') * 100 / (double) size); // L
	v.push_back((double) std::count(seq.begin(), seq.end(), 'K') * 100 / (double) size); // K
	v.push_back((double) std::count(seq.begin(), seq.end(), 'M') * 100 / (double) size); // M
	v.push_back((double) std::count(seq.begin(), seq.end(), 'F') * 100 / (double) size); // F
	v.push_back((double) std::count(seq.begin(), seq.end(), 'P') * 100 / (double) size); // P
	v.push_back((double) std::count(seq.begin(), seq.end(), 'S') * 100 / (double) size); // S
	v.push_back((double) std::count(seq.begin(), seq.end(), 'T') * 100 / (double) size); // T
	v.push_back((double) std::count(seq.begin(), seq.end(), 'W') * 100 / (double) size); // W
	v.push_back((double) std::count(seq.begin(), seq.end(), 'Y') * 100 / (double) size); // Y
	v.push_back((double) std::count(seq.begin(), seq.end(), 'V') * 100 / (double) size); // V
	return v;
}

int main(int argc, const char* argv[])
{
	RInside R(argc, argv);              // create an embedded R instance

	R.parseEvalQ("library(seqinr)");

	ifstream input;
	input.open(argv[1]);

	vector<vector<string> > table;	
	vector<string> curr;
	
	for (string row; getline(input, row, '\n'); ){
		curr.clear();
		istringstream ss(row);
		for (string word; getline(ss, word, '\t'); )
			curr.push_back(word);
		
		table.push_back(curr);
	}
	input.close();
	
	ofstream output;
	output.open("protein_metrics.csv");
	
	int size = table.size();
	string seq = "";
	int length = 0;
	vector<double> aaPercent;
	
	output << "function\tlength\tmol weight\ttheortical pI";
	output << "\tpercent A";
	output << "\tpercent R";
	output << "\tpercent N";
	output << "\tpercent D";
	output << "\tpercent C";
	output << "\tpercent Q";
	output << "\tpercent E";
	output << "\tpercent G";
	output << "\tpercent H";
	output << "\tpercent I";
	output << "\tpercent L";
	output << "\tpercent K";
	output << "\tpercent M";
	output << "\tpercent F";
	output << "\tpercent P";
	output << "\tpercent S";
	output << "\tpercent T";
	output << "\tpercent W";
	output << "\tpercent Y";
	output << "\tpercent V";
	output << "\tpercent residue 1";
	output << "\tpercent residue 2";
	output << "\tnumber atoms";
	output << "\tnumber carbon";
	output << "\tnumber nitrogen";
	output << "\tnumber oxygen";
	output << "\tnumber sulphur";
	output << endl;
	
	for (int i = 0; i < size; ++i){
		seq = table[i].at(2);
		length = seq.length();
		output << table[i].at(1);
		
		// print length
		output << "\t" << length;
		
		// print mol weight
		output << "\t" << getMolWeight(seq);
		
		// print theoretical pI
		R["v"] = seq;
		R.parseEvalQ("prot <- s2c(v)");
		R.parseEvalQ("pi <- computePI(prot)");
		Rcpp::NumericVector p = R.parseEval("print(pi); pi");
		output << "\t" << p[0];
		
		// print composition AA
		aaPercent = getAAPercent(seq, length);
		for (int aa = 0; aa < 20; ++aa)
			output << "\t" << aaPercent[aa];
			
		// print residue 1
		output << "\t" << percentResidue1(seq, length);
		
		// print residue 2
		output << "\t" << percentResidue2(seq, length);
		
		// print num atoms
		output << "\t" << getAtoms(seq);
		// print num carbon
		output << "\t" << getCarbonAtoms(seq);
		// print num nitrogen
		output << "\t" << getNitrogenAtoms(seq);
		// print num oxygen
		output << "\t" << getOxygenAtoms(seq);
		// print num sulphur
		output << "\t" << getSulfurAtoms(seq);

		output << endl;
	}
	
    return 0;
}
