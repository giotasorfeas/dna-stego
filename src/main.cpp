#include <iostream>
#include <fstream>
#include <string>
#include "encoder.h"
#include "decoder.h"

using namespace std;

void show_help(){
	cout << "Usage:\n"
		 << "  ./dna-stego encode <message>\n"
		 << "  ./dna-stego decode <sequence>\n"
		 << "  ./dna-stego encodefile input.txt output.dna\n"
         << "  ./dna-stego decodefile input.dna output.txt\n"
		 << "\nShorthands:"
		 << "   encode      -->  -e\n"
		 << "   decode      -->  -d\n"
		 << "   encodefile  -->  -ef\n"
		 << "   decodefile  -->  -df\n";
}

int main(int argc, char* argv[]){
	if (argc < 3){
		show_help();
		return 1;
	}

	string command = argv[1];
	string input = argv[2];

	if (command == "encode" || command == "-e"){
		string encoded = encode_message(input);
		cout << "[DNA Sequence] " << encoded << '\n';
	}

	else if (command == "decode" || command == "-d") {
		string decoded = decode_dna(input);
		cout << "[Decoded Message] " << decoded << '\n';
	}

	else if (command == "encodefile" || command == "-ef") {
        ifstream in(argv[2]);
        ofstream out(argv[3]);
        if (!in || !out) {
            cerr << "Error opening file(s)." << '\n';
            return 1;
        }
        string contents((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
        out << encode_message(contents);
        cout << "[File Encoded] Saved to " << argv[3] << '\n';

    } else if (command == "decodefile" || command == "-df") {
        ifstream in(argv[2]);
        ofstream out(argv[3]);
        if (!in || !out) {
            cerr << "Error opening file(s)." << '\n';
            return 1;
        }
        string dna((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
        out << decode_dna(dna);
        cout << "[File Decoded] Saved to " << argv[3] << '\n';

    }

	else {cout << "Unknown command." << '\n'; return 1;}

	return 0;
}